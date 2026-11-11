# OExpL → XSM Compiler

A compiler for **OExpL** (Object-oriented Experimental Language) that targets the **XSM** (eXperimental String Machine) assembly, built with Lex, Yacc and C. It follows the [SILC NITC compiler design roadmap](https://silcnitc.github.io/) and implements every stage from basic expressions through user-defined types, functions, classes, inheritance and VTable-based dynamic dispatch.

```
 program.expl ──► lex + yacc + C backend ──► target.xsm ──► translate ──► machine.xsm ──► XSM simulator
                  (./compiler)               (symbolic labels)  (./translator)  (absolute addresses)   (+ library.lib)
```

## Features

| Area | Supported |
|---|---|
| Types | `int`, `str`, `boolean`, `void`, `null`, user-defined types, classes |
| Expressions | `+ - * / %`, relational ops, `&&`/`AND`, `\|\|`/`OR`, `!`/`NOT`, ternary `? :`, `true`/`false` |
| Statements | assignment, `read`, `write`, `if/else`, `while`, `do-while`, `repeat-until`, `for`, `switch/case/default`, `break`, `continue`, `return` |
| Shorthand | `++`, `--`, `+=`, `-=`, `*=`, `/=`, `%=` (desugared to existing AST nodes) |
| Variables | globals, locals, 1D global arrays, pointers (`int *p`, `&x`, `*p`) |
| Functions | declarations, parameters, recursion, return values, stack frames on `BP` |
| User-defined types | `type ... endtype` records, field access, heap allocation |
| Heap | `initialize()`, `alloc()`, `free()` via `library.lib` |
| OOP | classes, fields, methods, `self`, `new(Class)`, `delete(obj)` |
| Inheritance | `extends`, method overriding, `super.method()`, subclass assignment checks |
| Polymorphism | per-class VTables, dispatch through the object's VTable word |
| Overloading | methods overloaded by parameter types (name mangling `name_type1_type2`) |

## Repository layout

| File | Role |
|---|---|
| `exprtree.l` | Lexer: keywords, operators, literals, comments |
| `exprtree.y` | Parser and semantic actions; builds the AST and triggers code generation per function; boot code |
| `exprtree.h` | AST node types, type/class/symbol-table structs, shared prototypes |
| `exprtree.c` | `createTree` (type checking), register/label allocation, `codeGen`, `codeGenAddress`, VTable initialisation |
| `symboltable.c` | Type table, class table (with inheritance deep copy), global and local symbol tables |
| `translate.c` | Two-pass label resolver: turns `target.xsm` into runnable `machine.xsm` |
| `library.lib` | XSM runtime library (Alloc, Free, Read, Write, Exit, Initialize) |
| `input.expl` | Sample OExpL program |

## Prerequisites

- `flex` (or `lex`), `bison` (or `yacc`), `gcc`
- The **XSM simulator** (`xsm`) from the SILC toolchain: <https://silcnitc.github.io/>

## Build and run

```bash
# 1. Build the compiler
lex exprtree.l
yacc -d exprtree.y
gcc lex.yy.c y.tab.c exprtree.c symboltable.c -o compiler

# 2. Build the label translator
gcc translate.c -o translator

# 3. Compile an OExpL program (writes target.xsm in the current directory)
./compiler input.expl

# 4. Resolve labels to absolute addresses
./translator target.xsm machine.xsm

# 5. Run on the XSM simulator
./xsm -l library.lib -e machine.xsm
```

## Language overview

A program has this shape, in this order:

```
type    ... endtype          (optional user-defined types)
class   ... endclass         (optional class definitions)
decl    ... enddecl          (global declarations and function prototypes)
<function definitions>
int main() { decl ... enddecl begin ... end }
```

### Example

```c
class
Calculator {
    decl
        int compute(int a);
        int compute(int a, int b);
    enddecl

    int compute(int a) {
        decl enddecl
        begin
            return a * 10;
        end
    }

    int compute(int a, int b) {
        decl enddecl
        begin
            return a + b;
        end
    }
}
endclass

decl
    Calculator calc;
    int res1, res2;
enddecl

int main() {
    decl enddecl
    begin
        calc = new(Calculator);
        res1 = calc.compute(5);
        write(res1);
        res2 = calc.compute(5, 20);
        write(res2);
        return 1;
    end
}
```

Inheritance and dispatch use `extends` and `super`:

```c
Child extends Parent { ... }          // class header
x = super.method(args);               // call the parent's implementation
```

### Limits

- At most **8 fields** per user-defined type or class and **8 methods** per class (heap blocks and VTable rows are 8 words).
- Programs that use the heap must call `initialize()` before the first `alloc()` or `new()`.

## How it works

### Pipeline

1. The lexer tokenises the source; the parser builds an expression/statement tree with `createTree`, which also performs type checking.
2. When a function, method or `main` body is fully parsed, its tree is passed to `codeGen`, which writes XSM instructions to `target.xsm` (code generation happens inside Yacc reductions).
3. `makeBootCode` emits the `BOOT` section: stack pointer setup, VTable initialisation, `CALL MAIN`, then the library `Exit`.
4. `translate` makes two passes over `target.xsm`: it records the address of every label (code starts at 2056, two words per instruction) and rewrites `JMP`, `CALL`, `JZ`, `JNZ` and `MOV Rx, F<n>` to absolute addresses.

### Memory model

| Region | Layout |
|---|---|
| VTables | `4096 + 8 * class_index`, one 8-word row per class holding method addresses |
| Globals | start at `4096 + 8 * number_of_classes` |
| Heap | 8-word blocks from `library.lib`, free list headed at address 1024 |
| Object variable | **2 words**: Word 1 = heap pointer, Word 2 = VTable base address |
| Method call | pushes Word 1, Word 2 (`self`), then arguments, then a return slot; target is `[Word2 + funcposition]` |

### Stack frame (callee, with `n` parameters)

```
BP+1 … BP+k       locals
BP                saved BP
BP-1              return address
BP-2              return value slot
BP-3 … BP-(n+2)   parameters
BP-(n+3)          self, Word 2 (VTable)      (methods only)
BP-(n+4)          self, Word 1 (heap pointer)
```

## Known limitations

- Arrays are **1D and global** only (the 2D node exists in the backend but has no grammar rule).
- `obj1 = obj2` copies only the heap pointer, not the VTable word; assign via `new(...)` for correct dispatch.
- Class-typed **fields** and **function parameters** occupy a single word, so they do not carry a VTable pointer.
- `alloc()` with no size relies on the library's fixed 8-word block; the size argument is not supported yet.
- Function calls do not check argument count or types, and `return` is not checked against the declared return type.
- There is no implicit return: every non-`main` function must end with `return`.
- Override checking compares parameter **names** as well as types.

## References

- SILC NITC compiler design roadmap: <https://silcnitc.github.io/>
- XSM and OExpL specifications: linked from the roadmap above

## License

Add a license of your choice (for example MIT) before publishing.
