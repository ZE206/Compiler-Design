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

void makeBootCode(void);

#line 88 "y.tab.c"

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
    INT = 258,
    STR = 259,
    MAIN = 260,
    RETURN = 261,
    TYPE = 262,
    ENDTYPE = 263,
    DECL = 264,
    ENDDECL = 265,
    BEGIN_TOK = 266,
    END_TOK = 267,
    READ = 268,
    WRITE = 269,
    ASSIGN = 270,
    IF = 271,
    THEN = 272,
    ELSE = 273,
    ENDIF = 274,
    WHILE = 275,
    DO = 276,
    ENDWHILE = 277,
    LT = 278,
    GT = 279,
    LE = 280,
    GE = 281,
    EQ = 282,
    NE = 283,
    REPEAT = 284,
    UNTIL = 285,
    CONTINUE = 286,
    BREAK = 287,
    AND = 288,
    INIT = 289,
    ALLOC = 290,
    FREE = 291,
    NULL_TOK = 292,
    DOT = 293,
    PLUS = 294,
    MINUS = 295,
    MUL = 296,
    DIV = 297,
    NUM = 298,
    ID = 299,
    STRING = 300,
    USTAR = 301
  };
#endif
/* Tokens.  */
#define INT 258
#define STR 259
#define MAIN 260
#define RETURN 261
#define TYPE 262
#define ENDTYPE 263
#define DECL 264
#define ENDDECL 265
#define BEGIN_TOK 266
#define END_TOK 267
#define READ 268
#define WRITE 269
#define ASSIGN 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ENDIF 274
#define WHILE 275
#define DO 276
#define ENDWHILE 277
#define LT 278
#define GT 279
#define LE 280
#define GE 281
#define EQ 282
#define NE 283
#define REPEAT 284
#define UNTIL 285
#define CONTINUE 286
#define BREAK 287
#define AND 288
#define INIT 289
#define ALLOC 290
#define FREE 291
#define NULL_TOK 292
#define DOT 293
#define PLUS 294
#define MINUS 295
#define MUL 296
#define DIV 297
#define NUM 298
#define ID 299
#define STRING 300
#define USTAR 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "exprtree.y"

    int val;
    char *varname;
    struct Typetable *type;
    struct tnode *no;
    struct ParamNode *param;

