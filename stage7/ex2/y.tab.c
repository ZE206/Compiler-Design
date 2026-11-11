/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "exprtree.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exprtree.h"

int yylex(void);
void yyerror(char const *s);
FILE *target_file;
extern FILE *yyin;

struct Typetable *current_type = NULL;
struct Typetable *current_func_type = NULL;
static struct Typetable *curr_type_defining = NULL;
struct Classtable *Cptr = NULL;

void makeBootCode(void);
extern struct Classtable *ClassTableHead;
void initializeVTables(struct Classtable *Chead);

int count_params(struct ParamNode *p) {
    int c = 0;
    while(p) { c++; p = p->next; }
    return c;
}

#line 97 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    ENDCLASS = 259,
    NEW = 260,
    DELETE = 261,
    SELF = 262,
    INT = 263,
    STR = 264,
    MAIN = 265,
    RETURN = 266,
    TYPE = 267,
    ENDTYPE = 268,
    DECL = 269,
    ENDDECL = 270,
    BEGIN_TOK = 271,
    END_TOK = 272,
    READ = 273,
    WRITE = 274,
    ASSIGN = 275,
    IF = 276,
    THEN = 277,
    ELSE = 278,
    ENDIF = 279,
    WHILE = 280,
    DO = 281,
    ENDWHILE = 282,
    LT = 283,
    GT = 284,
    LE = 285,
    GE = 286,
    EQ = 287,
    NE = 288,
    REPEAT = 289,
    UNTIL = 290,
    CONTINUE = 291,
    BREAK = 292,
    AND = 293,
    INIT = 294,
    ALLOC = 295,
    FREE = 296,
    NULL_TOK = 297,
    DOT = 298,
    PLUS = 299,
    MINUS = 300,
    MUL = 301,
    DIV = 302,
    NUM = 303,
    ID = 304,
    STRING = 305,
    USTAR = 306
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ENDCLASS 259
#define NEW 260
#define DELETE 261
#define SELF 262
#define INT 263
#define STR 264
#define MAIN 265
#define RETURN 266
#define TYPE 267
#define ENDTYPE 268
#define DECL 269
#define ENDDECL 270
#define BEGIN_TOK 271
#define END_TOK 272
#define READ 273
#define WRITE 274
#define ASSIGN 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ENDIF 279
#define WHILE 280
#define DO 281
#define ENDWHILE 282
#define LT 283
#define GT 284
#define LE 285
#define GE 286
#define EQ 287
#define NE 288
#define REPEAT 289
#define UNTIL 290
#define CONTINUE 291
#define BREAK 292
#define AND 293
#define INIT 294
#define ALLOC 295
#define FREE 296
#define NULL_TOK 297
#define DOT 298
#define PLUS 299
#define MINUS 300
#define MUL 301
#define DIV 302
#define NUM 303
#define ID 304
#define STRING 305
#define USTAR 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "exprtree.y"

    int val;
    char *varname;
    struct Typetable *type;
    struct Classtable *ctype;
    struct tnode *no;
    struct ParamNode *param;

