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

int current_type; 
int current_func_type; /* NEW: Tracks the return type of the function we are currently inside */

#line 85 "y.tab.c"

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
    DECL = 262,
    ENDDECL = 263,
    BEGIN_TOK = 264,
    END_TOK = 265,
    READ = 266,
    WRITE = 267,
    ASSIGN = 268,
    IF = 269,
    THEN = 270,
    ELSE = 271,
    ENDIF = 272,
    WHILE = 273,
    DO = 274,
    ENDWHILE = 275,
    LT = 276,
    GT = 277,
    LE = 278,
    GE = 279,
    EQ = 280,
    NE = 281,
    REPEAT = 282,
    UNTIL = 283,
    CONTINUE = 284,
    BREAK = 285,
    AND = 286,
    NUM = 287,
    ID = 288,
    STRING = 289,
    PLUS = 290,
    MINUS = 291,
    MUL = 292,
    DIV = 293,
    USTAR = 294
  };
#endif
/* Tokens.  */
#define INT 258
#define STR 259
#define MAIN 260
#define RETURN 261
#define DECL 262
#define ENDDECL 263
#define BEGIN_TOK 264
#define END_TOK 265
#define READ 266
#define WRITE 267
#define ASSIGN 268
#define IF 269
#define THEN 270
#define ELSE 271
#define ENDIF 272
#define WHILE 273
#define DO 274
#define ENDWHILE 275
#define LT 276
#define GT 277
#define LE 278
#define GE 279
#define EQ 280
#define NE 281
#define REPEAT 282
#define UNTIL 283
#define CONTINUE 284
#define BREAK 285
#define AND 286
#define NUM 287
#define ID 288
#define STRING 289
#define PLUS 290
#define MINUS 291
#define MUL 292
#define DIV 293
#define USTAR 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "exprtree.y"

    int val;
    char *varname;
    struct tnode *no;
    struct ParamNode *param; /* NEW: Added to support parameter lists */

#line 222 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