#line 240 "y.tab.c"

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
#define YYLAST   587

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  220

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


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
       2,     2,     2,     2,     2,     2,     2,     2,    46,     2,
      54,    55,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      45,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    54,    55,    62,    63,    64,    67,    68,
      71,    71,    79,    80,    83,    88,    89,    90,   104,   104,
     105,   105,   106,   106,   108,   108,   109,   110,   111,   114,
     120,   121,   124,   137,   137,   139,   145,   145,   191,   191,
     191,   192,   192,   193,   193,   194,   195,   202,   202,   229,
     230,   233,   234,   237,   241,   244,   245,   249,   252,   257,
     261,   264,   268,   269,   270,   271,   272,   273,   274,   288,
     298,   309,   315,   316,   319,   320,   321,   322,   323,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STR", "MAIN", "RETURN", "TYPE",
  "ENDTYPE", "DECL", "ENDDECL", "BEGIN_TOK", "END_TOK", "READ", "WRITE",
  "ASSIGN", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "LT",
  "GT", "LE", "GE", "EQ", "NE", "REPEAT", "UNTIL", "CONTINUE", "BREAK",
  "AND", "INIT", "ALLOC", "FREE", "NULL_TOK", "DOT", "PLUS", "MINUS",
  "MUL", "DIV", "NUM", "ID", "STRING", "'&'", "USTAR", "'{'", "'}'", "';'",
  "','", "'['", "']'", "'('", "')'", "$accept", "Program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "$@1", "FieldDeclList", "FieldDecl",
  "TypeName", "GDeclBlock", "GDeclList", "GDecl", "$@2", "GVarList",
  "GVar", "ParamList", "Param", "FDefBlock", "FuncName", "FDef", "$@3",
  "LDeclBlock", "LDeclList", "LDecl", "$@4", "LVarList", "MainBlock",
  "$@5", "Body", "slist", "stmt", "Field", "ArgList", "expr", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,    38,   301,   123,   125,
      59,    44,    91,    93,    40,    41
};
# endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,     8,    29,    91,   -95,    -1,    49,   -95,   -95,    87,
       4,    57,   -95,   -95,   -95,   -95,     0,   -95,   -95,   -95,
     -95,   -95,    15,   -95,    87,    51,    57,   -95,   -95,    86,
      32,    59,   -95,   -95,   -95,    50,   -95,   -95,     6,   -95,
      65,    81,    30,   -27,   -95,    86,   -95,   -95,    84,   123,
      96,    86,   -95,    59,   101,    93,   -95,   -95,    73,   -95,
      94,    95,   -95,   -95,    86,   104,   -95,   -95,    76,   -95,
     149,   -95,   -95,   -95,   123,   118,   -95,   -95,   143,   120,
     -95,   -95,   117,    62,   -95,   119,   127,   128,   129,   248,
     248,   121,   136,   134,   -12,   164,   -95,   -11,   -95,   149,
     -95,   145,   138,   140,   -95,   -95,   -18,   -95,    62,   152,
     445,   153,    62,    62,    62,   269,   185,   -95,   -95,   158,
      62,   159,    62,   -95,   -95,    62,   160,   161,   -95,   154,
     156,    62,    62,   283,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,   -95,   -23,    43,   303,   323,
     343,   169,   170,    47,    53,   465,   -95,   403,   485,   -95,
     -95,   -95,   -95,   424,   110,   525,   -95,   545,   545,   545,
     545,   545,   545,   254,    82,    82,   -95,   -95,   157,   163,
     168,   208,   209,    62,    62,   181,   182,   -95,   219,   -95,
     -95,    62,   -95,   -95,   -95,   -95,   248,   248,   363,   383,
     -95,   -95,    62,   525,   122,   206,    14,   186,   505,   248,
     189,   194,   -95,   -95,   -95,   227,   -95,   -95,   195,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     0,     6,     0,     0,     9,     1,     0,
       0,     0,     4,    10,     5,     8,     0,    15,    16,    19,
      17,    22,     0,    21,    15,     0,     0,    34,     3,     0,
       0,     0,    18,    20,    35,     0,    33,     2,     0,    13,
       0,     0,    26,     0,    25,    31,    11,    12,     0,    40,
       0,    31,    23,     0,     0,     0,    30,    14,     0,    47,
       0,     0,    24,    32,     0,     0,    39,    43,     0,    42,
       0,    27,    28,    29,    40,     0,    38,    41,     0,     0,
      36,    46,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,     0,    48,     0,
      44,     0,     0,     0,    77,    91,    93,    92,     0,    74,
       0,     0,     0,     0,     0,     0,     0,    67,    66,     0,
       0,     0,     0,    49,    51,     0,     0,     0,    45,     0,
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     0,    70,
      37,    75,    76,     0,     0,    72,    90,    83,    84,    85,
      86,    87,    88,    89,    79,    80,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,    57,
      94,     0,    78,    53,    54,    55,     0,     0,     0,     0,
      59,    60,     0,    71,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    58,     0,    62,    63,     0,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   -95,   243,   -95,   -95,   213,    20,   -95,
     -95,   230,   -95,   -95,   200,   204,   193,   -95,   -95,   234,
     -95,   191,   -95,   198,   -95,   -95,     2,   -95,   171,   -84,
     -94,   -78,   -95,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    29,    38,    39,    54,    11,
      22,    23,    31,    43,    44,    55,    56,    26,    35,    27,
      99,    59,    68,    69,    75,    82,    12,    70,    79,    95,
      96,   109,   164,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,   124,     1,   120,   125,   115,   116,    17,    18,    17,
      18,    97,    97,    28,    19,   121,     4,    97,    17,    18,
     121,   124,   124,    52,    53,    32,   121,   126,    37,     8,
      21,    25,   178,   147,   131,   197,   132,    97,    97,   133,
     122,   154,    21,   148,   149,   150,    25,    13,    20,    40,
      20,   155,     5,   157,    30,    46,   158,    14,    40,    20,
      24,    18,   163,   165,   212,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,    17,    18,    67,    17,
      18,   126,    50,    66,    51,   121,    76,    41,    67,    17,
      18,   126,    16,     5,     9,    34,   102,   103,   179,   104,
      10,    20,   185,    42,    45,   105,   106,   107,   186,    48,
     124,   124,   204,   205,   198,   199,   108,    20,    97,    97,
      20,   124,   203,   143,   144,   215,    97,    97,    83,    49,
      20,    97,    58,   208,    57,    85,    86,    97,    87,    60,
     209,   210,    88,    89,    64,    63,    64,    71,    65,    83,
      72,    90,    74,    91,    92,    84,    85,    86,    93,    87,
      78,   191,    81,    88,    89,   192,    94,   100,   101,    98,
      83,   117,    90,   111,    91,    92,   123,    85,    86,    93,
      87,   112,   113,   114,    88,    89,   118,    94,   119,   128,
     126,    83,   129,    90,   130,    91,    92,   146,    85,    86,
      93,    87,   153,   156,   159,    88,    89,   193,    94,   161,
     160,   162,    83,   194,    90,   152,    91,    92,   195,    85,
      86,    93,    87,   183,   184,   196,    88,    89,   211,    94,
     197,   200,   201,    83,   202,    90,   213,    91,    92,   216,
      85,    86,    93,    87,   217,   219,   218,    88,    89,    15,
      94,    47,    33,    62,    83,    61,    90,    73,    91,    92,
      36,    85,    86,    93,    87,    80,    77,     0,    88,    89,
     127,    94,     0,     0,     0,    83,     0,    90,     0,    91,
      92,     0,    85,    86,    93,    87,     0,     0,     0,   151,
      89,     0,    94,   141,   142,   143,   144,     0,    90,     0,
      91,    92,     0,     0,     0,    93,   134,   135,   136,   137,
     138,   139,     0,    94,     0,     0,   140,     0,     0,     0,
       0,     0,   141,   142,   143,   144,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,   140,     0,   166,     0,
       0,     0,   141,   142,   143,   144,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,   140,     0,   180,     0,
       0,     0,   141,   142,   143,   144,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,   140,     0,   181,     0,
       0,     0,   141,   142,   143,   144,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,   140,     0,   182,     0,
       0,     0,   141,   142,   143,   144,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,   140,     0,   206,     0,
       0,     0,   141,   142,   143,   144,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,   140,     0,   207,     0,
       0,     0,   141,   142,   143,   144,     0,   134,   135,   136,
     137,   138,   139,     0,     0,     0,   188,   140,     0,     0,
       0,     0,     0,   141,   142,   143,   144,     0,   134,   135,
     136,   137,   138,   139,     0,     0,     0,   190,   140,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   134,   135,
     136,   137,   138,   139,     0,   145,     0,     0,   140,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   134,   135,
     136,   137,   138,   139,     0,   187,     0,     0,   140,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   134,   135,
     136,   137,   138,   139,     0,   189,     0,     0,   140,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   134,   135,
     136,   137,   138,   139,     0,   214,     0,     0,   140,     0,
       0,     0,     0,     0,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     0,     0,     0,   140,     0,
       0,     0,     0,     0,   141,   142,   143,   144
};

