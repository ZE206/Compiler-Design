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
int current_func_type; 
extern struct TupleDefNode *current_tuple_type; /* NEW: Tracks tuple schema being parsed */

#line 86 "y.tab.c"

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
    TUPLE = 262,
    DOT = 263,
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
    PLUS = 289,
    MINUS = 290,
    MUL = 291,
    DIV = 292,
    NUM = 293,
    ID = 294,
    STRING = 295,
    USTAR = 296
  };
#endif
/* Tokens.  */
#define INT 258
#define STR 259
#define MAIN 260
#define RETURN 261
#define TUPLE 262
#define DOT 263
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
#define PLUS 289
#define MINUS 290
#define MUL 291
#define DIV 292
#define NUM 293
#define ID 294
#define STRING 295
#define USTAR 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "exprtree.y"

    int val;
    char *varname;
    struct tnode *no;
    struct ParamNode *param; 
    struct FieldNode *FieldNode_ptr; /* NEW: Added to support tuple field lists */

#line 228 "y.tab.c"

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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   877

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  262

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


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
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      44,    45,     2,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    51,    52,    58,    58,    59,    59,    61,
      63,    63,    68,    69,    73,    73,    74,    75,    76,    77,
      78,    82,    83,    84,    85,    89,    95,    98,   107,   113,
     114,   117,   124,   136,   136,   138,   142,   148,   148,   206,
     206,   206,   207,   207,   209,   211,   211,   217,   218,   219,
     220,   224,   228,   237,   237,   256,   257,   260,   261,   264,
     269,   280,   284,   290,   296,   300,   305,   308,   314,   326,
     331,   335,   336,   337,   338,   339,   340,   342,   351,   357,
     358,   361,   365,   370,   377,   388,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STR", "MAIN", "RETURN", "TUPLE",
  "DOT", "DECL", "ENDDECL", "BEGIN_TOK", "END_TOK", "READ", "WRITE",
  "ASSIGN", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "LT",
  "GT", "LE", "GE", "EQ", "NE", "REPEAT", "UNTIL", "CONTINUE", "BREAK",
  "AND", "PLUS", "MINUS", "MUL", "DIV", "NUM", "ID", "STRING", "'&'",
  "USTAR", "';'", "'('", "')'", "','", "'['", "']'", "'{'", "'}'",
  "$accept", "Program", "GDeclBlock", "GDeclList", "GDecl", "$@1", "Type",
  "GVarList", "GVar", "TupGVarList", "FieldDefList", "FieldDef",
  "ParamList", "Param", "FDefBlock", "FuncName", "FDef", "$@2",
  "LDeclBlock", "LDeclList", "LDecl", "$@3", "LVarList", "TupLVarList",
  "MainBlock", "$@4", "Body", "slist", "stmt", "ArgList", "expr", YY_NULLPTR
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
     295,    38,   296,    59,    40,    41,    44,    91,    93,   123,
     125
};
# endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      89,     8,   126,     9,    55,  -109,   -27,  -109,  -109,   -15,
    -109,   131,  -109,    34,  -109,     8,    63,    55,  -109,  -109,
      -8,    22,  -109,  -109,     6,    76,    61,  -109,    42,  -109,
      46,  -109,  -109,    54,   121,    65,   121,    88,  -109,    34,
    -109,   121,   122,   101,   113,  -109,   121,   103,   163,  -109,
     112,  -109,   173,   165,  -109,  -109,  -109,   121,   175,   110,
    -109,  -109,   121,  -109,   102,   141,  -109,   109,   195,  -109,
     178,   111,  -109,  -109,  -109,  -109,   122,   146,   162,  -109,
     127,  -109,  -109,   310,   154,   167,  -109,   128,  -109,   121,
    -109,  -109,   140,    38,  -109,   166,   188,   190,   191,   462,
     462,   168,   193,    38,  -109,    -9,  -109,   194,    38,   346,
    -109,   777,  -109,  -109,  -109,   142,   178,   183,   199,  -109,
      38,   144,   651,    75,    38,    38,    38,   491,   375,  -109,
    -109,     3,    38,    38,    38,  -109,   513,  -109,  -109,   200,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,   201,  -109,   198,  -109,  -109,   233,    38,   210,  -109,
      38,   -19,   798,   536,   559,   582,   206,   207,    38,   672,
     185,   819,    60,  -109,   243,   840,   840,   840,   840,   840,
     840,    26,    35,    35,   233,   233,  -109,  -109,   220,   129,
    -109,    -3,   217,    38,   222,   221,   245,   242,    38,    38,
     693,  -109,  -109,    38,   -11,    38,  -109,   157,   218,   223,
    -109,   159,   224,  -109,   462,   462,   605,   628,  -109,   819,
      38,    38,   714,  -109,   229,    38,  -109,    44,   227,   274,
     404,     1,   228,   735,   189,  -109,  -109,   219,   235,    38,
    -109,   462,   236,   238,  -109,  -109,  -109,   276,  -109,  -109,
     249,   433,  -109,  -109,    38,   244,   253,   756,   255,  -109,
    -109,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,    12,    13,     0,
       6,     0,     8,     0,     1,    12,     0,     0,    34,     3,
       0,     0,     5,     7,     0,    16,     0,    15,     0,    35,
       0,    33,     2,     0,     0,    19,    30,     0,     9,     0,
      36,    30,    41,     0,     0,    26,    30,     0,     0,    29,
       0,    14,     0,     0,    53,    27,    10,     0,     0,     0,
      31,    18,     0,    17,     0,     0,    40,     0,     0,    43,
       0,     0,    25,    20,    32,    28,    41,     0,     0,    48,
       0,    39,    42,     0,     0,     0,    23,     0,    37,     0,
      50,    44,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,   100,    99,     0,     0,     0,
      58,     0,    54,    24,    11,     0,     0,     0,     0,    47,
       0,   100,     0,     0,     0,     0,     0,     0,     0,    76,
      75,    81,     0,    80,     0,    82,     0,    55,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,    45,    49,    81,     0,     0,    77,
       0,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,    97,    84,    90,    91,    92,    93,    94,
      95,    96,    86,    87,    88,    89,    22,    38,     0,     0,
      84,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    85,     0,   101,     0,    52,     0,   101,     0,
      64,     0,    84,    66,     0,     0,     0,     0,    61,    78,
       0,     0,     0,    46,     0,     0,    59,   101,     0,     0,
       0,     0,     0,     0,     0,    68,    51,     0,     0,     0,
      60,     0,     0,     0,    73,    74,    69,    83,    83,    65,
       0,     0,    71,    72,     0,    83,     0,     0,     0,    70,
      63,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,  -109,   288,  -109,    12,  -109,   261,  -109,
     212,   247,   -34,   240,  -109,  -109,   290,  -109,   232,  -109,
     241,  -109,  -109,  -109,     4,  -109,   203,   -97,  -108,  -109,
     -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    11,    12,    71,    47,    26,    27,    87,
      44,    45,    48,    49,    17,    30,    18,   116,    54,    68,
      69,   188,    80,   207,     5,    70,    84,   109,   110,   170,
     111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     122,   138,   127,   128,   220,   158,   132,    52,    19,    14,
     131,   158,    58,     6,    13,   136,    16,    20,   168,   138,
     138,    32,   215,    13,    21,   133,   192,   156,   193,    16,
     162,   163,   164,   165,   158,   133,   221,    33,   134,   169,
     171,   172,   209,   158,   244,    35,    43,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    15,     8,
     147,   148,   149,   150,   189,    67,    34,   191,   158,    43,
      24,   149,   150,    25,   120,   200,   104,   121,   106,   107,
      67,    40,   108,   140,   141,   142,   143,   144,   145,   238,
      41,   239,     1,   146,   147,   148,   149,   150,     2,    28,
     211,    43,    29,    42,    38,   216,   217,    39,   204,    46,
     219,   160,   222,   104,   161,   106,   107,   229,   230,   108,
      36,   138,   138,    37,     7,     8,    50,   233,   234,     7,
       8,    53,   237,     9,     7,     8,    10,   158,     9,    59,
      55,    22,    60,   138,   251,    78,   250,    85,    79,    74,
      86,    76,   140,   141,   142,   143,   144,   145,    56,    57,
      63,   257,   146,   147,   148,   149,   150,   158,     7,     8,
      91,   114,    65,    92,   115,    66,   118,   208,   151,   119,
      77,   152,   140,   141,   142,   143,   144,   145,   133,    83,
      89,   157,   146,   147,   148,   149,   150,   158,     7,     8,
     223,    90,    65,   224,   112,    81,   113,   227,    61,    62,
     123,   129,   140,   141,   142,   143,   144,   145,    64,    62,
      73,    62,   146,   147,   148,   149,   150,   158,   154,    57,
     202,   203,   124,   135,   125,   126,   130,   247,   155,   174,
     186,   158,   140,   141,   142,   143,   144,   145,   187,   190,
     198,   199,   146,   147,   148,   149,   150,   158,   205,   206,
     210,   212,   214,   215,   213,   225,   226,   248,   236,   228,
     240,   245,   140,   141,   142,   143,   144,   145,   249,   252,
      93,   253,   146,   147,   148,   149,   150,    95,    96,   258,
      97,   254,   241,   242,    98,    99,   259,   255,   261,    23,
      51,   117,    75,   100,    72,   101,   102,    31,    88,    82,
     103,     0,   104,   105,   106,   107,    93,     0,   108,   153,
       0,     0,    94,    95,    96,     0,    97,     0,     0,     0,
      98,    99,     0,     0,     0,     0,     0,     0,     0,   100,
       0,   101,   102,     0,     0,     0,   103,     0,   104,   105,
     106,   107,    93,     0,   108,     0,     0,     0,   137,    95,
      96,     0,    97,     0,     0,     0,    98,    99,     0,     0,
       0,     0,     0,     0,     0,   100,     0,   101,   102,     0,
       0,    93,   103,     0,   104,   105,   106,   107,    95,    96,
     108,    97,     0,     0,     0,    98,    99,     0,     0,     0,
       0,     0,     0,     0,   100,   167,   101,   102,     0,     0,
      93,   103,     0,   104,   105,   106,   107,    95,    96,   108,
      97,     0,     0,     0,    98,    99,   243,     0,     0,     0,
       0,     0,     0,   100,     0,   101,   102,     0,     0,    93,
     103,     0,   104,   105,   106,   107,    95,    96,   108,    97,
       0,     0,   256,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   100,     0,   101,   102,     0,     0,    93,   103,
       0,   104,   105,   106,   107,    95,    96,   108,    97,     0,
       0,     0,    98,    99,     0,     0,     0,     0,     0,     0,
       0,   100,     0,   101,   102,     0,     0,    93,   103,     0,
     104,   105,   106,   107,    95,    96,   108,    97,     0,     0,
       0,   166,    99,     0,     0,     0,     0,     0,     0,     0,
     100,   158,   101,   102,     0,     0,     0,   103,     0,   104,
     105,   106,   107,     0,     0,   108,   140,   141,   142,   143,
     144,   145,     0,     0,   158,     0,   146,   147,   148,   149,
     150,     0,     0,     0,     0,     0,     0,     0,   173,   140,
     141,   142,   143,   144,   145,     0,     0,   158,     0,   146,
     147,   148,   149,   150,     0,     0,     0,     0,     0,     0,
       0,   195,   140,   141,   142,   143,   144,   145,     0,     0,
     158,     0,   146,   147,   148,   149,   150,     0,     0,     0,
       0,     0,     0,     0,   196,   140,   141,   142,   143,   144,
     145,     0,     0,   158,     0,   146,   147,   148,   149,   150,
       0,     0,     0,     0,     0,     0,     0,   197,   140,   141,
     142,   143,   144,   145,     0,     0,   158,     0,   146,   147,
     148,   149,   150,     0,     0,     0,     0,     0,     0,     0,
     231,   140,   141,   142,   143,   144,   145,     0,     0,   158,
       0,   146,   147,   148,   149,   150,     0,     0,     0,     0,
       0,     0,     0,   232,   140,   141,   142,   143,   144,   145,
     158,     0,     0,     0,   146,   147,   148,   149,   150,     0,
       0,     0,     0,     0,   159,   140,   141,   142,   143,   144,
     145,   158,     0,     0,     0,   146,   147,   148,   149,   150,
       0,     0,     0,     0,     0,   201,   140,   141,   142,   143,
     144,   145,   158,     0,     0,     0,   146,   147,   148,   149,
     150,     0,     0,     0,     0,     0,   218,   140,   141,   142,
     143,   144,   145,   158,     0,     0,     0,   146,   147,   148,
     149,   150,     0,     0,     0,     0,     0,   235,   140,   141,
     142,   143,   144,   145,   158,     0,     0,     0,   146,   147,
     148,   149,   150,     0,     0,     0,     0,     0,   246,   140,
     141,   142,   143,   144,   145,   139,     0,     0,     0,   146,
     147,   148,   149,   150,     0,     0,     0,     0,     0,   260,
     140,   141,   142,   143,   144,   145,   194,     0,     0,     0,
     146,   147,   148,   149,   150,     0,     0,     0,     0,     0,
       0,   140,   141,   142,   143,   144,   145,   158,     0,     0,
       0,   146,   147,   148,   149,   150,     0,     0,     0,     0,
       0,     0,   140,   141,   142,   143,   144,   145,   158,     0,
       0,     0,   146,   147,   148,   149,   150,     0,     0,     0,
       0,     0,     0,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       0,     0,     0,   146,   147,   148,   149,   150
};