#line 260 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   579

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,     2,
      56,    57,     2,     2,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    74,    75,    78,    79,    82,    87,    94,
      95,    98,   101,   107,   108,   111,   111,   157,   158,   159,
     162,   163,   166,   166,   173,   174,   177,   182,   183,   184,
     198,   199,   200,   203,   204,   207,   207,   209,   209,   210,
     211,   212,   215,   221,   222,   225,   238,   239,   242,   248,
     248,   274,   274,   274,   275,   275,   276,   276,   279,   287,
     302,   302,   328,   329,   332,   333,   336,   339,   340,   343,
     346,   349,   353,   354,   355,   356,   357,   358,   359,   364,
     371,   381,   385,   401,   407,   408,   411,   412,   413,   414,
     415,   431,   444,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ENDCLASS", "NEW", "DELETE",
  "SELF", "INT", "STR", "MAIN", "RETURN", "TYPE", "ENDTYPE", "DECL",
  "ENDDECL", "BEGIN_TOK", "END_TOK", "READ", "WRITE", "ASSIGN", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "LT", "GT", "LE",
  "GE", "EQ", "NE", "REPEAT", "UNTIL", "CONTINUE", "BREAK", "AND", "INIT",
  "ALLOC", "FREE", "NULL_TOK", "DOT", "PLUS", "MINUS", "MUL", "DIV", "NUM",
  "ID", "STRING", "'&'", "USTAR", "'{'", "'}'", "';'", "'('", "')'", "','",
  "'['", "']'", "$accept", "Program", "ClassDefBlock", "ClassDefList",
  "ClassDef", "Cname", "ClassDeclList", "ClassDecl", "MethodDefList",
  "MethodDef", "$@1", "TypeDefBlock", "TypeDefList", "TypeDef", "$@2",
  "TypeFieldDeclList", "TypeFieldDecl", "TypeName", "GDeclBlock",
  "GDeclList", "GDecl", "$@3", "GVarList", "GVar", "ParamList", "Param",
  "FDefList", "FuncName", "FDef", "$@4", "LDeclBlock", "LDeclList",
  "LDecl", "$@5", "LVarList", "MainBlock", "$@6", "Body", "slist", "stmt",
  "Lvalue", "ArgList", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    38,   306,   123,   125,    59,    40,    41,    44,    91,
      93
};
# endif

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,    79,    24,    28,  -115,   -11,    80,  -115,  -115,   -13,
      72,  -115,  -115,  -115,  -115,     6,  -115,     8,    10,  -115,
    -115,  -115,  -115,    89,  -115,  -115,  -115,  -115,  -115,    18,
    -115,    57,    -1,  -115,    64,  -115,  -115,    -8,  -115,  -115,
    -115,  -115,    99,    87,   -19,    84,  -115,   101,  -115,   105,
     116,  -115,  -115,   125,    57,   134,  -115,    64,   123,    57,
    -115,    14,   -44,   136,    13,  -115,   129,  -115,   151,   112,
    -115,  -115,   141,  -115,    57,  -115,  -115,    57,  -115,   186,
     158,   157,   135,  -115,    92,  -115,   186,    57,   160,  -115,
    -115,   106,  -115,   202,  -115,   137,  -115,   174,  -115,  -115,
     147,   170,   202,   172,  -115,    88,   175,  -115,    49,  -115,
     176,   177,   178,   185,   286,   286,   173,   188,   189,   171,
     180,  -115,    42,  -115,   192,   186,  -115,   198,     9,   193,
     197,   199,  -115,  -115,   100,  -115,    49,   205,   472,     9,
      49,    49,    49,   318,   201,  -115,  -115,     9,    49,  -115,
    -115,    49,   207,  -115,  -115,  -115,    26,   208,   204,   206,
      49,   352,   213,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,  -115,    47,   372,   392,   412,   209,
     210,    77,   332,   492,  -115,   202,   218,   211,  -115,  -115,
     145,   512,  -115,   219,   532,   532,   532,   532,   532,   532,
     132,    62,    62,  -115,  -115,   222,   223,   242,   253,    49,
      49,   225,  -115,  -115,   227,  -115,  -115,  -115,    49,    49,
    -115,  -115,   286,   286,   432,   452,  -115,  -115,   512,   152,
     126,   233,   -17,   230,  -115,   286,   232,   239,  -115,  -115,
     265,  -115,  -115,   240,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      19,     0,     0,     4,    18,     0,     0,    21,     1,     0,
      32,    22,    17,    20,     8,     0,     6,     0,     0,    47,
      25,     3,     5,     0,    27,    28,    31,    29,    35,     0,
      34,     0,     0,    10,     0,    30,    33,     0,    46,     2,
      23,    24,     0,     0,    39,     0,    38,     0,    48,     0,
       0,    14,     9,     0,    44,     0,    36,     0,     0,    44,
      26,     0,     0,     0,     0,    43,     0,    37,     0,     0,
       7,    13,     0,    11,    44,    45,    41,     0,    40,    53,
       0,     0,     0,    42,     0,    60,    53,    44,     0,    52,
      56,     0,    55,     0,    49,     0,    12,     0,    51,    54,
       0,     0,     0,     0,    59,     0,     0,    80,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
       0,    65,     0,    61,     0,    53,    57,     0,     0,     0,
       0,     0,    89,   105,    79,   106,     0,    86,     0,     0,
       0,     0,     0,     0,     0,    77,    76,     0,     0,    62,
      64,     0,     0,    50,    15,    58,     0,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,    87,    88,
       0,    84,   104,    82,    97,    98,    99,   100,   101,   102,
     103,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,     0,    81,    68,     0,    70,    90,    92,     0,    85,
      66,    67,     0,     0,     0,     0,    69,    16,    83,     0,
       0,     0,     0,     0,    91,     0,     0,     0,    74,    75,
       0,    72,    73,     0,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,  -115,   273,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,   290,  -115,  -115,  -115,     3,  -115,  -115,
     269,  -115,  -115,   243,    51,   226,  -115,  -115,  -115,  -115,
     -73,  -115,   217,  -115,  -115,  -115,  -115,  -101,  -111,  -114,
    -100,    90,   -91
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    15,    16,    17,    43,    52,    61,    71,
     185,     3,     6,     7,    20,    32,    41,    63,    19,    29,
      30,    34,    45,    46,    64,    65,    31,    49,    38,   102,
      85,    91,    92,    97,   105,    39,    93,   101,   120,   121,
     137,   190,   191
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     122,   124,    47,   143,   144,     1,   150,    24,    25,   223,
      21,    73,    74,    94,   122,   122,   107,   138,    24,    25,
     122,    28,    24,    25,     8,    26,    24,    25,   156,   150,
     150,     9,    28,    35,    37,    42,    14,    54,   238,   175,
      55,    48,    11,   122,   122,   161,    53,   181,    27,   176,
     177,   178,   154,    40,   129,    14,   107,   182,   119,    27,
     183,    23,   151,    27,    72,    24,    25,    27,    70,   152,
      76,    77,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   186,   214,   152,    18,    90,   130,   131,
     152,   132,     4,    12,    90,    24,    25,   133,   134,   135,
      24,    25,    51,    33,   205,   136,    27,    89,   172,   173,
      69,   230,   231,    44,    24,    25,   150,   150,   224,   225,
     152,    98,   122,   122,   240,    82,   150,   228,     5,     5,
     122,   122,   106,   107,   211,   122,    27,   108,    95,    56,
     122,    27,    57,   126,   110,   111,   127,   112,    50,   235,
     236,   113,   114,   106,   107,    27,   160,    58,   108,   148,
     115,    59,   116,   117,   109,   110,   111,   118,   112,    80,
      77,    60,   113,   114,    62,   119,   170,   171,   172,   173,
      68,   115,    66,   116,   117,    75,   106,   107,   118,    78,
      81,   108,    88,    77,   103,    77,   119,   149,   110,   111,
      84,   112,   217,   218,    79,   113,   114,   106,   107,   234,
     218,    86,   108,    87,   115,    96,   116,   117,   100,   110,
     111,   118,   112,   104,   123,   125,   113,   114,   145,   119,
     148,   128,   139,   140,   141,   115,   180,   116,   117,   106,
     107,   142,   118,   146,   108,   147,   153,   155,   162,   157,
     119,   110,   111,   158,   112,   159,   184,   187,   113,   114,
     237,   188,   193,   189,   222,   209,   210,   115,   216,   116,
     117,   106,   107,   215,   118,   219,   108,   220,   221,   223,
     226,   227,   119,   110,   111,   239,   112,   241,    22,   243,
     113,   114,   106,   107,   242,   244,    13,   108,    36,   115,
      67,   116,   117,    83,   110,   111,   118,   112,    99,   229,
       0,   113,   114,     0,   119,     0,     0,     0,     0,     0,
     115,     0,   116,   117,   106,   107,     0,   118,     0,   108,
       0,     0,     0,     0,     0,   119,   110,   111,     0,   112,
       0,     0,     0,   179,   114,     0,     0,     0,     0,     0,
       0,     0,   115,     0,   116,   117,     0,     0,     0,   118,
     163,   164,   165,   166,   167,   168,     0,   119,     0,     0,
     169,     0,     0,     0,     0,     0,   170,   171,   172,   173,
     163,   164,   165,   166,   167,   168,     0,     0,     0,     0,
     169,     0,   212,     0,     0,     0,   170,   171,   172,   173,
     163,   164,   165,   166,   167,   168,     0,     0,     0,   192,
     169,     0,     0,     0,     0,     0,   170,   171,   172,   173,
     163,   164,   165,   166,   167,   168,     0,     0,     0,   206,
     169,     0,     0,     0,     0,     0,   170,   171,   172,   173,
     163,   164,   165,   166,   167,   168,     0,     0,     0,   207,
     169,     0,     0,     0,     0,     0,   170,   171,   172,   173,
     163,   164,   165,   166,   167,   168,     0,     0,     0,   208,
     169,     0,     0,     0,     0,     0,   170,   171,   172,   173,
     163,   164,   165,   166,   167,   168,     0,     0,     0,   232,
     169,     0,     0,     0,     0,     0,   170,   171,   172,   173,
     163,   164,   165,   166,   167,   168,     0,     0,     0,   233,
     169,     0,     0,     0,     0,     0,   170,   171,   172,   173,
     163,   164,   165,   166,   167,   168,     0,   174,     0,     0,
     169,     0,     0,     0,     0,     0,   170,   171,   172,   173,
     163,   164,   165,   166,   167,   168,     0,   213,     0,     0,
     169,     0,     0,     0,     0,     0,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     0,     0,     0,
     169,     0,     0,     0,     0,     0,   170,   171,   172,   173
};