#define YYUNDEFTOK  2
#define YYMAXUTOK   294


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
       2,     2,     2,     2,     2,     2,     2,     2,    39,     2,
      45,    46,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    45,    46,    52,    52,    53,    53,    54,
      56,    57,    60,    60,    61,    62,    63,    66,    72,    73,
      76,    88,    88,    90,    90,   152,   152,   152,   153,   153,
     154,   155,   156,   162,   162,   195,   196,   199,   200,   203,
     207,   211,   217,   223,   227,   232,   233,   237,   242,   246,
     247,   248,   249,   250,   251,   254,   264,   270,   271,   274,
     275,   279,   286,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STR", "MAIN", "RETURN", "DECL",
  "ENDDECL", "BEGIN_TOK", "END_TOK", "READ", "WRITE", "ASSIGN", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "LT", "GT", "LE",
  "GE", "EQ", "NE", "REPEAT", "UNTIL", "CONTINUE", "BREAK", "AND", "NUM",
  "ID", "STRING", "PLUS", "MINUS", "MUL", "DIV", "'&'", "USTAR", "';'",
  "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept", "Program",
  "GDeclBlock", "GDeclList", "GDecl", "Type", "GVarList", "GVar",
  "ParamList", "Param", "FDefBlock", "FDef", "$@1", "LDeclBlock",
  "LDeclList", "LDecl", "LVarList", "MainBlock", "$@2", "Body", "slist",
  "stmt", "ArgList", "expr", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    38,
     294,    59,    44,    91,    93,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,     2,    21,    12,   110,   -76,   -19,   -76,   -76,   -76,
      55,   -76,    22,   -76,     2,    29,   110,   -76,   -76,    23,
     -76,   -76,    46,    83,   -76,    27,   -76,   -76,    34,    71,
     125,   -76,    22,   125,    81,    64,    85,     5,   -76,   -76,
      41,    70,   -76,   -76,   -76,   125,   -76,    87,   -76,   129,
      76,   -76,   133,   -76,    81,   -76,   111,   -76,   -76,   121,
     116,   -76,   -76,   132,   104,   -76,   124,   126,   127,   128,
     217,   217,   136,   143,   -12,   104,   149,   -76,   -76,   133,
     -76,   -76,    72,   -76,   104,   137,   104,   543,    53,   104,
     104,   104,   237,    38,   -76,   -76,   104,   104,   255,   -76,
     -76,   118,   104,   104,   -76,   -76,   273,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   -76,   -23,
     104,   291,   309,   327,   140,   145,   564,   399,   104,   -76,
     423,    56,   648,   -76,   666,   666,   666,   666,   666,   666,
     109,   119,   119,   -76,   -76,   104,   150,   345,   151,   159,
     174,   104,   104,   -76,     0,   585,   152,   104,   -76,   447,
     -76,   153,   -76,   217,   217,   363,   381,   104,   104,   -76,
     104,   648,    18,   -76,    93,   169,   -11,   156,   606,   471,
     495,   104,   160,   217,   163,   164,   -76,   -76,   -76,   187,
     -76,   519,   -76,   197,   -76,   -76,   104,   161,   171,   627,
     172,   -76,   -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,    10,    11,     6,
       0,     8,     0,     1,    10,     0,     0,    22,     3,     0,
       5,     7,    14,     0,    13,     0,    21,     2,     0,     0,
      19,     9,     0,    19,    27,     0,     0,     0,    18,    12,
       0,     0,    33,    15,    20,     0,    16,     0,    26,     0,
       0,    29,     0,    17,    27,    32,     0,    25,    28,     0,
       0,    23,    30,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    34,     0,
      31,    75,    77,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    53,     0,     0,     0,    35,
      37,     0,     0,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,    57,    74,    67,    68,    69,    70,    71,    72,
      73,    63,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,    78,     0,    62,     0,
      43,     0,    45,     0,     0,     0,     0,     0,     0,    40,
       0,    56,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    47,     0,
      61,     0,    44,     0,    49,    50,     0,     0,     0,     0,
       0,    48,    42,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   -76,   200,    44,   -76,   185,   186,   173,
     -76,   204,   -76,   167,   -76,   175,   -76,     1,   -76,   154,
     -67,   -74,   -76,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    10,    11,    36,    23,    24,    37,    38,
      16,    17,    79,    42,    50,    51,    56,     5,    52,    60,
      76,    77,   131,    87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,    96,   100,    92,    93,    18,     1,     6,   164,   104,
       2,   106,    13,   167,   121,   122,   123,    27,   100,   100,
     145,   126,   127,   146,     7,     8,    19,   130,   132,     9,
     186,    97,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   168,    64,   147,    12,    45,    15,    66,
      67,    46,    68,   155,    12,    22,    69,    70,     7,     8,
      15,   181,    25,    20,   182,    71,   125,    72,    73,    28,
     159,    74,    33,     7,     8,    75,   165,   166,    48,     7,
       8,    34,   171,    45,    57,    49,   119,    47,    41,    29,
     120,    30,   178,   179,    49,   180,   174,   175,   157,    64,
     100,   100,   158,    35,    66,    67,   191,    68,    43,   183,
     184,    69,    70,    14,     8,   102,   193,   103,    44,   100,
      71,   199,    72,    73,    31,    32,    74,    64,     7,     8,
      75,    65,    66,    67,    54,    68,    81,    82,    83,    69,
      70,    84,    59,    85,   114,   115,   116,   117,    71,    86,
      72,    73,    62,    63,    74,    64,   116,   117,    75,    99,
      66,    67,    55,    68,    78,    80,   129,    69,    70,    88,
     105,    89,    90,    91,   163,    64,    71,    94,    72,    73,
      66,    67,    74,    68,    95,   151,    75,    69,    70,   185,
     152,   160,   162,   164,   173,   170,    71,   187,    72,    73,
     196,   192,    74,    64,   194,   195,    75,   200,    66,    67,
      21,    68,   201,   203,   198,    69,    70,    39,    53,    40,
      26,    61,     0,    64,    71,    58,    72,    73,    66,    67,
      74,    68,     0,   101,    75,    69,    70,     0,     0,     0,
       0,     0,     0,    64,    71,     0,    72,    73,    66,    67,
      74,    68,     0,     0,    75,   124,    70,     0,     0,     0,
       0,     0,     0,     0,    71,     0,    72,    73,   128,     0,
      74,     0,     0,     0,    75,     0,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,   113,     0,     0,     0,
     114,   115,   116,   117,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,   113,     0,     0,     0,   114,   115,
     116,   117,   107,   108,   109,   110,   111,   112,     0,   133,
       0,     0,   113,     0,     0,     0,   114,   115,   116,   117,
     107,   108,   109,   110,   111,   112,     0,   148,     0,     0,
     113,     0,     0,     0,   114,   115,   116,   117,   107,   108,
     109,   110,   111,   112,     0,   149,     0,     0,   113,     0,
       0,     0,   114,   115,   116,   117,   107,   108,   109,   110,
     111,   112,     0,   150,     0,     0,   113,     0,     0,     0,
     114,   115,   116,   117,   107,   108,   109,   110,   111,   112,
       0,   161,     0,     0,   113,     0,     0,     0,   114,   115,
     116,   117,   107,   108,   109,   110,   111,   112,     0,   176,
       0,     0,   113,     0,     0,     0,   114,   115,   116,   117,
     107,   108,   109,   110,   111,   112,     0,   177,     0,     0,
     113,     0,     0,     0,   114,   115,   116,   117,     0,     0,
       0,     0,     0,   154,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,   113,     0,     0,     0,   114,   115,
     116,   117,     0,     0,     0,     0,     0,   156,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,   113,     0,
       0,     0,   114,   115,   116,   117,     0,     0,     0,     0,
       0,   172,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,   113,     0,     0,     0,   114,   115,   116,   117,
       0,     0,     0,     0,     0,   189,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,   113,     0,     0,     0,
     114,   115,   116,   117,     0,     0,     0,     0,     0,   190,
     107,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     113,     0,     0,     0,   114,   115,   116,   117,     0,     0,
       0,     0,     0,   197,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,   113,     0,     0,     0,   114,   115,
     116,   117,     0,     0,   118,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,   113,     0,     0,     0,   114,
     115,   116,   117,     0,     0,   153,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,   113,     0,     0,     0,
     114,   115,   116,   117,     0,     0,   169,   107,   108,   109,
     110,   111,   112,     0,     0,     0,     0,   113,     0,     0,
       0,   114,   115,   116,   117,     0,     0,   188,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,   113,     0,
       0,     0,   114,   115,   116,   117,     0,     0,   202,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,   113,
       0,     0,     0,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     0,     0,     0,   113,     0,     0,
       0,   114,   115,   116,   117
};