static const yytype_int16 yycheck[] =
{
      93,   109,    99,   100,    15,     8,    15,    41,     4,     0,
     103,     8,    46,     5,     2,   108,     4,    44,    15,   127,
     128,    17,    21,    11,    39,    44,    45,   120,    47,    17,
     123,   124,   125,   126,     8,    44,    47,    45,    47,   132,
     133,   134,    45,     8,    43,    39,    34,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     3,     4,
      34,    35,    36,    37,   157,    53,    44,   160,     8,    57,
      36,    36,    37,    39,    36,   168,    38,    39,    40,    41,
      68,    39,    44,    23,    24,    25,    26,    27,    28,    45,
      44,    47,     3,    33,    34,    35,    36,    37,     9,    36,
     193,    89,    39,    49,    43,   198,   199,    46,    48,    44,
     203,    36,   205,    38,    39,    40,    41,   214,   215,    44,
      44,   229,   230,    47,     3,     4,    38,   220,   221,     3,
       4,     9,   225,     7,     3,     4,    10,     8,     7,    36,
      39,    10,    39,   251,   241,    36,   239,    36,    39,    39,
      39,    49,    23,    24,    25,    26,    27,    28,    45,    46,
      48,   254,    33,    34,    35,    36,    37,     8,     3,     4,
      43,    43,     7,    46,    46,    10,    36,    48,    36,    39,
      39,    39,    23,    24,    25,    26,    27,    28,    44,    11,
      44,    47,    33,    34,    35,    36,    37,     8,     3,     4,
      43,    39,     7,    46,    50,    10,    39,    48,    45,    46,
      44,    43,    23,    24,    25,    26,    27,    28,    45,    46,
      45,    46,    33,    34,    35,    36,    37,     8,    45,    46,
      45,    46,    44,    39,    44,    44,    43,    48,    39,    39,
      39,     8,    23,    24,    25,    26,    27,    28,    50,    39,
      44,    44,    33,    34,    35,    36,    37,     8,    15,    39,
      43,    39,    17,    21,    43,    47,    43,    48,    39,    45,
      43,    43,    23,    24,    25,    26,    27,    28,    43,    43,
       6,    43,    33,    34,    35,    36,    37,    13,    14,    45,
      16,    15,    18,    19,    20,    21,    43,    48,    43,    11,
      39,    89,    62,    29,    57,    31,    32,    17,    76,    68,
      36,    -1,    38,    39,    40,    41,     6,    -1,    44,   116,
      -1,    -1,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    31,    32,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    41,     6,    -1,    44,    -1,    -1,    -1,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,     6,    36,    -1,    38,    39,    40,    41,    13,    14,
      44,    16,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
       6,    36,    -1,    38,    39,    40,    41,    13,    14,    44,
      16,    -1,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,     6,
      36,    -1,    38,    39,    40,    41,    13,    14,    44,    16,
      -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    31,    32,    -1,    -1,     6,    36,
      -1,    38,    39,    40,    41,    13,    14,    44,    16,    -1,
      -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31,    32,    -1,    -1,     6,    36,    -1,
      38,    39,    40,    41,    13,    14,    44,    16,    -1,    -1,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,     8,    31,    32,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    41,    -1,    -1,    44,    23,    24,    25,    26,
      27,    28,    -1,    -1,     8,    -1,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    23,
      24,    25,    26,    27,    28,    -1,    -1,     8,    -1,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    23,    24,    25,    26,    27,    28,    -1,    -1,
       8,    -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    23,    24,    25,    26,    27,
      28,    -1,    -1,     8,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    23,    24,
      25,    26,    27,    28,    -1,    -1,     8,    -1,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    23,    24,    25,    26,    27,    28,    -1,    -1,     8,
      -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    23,    24,    25,    26,    27,    28,
       8,    -1,    -1,    -1,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    43,    23,    24,    25,    26,    27,
      28,     8,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    23,    24,    25,    26,
      27,    28,     8,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    23,    24,    25,
      26,    27,    28,     8,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    23,    24,
      25,    26,    27,    28,     8,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,    23,
      24,    25,    26,    27,    28,     8,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      23,    24,    25,    26,    27,    28,     8,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,     8,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,     8,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     9,    52,    53,    75,     5,     3,     4,     7,
      10,    54,    55,    57,     0,     3,    57,    65,    67,    75,
      44,    39,    10,    55,    36,    39,    58,    59,    36,    39,
      66,    67,    75,    45,    44,    39,    44,    47,    43,    46,
      39,    44,    49,    57,    61,    62,    44,    57,    63,    64,
      38,    59,    63,     9,    69,    39,    45,    46,    63,    36,
      39,    45,    46,    48,    45,     7,    10,    57,    70,    71,
      76,    56,    62,    45,    39,    64,    49,    39,    36,    39,
      73,    10,    71,    11,    77,    36,    39,    60,    69,    44,
      39,    43,    46,     6,    12,    13,    14,    16,    20,    21,
      29,    31,    32,    36,    38,    39,    40,    41,    44,    78,
      79,    81,    50,    39,    43,    46,    68,    61,    36,    39,
      36,    39,    81,    44,    44,    44,    44,    78,    78,    43,
      43,    81,    15,    44,    47,    39,    81,    12,    79,     8,
      23,    24,    25,    26,    27,    28,    33,    34,    35,    36,
      37,    36,    39,    77,    45,    39,    81,    47,     8,    43,
      36,    39,    81,    81,    81,    81,    20,    30,    15,    81,
      80,    81,    81,    45,    39,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    39,    50,    72,    81,
      39,    81,    45,    47,     8,    45,    45,    45,    44,    44,
      81,    43,    45,    46,    48,    15,    39,    74,    48,    45,
      43,    81,    39,    43,    17,    21,    81,    81,    43,    81,
      15,    47,    81,    43,    46,    47,    43,    48,    45,    78,
      78,    45,    45,    81,    81,    43,    39,    81,    45,    47,
      43,    18,    19,    22,    43,    43,    43,    48,    48,    43,
      81,    78,    43,    43,    15,    48,    19,    81,    45,    43,
      43,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    55,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    60,    60,    60,    60,    61,    61,    62,    63,    63,
      63,    64,    64,    65,    65,    66,    66,    68,    67,    69,
      69,    69,    70,    70,    71,    72,    71,    73,    73,    73,
      73,    74,    74,    76,    75,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       0,     8,     1,     1,     3,     1,     1,     4,     4,     2,
       5,     3,     4,     1,     2,     3,     1,     2,     3,     1,
       0,     2,     3,     2,     1,     1,     2,     0,    10,     3,
       2,     0,     2,     1,     3,     0,     8,     3,     1,     4,
       2,     3,     1,     0,     9,     3,     2,     2,     1,     6,
       7,     5,    11,    10,     5,     8,     5,     4,     6,     7,
      10,     8,     8,     7,     7,     2,     2,     3,     3,     1,
       0,     2,     2,     7,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     4
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
#line 63 "exprtree.y"
                                           { 
                current_tuple_type = TupleInstall((yyvsp[-3].varname), (yyvsp[-1].FieldNode_ptr)); 
             }
#line 1698 "y.tab.c"
    break;

  case 12:
#line 68 "exprtree.y"
                 { current_type = TYPE_INT; }
#line 1704 "y.tab.c"
    break;

  case 13:
#line 69 "exprtree.y"
                 { current_type = TYPE_STR; }
#line 1710 "y.tab.c"
    break;

  case 16:
#line 74 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), current_type, 1, NULL, NULL); }
#line 1716 "y.tab.c"
    break;

  case 17:
#line 75 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), current_type, (yyvsp[-1].val), NULL, NULL); }
#line 1722 "y.tab.c"
    break;

  case 18:
#line 76 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), current_type, 0, (yyvsp[-1].param), NULL); }
#line 1728 "y.tab.c"
    break;

  case 19:
#line 77 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR, 1, NULL, NULL); }
#line 1734 "y.tab.c"
    break;

  case 20:
#line 78 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR, 0, (yyvsp[-1].param), NULL); }
#line 1740 "y.tab.c"
    break;

  case 21:
#line 82 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), TYPE_TUPLE, 1, NULL, current_tuple_type); }
#line 1746 "y.tab.c"
    break;

  case 22:
#line 83 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), TYPE_TUPLE, 1, NULL, current_tuple_type); }
#line 1752 "y.tab.c"
    break;

  case 23:
#line 84 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), TYPE_TUPLE, 1, NULL, current_tuple_type); }
#line 1758 "y.tab.c"
    break;

  case 24:
#line 85 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), TYPE_TUPLE, 1, NULL, current_tuple_type); }
#line 1764 "y.tab.c"
    break;

  case 25:
#line 89 "exprtree.y"
                                        {
                struct FieldNode *temp = (yyvsp[-2].FieldNode_ptr);
                while(temp->next != NULL) temp = temp->next;
                temp->next = (yyvsp[0].FieldNode_ptr);
                (yyval.FieldNode_ptr) = (yyvsp[-2].FieldNode_ptr);
            }
#line 1775 "y.tab.c"
    break;

  case 26:
#line 95 "exprtree.y"
                       { (yyval.FieldNode_ptr) = (yyvsp[0].FieldNode_ptr); }
#line 1781 "y.tab.c"
    break;

  case 27:
#line 98 "exprtree.y"
                      {
                struct FieldNode *f = (struct FieldNode *)malloc(sizeof(struct FieldNode));
                f->name = (yyvsp[0].varname);
                f->type = current_type;
                f->next = NULL;
                (yyval.FieldNode_ptr) = f;
            }
#line 1793 "y.tab.c"
    break;

  case 28:
#line 107 "exprtree.y"
                                 {
                struct ParamNode *temp = (yyvsp[-2].param);
                while(temp->next != NULL) temp = temp->next;
                temp->next = (yyvsp[0].param);
                (yyval.param) = (yyvsp[-2].param);
           }
#line 1804 "y.tab.c"
    break;

  case 29:
#line 113 "exprtree.y"
                   { (yyval.param) = (yyvsp[0].param); }
#line 1810 "y.tab.c"
    break;

  case 30:
#line 114 "exprtree.y"
                         { (yyval.param) = NULL; }
#line 1816 "y.tab.c"
    break;

  case 31:
#line 117 "exprtree.y"
                     {
                struct ParamNode *temp = (struct ParamNode *)malloc(sizeof(struct ParamNode));
                temp->name = (yyvsp[0].varname);
                temp->type = current_type;
                temp->next = NULL;
                (yyval.param) = temp;
           }
#line 1828 "y.tab.c"
    break;

  case 32:
#line 124 "exprtree.y"
                         {
                struct ParamNode *temp = (struct ParamNode *)malloc(sizeof(struct ParamNode));
                temp->name = (yyvsp[0].varname);
                temp->type = (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR;
                temp->next = NULL;
                (yyval.param) = temp;
           }
#line 1840 "y.tab.c"
    break;

  case 35:
#line 138 "exprtree.y"
                { 
                current_func_type = current_type; 
                (yyval.varname) = (yyvsp[0].varname); 
           }
#line 1849 "y.tab.c"
    break;

  case 36:
#line 142 "exprtree.y"
                    { 
                current_func_type = (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR; 
                (yyval.varname) = (yyvsp[0].varname); 
           }
#line 1858 "y.tab.c"
    break;

  case 37:
#line 148 "exprtree.y"
                                                            {
                /* MID-RULE ACTION: Execute this BEFORE parsing Body */
                struct GST_Node *g = GLookup((yyvsp[-5].varname));
                if (g == NULL) { 
                    printf("Semantic Error: Function '%s' not declared.\n", (yyvsp[-5].varname)); 
                    exit(1); 
                }

                if (g->type != current_func_type) {
                    printf("Semantic Error: Return type mismatch for function '%s'.\n", (yyvsp[-5].varname));
                    exit(1);
                }
                
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

                InstallParameters((yyvsp[-3].param));
                
           }
#line 1902 "y.tab.c"
    break;

  case 38:
#line 186 "exprtree.y"
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
                
                if ((yyvsp[-1].no) != NULL) codeGen((yyvsp[-1].no));
                
                LST_reset(); 
           }
#line 1924 "y.tab.c"
    break;

  case 45:
#line 211 "exprtree.y"
                                           { 
                current_tuple_type = TupleInstall((yyvsp[-3].varname), (yyvsp[-1].FieldNode_ptr)); 
             }
#line 1932 "y.tab.c"
    break;

  case 47:
#line 217 "exprtree.y"
                                     { LInstall((yyvsp[0].varname), current_type, local_binding++, NULL); }
#line 1938 "y.tab.c"
    break;

  case 48:
#line 218 "exprtree.y"
                                     { LInstall((yyvsp[0].varname), current_type, local_binding++, NULL); }
#line 1944 "y.tab.c"
    break;

  case 49:
#line 219 "exprtree.y"
                                     { LInstall((yyvsp[0].varname), (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR, local_binding++, NULL); }
#line 1950 "y.tab.c"
    break;

  case 50:
#line 220 "exprtree.y"
                                     { LInstall((yyvsp[0].varname), (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR, local_binding++, NULL); }
#line 1956 "y.tab.c"
    break;

  case 51:
#line 224 "exprtree.y"
                                 { 
                LInstall((yyvsp[0].varname), TYPE_TUPLE, local_binding, current_tuple_type); 
                local_binding += current_tuple_type->size; 
            }
#line 1965 "y.tab.c"
    break;

  case 52:
#line 228 "exprtree.y"
                 { 
                LInstall((yyvsp[0].varname), TYPE_TUPLE, local_binding, current_tuple_type); 
                local_binding += current_tuple_type->size; 
            }
#line 1974 "y.tab.c"
    break;

  case 53:
#line 237 "exprtree.y"
                                             {
                current_func_type = TYPE_INT; 
           }
#line 1982 "y.tab.c"
    break;

  case 54:
#line 239 "exprtree.y"
                      {
           
                fprintf(target_file, "MAIN:\n");
                fprintf(target_file, "PUSH BP\n");
                fprintf(target_file, "MOV BP, SP\n");
                
                int num_locals = local_binding - 1;
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "PUSH R0\n");
                }

                if ((yyvsp[-1].no) != NULL) codeGen((yyvsp[-1].no));

                LST_reset();
           }
#line 2002 "y.tab.c"
    break;

  case 55:
#line 256 "exprtree.y"
                                     { (yyval.no) = (yyvsp[-1].no); }
#line 2008 "y.tab.c"
    break;

  case 56:
#line 257 "exprtree.y"
                                     { (yyval.no) = NULL; }
#line 2014 "y.tab.c"
    break;

  case 57:
#line 260 "exprtree.y"
                   { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_CONN, (yyvsp[-1].no), (yyvsp[0].no)); }
#line 2020 "y.tab.c"
    break;

  case 58:
#line 261 "exprtree.y"
                   { (yyval.no) = (yyvsp[0].no); }
#line 2026 "y.tab.c"
    break;

  case 59:
#line 264 "exprtree.y"
                                 { 
            struct tnode *ptrNode = createTree(0, TYPE_INT, NULL, NODE_PTR_DEREF, (yyvsp[-2].no), NULL);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_READ, ptrNode, NULL); 
       }