static const yytype_int16 yycheck[] =
{
     100,   102,    10,   114,   115,    12,   120,     8,     9,    26,
       4,    55,    56,    86,   114,   115,     7,   108,     8,     9,
     120,    18,     8,     9,     0,    15,     8,     9,   128,   143,
     144,     3,    29,    15,    31,    32,    49,    56,    55,   139,
      59,    49,    53,   143,   144,   136,    43,   147,    49,   140,
     141,   142,   125,    54,     5,    49,     7,   148,    49,    49,
     151,    53,    20,    49,    61,     8,     9,    49,    54,    43,
      57,    58,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    57,   185,    43,    14,    84,    39,    40,
      43,    42,    13,    13,    91,     8,     9,    48,    49,    50,
       8,     9,    15,    14,    57,    56,    49,    15,    46,    47,
      59,   222,   223,    49,     8,     9,   230,   231,   209,   210,
      43,    15,   222,   223,   235,    74,   240,   218,    49,    49,
     230,   231,     6,     7,    57,   235,    49,    11,    87,    55,
     240,    49,    58,    55,    18,    19,    58,    21,    49,    23,
      24,    25,    26,     6,     7,    49,    56,    56,    11,    59,
      34,    56,    36,    37,    17,    18,    19,    41,    21,    57,
      58,    55,    25,    26,    49,    49,    44,    45,    46,    47,
      57,    34,    48,    36,    37,    49,     6,     7,    41,    60,
      49,    11,    57,    58,    57,    58,    49,    17,    18,    19,
      14,    21,    57,    58,    53,    25,    26,     6,     7,    57,
      58,    53,    11,    56,    34,    55,    36,    37,    16,    18,
      19,    41,    21,    49,    54,    53,    25,    26,    55,    49,
      59,    56,    56,    56,    56,    34,    35,    36,    37,     6,
       7,    56,    41,    55,    11,    56,    54,    49,    43,    56,
      49,    18,    19,    56,    21,    56,    49,    49,    25,    26,
      27,    57,    49,    57,    22,    56,    56,    34,    57,    36,
      37,     6,     7,    55,    41,    56,    11,    55,    55,    26,
      55,    54,    49,    18,    19,    55,    21,    55,    15,    24,
      25,    26,     6,     7,    55,    55,     6,    11,    29,    34,
      57,    36,    37,    77,    18,    19,    41,    21,    91,   219,
      -1,    25,    26,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    36,    37,     6,     7,    -1,    41,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    49,    18,    19,    -1,    21,
      -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    36,    37,    -1,    -1,    -1,    41,
      28,    29,    30,    31,    32,    33,    -1,    49,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    60,    -1,    -1,    -1,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    57,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    57,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    57,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    57,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    57,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    57,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    -1,    55,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    -1,    55,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    62,    72,    13,    49,    73,    74,     0,     3,
      63,    53,    13,    74,    49,    64,    65,    66,    14,    79,
      75,     4,    65,    53,     8,     9,    15,    49,    78,    80,
      81,    87,    76,    14,    82,    15,    81,    78,    89,    96,
      54,    77,    78,    67,    49,    83,    84,    10,    49,    88,
      49,    15,    68,    78,    56,    59,    55,    58,    56,    56,
      55,    69,    49,    78,    85,    86,    48,    84,    57,    85,
      54,    70,    78,    55,    56,    49,    57,    58,    60,    53,
      57,    49,    85,    86,    14,    91,    53,    56,    57,    15,
      78,    92,    93,    97,    91,    85,    55,    94,    15,    93,
      16,    98,    90,    57,    49,    95,     6,     7,    11,    17,
      18,    19,    21,    25,    26,    34,    36,    37,    41,    49,
      99,   100,   101,    54,    98,    53,    55,    58,    56,     5,
      39,    40,    42,    48,    49,    50,    56,   101,   103,    56,
      56,    56,    56,    99,    99,    55,    55,    56,    59,    17,
     100,    20,    43,    54,    91,    49,   101,    56,    56,    56,
      56,   103,    43,    28,    29,    30,    31,    32,    33,    38,
      44,    45,    46,    47,    55,   101,   103,   103,   103,    25,
      35,   101,   103,   103,    49,    71,    57,    49,    57,    57,
     102,   103,    57,    49,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,    57,    57,    57,    57,    56,
      56,    57,    60,    55,    98,    55,    57,    57,    58,    56,
      55,    55,    22,    26,   103,   103,    55,    54,   103,   102,
      99,    99,    57,    57,    57,    23,    24,    27,    55,    55,
      99,    55,    55,    24,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    65,    66,    67,
      67,    68,    68,    69,    69,    71,    70,    72,    72,    72,
      73,    73,    75,    74,    76,    76,    77,    78,    78,    78,
      79,    79,    79,    80,    80,    82,    81,    83,    83,    84,
      84,    84,    85,    85,    85,    86,    87,    87,    88,    90,
      89,    91,    91,    91,    92,    92,    94,    93,    95,    95,
      97,    96,    98,    98,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     1,     7,     1,     2,
       0,     3,     6,     2,     0,     0,    10,     3,     2,     0,
       2,     1,     0,     5,     2,     0,     3,     1,     1,     1,
       3,     2,     0,     2,     1,     0,     4,     3,     1,     1,
       4,     4,     3,     1,     0,     2,     2,     0,     1,     0,
      10,     3,     2,     0,     2,     1,     0,     4,     3,     1,
       0,     9,     3,     2,     2,     1,     5,     5,     4,     5,
       5,    10,     8,     8,     7,     7,     2,     2,     3,     1,
       1,     4,     3,     3,     1,     0,     1,     3,     3,     1,
       4,     6,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7:
#line 82 "exprtree.y"
                                                                       {
                    Cptr = NULL;
              }
#line 1672 "y.tab.c"
    break;

  case 8:
#line 87 "exprtree.y"
                   {
                    Cptr = CInstall((yyvsp[0].varname), NULL);
                    (yyval.ctype) = Cptr;
              }
#line 1681 "y.tab.c"
    break;

  case 11:
#line 98 "exprtree.y"
                                {
                    ClassFInstall(Cptr, (yyvsp[-2].type), (yyvsp[-1].varname));
              }
#line 1689 "y.tab.c"
    break;

  case 12:
#line 101 "exprtree.y"
                                                  {
                    ClassMInstall(Cptr, (yyvsp[-4].varname), (yyvsp[-5].type), (yyvsp[-2].param));
              }
#line 1697 "y.tab.c"
    break;

  case 15:
#line 111 "exprtree.y"
                                                             {
                    
                    struct Memberfunclist *m = ClassMLookup(Cptr, (yyvsp[-5].varname));
                    if (m == NULL) {
                        printf("Semantic Error: Method '%s' not declared in class '%s'.\n", (yyvsp[-5].varname), Cptr->name);
                        exit(1);
                    }
                    if (m->type != (yyvsp[-6].type)) {
                        printf("Semantic Error: Return type mismatch for method '%s'.\n", (yyvsp[-5].varname));
                        exit(1);
                    }
                    
                    current_func_type = m->type;
                    InstallParameters((yyvsp[-3].param));

                    /* INJECT IMPLICIT 'self' PARAMETER */
                    int param_count = count_params((yyvsp[-3].param));
                    int self_binding = -(param_count + 4); 
                    LInstall("self", NULL, self_binding);
                    
                    struct LST_Node *self_node = LLookup("self");
                    self_node->ctype = Cptr;

              }
#line 1726 "y.tab.c"
    break;

  case 16:
#line 134 "exprtree.y"
                         {
              
                    struct Memberfunclist *m = ClassMLookup(Cptr, (yyvsp[-8].varname));
                    
                    fprintf(target_file, "F%d:\n", m->flabel);
                    fprintf(target_file, "PUSH BP\n");
                    fprintf(target_file, "MOV BP, SP\n");
                    
                    int num_locals = local_binding - 1;
                    for(int i = 0; i < num_locals; i++) {
                        fprintf(target_file, "PUSH R0\n");
                    }
                    
                    if ((yyvsp[-1].no) != NULL) codeGen((yyvsp[-1].no));
                    
                    LST_reset(); 
              }
#line 1748 "y.tab.c"
    break;

  case 22:
#line 166 "exprtree.y"
                      {
                curr_type_defining = TInstall((yyvsp[-1].varname), 0, NULL);
             }
#line 1756 "y.tab.c"
    break;

  case 23:
#line 168 "exprtree.y"
                                     {
                curr_type_defining = NULL;
             }
#line 1764 "y.tab.c"
    break;

  case 26:
#line 177 "exprtree.y"
                                    {
                    FInstall(curr_type_defining, (yyvsp[-1].varname), (yyvsp[-2].type)->name);
                  }
#line 1772 "y.tab.c"
    break;

  case 27:
#line 182 "exprtree.y"
                     { (yyval.type) = TLookup("int"); }
#line 1778 "y.tab.c"
    break;

  case 28:
#line 183 "exprtree.y"
                     { (yyval.type) = TLookup("str"); }
#line 1784 "y.tab.c"
    break;

  case 29:
#line 184 "exprtree.y"
                     { 
                  struct Typetable *t = TLookup((yyvsp[0].varname));
                  if (!t) {
                      printf("Semantic Error: Unknown type '%s'.\n", (yyvsp[0].varname));
                      exit(1);
                  }
                  (yyval.type) = t;
              }
#line 1797 "y.tab.c"
    break;

  case 35:
#line 207 "exprtree.y"
                      { current_type = (yyvsp[0].type); }
#line 1803 "y.tab.c"
    break;

  case 39:
#line 210 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), current_type, 1, NULL); }
#line 1809 "y.tab.c"
    break;

  case 40:
#line 211 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), current_type, (yyvsp[-1].val), NULL); }
#line 1815 "y.tab.c"
    break;

  case 41:
#line 212 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), current_type, 0, (yyvsp[-1].param)); }
#line 1821 "y.tab.c"
    break;

  case 42:
#line 215 "exprtree.y"
                                 {
                struct ParamNode *temp = (yyvsp[-2].param);
                while(temp->next != NULL) temp = temp->next;
                temp->next = (yyvsp[0].param);
                (yyval.param) = (yyvsp[-2].param);
           }
#line 1832 "y.tab.c"
    break;

  case 43:
#line 221 "exprtree.y"
                   { (yyval.param) = (yyvsp[0].param); }
#line 1838 "y.tab.c"
    break;

  case 44:
#line 222 "exprtree.y"
                         { (yyval.param) = NULL; }
#line 1844 "y.tab.c"
    break;

  case 45:
#line 225 "exprtree.y"
                         {
                struct ParamNode *temp = (struct ParamNode *)malloc(sizeof(struct ParamNode));
                temp->name = (yyvsp[0].varname);
                temp->type = (yyvsp[-1].type);
                temp->next = NULL;
                (yyval.param) = temp;
           }
#line 1856 "y.tab.c"
    break;

  case 48:
#line 242 "exprtree.y"
                { 
                current_func_type = current_type; 
                (yyval.varname) = (yyvsp[0].varname); 
           }
#line 1865 "y.tab.c"
    break;

  case 49:
#line 248 "exprtree.y"
                                                                {
                struct GST_Node *g = GLookup((yyvsp[-5].varname));
                if (g == NULL) { 
                    printf("Semantic Error: Function '%s' not declared.\n", (yyvsp[-5].varname)); 
                    exit(1); 
                }
                current_func_type = g->type; 

                InstallParameters((yyvsp[-3].param));
           }
#line 1880 "y.tab.c"
    break;

  case 50:
#line 257 "exprtree.y"
                      {
                struct GST_Node *g = GLookup((yyvsp[-8].varname));
                fprintf(target_file, "F%d:\n", g->flabel);
                fprintf(target_file, "PUSH BP\n");
                fprintf(target_file, "MOV BP, SP\n");
                
                int num_locals = local_binding - 1;
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "PUSH R0\n");
                }

                if ((yyvsp[-1].no) != NULL) codeGen((yyvsp[-1].no));
                LST_reset(); 
           }