static const yytype_int16 yycheck[] =
{
      75,    13,    76,    70,    71,     4,     3,     5,    19,    84,
       7,    86,     0,    13,    89,    90,    91,    16,    92,    93,
      43,    96,    97,    46,     3,     4,    45,   102,   103,     8,
      41,    43,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    43,     6,   120,     2,    42,     4,    11,
      12,    46,    14,   128,    10,    33,    18,    19,     3,     4,
      16,    43,    33,     8,    46,    27,    28,    29,    30,    46,
     145,    33,    45,     3,     4,    37,   151,   152,     8,     3,
       4,    47,   157,    42,     8,    41,    33,    46,     7,    43,
      37,    45,   167,   168,    50,   170,   163,   164,    42,     6,
     174,   175,    46,    32,    11,    12,   181,    14,    44,    16,
      17,    18,    19,     3,     4,    43,   183,    45,    33,   193,
      27,   196,    29,    30,    41,    42,    33,     6,     3,     4,
      37,    10,    11,    12,    47,    14,    32,    33,    34,    18,
      19,    37,     9,    39,    35,    36,    37,    38,    27,    45,
      29,    30,    41,    42,    33,     6,    37,    38,    37,    10,
      11,    12,    33,    14,    48,    33,    48,    18,    19,    45,
      33,    45,    45,    45,    15,     6,    27,    41,    29,    30,
      11,    12,    33,    14,    41,    45,    37,    18,    19,    20,
      45,    41,    41,    19,    41,    43,    27,    41,    29,    30,
      13,    41,    33,     6,    41,    41,    37,    46,    11,    12,
      10,    14,    41,    41,    17,    18,    19,    32,    45,    33,
      16,    54,    -1,     6,    27,    50,    29,    30,    11,    12,
      33,    14,    -1,    79,    37,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    27,    -1,    29,    30,    11,    12,
      33,    14,    -1,    -1,    37,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    29,    30,    13,    -1,
      33,    -1,    -1,    -1,    37,    -1,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,    37,    38,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    21,    22,    23,    24,    25,    26,    -1,    46,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,    37,    38,
      21,    22,    23,    24,    25,    26,    -1,    46,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,    37,    38,    21,    22,
      23,    24,    25,    26,    -1,    46,    -1,    -1,    31,    -1,
      -1,    -1,    35,    36,    37,    38,    21,    22,    23,    24,
      25,    26,    -1,    46,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,    37,    38,    21,    22,    23,    24,    25,    26,
      -1,    46,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    21,    22,    23,    24,    25,    26,    -1,    46,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,    37,    38,
      21,    22,    23,    24,    25,    26,    -1,    46,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    44,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    44,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    44,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    41,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    41,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      35,    36,    37,    38,    -1,    -1,    41,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,    37,    38,    -1,    -1,    41,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    35,    36,    37,    38,    -1,    -1,    41,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    36,    37,    38,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    35,    36,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     7,    50,    51,    66,     5,     3,     4,     8,
      52,    53,    54,     0,     3,    54,    59,    60,    66,    45,
       8,    53,    33,    55,    56,    33,    60,    66,    46,    43,
      45,    41,    42,    45,    47,    32,    54,    57,    58,    56,
      57,     7,    62,    44,    33,    42,    46,    46,     8,    54,
      63,    64,    67,    58,    47,    33,    65,     8,    64,     9,
      68,    62,    41,    42,     6,    10,    11,    12,    14,    18,
      19,    27,    29,    30,    33,    37,    69,    70,    48,    61,
      33,    32,    33,    34,    37,    39,    45,    72,    45,    45,
      45,    45,    69,    69,    41,    41,    13,    43,    72,    10,
      70,    68,    43,    45,    72,    33,    72,    21,    22,    23,
      24,    25,    26,    31,    35,    36,    37,    38,    41,    33,
      37,    72,    72,    72,    18,    28,    72,    72,    13,    48,
      72,    71,    72,    46,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    43,    46,    72,    46,    46,
      46,    45,    45,    41,    44,    72,    44,    42,    46,    72,
      41,    46,    41,    15,    19,    72,    72,    13,    43,    41,
      43,    72,    44,    41,    69,    69,    46,    46,    72,    72,
      72,    43,    46,    16,    17,    20,    41,    41,    41,    44,
      44,    72,    41,    69,    41,    41,    13,    44,    17,    72,
      46,    41,    41,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    50,    51,    51,    52,    52,    53,
      54,    54,    55,    55,    56,    56,    56,    57,    57,    57,
      58,    59,    59,    61,    60,    62,    62,    62,    63,    63,
      64,    65,    65,    67,    66,    68,    68,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     3,     1,     1,     4,     4,     3,     1,     0,
       2,     2,     1,     0,    10,     3,     2,     0,     2,     1,
       3,     3,     1,     0,     9,     3,     2,     2,     1,     6,
       5,    11,    10,     5,     8,     5,     4,     7,    10,     8,
       8,     7,     7,     2,     2,     3,     3,     1,     0,     2,
       2,     7,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     4
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
#line 56 "exprtree.y"
                 { current_type = TYPE_INT; }
#line 1625 "y.tab.c"
    break;

  case 11:
#line 57 "exprtree.y"
                 { current_type = TYPE_STR; }
#line 1631 "y.tab.c"
    break;

  case 14:
#line 61 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), current_type, 1, NULL); }
#line 1637 "y.tab.c"
    break;

  case 15:
#line 62 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), current_type, (yyvsp[-1].val), NULL); }
#line 1643 "y.tab.c"
    break;

  case 16:
#line 63 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), current_type, 0, (yyvsp[-1].param)); }
#line 1649 "y.tab.c"
    break;

  case 17:
#line 66 "exprtree.y"
                                 {
                struct ParamNode *temp = (yyvsp[-2].param);
                while(temp->next != NULL) temp = temp->next;
                temp->next = (yyvsp[0].param);
                (yyval.param) = (yyvsp[-2].param);
           }
#line 1660 "y.tab.c"
    break;

  case 18:
#line 72 "exprtree.y"
                   { (yyval.param) = (yyvsp[0].param); }
#line 1666 "y.tab.c"
    break;

  case 19:
#line 73 "exprtree.y"
                         { (yyval.param) = NULL; }
#line 1672 "y.tab.c"
    break;

  case 20:
#line 76 "exprtree.y"
                     {
                struct ParamNode *temp = (struct ParamNode *)malloc(sizeof(struct ParamNode));
                temp->name = (yyvsp[0].varname);
                temp->type = current_type;
                temp->next = NULL;
                (yyval.param) = temp;
           }
#line 1684 "y.tab.c"
    break;

  case 23:
#line 90 "exprtree.y"
                                                      {
                /* MID-RULE ACTION: Execute this BEFORE parsing Body */
                struct GST_Node *g = GLookup((yyvsp[-5].varname));
                if (g == NULL) { 
                    printf("Semantic Error: Function '%s' not declared.\n", (yyvsp[-5].varname)); 
                    exit(1); 
                }

                if (g->type != current_type) {
                    printf("Semantic Error: Return type mismatch for function '%s'.\n", (yyvsp[-5].varname));
                    exit(1);
                }
                
                current_func_type = g->type; 

                struct ParamNode *decl_param = g->paramlist; 
                struct ParamNode *def_param = (yyvsp[-3].param);            
                
                while (decl_param != NULL && def_param != NULL) {
                    if (strcmp(decl_param->name, def_param->name) != 0) {
                        printf("Semantic Error: Parameter name mismatch in '%s'. Expected '%s', got '%s'.\n", 
                               (yyvsp[-5].varname), decl_param->name, def_param->name);
                        exit(1);
                    }
                    if (decl_param->type != def_param->type) {
                        printf("Semantic Error: Parameter type mismatch in '%s' for '%s'.\n", 
                               (yyvsp[-5].varname), decl_param->name);
                        exit(1);
                    }
                    decl_param = decl_param->next;
                    def_param = def_param->next;
                }
                
                if (decl_param != NULL || def_param != NULL) {
                    printf("Semantic Error: Parameter count in definition of '%s' does not match declaration.\n", (yyvsp[-5].varname));
                    exit(1);
                }

                /* Load parameters so Body can find them! */
                InstallParameters((yyvsp[-3].param));
                
           }
#line 1731 "y.tab.c"
    break;

  case 24:
#line 131 "exprtree.y"
                      {
                /* END-RULE ACTION: Execute this AFTER parsing Body */
                struct GST_Node *g = GLookup((yyvsp[-8].varname));
                
                fprintf(target_file, "F%d:\n", g->flabel);
                fprintf(target_file, "PUSH BP\n");
                fprintf(target_file, "MOV BP, SP\n");
                
                int num_locals = local_binding - 1;
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "PUSH R0\n");
                }
                
                /* Notice we use $9 here because Body is now the 9th item in the rule */
                if ((yyvsp[-1].no) != NULL) codeGen((yyvsp[-1].no));
                
                LST_reset(); 
           }