static const yytype_int16 yycheck[] =
{
      78,    95,     7,    15,    15,    89,    90,     3,     4,     3,
       4,    89,    90,    11,    10,    38,     8,    95,     3,     4,
      38,   115,   116,    50,    51,    10,    38,    38,    26,     0,
      10,    11,    55,   111,    52,    21,    54,   115,   116,   108,
      52,   119,    22,   112,   113,   114,    26,    48,    44,    29,
      44,   120,    44,   122,    54,    49,   125,     8,    38,    44,
       3,     4,   131,   132,    50,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     3,     4,    58,     3,
       4,    38,    52,    10,    54,    38,    10,    55,    68,     3,
       4,    38,     5,    44,     3,    44,    34,    35,    55,    37,
       9,    44,    55,    44,    54,    43,    44,    45,    55,    44,
     204,   205,   196,   197,   183,   184,    54,    44,   196,   197,
      44,   215,   191,    41,    42,   209,   204,   205,     6,    48,
      44,   209,     9,   202,    50,    13,    14,   215,    16,    43,
      18,    19,    20,    21,    51,    44,    51,    53,    55,     6,
      55,    29,    48,    31,    32,    12,    13,    14,    36,    16,
      11,    51,    44,    20,    21,    55,    44,    50,    51,    49,
       6,    50,    29,    54,    31,    32,    12,    13,    14,    36,
      16,    54,    54,    54,    20,    21,    50,    44,    54,    44,
      38,     6,    54,    29,    54,    31,    32,    44,    13,    14,
      36,    16,    44,    44,    44,    20,    21,    50,    44,    55,
      49,    55,     6,    50,    29,    30,    31,    32,    50,    13,
      14,    36,    16,    54,    54,    17,    20,    21,    22,    44,
      21,    50,    50,     6,    15,    29,    50,    31,    32,    50,
      13,    14,    36,    16,    50,    50,    19,    20,    21,     6,
      44,    38,    22,    53,     6,    51,    29,    64,    31,    32,
      26,    13,    14,    36,    16,    74,    68,    -1,    20,    21,
      99,    44,    -1,    -1,    -1,     6,    -1,    29,    -1,    31,
      32,    -1,    13,    14,    36,    16,    -1,    -1,    -1,    20,
      21,    -1,    44,    39,    40,    41,    42,    -1,    29,    -1,
      31,    32,    -1,    -1,    -1,    36,    23,    24,    25,    26,
      27,    28,    -1,    44,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    55,    -1,
      -1,    -1,    39,    40,    41,    42,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    55,    -1,
      -1,    -1,    39,    40,    41,    42,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    55,    -1,
      -1,    -1,    39,    40,    41,    42,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    55,    -1,
      -1,    -1,    39,    40,    41,    42,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    55,    -1,
      -1,    -1,    39,    40,    41,    42,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    55,    -1,
      -1,    -1,    39,    40,    41,    42,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    53,    33,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    53,    33,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    23,    24,
      25,    26,    27,    28,    -1,    50,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    23,    24,
      25,    26,    27,    28,    -1,    50,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    23,    24,
      25,    26,    27,    28,    -1,    50,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    23,    24,
      25,    26,    27,    28,    -1,    50,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    57,    58,     8,    44,    59,    60,     0,     3,
       9,    65,    82,    48,     8,    60,     5,     3,     4,    10,
      44,    64,    66,    67,     3,    64,    73,    75,    82,    61,
      54,    68,    10,    67,    44,    74,    75,    82,    62,    63,
      64,    55,    44,    69,    70,    54,    49,    63,    44,    48,
      52,    54,    50,    51,    64,    71,    72,    50,     9,    77,
      43,    71,    70,    44,    51,    55,    10,    64,    78,    79,
      83,    53,    55,    72,    48,    80,    10,    79,    11,    84,
      77,    44,    81,     6,    12,    13,    14,    16,    20,    21,
      29,    31,    32,    36,    44,    85,    86,    87,    49,    76,
      50,    51,    34,    35,    37,    43,    44,    45,    54,    87,
      89,    54,    54,    54,    54,    85,    85,    50,    50,    54,
      15,    38,    52,    12,    86,    15,    38,    84,    44,    54,
      54,    52,    54,    89,    23,    24,    25,    26,    27,    28,
      33,    39,    40,    41,    42,    50,    44,    87,    89,    89,
      89,    20,    30,    44,    87,    89,    44,    89,    89,    44,
      49,    55,    55,    89,    88,    89,    55,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    55,    55,
      55,    55,    55,    54,    54,    55,    55,    50,    53,    50,
      53,    51,    55,    50,    50,    50,    17,    21,    89,    89,
      50,    50,    15,    89,    85,    85,    55,    55,    89,    18,
      19,    22,    50,    50,    50,    85,    50,    50,    19,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    57,    58,    58,    58,    59,    59,
      61,    60,    62,    62,    63,    64,    64,    64,    65,    65,
      66,    66,    68,    67,    69,    69,    70,    70,    70,    71,
      71,    71,    72,    73,    73,    74,    76,    75,    77,    77,
      77,    78,    78,    80,    79,    81,    81,    83,    82,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    87,
      87,    88,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     0,     2,     1,
       0,     5,     2,     1,     3,     1,     1,     1,     3,     2,
       2,     1,     0,     4,     3,     1,     1,     4,     4,     3,
       1,     0,     2,     2,     1,     1,     0,    10,     3,     2,
       0,     2,     1,     0,     4,     3,     1,     0,     9,     3,
       2,     2,     1,     5,     5,     5,     4,     4,     7,     5,
       5,    10,     8,     8,     7,     7,     2,     2,     3,     3,
       3,     3,     1,     0,     1,     3,     3,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     4
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
  case 10:
#line 71 "exprtree.y"
                      {
                /* Pre-install shell to allow recursive structures (e.g. node.next) */
                curr_type_defining = TInstall((yyvsp[-1].varname), 0, NULL);
             }
#line 1637 "y.tab.c"
    break;

  case 11:
#line 74 "exprtree.y"
                                 {
                curr_type_defining = NULL;
             }
#line 1645 "y.tab.c"
    break;

  case 14:
#line 83 "exprtree.y"
                                {
                FInstall(curr_type_defining, (yyvsp[-1].varname), (yyvsp[-2].type)->name);
              }
#line 1653 "y.tab.c"
    break;

  case 15:
#line 88 "exprtree.y"
                     { (yyval.type) = TLookup("int"); }
#line 1659 "y.tab.c"
    break;

  case 16:
#line 89 "exprtree.y"
                     { (yyval.type) = TLookup("str"); }
#line 1665 "y.tab.c"
    break;

  case 17:
#line 90 "exprtree.y"
                     { 
                  struct Typetable *t = TLookup((yyvsp[0].varname));
                  if (!t) {
                      printf("Semantic Error: Unknown type '%s'.\n", (yyvsp[0].varname));
                      exit(1);
                  }
                  (yyval.type) = t;
              }
#line 1678 "y.tab.c"
    break;

  case 22:
#line 106 "exprtree.y"
                      { current_type = (yyvsp[0].type); }
#line 1684 "y.tab.c"
    break;

  case 26:
#line 109 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), current_type, 1, NULL); }
#line 1690 "y.tab.c"
    break;

  case 27:
#line 110 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), current_type, (yyvsp[-1].val), NULL); }
#line 1696 "y.tab.c"
    break;

  case 28:
#line 111 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), current_type, 0, (yyvsp[-1].param)); }
#line 1702 "y.tab.c"
    break;

  case 29:
#line 114 "exprtree.y"
                                 {
                struct ParamNode *temp = (yyvsp[-2].param);
                while(temp->next != NULL) temp = temp->next;
                temp->next = (yyvsp[0].param);
                (yyval.param) = (yyvsp[-2].param);
           }
#line 1713 "y.tab.c"
    break;

  case 30:
#line 120 "exprtree.y"
                   { (yyval.param) = (yyvsp[0].param); }
#line 1719 "y.tab.c"
    break;

  case 31:
#line 121 "exprtree.y"
                         { (yyval.param) = NULL; }
#line 1725 "y.tab.c"
    break;

  case 32:
#line 124 "exprtree.y"
                         {
                struct ParamNode *temp = (struct ParamNode *)malloc(sizeof(struct ParamNode));
                temp->name = (yyvsp[0].varname);
                temp->type = (yyvsp[-1].type);
                temp->next = NULL;
                (yyval.param) = temp;
           }
#line 1737 "y.tab.c"
    break;

  case 35:
#line 139 "exprtree.y"
                { 
                current_func_type = current_type; 
                (yyval.varname) = (yyvsp[0].varname); 
           }
#line 1746 "y.tab.c"
    break;

  case 36:
#line 145 "exprtree.y"
                                                                {
                struct GST_Node *g = GLookup((yyvsp[-5].varname));
                if (g == NULL) { 
                    printf("Semantic Error: Function '%s' not declared.\n", (yyvsp[-5].varname)); 
                    exit(1); 
                }
                if (g->type != (yyvsp[-6].type)) {
                    printf("Semantic Error: Return type mismatch for function '%s'.\n", (yyvsp[-5].varname));
                    exit(1);
                }
                current_func_type = g->type; 

                /* Formal parameter verification */
                struct ParamNode *decl_p = g->paramlist;
                struct ParamNode *def_p = (yyvsp[-3].param);
                while (decl_p && def_p) {
                    if (strcmp(decl_p->name, def_p->name) != 0 || decl_p->type != def_p->type) {
                        printf("Semantic Error: Formal parameters do not match signature in '%s'.\n", (yyvsp[-5].varname));
                        exit(1);
                    }
                    decl_p = decl_p->next;
                    def_p = def_p->next;
                }
                if (decl_p != NULL || def_p != NULL) {
                    printf("Semantic Error: Parameter count mismatch in '%s'.\n", (yyvsp[-5].varname));
                    exit(1);
                }

                InstallParameters((yyvsp[-3].param));
           }
#line 1781 "y.tab.c"
    break;

  case 37:
#line 174 "exprtree.y"
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
#line 1800 "y.tab.c"
    break;

  case 43:
#line 193 "exprtree.y"
                      { current_type = (yyvsp[0].type); }
#line 1806 "y.tab.c"
    break;

  case 45:
#line 194 "exprtree.y"
                             { LInstall((yyvsp[0].varname), current_type, local_binding++); }
#line 1812 "y.tab.c"
    break;

  case 46:
#line 195 "exprtree.y"
                             { LInstall((yyvsp[0].varname), current_type, local_binding++); }
#line 1818 "y.tab.c"
    break;

  case 47:
#line 202 "exprtree.y"
                                             {
                current_func_type = TLookup("int"); 
           }
#line 1826 "y.tab.c"
    break;

  case 48:
#line 204 "exprtree.y"
                      {
                fprintf(target_file, "MAIN:\n");
                fprintf(target_file, "PUSH BP\n");
                fprintf(target_file, "MOV BP, SP\n");
                
                int num_locals = local_binding - 1;
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "PUSH R0\n");
                }

                if ((yyvsp[-1].no) != NULL) codeGen((yyvsp[-1].no));

                /* Graceful fallthrough cleanup in case return 0 was omitted */
                int discard = getReg();
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "POP R%d\n", discard);
                }
                freeReg();
                fprintf(target_file, "POP BP\n");
                fprintf(target_file, "RET\n");

                LST_reset();
           }