#line 2035 "y.tab.c"
    break;

  case 60:
#line 269 "exprtree.y"
                                    {
            if ((yyvsp[-4].no)->type != TYPE_TUPLE) {
                printf("Semantic Error: Left of '.' is not a tuple.\n"); exit(1);
            }
            struct FieldNode *f = GetField((yyvsp[-4].no)->tuptype, (yyvsp[-2].varname));
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist.\n", (yyvsp[-2].varname)); exit(1);
            }
            struct tnode *fieldNode = createTree(f->offset, f->type, NULL, NODE_FIELD, (yyvsp[-4].no), NULL);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_READ, fieldNode, NULL);
       }
#line 2051 "y.tab.c"
    break;

  case 61:
#line 280 "exprtree.y"
                                { 
            struct tnode *ptrNode = createTree(0, TYPE_INT, NULL, NODE_PTR_DEREF, (yyvsp[-3].no), NULL);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, ptrNode, (yyvsp[-1].no)); 
       }
#line 2060 "y.tab.c"
    break;

  case 62:
#line 284 "exprtree.y"
                                                     { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-8].varname), NODE_VAR, NULL, NULL);
            struct tnode *idxNode = createTree(0, TYPE_INT, NULL, NODE_INDEX, (yyvsp[-6].no), (yyvsp[-3].no)); 
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY_2D, varNode, idxNode);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_READ, arrNode, NULL); 
       }