#line 1899 "y.tab.c"
    break;

  case 56:
#line 276 "exprtree.y"
                 { current_type = (yyvsp[0].type); }
#line 1905 "y.tab.c"
    break;

  case 58:
#line 279 "exprtree.y"
                      {
        LInstall((yyvsp[0].varname), current_type, local_binding);

        if (CLookup(current_type->name) != NULL)
            local_binding += 2;
        else
            local_binding += 1;
    }
#line 1918 "y.tab.c"
    break;

  case 59:
#line 287 "exprtree.y"
         {
        LInstall((yyvsp[0].varname), current_type, local_binding);

        if (CLookup(current_type->name) != NULL)
            local_binding += 2;
        else
            local_binding += 1;
    }
#line 1931 "y.tab.c"
    break;

  case 60:
#line 302 "exprtree.y"
                                                  {
                current_func_type = TLookup("int"); 
           }
#line 1939 "y.tab.c"
    break;

  case 61:
#line 304 "exprtree.y"
                      {
                fprintf(target_file, "MAIN:\n");
                fprintf(target_file, "PUSH BP\n");
                fprintf(target_file, "MOV BP, SP\n");
                
                int num_locals = local_binding - 1;
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "PUSH R0\n");
                }

                if ((yyvsp[-1].no) != NULL) codeGen((yyvsp[-1].no));

                int discard = getReg();
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "POP R%d\n", discard);
                }
                freeReg();
                fprintf(target_file, "POP BP\n");
                fprintf(target_file, "RET\n");

                LST_reset();
           }