#line 1754 "y.tab.c"
    break;

  case 31:
#line 155 "exprtree.y"
                             { LInstall((yyvsp[0].varname), current_type, local_binding++); }
#line 1760 "y.tab.c"
    break;

  case 32:
#line 156 "exprtree.y"
                             { LInstall((yyvsp[0].varname), current_type, local_binding++); }
#line 1766 "y.tab.c"
    break;

  case 33:
#line 162 "exprtree.y"
                                             {
                /* Set function type BEFORE Body parses so RETURN statements don't crash */
                current_func_type = TYPE_INT; 
                
           }
#line 1776 "y.tab.c"
    break;

  case 34:
#line 166 "exprtree.y"
                      {
           
                fprintf(target_file, "MAIN:\n");
                fprintf(target_file, "MOV SP, %d\n", getSP());
                fprintf(target_file, "MOV BP, SP\n");
                
                int num_locals = local_binding - 1;
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "PUSH R0\n");
                }

                /* Notice we use $8 here because Body is now the 8th item in the rule */
                if ((yyvsp[-1].no) != NULL) codeGen((yyvsp[-1].no));

                int r = getReg();
                fprintf(target_file, "MOV R%d, \"Exit\"\n", r);
                fprintf(target_file, "PUSH R%d\n", r);      
                fprintf(target_file, "MOV R%d, 0\n", r);
                fprintf(target_file, "PUSH R%d\n", r);      
                fprintf(target_file, "PUSH R%d\n", r);      
                fprintf(target_file, "PUSH R%d\n", r);     
                fprintf(target_file, "PUSH R%d\n", r);      
                fprintf(target_file, "CALL 0\n");
                freeReg();

                LST_reset();
           }