#line 2071 "y.tab.c"
    break;

  case 63:
#line 290 "exprtree.y"
                                                    { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-9].varname), NODE_VAR, NULL, NULL);
            struct tnode *idxNode = createTree(0, TYPE_INT, NULL, NODE_INDEX, (yyvsp[-7].no), (yyvsp[-4].no));
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY_2D, varNode, idxNode);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, arrNode, (yyvsp[-1].no)); 
       }
#line 2082 "y.tab.c"
    break;

  case 64:
#line 296 "exprtree.y"
                           { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-2].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_READ, varNode, NULL); 
       }
#line 2091 "y.tab.c"
    break;

  case 65:
#line 300 "exprtree.y"
                                        { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-5].varname), NODE_VAR, NULL, NULL);
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY, varNode, (yyvsp[-3].no));
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_READ, arrNode, NULL); 
       }
#line 2101 "y.tab.c"
    break;

  case 66:
#line 305 "exprtree.y"
                              { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_WRITE, (yyvsp[-2].no), NULL); }
#line 2107 "y.tab.c"
    break;

  case 67:
#line 308 "exprtree.y"
                          { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, varNode, (yyvsp[-1].no)); 
       }
#line 2116 "y.tab.c"
    break;

  case 68:
#line 314 "exprtree.y"
                                   {
            if ((yyvsp[-5].no)->type != TYPE_TUPLE) {
                printf("Semantic Error: Left of '.' is not a tuple.\n"); exit(1);
            }
            struct FieldNode *f = GetField((yyvsp[-5].no)->tuptype, (yyvsp[-3].varname));
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist.\n", (yyvsp[-3].varname)); exit(1);
            }
            struct tnode *fieldNode = createTree(f->offset, f->type, NULL, NODE_FIELD, (yyvsp[-5].no), NULL);
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, fieldNode, (yyvsp[-1].no));
       }