#line 1854 "y.tab.c"
    break;

  case 49:
#line 229 "exprtree.y"
                                     { (yyval.no) = (yyvsp[-1].no); }
#line 1860 "y.tab.c"
    break;

  case 50:
#line 230 "exprtree.y"
                                     { (yyval.no) = NULL; }
#line 1866 "y.tab.c"
    break;

  case 51:
#line 233 "exprtree.y"
                   { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[-1].no), (yyvsp[0].no)); }
#line 1872 "y.tab.c"
    break;

  case 52:
#line 234 "exprtree.y"
                   { (yyval.no) = (yyvsp[0].no); }
#line 1878 "y.tab.c"
    break;

  case 53:
#line 237 "exprtree.y"
                           { 
            struct tnode *v = createTree(0, NULL, (yyvsp[-2].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_READ, v, NULL); 
       }
#line 1887 "y.tab.c"
    break;

  case 54:
#line 241 "exprtree.y"
                              {
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_READ, (yyvsp[-2].no), NULL);
     }
#line 1895 "y.tab.c"
    break;

  case 55:
#line 244 "exprtree.y"
                              { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_WRITE, (yyvsp[-2].no), NULL); }
#line 1901 "y.tab.c"
    break;

  case 56:
#line 245 "exprtree.y"
                          { 
            struct tnode *v = createTree(0, NULL, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, v, (yyvsp[-1].no)); 
       }