#line 1808 "y.tab.c"
    break;

  case 35:
#line 195 "exprtree.y"
                                     { (yyval.no) = (yyvsp[-1].no); }
#line 1814 "y.tab.c"
    break;

  case 36:
#line 196 "exprtree.y"
                                     { (yyval.no) = NULL; }
#line 1820 "y.tab.c"
    break;

  case 37:
#line 199 "exprtree.y"
                   { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_CONN, (yyvsp[-1].no), (yyvsp[0].no)); }
#line 1826 "y.tab.c"
    break;

  case 38:
#line 200 "exprtree.y"
                   { (yyval.no) = (yyvsp[0].no); }
#line 1832 "y.tab.c"
    break;

  case 39:
#line 203 "exprtree.y"
                                 { 
            struct tnode *ptrNode = createTree(0, TYPE_INT, NULL, NODE_PTR_DEREF, (yyvsp[-2].no), NULL);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_READ, ptrNode, NULL); 
       }
#line 1841 "y.tab.c"
    break;

  case 40:
#line 207 "exprtree.y"
                                { 
            struct tnode *ptrNode = createTree(0, TYPE_INT, NULL, NODE_PTR_DEREF, (yyvsp[-3].no), NULL);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, ptrNode, (yyvsp[-1].no)); 
       }