#line 2132 "y.tab.c"
    break;

  case 69:
#line 326 "exprtree.y"
                                       { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-6].varname), NODE_VAR, NULL, NULL);
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY, varNode, (yyvsp[-4].no));
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, arrNode, (yyvsp[-1].no)); 
       }
#line 2142 "y.tab.c"
    break;

  case 70:
#line 331 "exprtree.y"
                                                       { 
            struct tnode *then_else = createTree(0, TYPE_VOID, NULL, NODE_CONN, (yyvsp[-4].no), (yyvsp[-2].no));
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_IF_ELSE, (yyvsp[-7].no), then_else); 
       }
#line 2151 "y.tab.c"
    break;

  case 71:
#line 335 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_IF, (yyvsp[-5].no), (yyvsp[-2].no)); }
#line 2157 "y.tab.c"
    break;

  case 72:
#line 336 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_WHILE, (yyvsp[-5].no), (yyvsp[-2].no)); }
#line 2163 "y.tab.c"
    break;

  case 73:
#line 337 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_DO_WHILE, (yyvsp[-2].no), (yyvsp[-5].no)); }
#line 2169 "y.tab.c"
    break;

  case 74:
#line 338 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_REPEAT_UNTIL, (yyvsp[-2].no), (yyvsp[-5].no)); }
#line 2175 "y.tab.c"
    break;

  case 75:
#line 339 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_BREAK, NULL, NULL); }
#line 2181 "y.tab.c"
    break;

  case 76:
#line 340 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_CONTINUE, NULL, NULL); }
#line 2187 "y.tab.c"
    break;

  case 77:
#line 342 "exprtree.y"
                       {
            if ((yyvsp[-1].no)->type != current_func_type) {
                printf("Semantic Error: Return type mismatch. Expected %d, got %d.\n", current_func_type, (yyvsp[-1].no)->type);
                exit(1);
            }
            (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_RET, (yyvsp[-1].no), NULL);
       }
#line 2199 "y.tab.c"
    break;

  case 78:
#line 351 "exprtree.y"
                           {
            struct tnode *temp = (yyvsp[-2].no);
            while(temp->right != NULL) temp = temp->right;
            temp->right = createTree(0, TYPE_VOID, NULL, NODE_CONN, (yyvsp[0].no), NULL);
            (yyval.no) = (yyvsp[-2].no);
        }
#line 2210 "y.tab.c"
    break;

  case 79:
#line 357 "exprtree.y"
                           { (yyval.no) = createTree(0, TYPE_VOID, NULL, NODE_CONN, (yyvsp[0].no), NULL); }
#line 2216 "y.tab.c"
    break;

  case 80:
#line 358 "exprtree.y"
                           { (yyval.no) = NULL; }