#line 1910 "y.tab.c"
    break;

  case 57:
#line 249 "exprtree.y"
                             {
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, (yyvsp[-3].no), (yyvsp[-1].no));
     }
#line 1918 "y.tab.c"
    break;

  case 58:
#line 252 "exprtree.y"
                                       { 
            struct tnode *varNode = createTree(0, NULL, (yyvsp[-6].varname), NODE_VAR, NULL, NULL);
            struct tnode *arrNode = createTree(0, varNode->type, NULL, NODE_ARRAY, varNode, (yyvsp[-4].no));
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, arrNode, (yyvsp[-1].no)); 
       }
#line 1928 "y.tab.c"
    break;

  case 59:
#line 257 "exprtree.y"
                           {
            struct tnode *v = createTree(0, NULL, (yyvsp[-2].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_FREE, v, NULL);
     }
#line 1937 "y.tab.c"
    break;

  case 60:
#line 261 "exprtree.y"
                              {
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_FREE, (yyvsp[-2].no), NULL);
     }
#line 1945 "y.tab.c"
    break;

  case 61:
#line 264 "exprtree.y"
                                                       { 
            struct tnode *then_else = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[-4].no), (yyvsp[-2].no));
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_IF_ELSE, (yyvsp[-7].no), then_else); 
       }