#line 1966 "y.tab.c"
    break;

  case 62:
#line 328 "exprtree.y"
                                     { (yyval.no) = (yyvsp[-1].no); }
#line 1972 "y.tab.c"
    break;

  case 63:
#line 329 "exprtree.y"
                                     { (yyval.no) = NULL; }
#line 1978 "y.tab.c"
    break;

  case 64:
#line 332 "exprtree.y"
                   { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[-1].no), (yyvsp[0].no)); }
#line 1984 "y.tab.c"
    break;

  case 65:
#line 333 "exprtree.y"
                   { (yyval.no) = (yyvsp[0].no); }
#line 1990 "y.tab.c"
    break;

  case 66:
#line 336 "exprtree.y"
                               { 
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_READ, (yyvsp[-2].no), NULL); 
       }
#line 1998 "y.tab.c"
    break;

  case 67:
#line 339 "exprtree.y"
                              { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_WRITE, (yyvsp[-2].no), NULL); }
#line 2004 "y.tab.c"
    break;

  case 68:
#line 340 "exprtree.y"
                              { 
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, (yyvsp[-3].no), (yyvsp[-1].no)); 
       }
#line 2012 "y.tab.c"
    break;

  case 69:
#line 343 "exprtree.y"
                               {
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_FREE, (yyvsp[-2].no), NULL);
     }