#line 1850 "y.tab.c"
    break;

  case 41:
#line 211 "exprtree.y"
                                                     { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-8].varname), NODE_VAR, NULL, NULL);
            struct tnode *idxNode = createTree(0, TYPE_INT, NULL, NODE_INDEX, (yyvsp[-6].no), (yyvsp[-3].no)); 
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY_2D, varNode, idxNode);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_READ, arrNode, NULL); 
       }
#line 1861 "y.tab.c"
    break;

  case 42:
#line 217 "exprtree.y"
                                                    { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-9].varname), NODE_VAR, NULL, NULL);
            struct tnode *idxNode = createTree(0, TYPE_INT, NULL, NODE_INDEX, (yyvsp[-7].no), (yyvsp[-4].no));
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY_2D, varNode, idxNode);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, arrNode, (yyvsp[-1].no)); 
       }
#line 1872 "y.tab.c"
    break;

  case 43:
#line 223 "exprtree.y"
                           { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-2].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_READ, varNode, NULL); 
       }
#line 1881 "y.tab.c"
    break;

  case 44:
#line 227 "exprtree.y"
                                        { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-5].varname), NODE_VAR, NULL, NULL);
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY, varNode, (yyvsp[-3].no));
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_READ, arrNode, NULL); 
       }
#line 1891 "y.tab.c"
    break;

  case 45:
#line 232 "exprtree.y"
                              { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_WRITE, (yyvsp[-2].no), NULL); }
#line 1897 "y.tab.c"
    break;

  case 46:
#line 233 "exprtree.y"
                          { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, varNode, (yyvsp[-1].no)); 
       }
#line 1906 "y.tab.c"
    break;

  case 47:
#line 237 "exprtree.y"
                                       { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-6].varname), NODE_VAR, NULL, NULL);
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY, varNode, (yyvsp[-4].no));
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, arrNode, (yyvsp[-1].no)); 
       }
#line 1916 "y.tab.c"
    break;

  case 48:
#line 242 "exprtree.y"
                                                       { 
            struct tnode *then_else = createTree(0, TYPE_VOID, NULL, NODE_CONN, (yyvsp[-4].no), (yyvsp[-2].no));
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_IF_ELSE, (yyvsp[-7].no), then_else); 
       }