#line 1954 "y.tab.c"
    break;

  case 62:
#line 268 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_IF, (yyvsp[-5].no), (yyvsp[-2].no)); }
#line 1960 "y.tab.c"
    break;

  case 63:
#line 269 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_WHILE, (yyvsp[-5].no), (yyvsp[-2].no)); }
#line 1966 "y.tab.c"
    break;

  case 64:
#line 270 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_DO_WHILE, (yyvsp[-2].no), (yyvsp[-5].no)); }
#line 1972 "y.tab.c"
    break;

  case 65:
#line 271 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_REPEAT_UNTIL, (yyvsp[-2].no), (yyvsp[-5].no)); }
#line 1978 "y.tab.c"
    break;

  case 66:
#line 272 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_BREAK, NULL, NULL); }
#line 1984 "y.tab.c"
    break;

  case 67:
#line 273 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONTINUE, NULL, NULL); }
#line 1990 "y.tab.c"
    break;

  case 68:
#line 274 "exprtree.y"
                       {
            int is_udt = (current_func_type != TLookup("int") && current_func_type != TLookup("str") && current_func_type != TLookup("boolean"));
            if ((yyvsp[-1].no)->type != current_func_type) {
                if (!(is_udt && (yyvsp[-1].no)->type == TLookup("null"))) {
                    printf("Semantic Error: Return type mismatch. Expected '%s', got '%s'.\n", 
                           current_func_type->name, (yyvsp[-1].no)->type ? (yyvsp[-1].no)->type->name : "null");
                    exit(1);
                }
            }
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_RET, (yyvsp[-1].no), NULL);
       }