#line 2020 "y.tab.c"
    break;

  case 70:
#line 346 "exprtree.y"
                                 {
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_DELETE, (yyvsp[-2].no), NULL);
     }
#line 2028 "y.tab.c"
    break;

  case 71:
#line 349 "exprtree.y"
                                                       { 
            struct tnode *then_else = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[-4].no), (yyvsp[-2].no));
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_IF_ELSE, (yyvsp[-7].no), then_else); 
       }
#line 2037 "y.tab.c"
    break;

  case 72:
#line 353 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_IF, (yyvsp[-5].no), (yyvsp[-2].no)); }
#line 2043 "y.tab.c"
    break;

  case 73:
#line 354 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_WHILE, (yyvsp[-5].no), (yyvsp[-2].no)); }
#line 2049 "y.tab.c"
    break;

  case 74:
#line 355 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_DO_WHILE, (yyvsp[-2].no), (yyvsp[-5].no)); }
#line 2055 "y.tab.c"
    break;

  case 75:
#line 356 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_REPEAT_UNTIL, (yyvsp[-2].no), (yyvsp[-5].no)); }
#line 2061 "y.tab.c"
    break;

  case 76:
#line 357 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_BREAK, NULL, NULL); }
#line 2067 "y.tab.c"
    break;

  case 77:
#line 358 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONTINUE, NULL, NULL); }
#line 2073 "y.tab.c"
    break;

  case 78:
#line 359 "exprtree.y"
                       {
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_RET, (yyvsp[-1].no), NULL);
       }
#line 2081 "y.tab.c"
    break;

  case 79:
#line 364 "exprtree.y"
            {
        (yyval.no) = createTree(0, NULL, (yyvsp[0].varname), NODE_VAR, NULL, NULL);

        if ((yyval.no)->type != NULL) {
            (yyval.no)->ctype = CLookup((yyval.no)->type->name);
        }
    }
#line 2093 "y.tab.c"
    break;

  case 80:
#line 371 "exprtree.y"
              {
    (yyval.no) = createTree(0, NULL, "self", NODE_SELF, NULL, NULL);
    (yyval.no)->Lentry = LLookup("self");
    (yyval.no)->ctype = Cptr;

    if ((yyval.no)->Lentry == NULL) {
        printf("Semantic Error: 'self' is not defined here.\n");
        exit(1);
    }
}
#line 2108 "y.tab.c"
    break;

  case 81:
#line 381 "exprtree.y"
                         {
            struct tnode *v = createTree(0, NULL, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, v->type, NULL, NODE_ARRAY, v, (yyvsp[-1].no));
       }
#line 2117 "y.tab.c"
    break;

  case 82:
#line 385 "exprtree.y"
                       {
            struct Fieldlist *f = NULL;
            if ((yyvsp[-2].no)->ctype != NULL) {
                f = ClassFLookup((yyvsp[-2].no)->ctype, (yyvsp[0].varname));
            } else {
                f = FLookup((yyvsp[-2].no)->type, (yyvsp[0].varname));
            }
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist.\n", (yyvsp[0].varname)); exit(1);
            }
            (yyval.no) = createTree(f->fieldIndex, f->type, (yyvsp[0].varname), NODE_FIELD, (yyvsp[-2].no), NULL);
            (yyval.no)->Fentry = f;
            (yyval.no)->ctype = f->ctype;
       }
#line 2136 "y.tab.c"
    break;

  case 83:
#line 401 "exprtree.y"
                           {
            struct tnode *temp = (yyvsp[-2].no);
            while(temp->right != NULL) temp = temp->right;
            temp->right = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[0].no), NULL);
            (yyval.no) = (yyvsp[-2].no);
        }
#line 2147 "y.tab.c"
    break;

  case 84:
#line 407 "exprtree.y"
                           { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[0].no), NULL); }
#line 2153 "y.tab.c"
    break;

  case 85:
#line 408 "exprtree.y"
                           { (yyval.no) = NULL; }
#line 2159 "y.tab.c"
    break;

  case 86:
#line 411 "exprtree.y"
                          { (yyval.no) = (yyvsp[0].no); }
#line 2165 "y.tab.c"
    break;

  case 87:
#line 412 "exprtree.y"
                          { (yyval.no) = createTree(0, TLookup("int"), NULL, NODE_INIT, NULL, NULL); }
#line 2171 "y.tab.c"
    break;

  case 88:
#line 413 "exprtree.y"
                          { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ALLOC, NULL, NULL); }
#line 2177 "y.tab.c"
    break;

  case 89:
#line 414 "exprtree.y"
                          { (yyval.no) = createTree(0, TLookup("null"), NULL, NODE_NULL, NULL, NULL); }
#line 2183 "y.tab.c"
    break;

  case 90:
#line 415 "exprtree.y"
                      {
            struct Classtable *c = CLookup((yyvsp[-1].varname));

            if (c == NULL) {
                printf("Semantic Error: Class '%s' not found.\n", (yyvsp[-1].varname));
                exit(1);
            }

            struct tnode *classNode =
                createTree(0, NULL, (yyvsp[-1].varname), NODE_NULL, NULL, NULL);

            classNode->ctype = c;

            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_NEW, classNode, NULL);
            (yyval.no)->ctype = c;
        }