#line 2222 "y.tab.c"
    break;

  case 81:
#line 361 "exprtree.y"
                            { 
            int base_type = ((yyvsp[0].no)->type == TYPE_INTPTR) ? TYPE_INT : TYPE_STR;
            (yyval.no) = createTree(0, base_type, NULL, NODE_PTR_DEREF, (yyvsp[0].no), NULL); 
       }
#line 2231 "y.tab.c"
    break;

  case 82:
#line 365 "exprtree.y"
              { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[0].varname), NODE_VAR, NULL, NULL);
            int ptr_type = (varNode->type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR;
            (yyval.no) = createTree(0, ptr_type, NULL, NODE_PTR_ADDR, varNode, NULL); 
       }
#line 2241 "y.tab.c"
    break;

  case 83:
#line 370 "exprtree.y"
                                    { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-6].varname), NODE_VAR, NULL, NULL);
            struct tnode *idxNode = createTree(0, TYPE_INT, NULL, NODE_INDEX, (yyvsp[-4].no), (yyvsp[-1].no));
            (yyval.no) = createTree(0, varNode->type, NULL, NODE_ARRAY_2D, varNode, idxNode); 
       }
#line 2251 "y.tab.c"
    break;

  case 84:
#line 377 "exprtree.y"
                   {
            if ((yyvsp[-2].no)->type != TYPE_TUPLE) {
                printf("Semantic Error: Left of '.' is not a tuple.\n"); exit(1);
            }
            struct FieldNode *f = GetField((yyvsp[-2].no)->tuptype, (yyvsp[0].varname));
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist.\n", (yyvsp[0].varname)); exit(1);
            }
            (yyval.no) = createTree(f->offset, f->type, NULL, NODE_FIELD, (yyvsp[-2].no), NULL);
       }