#line 1925 "y.tab.c"
    break;

  case 49:
#line 246 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_IF, (yyvsp[-5].no), (yyvsp[-2].no)); }
#line 1931 "y.tab.c"
    break;

  case 50:
#line 247 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_WHILE, (yyvsp[-5].no), (yyvsp[-2].no)); }
#line 1937 "y.tab.c"
    break;

  case 51:
#line 248 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_DO_WHILE, (yyvsp[-2].no), (yyvsp[-5].no)); }
#line 1943 "y.tab.c"
    break;

  case 52:
#line 249 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_REPEAT_UNTIL, (yyvsp[-2].no), (yyvsp[-5].no)); }
#line 1949 "y.tab.c"
    break;

  case 53:
#line 250 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_BREAK, NULL, NULL); }
#line 1955 "y.tab.c"
    break;

  case 54:
#line 251 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_CONTINUE, NULL, NULL); }
#line 1961 "y.tab.c"
    break;

  case 55:
#line 254 "exprtree.y"
                       {
            if ((yyvsp[-1].no)->type != current_func_type) {
                printf("Semantic Error: Return type mismatch. Expected %d, got %d.\n", current_func_type, (yyvsp[-1].no)->type);
                exit(1);
            }
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_RET, (yyvsp[-1].no), NULL);
       }
#line 1973 "y.tab.c"
    break;

  case 56:
#line 264 "exprtree.y"
                           {
            struct tnode *temp = (yyvsp[-2].no);
            while(temp->right != NULL) temp = temp->right;
            temp->right = createTree(0, TYPE_VOID, NULL, NODE_CONN, (yyvsp[0].no), NULL);
            (yyval.no) = (yyvsp[-2].no);
        }
#line 1984 "y.tab.c"
    break;

  case 57:
#line 270 "exprtree.y"
                           { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_CONN, (yyvsp[0].no), NULL); }
#line 1990 "y.tab.c"
    break;

  case 58:
#line 271 "exprtree.y"
                           { (yyval.no) = NULL; }
#line 1996 "y.tab.c"
    break;

  case 59:
#line 274 "exprtree.y"
                            { (yyval.no) = createTree(0, TYPE_INT, NULL, NODE_PTR_DEREF, (yyvsp[0].no), NULL); }
#line 2002 "y.tab.c"
    break;

  case 60:
#line 275 "exprtree.y"
              { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[0].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, TYPE_INT, NULL, NODE_PTR_ADDR, varNode, NULL); 
       }
#line 2011 "y.tab.c"
    break;

  case 61:
#line 279 "exprtree.y"
                                    { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-6].varname), NODE_VAR, NULL, NULL);
            struct tnode *idxNode = createTree(0, TYPE_INT, NULL, NODE_INDEX, (yyvsp[-4].no), (yyvsp[-1].no));
            (yyval.no) = createTree(0, varNode->type, NULL, NODE_ARRAY_2D, varNode, idxNode); 
       }
#line 2021 "y.tab.c"
    break;

  case 62:
#line 286 "exprtree.y"
                          {
            struct GST_Node *g = GLookup((yyvsp[-3].varname));
            if (g == NULL) { 
                printf("Semantic Error: Function '%s' is not declared.\n", (yyvsp[-3].varname)); 
                exit(1); 
            }
            
            struct ParamNode *param = g->paramlist;
            struct tnode *arg = (yyvsp[-1].no);
            while (param != NULL && arg != NULL) {
                if (param->type != arg->left->type) { 
                    printf("Semantic Error: Argument type mismatch in call to '%s'.\n", (yyvsp[-3].varname));
                    exit(1);
                }
                param = param->next;
                arg = arg->right; 
            }
            if (param != NULL || arg != NULL) {
                printf("Semantic Error: Incorrect number of arguments passed to '%s'.\n", (yyvsp[-3].varname));
                exit(1);
            }

            struct tnode *funcNode = createTree(0, 0, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            funcNode->Gentry = g; 
            (yyval.no) = createTree(0, g->type, NULL, NODE_FUNC_CALL, funcNode, (yyvsp[-1].no)); 
       }
#line 2052 "y.tab.c"
    break;

  case 63:
#line 313 "exprtree.y"
                        { (yyval.no) = createTree('+', TYPE_INT, NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2058 "y.tab.c"
    break;

  case 64:
#line 314 "exprtree.y"
                        { (yyval.no) = createTree('-', TYPE_INT, NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2064 "y.tab.c"
    break;

  case 65:
#line 315 "exprtree.y"
                        { (yyval.no) = createTree('*', TYPE_INT, NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2070 "y.tab.c"
    break;

  case 66:
#line 316 "exprtree.y"
                        { (yyval.no) = createTree('/', TYPE_INT, NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2076 "y.tab.c"
    break;

  case 67:
#line 317 "exprtree.y"
                        { (yyval.no) = createTree(LT, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2082 "y.tab.c"
    break;

  case 68:
#line 318 "exprtree.y"
                        { (yyval.no) = createTree(GT, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2088 "y.tab.c"
    break;

  case 69:
#line 319 "exprtree.y"
                        { (yyval.no) = createTree(LE, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2094 "y.tab.c"
    break;

  case 70:
#line 320 "exprtree.y"
                        { (yyval.no) = createTree(GE, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2100 "y.tab.c"
    break;

  case 71:
#line 321 "exprtree.y"
                        { (yyval.no) = createTree(EQ, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2106 "y.tab.c"
    break;

  case 72:
#line 322 "exprtree.y"
                        { (yyval.no) = createTree(NE, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2112 "y.tab.c"
    break;

  case 73:
#line 323 "exprtree.y"
                        { (yyval.no) = createTree(AND, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2118 "y.tab.c"
    break;

  case 74:
#line 324 "exprtree.y"
                        { (yyval.no) = (yyvsp[-1].no); }
#line 2124 "y.tab.c"
    break;

  case 75:
#line 325 "exprtree.y"
                        { (yyval.no) = createTree((yyvsp[0].val), TYPE_INT, NULL, NODE_NUM, NULL, NULL); }
#line 2130 "y.tab.c"
    break;

  case 76:
#line 326 "exprtree.y"
                        { (yyval.no) = createTree(0, TYPE_STR, (yyvsp[0].varname), NODE_STR_VAL, NULL, NULL); }
#line 2136 "y.tab.c"
    break;

  case 77:
#line 327 "exprtree.y"
                        { (yyval.no) = createTree(0, 0, (yyvsp[0].varname), NODE_VAR, NULL, NULL); }
#line 2142 "y.tab.c"
    break;

  case 78:
#line 328 "exprtree.y"
                        { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, varNode->type, NULL, NODE_ARRAY, varNode, (yyvsp[-1].no)); 
       }
#line 2151 "y.tab.c"
    break;


#line 2155 "y.tab.c"

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
#line 333 "exprtree.y"


void yyerror(char const *s) { 
    extern char *yytext;
    printf("YYError: %s at token '%s'\n", s, yytext); 
}
void makeBootCode() {
    fprintf(target_file, "BOOT:\n");
    fprintf(target_file, "MOV SP, %d\n", getSP());
    fprintf(target_file, "PUSH R0\n"); /* Space for MAIN's return value */
    fprintf(target_file, "CALL MAIN\n");
    
    /* Safely Halt the Machine via Exit */
    int r = getReg();
    fprintf(target_file, "MOV R%d, \"Exit\"\n", r);
    fprintf(target_file, "PUSH R%d\n", r);      
    fprintf(target_file, "MOV R%d, 0\n", r);
    fprintf(target_file, "PUSH R%d\n", r);      
    fprintf(target_file, "PUSH R%d\n", r);      
    fprintf(target_file, "PUSH R%d\n", r);     
    fprintf(target_file, "PUSH R%d\n", r);      
    fprintf(target_file, "CALL 0\n");
    freeReg();
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (fp) yyin = fp;
        else { printf("Error opening input file: %s\n", argv[1]); return 1; }
    }
    target_file = fopen("target.xsm", "w");
    if (!target_file) { printf("Error creating target.xsm\n"); return 1; }
    
    /* NEW: XSM Header & Boot Sequence */
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(target_file, "JMP BOOT\n"); 
    
    yyparse();
    makeBootCode();
    return 0;
}