#line 2204 "y.tab.c"
    break;

  case 91:
#line 431 "exprtree.y"
                                     {
            struct Classtable *c = (yyvsp[-5].no)->ctype;
            if (c == NULL) {
                printf("Semantic Error: Left side is not an object.\n"); exit(1);
            }
            struct Memberfunclist *m = ClassMLookup(c, (yyvsp[-3].varname));
            if (m == NULL) {
                printf("Semantic Error: Method '%s' not found in class.\n", (yyvsp[-3].varname)); exit(1);
            }
            struct tnode *funcNode = createTree(0, m->type, (yyvsp[-3].varname), NODE_OBJ_FUNC_CALL, (yyvsp[-5].no), (yyvsp[-1].no));
            funcNode->ctype = c;
            (yyval.no) = funcNode;
     }
#line 2222 "y.tab.c"
    break;

  case 92:
#line 444 "exprtree.y"
                          {
            struct GST_Node *g = GLookup((yyvsp[-3].varname));
            if (g == NULL) { 
                printf("Semantic Error: Function '%s' is not declared.\n", (yyvsp[-3].varname)); 
                exit(1); 
            }
            struct tnode *funcNode = createTree(0, NULL, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            funcNode->Gentry = g; 
            (yyval.no) = createTree(0, g->type, NULL, NODE_FUNC_CALL, funcNode, (yyvsp[-1].no)); 
       }
#line 2237 "y.tab.c"
    break;

  case 93:
#line 454 "exprtree.y"
                        { (yyval.no) = createTree('+', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2243 "y.tab.c"
    break;

  case 94:
#line 455 "exprtree.y"
                        { (yyval.no) = createTree('-', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2249 "y.tab.c"
    break;

  case 95:
#line 456 "exprtree.y"
                        { (yyval.no) = createTree('*', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2255 "y.tab.c"
    break;

  case 96:
#line 457 "exprtree.y"
                        { (yyval.no) = createTree('/', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2261 "y.tab.c"
    break;

  case 97:
#line 458 "exprtree.y"
                        { (yyval.no) = createTree(LT, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2267 "y.tab.c"
    break;

  case 98:
#line 459 "exprtree.y"
                        { (yyval.no) = createTree(GT, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2273 "y.tab.c"
    break;

  case 99:
#line 460 "exprtree.y"
                        { (yyval.no) = createTree(LE, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2279 "y.tab.c"
    break;

  case 100:
#line 461 "exprtree.y"
                        { (yyval.no) = createTree(GE, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2285 "y.tab.c"
    break;

  case 101:
#line 462 "exprtree.y"
                        { (yyval.no) = createTree(EQ, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2291 "y.tab.c"
    break;

  case 102:
#line 463 "exprtree.y"
                        { (yyval.no) = createTree(NE, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2297 "y.tab.c"
    break;

  case 103:
#line 464 "exprtree.y"
                        { (yyval.no) = createTree(AND, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2303 "y.tab.c"
    break;

  case 104:
#line 465 "exprtree.y"
                        { (yyval.no) = (yyvsp[-1].no); }
#line 2309 "y.tab.c"
    break;

  case 105:
#line 466 "exprtree.y"
                        { (yyval.no) = createTree((yyvsp[0].val), TLookup("int"), NULL, NODE_NUM, NULL, NULL); }
#line 2315 "y.tab.c"
    break;

  case 106:
#line 467 "exprtree.y"
                        { (yyval.no) = createTree(0, TLookup("str"), (yyvsp[0].varname), NODE_STR_VAL, NULL, NULL); }
#line 2321 "y.tab.c"
    break;


#line 2325 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 469 "exprtree.y"


void yyerror(char const *s) { 
    extern char *yytext;
    printf("YYError: %s at token '%s'\n", s, yytext); 
}

void makeBootCode(void) {
    fprintf(target_file, "BOOT:\n");
    fprintf(target_file, "MOV SP, %d\n", getSP());
    
    if (ClassTableHead != NULL) {
        initializeVTables(ClassTableHead);
    }

    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "CALL MAIN\n");
    
    int r = getReg();
    fprintf(target_file, "MOV R%d, \"Exit\"\n", r);
    fprintf(target_file, "PUSH R%d\n", r);      
    fprintf(target_file, "MOV R%d, 0\n", r);
    fprintf(target_file, "PUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\n", r, r, r, r);
    fprintf(target_file, "CALL 0\n");
    freeReg();
}

int main(int argc, char *argv[]) {
    TypeTableCreate();

    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (fp) yyin = fp;
        else { printf("Error opening input file: %s\n", argv[1]); return 1; }
    }
    target_file = fopen("target.xsm", "w");
    if (!target_file) { printf("Error creating target.xsm\n"); return 1; }
    
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(target_file, "JMP BOOT\n"); 
    
    yyparse();
    makeBootCode();
    fclose(target_file);
    return 0;
}