#line 2266 "y.tab.c"
    break;

  case 85:
#line 388 "exprtree.y"
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
#line 2297 "y.tab.c"
    break;

  case 86:
#line 415 "exprtree.y"
                        { (yyval.no) = createTree('+', TYPE_INT, NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2303 "y.tab.c"
    break;

  case 87:
#line 416 "exprtree.y"
                        { (yyval.no) = createTree('-', TYPE_INT, NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2309 "y.tab.c"
    break;

  case 88:
#line 417 "exprtree.y"
                        { (yyval.no) = createTree('*', TYPE_INT, NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2315 "y.tab.c"
    break;

  case 89:
#line 418 "exprtree.y"
                        { (yyval.no) = createTree('/', TYPE_INT, NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2321 "y.tab.c"
    break;

  case 90:
#line 419 "exprtree.y"
                        { (yyval.no) = createTree(LT, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2327 "y.tab.c"
    break;

  case 91:
#line 420 "exprtree.y"
                        { (yyval.no) = createTree(GT, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2333 "y.tab.c"
    break;

  case 92:
#line 421 "exprtree.y"
                        { (yyval.no) = createTree(LE, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2339 "y.tab.c"
    break;

  case 93:
#line 422 "exprtree.y"
                        { (yyval.no) = createTree(GE, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2345 "y.tab.c"
    break;

  case 94:
#line 423 "exprtree.y"
                        { (yyval.no) = createTree(EQ, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2351 "y.tab.c"
    break;

  case 95:
#line 424 "exprtree.y"
                        { (yyval.no) = createTree(NE, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2357 "y.tab.c"
    break;

  case 96:
#line 425 "exprtree.y"
                        { (yyval.no) = createTree(AND, TYPE_BOOL, NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2363 "y.tab.c"
    break;

  case 97:
#line 426 "exprtree.y"
                        { (yyval.no) = (yyvsp[-1].no); }
#line 2369 "y.tab.c"
    break;

  case 98:
#line 427 "exprtree.y"
                        { (yyval.no) = createTree((yyvsp[0].val), TYPE_INT, NULL, NODE_NUM, NULL, NULL); }
#line 2375 "y.tab.c"
    break;

  case 99:
#line 428 "exprtree.y"
                        { (yyval.no) = createTree(0, TYPE_STR, (yyvsp[0].varname), NODE_STR_VAL, NULL, NULL); }
#line 2381 "y.tab.c"
    break;

  case 100:
#line 429 "exprtree.y"
                        { (yyval.no) = createTree(0, 0, (yyvsp[0].varname), NODE_VAR, NULL, NULL); }
#line 2387 "y.tab.c"
    break;

  case 101:
#line 430 "exprtree.y"
                        { 
            struct tnode *varNode = createTree(0, 0, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, varNode->type, NULL, NODE_ARRAY, varNode, (yyvsp[-1].no)); 
       }
#line 2396 "y.tab.c"
    break;


#line 2400 "y.tab.c"

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
#line 435 "exprtree.y"


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
    
    /* XSM Header & Boot Sequence */
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(target_file, "JMP BOOT\n"); 
    
    yyparse();
    makeBootCode();
    return 0;
}