#line 2006 "y.tab.c"
    break;

  case 69:
#line 288 "exprtree.y"
                  {
            struct tnode *v = createTree(0, NULL, (yyvsp[-2].varname), NODE_VAR, NULL, NULL);
            struct Fieldlist *f = FLookup(v->type, (yyvsp[0].varname));
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist in type '%s'.\n", (yyvsp[0].varname), v->type ? v->type->name : "unknown");
                exit(1);
            }
            (yyval.no) = createTree(f->fieldIndex, f->type, (yyvsp[0].varname), NODE_FIELD, v, NULL);
            (yyval.no)->Fentry = f;
      }
#line 2021 "y.tab.c"
    break;

  case 70:
#line 298 "exprtree.y"
                     {
            struct Fieldlist *f = FLookup((yyvsp[-2].no)->type, (yyvsp[0].varname));
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist in type '%s'.\n", (yyvsp[0].varname), (yyvsp[-2].no)->type ? (yyvsp[-2].no)->type->name : "unknown");
                exit(1);
            }
            (yyval.no) = createTree(f->fieldIndex, f->type, (yyvsp[0].varname), NODE_FIELD, (yyvsp[-2].no), NULL);
            (yyval.no)->Fentry = f;
      }
#line 2035 "y.tab.c"
    break;

  case 71:
#line 309 "exprtree.y"
                           {
            struct tnode *temp = (yyvsp[-2].no);
            while(temp->right != NULL) temp = temp->right;
            temp->right = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[0].no), NULL);
            (yyval.no) = (yyvsp[-2].no);
        }
#line 2046 "y.tab.c"
    break;

  case 72:
#line 315 "exprtree.y"
                           { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[0].no), NULL); }
#line 2052 "y.tab.c"
    break;

  case 73:
#line 316 "exprtree.y"
                           { (yyval.no) = NULL; }
#line 2058 "y.tab.c"
    break;

  case 74:
#line 319 "exprtree.y"
                          { (yyval.no) = (yyvsp[0].no); }
#line 2064 "y.tab.c"
    break;

  case 75:
#line 320 "exprtree.y"
                          { (yyval.no) = createTree(0, TLookup("int"), NULL, NODE_INIT, NULL, NULL); }
#line 2070 "y.tab.c"
    break;

  case 76:
#line 321 "exprtree.y"
                          { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ALLOC, NULL, NULL); }
#line 2076 "y.tab.c"
    break;

  case 77:
#line 322 "exprtree.y"
                          { (yyval.no) = createTree(0, TLookup("null"), NULL, NODE_NULL, NULL, NULL); }
#line 2082 "y.tab.c"
    break;

  case 78:
#line 323 "exprtree.y"
                          {
            struct GST_Node *g = GLookup((yyvsp[-3].varname));
            if (g == NULL) { 
                printf("Semantic Error: Function '%s' is not declared.\n", (yyvsp[-3].varname)); 
                exit(1); 
            }
            struct ParamNode *param = g->paramlist;
            struct tnode *arg = (yyvsp[-1].no);
            while (param != NULL && arg != NULL) {
                int p_is_udt = (param->type != TLookup("int") && 
                                param->type != TLookup("str") && 
                                param->type != TLookup("boolean"));

                if (param->type != arg->left->type) { 
                    /* Allow passing 'null' to any parameter expecting a UDT */
                    if (!(p_is_udt && arg->left->type == TLookup("null"))) {
                        printf("Semantic Error: Argument type mismatch in call to '%s'.\n", (yyvsp[-3].varname));
                        exit(1);
                    }
                }
                param = param->next;
                arg = arg->right; 
            }
            if (param != NULL || arg != NULL) {
                printf("Semantic Error: Incorrect argument count in '%s'.\n", (yyvsp[-3].varname));
                exit(1);
            }
            struct tnode *funcNode = createTree(0, NULL, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            funcNode->Gentry = g; 
            (yyval.no) = createTree(0, g->type, NULL, NODE_FUNC_CALL, funcNode, (yyvsp[-1].no)); 
       }
#line 2118 "y.tab.c"
    break;

  case 79:
#line 354 "exprtree.y"
                        { (yyval.no) = createTree('+', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2124 "y.tab.c"
    break;

  case 80:
#line 355 "exprtree.y"
                        { (yyval.no) = createTree('-', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2130 "y.tab.c"
    break;

  case 81:
#line 356 "exprtree.y"
                        { (yyval.no) = createTree('*', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2136 "y.tab.c"
    break;

  case 82:
#line 357 "exprtree.y"
                        { (yyval.no) = createTree('/', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2142 "y.tab.c"
    break;

  case 83:
#line 358 "exprtree.y"
                        { (yyval.no) = createTree(LT, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2148 "y.tab.c"
    break;

  case 84:
#line 359 "exprtree.y"
                        { (yyval.no) = createTree(GT, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2154 "y.tab.c"
    break;

  case 85:
#line 360 "exprtree.y"
                        { (yyval.no) = createTree(LE, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2160 "y.tab.c"
    break;

  case 86:
#line 361 "exprtree.y"
                        { (yyval.no) = createTree(GE, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2166 "y.tab.c"
    break;

  case 87:
#line 362 "exprtree.y"
                        { (yyval.no) = createTree(EQ, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2172 "y.tab.c"
    break;

  case 88:
#line 363 "exprtree.y"
                        { (yyval.no) = createTree(NE, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2178 "y.tab.c"
    break;

  case 89:
#line 364 "exprtree.y"
                        { (yyval.no) = createTree(AND, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2184 "y.tab.c"
    break;

  case 90:
#line 365 "exprtree.y"
                        { (yyval.no) = (yyvsp[-1].no); }
#line 2190 "y.tab.c"
    break;

  case 91:
#line 366 "exprtree.y"
                        { (yyval.no) = createTree((yyvsp[0].val), TLookup("int"), NULL, NODE_NUM, NULL, NULL); }
#line 2196 "y.tab.c"
    break;

  case 92:
#line 367 "exprtree.y"
                        { (yyval.no) = createTree(0, TLookup("str"), (yyvsp[0].varname), NODE_STR_VAL, NULL, NULL); }
#line 2202 "y.tab.c"
    break;

  case 93:
#line 368 "exprtree.y"
                        { (yyval.no) = createTree(0, NULL, (yyvsp[0].varname), NODE_VAR, NULL, NULL); }
#line 2208 "y.tab.c"
    break;

  case 94:
#line 369 "exprtree.y"
                        { 
            struct tnode *varNode = createTree(0, NULL, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, varNode->type, NULL, NODE_ARRAY, varNode, (yyvsp[-1].no)); 
       }
#line 2217 "y.tab.c"
    break;


#line 2221 "y.tab.c"

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
#line 374 "exprtree.y"


void yyerror(char const *s) { 
    extern char *yytext;
    printf("YYError: %s at token '%s'\n", s, yytext); 
}

void makeBootCode(void) {
    fprintf(target_file, "BOOT:\n");
    fprintf(target_file, "MOV SP, %d\n", getSP());
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
