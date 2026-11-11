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
/* Helper 1: Mangles names during Method Declarations (using ParamList) */
char* mangleDecl(char* base, struct ParamNode* p) {
    char *buffer = (char*)malloc(256);
    strcpy(buffer, base);
    struct ParamNode *curr = p;
    while(curr != NULL) {
        strcat(buffer, "_");
        strcat(buffer, curr->type->name);
        curr = curr->next;
    }
    return buffer;
}

/* Helper 2: Mangles names during Method Calls (using ArgList AST nodes) */
char* mangleCall(char* base, struct tnode* args) {
    char *buffer = (char*)malloc(256);
    strcpy(buffer, base);
    struct tnode *curr = args;
    while(curr != NULL) {
        /* Extract the actual argument node from the CONN wrapper */
        struct tnode *argNode = curr;
        if (curr->nodetype == NODE_CONN) argNode = curr->left;
        
        strcat(buffer, "_");
        if (argNode->type != NULL) strcat(buffer, argNode->type->name);
        else strcat(buffer, "unknown");
        
        if (curr->nodetype == NODE_CONN) curr = curr->right;
        else curr = NULL;
    }
    return buffer;
}

#line 129 "y.tab.c"

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
    EXTENDS = 263,
    INT = 264,
    STR = 265,
    MAIN = 266,
    RETURN = 267,
    TYPE = 268,
    ENDTYPE = 269,
    DECL = 270,
    ENDDECL = 271,
    BEGIN_TOK = 272,
    END_TOK = 273,
    READ = 274,
    WRITE = 275,
    ASSIGN = 276,
    IF = 277,
    THEN = 278,
    ELSE = 279,
    ENDIF = 280,
    WHILE = 281,
    DO = 282,
    ENDWHILE = 283,
    LT = 284,
    GT = 285,
    LE = 286,
    GE = 287,
    EQ = 288,
    NE = 289,
    REPEAT = 290,
    UNTIL = 291,
    CONTINUE = 292,
    BREAK = 293,
    FOR = 294,
    AND = 295,
    OR = 296,
    INIT = 297,
    ALLOC = 298,
    FREE = 299,
    NULL_TOK = 300,
    DOT = 301,
    PLUS = 302,
    MINUS = 303,
    MUL = 304,
    DIV = 305,
    MOD = 306,
    SUPER = 307,
    NOT = 308,
    TRUE = 309,
    FALSE = 310,
    INC = 311,
    DEC = 312,
    SWITCH = 313,
    CASE = 314,
    DEFAULT = 315,
    PLUS_EQ = 316,
    MINUS_EQ = 317,
    MUL_EQ = 318,
    DIV_EQ = 319,
    MOD_EQ = 320,
    NUM = 321,
    ID = 322,
    STRING = 323,
    USTAR = 324
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ENDCLASS 259
#define NEW 260
#define DELETE 261
#define SELF 262
#define EXTENDS 263
#define INT 264
#define STR 265
#define MAIN 266
#define RETURN 267
#define TYPE 268
#define ENDTYPE 269
#define DECL 270
#define ENDDECL 271
#define BEGIN_TOK 272
#define END_TOK 273
#define READ 274
#define WRITE 275
#define ASSIGN 276
#define IF 277
#define THEN 278
#define ELSE 279
#define ENDIF 280
#define WHILE 281
#define DO 282
#define ENDWHILE 283
#define LT 284
#define GT 285
#define LE 286
#define GE 287
#define EQ 288
#define NE 289
#define REPEAT 290
#define UNTIL 291
#define CONTINUE 292
#define BREAK 293
#define FOR 294
#define AND 295
#define OR 296
#define INIT 297
#define ALLOC 298
#define FREE 299
#define NULL_TOK 300
#define DOT 301
#define PLUS 302
#define MINUS 303
#define MUL 304
#define DIV 305
#define MOD 306
#define SUPER 307
#define NOT 308
#define TRUE 309
#define FALSE 310
#define INC 311
#define DEC 312
#define SWITCH 313
#define CASE 314
#define DEFAULT 315
#define PLUS_EQ 316
#define MINUS_EQ 317
#define MUL_EQ 318
#define DIV_EQ 319
#define MOD_EQ 320
#define NUM 321
#define ID 322
#define STRING 323
#define USTAR 324

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "exprtree.y"

    int val;
    char *varname;
    struct Typetable *type;
    struct Classtable *ctype;
    struct tnode *no;
    struct ParamNode *param;

#line 328 "y.tab.c"

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1109

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  322

#define YYUNDEFTOK  2
#define YYMAXUTOK   324


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
       2,     2,     2,     2,     2,     2,     2,     2,    71,     2,
      76,    77,     2,     2,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    70,    75,
       2,     2,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,     2,    74,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    72
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   114,   115,   118,   119,   122,   127,   131,
     138,   139,   142,   146,   153,   154,   157,   157,   210,   211,
     212,   215,   216,   219,   219,   226,   227,   230,   235,   236,
     237,   251,   252,   253,   256,   257,   260,   260,   262,   262,
     263,   264,   265,   266,   269,   275,   276,   279,   292,   293,
     296,   302,   302,   328,   328,   328,   329,   329,   330,   330,
     333,   341,   346,   354,   366,   366,   392,   393,   396,   397,
     400,   403,   404,   407,   410,   413,   417,   418,   419,   420,
     421,   422,   423,   426,   432,   437,   442,   446,   450,   454,
     458,   462,   467,   470,   475,   479,   485,   492,   493,   503,
     507,   523,   529,   530,   533,   534,   535,   536,   537,   538,
     554,   574,   584,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   621,   622,   623,   624,
     625,   630,   631,   632
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ENDCLASS", "NEW", "DELETE",
  "SELF", "EXTENDS", "INT", "STR", "MAIN", "RETURN", "TYPE", "ENDTYPE",
  "DECL", "ENDDECL", "BEGIN_TOK", "END_TOK", "READ", "WRITE", "ASSIGN",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "LT", "GT",
  "LE", "GE", "EQ", "NE", "REPEAT", "UNTIL", "CONTINUE", "BREAK", "FOR",
  "AND", "OR", "INIT", "ALLOC", "FREE", "NULL_TOK", "DOT", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "SUPER", "NOT", "TRUE", "FALSE", "INC", "DEC",
  "SWITCH", "CASE", "DEFAULT", "PLUS_EQ", "MINUS_EQ", "MUL_EQ", "DIV_EQ",
  "MOD_EQ", "NUM", "ID", "STRING", "'?'", "':'", "'&'", "USTAR", "'{'",
  "'}'", "';'", "'('", "')'", "','", "'['", "']'", "$accept", "Program",
  "ClassDefBlock", "ClassDefList", "ClassDef", "Cname", "ClassDeclList",
  "ClassDecl", "MethodDefList", "MethodDef", "$@1", "TypeDefBlock",
  "TypeDefList", "TypeDef", "$@2", "TypeFieldDeclList", "TypeFieldDecl",
  "TypeName", "GDeclBlock", "GDeclList", "GDecl", "$@3", "GVarList",
  "GVar", "ParamList", "Param", "FDefList", "FuncName", "FDef", "$@4",
  "LDeclBlock", "LDeclList", "LDecl", "$@5", "LVarList", "MainBlock",
  "$@6", "Body", "slist", "stmt", "CaseList", "CaseStmt", "Lvalue",
  "ArgList", "expr", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,    63,
      58,    38,   324,   123,   125,    59,    40,    41,    44,    91,
      93
};
# endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    -5,    47,    49,  -131,   -10,     6,  -131,  -131,    19,
      73,  -131,  -131,  -131,    85,     2,  -131,    93,     9,  -131,
    -131,    70,  -131,  -131,   141,  -131,  -131,  -131,  -131,  -131,
      51,  -131,     1,    -8,  -131,  -131,   -19,  -131,  -131,    17,
    -131,  -131,  -131,  -131,    91,    69,   106,   -40,   -32,  -131,
     104,  -131,   118,   107,  -131,  -131,   122,  -131,     1,   135,
    -131,   -19,   126,     1,  -131,    -2,   -34,   138,    65,  -131,
     128,  -131,   133,    71,  -131,  -131,   142,  -131,     1,  -131,
    -131,     1,  -131,   198,   145,   144,    83,  -131,    80,  -131,
     198,     1,   146,  -131,  -131,    88,  -131,   207,  -131,    87,
    -131,    67,  -131,  -131,   305,   151,   207,   157,   164,  -131,
      30,   156,  -131,   174,  -131,   159,   160,   161,   162,   475,
     475,   168,   169,   172,   175,     7,   176,   177,   339,  -131,
      89,  -131,   181,   198,  -131,  -131,    90,     7,   182,   183,
     184,  -131,   211,   174,  -131,  -131,  -131,    33,  -131,     7,
     174,     5,   746,     7,   174,   174,   174,   509,   373,  -131,
    -131,   475,     7,   215,   174,   174,  -131,  -131,   174,   196,
     192,   193,   174,   174,   174,   174,   174,  -131,  -131,   202,
    -131,    29,   203,   195,   197,   206,  1006,   174,   215,   553,
     174,   208,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,  -131,    34,   584,   607,
     638,   204,   205,   174,    61,   661,   530,   769,  -131,  -131,
    -131,   799,   822,   852,   875,   905,   207,  -131,   209,   210,
    -131,  -131,   212,    92,  1006,  -131,  1006,   213,  1052,  1052,
    1052,  1052,  1052,  1052,  1058,  1029,    64,    64,  -131,  -131,
    -131,   958,   217,   224,   256,   255,   174,   174,   928,   225,
     229,  -131,  -131,  -131,  -131,  -131,  -131,  -131,   230,  -131,
    -131,   174,  -131,   174,   174,   174,  -131,  -131,   475,   475,
     692,   715,   475,  -131,   112,  -131,    99,  1006,   113,  1006,
     271,   407,    -4,   228,   236,   174,   216,   231,   112,  -131,
    -131,   475,   232,   239,  -131,  -131,   243,   982,   475,  -131,
    -131,   441,  -131,  -131,   475,   475,   475,   244,   227,   475,
    -131,  -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      20,     0,     0,     4,    19,     0,     0,    22,     1,     0,
      33,    23,    18,    21,     8,     0,     6,     0,     0,    49,
      26,     0,     3,     5,     0,    28,    29,    32,    30,    36,
       0,    35,     0,     0,     9,    11,     0,    31,    34,     0,
      48,     2,    24,    25,     0,     0,     0,    40,     0,    39,
       0,    50,     0,     0,    15,    10,     0,    43,    46,     0,
      37,     0,     0,    46,    27,     0,     0,     0,     0,    45,
       0,    38,     0,     0,     7,    14,     0,    12,    46,    47,
      42,     0,    41,    55,     0,     0,     0,    44,     0,    64,
      55,    46,     0,    54,    58,     0,    57,     0,    51,     0,
      13,     0,    53,    56,     0,     0,     0,     0,     0,    62,
       0,     0,    98,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,     0,    69,
       0,    65,     0,    55,    63,    59,     0,     0,     0,     0,
       0,   108,     0,     0,   131,   132,   127,    96,   128,     0,
       0,   104,     0,     0,     0,     0,     0,     0,     0,    81,
      80,     0,     0,    97,     0,     0,    66,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    16,     0,
      60,     0,     0,     0,     0,     0,   129,   103,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,    84,
      85,     0,     0,     0,     0,     0,     0,    61,     0,     0,
     106,   107,     0,     0,   102,   126,   105,   100,   118,   119,
     120,   121,   122,   123,   124,   125,   113,   114,   115,   116,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,    72,    87,    88,    89,    90,    91,     0,    74,
     109,   103,   111,     0,   103,     0,    70,    71,     0,     0,
       0,     0,     0,    73,     0,    17,     0,   101,     0,   130,
       0,     0,     0,     0,     0,     0,     0,     0,    93,   112,
     110,     0,     0,     0,    78,    79,     0,     0,     0,    86,
      92,     0,    76,    77,     0,     0,    95,     0,     0,    94,
      75,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -131,   303,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,   315,  -131,  -131,  -131,    -1,  -131,  -131,
     292,  -131,  -131,   265,   -41,   247,  -131,  -131,  -131,  -131,
     -78,  -131,   235,  -131,  -131,  -131,  -131,   -93,  -116,  -123,
      35,  -131,  -104,  -130,   -73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    15,    16,    17,    45,    55,    65,    75,
     226,     3,     6,     7,    20,    33,    43,    67,    19,    30,
      31,    36,    48,    49,    68,    69,    32,    52,    40,   106,
      89,    95,    96,   101,   110,    41,    97,   105,   128,   129,
     297,   298,   151,   233,   234
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     130,    25,    26,   157,   158,   167,    22,    25,    26,     4,
      25,    26,    98,   132,   112,   130,   130,    29,    25,    26,
      12,   163,    73,   279,   130,    27,   190,     1,    50,    29,
      46,    39,    44,   181,   167,   167,    58,    86,   213,    59,
     152,    77,    78,    60,    56,   188,    61,     8,    47,   207,
      99,   191,     9,   130,   130,   178,   125,   130,   214,    28,
      25,    26,     5,    11,    76,    28,    42,    37,    28,    14,
     186,   304,    74,     5,   127,   169,    28,   189,    25,    26,
     169,   208,   209,   210,    51,    54,    14,    94,    18,    25,
      26,   215,   216,    21,    94,   217,    93,    25,    26,   221,
     222,   223,   224,   225,   102,   135,   228,   169,   136,   187,
     168,   252,   165,   202,   203,   204,   108,   236,    28,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   268,   109,   169,    28,    34,   259,   179,
     258,   286,    80,    81,   288,   170,   171,    28,    84,    81,
     172,   173,   174,   175,   176,    28,    35,   180,    53,   294,
      92,    81,   290,   291,   107,    81,    24,   167,   167,   272,
     273,   295,   296,    57,   130,   130,   299,   273,   130,   138,
      62,   112,    64,   280,   281,   311,   130,   130,   167,    66,
     300,   273,   316,   167,    63,   167,   167,   130,   318,   319,
     287,    70,   289,    72,   130,    79,    83,   130,    82,    85,
     130,   130,   130,    88,   130,   130,   139,   140,    90,   141,
      91,   100,   307,   125,   104,   131,   142,   143,   144,   145,
     133,   134,   137,   111,   112,   153,   154,   155,   156,   113,
     146,   147,   148,   159,   160,   149,   115,   116,   161,   117,
     150,   162,   164,   118,   119,   177,   165,   185,   182,   183,
     184,   169,   120,   218,   121,   122,   123,   219,   220,   227,
     229,   124,   230,   232,   231,   237,   125,   111,   112,   278,
     256,   257,   279,   113,   269,   126,   308,   270,   271,   274,
     115,   116,   276,   117,   127,   301,   302,   118,   119,   277,
     283,   321,   284,   305,   285,   309,   120,   312,   121,   122,
     123,   111,   112,   306,   313,   124,   314,   113,    23,   320,
     125,    13,    38,   114,   115,   116,    71,   117,    87,   126,
     103,   118,   119,   310,     0,     0,     0,     0,   127,     0,
     120,     0,   121,   122,   123,   111,   112,     0,     0,   124,
       0,   113,     0,     0,   125,     0,     0,   166,   115,   116,
       0,   117,     0,   126,     0,   118,   119,     0,     0,     0,
       0,     0,   127,     0,   120,     0,   121,   122,   123,   111,
     112,     0,     0,   124,     0,   113,     0,     0,   125,     0,
       0,     0,   115,   116,     0,   117,     0,   126,     0,   118,
     119,     0,     0,     0,     0,     0,   127,     0,   120,   212,
     121,   122,   123,   111,   112,     0,     0,   124,     0,   113,
       0,     0,   125,     0,     0,     0,   115,   116,     0,   117,
       0,   126,     0,   118,   119,   303,     0,     0,     0,     0,
     127,     0,   120,     0,   121,   122,   123,   111,   112,     0,
       0,   124,     0,   113,     0,     0,   125,     0,     0,     0,
     115,   116,     0,   117,     0,   126,   317,   118,   119,     0,
       0,     0,     0,     0,   127,     0,   120,     0,   121,   122,
     123,   111,   112,     0,     0,   124,     0,   113,     0,     0,
     125,     0,     0,     0,   115,   116,     0,   117,     0,   126,
       0,   118,   119,     0,     0,     0,     0,     0,   127,     0,
     120,     0,   121,   122,   123,   111,   112,     0,     0,   124,
       0,   113,     0,     0,   125,     0,     0,     0,   115,   116,
       0,   117,     0,   126,     0,   211,   119,     0,     0,     0,
       0,     0,   127,     0,   120,     0,   121,   122,   123,     0,
       0,     0,     0,   124,     0,     0,     0,     0,   125,   192,
     193,   194,   195,   196,   197,     0,     0,   126,     0,     0,
     198,   199,     0,     0,     0,     0,   127,   200,   201,   202,
     203,   204,   192,   193,   194,   195,   196,   197,     0,     0,
       0,     0,     0,   198,   199,     0,     0,     0,     0,   205,
     200,   201,   202,   203,   204,     0,     0,     0,     0,     0,
     261,     0,     0,   192,   193,   194,   195,   196,   197,     0,
       0,     0,   205,     0,   198,   199,     0,     0,     0,     0,
     235,   200,   201,   202,   203,   204,   192,   193,   194,   195,
     196,   197,     0,     0,     0,     0,     0,   198,   199,     0,
       0,     0,     0,   205,   200,   201,   202,   203,   204,     0,
       0,   253,     0,     0,     0,     0,     0,   192,   193,   194,
     195,   196,   197,     0,     0,     0,   205,     0,   198,   199,
       0,     0,     0,     0,   254,   200,   201,   202,   203,   204,
     192,   193,   194,   195,   196,   197,     0,     0,     0,     0,
       0,   198,   199,     0,     0,     0,     0,   205,   200,   201,
     202,   203,   204,     0,     0,   255,     0,     0,     0,     0,
       0,   192,   193,   194,   195,   196,   197,     0,     0,     0,
     205,     0,   198,   199,     0,     0,     0,     0,   260,   200,
     201,   202,   203,   204,   192,   193,   194,   195,   196,   197,
       0,     0,     0,     0,     0,   198,   199,     0,     0,     0,
       0,   205,   200,   201,   202,   203,   204,     0,     0,   292,
       0,     0,     0,     0,     0,   192,   193,   194,   195,   196,
     197,     0,     0,     0,   205,     0,   198,   199,     0,     0,
       0,     0,   293,   200,   201,   202,   203,   204,   192,   193,
     194,   195,   196,   197,     0,     0,     0,     0,     0,   198,
     199,     0,     0,     0,     0,   205,   200,   201,   202,   203,
     204,   206,     0,     0,     0,     0,     0,     0,   192,   193,
     194,   195,   196,   197,     0,     0,     0,     0,   205,   198,
     199,     0,     0,     0,   262,     0,   200,   201,   202,   203,
     204,   192,   193,   194,   195,   196,   197,     0,     0,     0,
       0,     0,   198,   199,     0,     0,     0,     0,   205,   200,
     201,   202,   203,   204,   263,     0,     0,     0,     0,     0,
       0,   192,   193,   194,   195,   196,   197,     0,     0,     0,
       0,   205,   198,   199,     0,     0,     0,   264,     0,   200,
     201,   202,   203,   204,   192,   193,   194,   195,   196,   197,
       0,     0,     0,     0,     0,   198,   199,     0,     0,     0,
       0,   205,   200,   201,   202,   203,   204,   265,     0,     0,
       0,     0,     0,     0,   192,   193,   194,   195,   196,   197,
       0,     0,     0,     0,   205,   198,   199,     0,     0,     0,
     266,     0,   200,   201,   202,   203,   204,   192,   193,   194,
     195,   196,   197,     0,     0,     0,     0,     0,   198,   199,
       0,     0,     0,     0,   205,   200,   201,   202,   203,   204,
     267,     0,     0,     0,     0,     0,     0,   192,   193,   194,
     195,   196,   197,     0,     0,     0,     0,   205,   198,   199,
       0,     0,     0,   282,     0,   200,   201,   202,   203,   204,
       0,   192,   193,   194,   195,   196,   197,     0,     0,     0,
       0,     0,   198,   199,     0,     0,     0,   205,   275,   200,
     201,   202,   203,   204,     0,   192,   193,   194,   195,   196,
     197,     0,     0,     0,     0,     0,   198,   199,     0,     0,
       0,   205,   315,   200,   201,   202,   203,   204,   192,   193,
     194,   195,   196,   197,     0,     0,     0,     0,     0,   198,
       0,     0,     0,     0,     0,   205,   200,   201,   202,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,
     195,   196,   197,     0,     0,     0,     0,     0,     0,   200,
     201,   202,   203,   204,     0,   200,   201,   202,   203,   204
};

static const yytype_int16 yycheck[] =
{
     104,     9,    10,   119,   120,   128,     4,     9,    10,    14,
       9,    10,    90,   106,     7,   119,   120,    18,     9,    10,
      14,   125,    63,    27,   128,    16,    21,    13,    11,    30,
      49,    32,    33,   137,   157,   158,    76,    78,   161,    79,
     113,    75,    76,    75,    45,   149,    78,     0,    67,   153,
      91,    46,     3,   157,   158,   133,    49,   161,   162,    67,
       9,    10,    67,    73,    65,    67,    74,    16,    67,    67,
     143,    75,    74,    67,    67,    46,    67,   150,     9,    10,
      46,   154,   155,   156,    67,    16,    67,    88,    15,     9,
      10,   164,   165,     8,    95,   168,    16,     9,    10,   172,
     173,   174,   175,   176,    16,    75,    77,    46,    78,    76,
      21,    77,    79,    49,    50,    51,    49,   190,    67,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   226,    67,    46,    67,    67,    77,    49,
     213,   271,    77,    78,   274,    56,    57,    67,    77,    78,
      61,    62,    63,    64,    65,    67,    15,    67,    67,   282,
      77,    78,   278,   279,    77,    78,    73,   290,   291,    77,
      78,    59,    60,    67,   278,   279,    77,    78,   282,     5,
      76,     7,    75,   256,   257,   301,   290,   291,   311,    67,
      77,    78,   308,   316,    76,   318,   319,   301,   314,   315,
     273,    66,   275,    77,   308,    67,    73,   311,    80,    67,
     314,   315,   316,    15,   318,   319,    42,    43,    73,    45,
      76,    75,   295,    49,    17,    74,    52,    53,    54,    55,
      73,    67,    76,     6,     7,    76,    76,    76,    76,    12,
      66,    67,    68,    75,    75,    71,    19,    20,    76,    22,
      76,    76,    76,    26,    27,    74,    79,    46,    76,    76,
      76,    46,    35,    67,    37,    38,    39,    75,    75,    67,
      67,    44,    77,    67,    77,    67,    49,     6,     7,    23,
      76,    76,    27,    12,    75,    58,    70,    77,    76,    76,
      19,    20,    75,    22,    67,    24,    25,    26,    27,    75,
      75,    74,    73,    75,    74,    74,    35,    75,    37,    38,
      39,     6,     7,    77,    75,    44,    73,    12,    15,    75,
      49,     6,    30,    18,    19,    20,    61,    22,    81,    58,
      95,    26,    27,   298,    -1,    -1,    -1,    -1,    67,    -1,
      35,    -1,    37,    38,    39,     6,     7,    -1,    -1,    44,
      -1,    12,    -1,    -1,    49,    -1,    -1,    18,    19,    20,
      -1,    22,    -1,    58,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    35,    -1,    37,    38,    39,     6,
       7,    -1,    -1,    44,    -1,    12,    -1,    -1,    49,    -1,
      -1,    -1,    19,    20,    -1,    22,    -1,    58,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    67,    -1,    35,    36,
      37,    38,    39,     6,     7,    -1,    -1,    44,    -1,    12,
      -1,    -1,    49,    -1,    -1,    -1,    19,    20,    -1,    22,
      -1,    58,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,
      67,    -1,    35,    -1,    37,    38,    39,     6,     7,    -1,
      -1,    44,    -1,    12,    -1,    -1,    49,    -1,    -1,    -1,
      19,    20,    -1,    22,    -1,    58,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    35,    -1,    37,    38,
      39,     6,     7,    -1,    -1,    44,    -1,    12,    -1,    -1,
      49,    -1,    -1,    -1,    19,    20,    -1,    22,    -1,    58,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      35,    -1,    37,    38,    39,     6,     7,    -1,    -1,    44,
      -1,    12,    -1,    -1,    49,    -1,    -1,    -1,    19,    20,
      -1,    22,    -1,    58,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    35,    -1,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,    29,
      30,    31,    32,    33,    34,    -1,    -1,    58,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    67,    47,    48,    49,
      50,    51,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    69,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    69,    -1,    40,    41,    -1,    -1,    -1,    -1,
      77,    47,    48,    49,    50,    51,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    69,    47,    48,    49,    50,    51,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    69,    -1,    40,    41,
      -1,    -1,    -1,    -1,    77,    47,    48,    49,    50,    51,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    69,    47,    48,
      49,    50,    51,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      69,    -1,    40,    41,    -1,    -1,    -1,    -1,    77,    47,
      48,    49,    50,    51,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    69,    47,    48,    49,    50,    51,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    69,    -1,    40,    41,    -1,    -1,
      -1,    -1,    77,    47,    48,    49,    50,    51,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    69,    47,    48,    49,    50,
      51,    75,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    69,    40,
      41,    -1,    -1,    -1,    75,    -1,    47,    48,    49,    50,
      51,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    69,    47,
      48,    49,    50,    51,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    69,    40,    41,    -1,    -1,    -1,    75,    -1,    47,
      48,    49,    50,    51,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    69,    47,    48,    49,    50,    51,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    69,    40,    41,    -1,    -1,    -1,
      75,    -1,    47,    48,    49,    50,    51,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    69,    47,    48,    49,    50,    51,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    69,    40,    41,
      -1,    -1,    -1,    75,    -1,    47,    48,    49,    50,    51,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    69,    70,    47,
      48,    49,    50,    51,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    69,    70,    47,    48,    49,    50,    51,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    69,    47,    48,    49,    50,
      51,    29,    30,    31,    32,    33,    34,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    -1,    47,    48,    49,    50,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    82,    92,    14,    67,    93,    94,     0,     3,
      83,    73,    14,    94,    67,    84,    85,    86,    15,    99,
      95,     8,     4,    85,    73,     9,    10,    16,    67,    98,
     100,   101,   107,    96,    67,    15,   102,    16,   101,    98,
     109,   116,    74,    97,    98,    87,    49,    67,   103,   104,
      11,    67,   108,    67,    16,    88,    98,    67,    76,    79,
      75,    78,    76,    76,    75,    89,    67,    98,   105,   106,
      66,   104,    77,   105,    74,    90,    98,    75,    76,    67,
      77,    78,    80,    73,    77,    67,   105,   106,    15,   111,
      73,    76,    77,    16,    98,   112,   113,   117,   111,   105,
      75,   114,    16,   113,    17,   118,   110,    77,    49,    67,
     115,     6,     7,    12,    18,    19,    20,    22,    26,    27,
      35,    37,    38,    39,    44,    49,    58,    67,   119,   120,
     123,    74,   118,    73,    67,    75,    78,    76,     5,    42,
      43,    45,    52,    53,    54,    55,    66,    67,    68,    71,
      76,   123,   125,    76,    76,    76,    76,   119,   119,    75,
      75,    76,    76,   123,    76,    79,    18,   120,    21,    46,
      56,    57,    61,    62,    63,    64,    65,    74,   111,    49,
      67,   123,    76,    76,    76,    46,   125,    76,   123,   125,
      21,    46,    29,    30,    31,    32,    33,    34,    40,    41,
      47,    48,    49,    50,    51,    69,    75,   123,   125,   125,
     125,    26,    36,   120,   123,   125,   125,   125,    67,    75,
      75,   125,   125,   125,   125,   125,    91,    67,    77,    67,
      77,    77,    67,   124,   125,    77,   125,    67,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,    77,    77,    77,    77,    76,    76,   125,    77,
      77,    80,    75,    75,    75,    75,    75,    75,   118,    75,
      77,    76,    77,    78,    76,    70,    75,    75,    23,    27,
     125,   125,    75,    75,    73,    74,   124,   125,   124,   125,
     119,   119,    77,    77,   120,    59,    60,   121,   122,    77,
      77,    24,    25,    28,    75,    75,    77,   125,    70,    74,
     121,   119,    75,    75,    73,    70,   119,    25,   119,   119,
      75,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    81,    82,    83,    83,    84,    84,    85,    86,    86,
      87,    87,    88,    88,    89,    89,    91,    90,    92,    92,
      92,    93,    93,    95,    94,    96,    96,    97,    98,    98,
      98,    99,    99,    99,   100,   100,   102,   101,   103,   103,
     104,   104,   104,   104,   105,   105,   105,   106,   107,   107,
     108,   110,   109,   111,   111,   111,   112,   112,   114,   113,
     115,   115,   115,   115,   117,   116,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   121,   121,   122,   122,   123,   123,   123,   123,
     123,   124,   124,   124,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     1,     7,     1,     3,
       2,     0,     3,     6,     2,     0,     0,    10,     3,     2,
       0,     2,     1,     0,     5,     2,     0,     3,     1,     1,
       1,     3,     2,     0,     2,     1,     0,     4,     3,     1,
       1,     4,     4,     2,     3,     1,     0,     2,     2,     0,
       1,     0,    10,     3,     2,     0,     2,     1,     0,     4,
       3,     4,     1,     2,     0,     9,     3,     2,     2,     1,
       5,     5,     4,     5,     5,    10,     8,     8,     7,     7,
       2,     2,     3,    10,     3,     3,     7,     4,     4,     4,
       4,     4,     2,     1,     4,     3,     1,     2,     1,     4,
       3,     3,     1,     0,     1,     3,     3,     3,     1,     4,
       6,     4,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       5,     1,     1,     2
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
#line 122 "exprtree.y"
                                                                       {
                    Cptr = NULL;
              }
#line 1886 "y.tab.c"
    break;

  case 8:
#line 127 "exprtree.y"
                   {
                    Cptr = CInstall((yyvsp[0].varname), NULL);
                    (yyval.ctype) = Cptr;
              }
#line 1895 "y.tab.c"
    break;

  case 9:
#line 131 "exprtree.y"
                              {
                    Cptr = CInstall((yyvsp[-2].varname), (yyvsp[0].varname));
                    (yyval.ctype) = Cptr;
              }
#line 1904 "y.tab.c"
    break;

  case 12:
#line 142 "exprtree.y"
                                {
                    ClassFInstall(Cptr, (yyvsp[-2].type), (yyvsp[-1].varname));
              }
#line 1912 "y.tab.c"
    break;

  case 13:
#line 146 "exprtree.y"
                                                  {
                char *mangled = mangleDecl((yyvsp[-4].varname), (yyvsp[-2].param));
                ClassMInstall(Cptr, mangled, (yyvsp[-5].type), (yyvsp[-2].param));
                }
#line 1921 "y.tab.c"
    break;

  case 16:
#line 157 "exprtree.y"
                                                             {
                    char *mangled = mangleDecl((yyvsp[-5].varname), (yyvsp[-3].param));
                    struct Memberfunclist *m = ClassMLookup(Cptr, mangled);
                    
                    if (m == NULL) {
                        printf("Semantic Error: Method '%s' not declared in class.\n", mangled);
                        exit(1);
                    }
                    if (m->type != (yyvsp[-6].type)) {
                        printf("Semantic Error: Return type mismatch for method '%s'.\n", mangled);
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
#line 1951 "y.tab.c"
    break;

  case 17:
#line 181 "exprtree.y"
                         {
              
                    char *mangled = mangleDecl((yyvsp[-8].varname), (yyvsp[-6].param));
                    struct Memberfunclist *m = ClassMLookup(Cptr, mangled);

                    if (m == NULL) {
                        printf("Compiler Error: Method definition not found: %s\n", mangled);
                        exit(1);
                    }
                    
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
#line 1979 "y.tab.c"
    break;

  case 23:
#line 219 "exprtree.y"
                      {
                curr_type_defining = TInstall((yyvsp[-1].varname), 0, NULL);
             }
#line 1987 "y.tab.c"
    break;

  case 24:
#line 221 "exprtree.y"
                                     {
                curr_type_defining = NULL;
             }
#line 1995 "y.tab.c"
    break;

  case 27:
#line 230 "exprtree.y"
                                    {
                    FInstall(curr_type_defining, (yyvsp[-1].varname), (yyvsp[-2].type)->name);
                  }
#line 2003 "y.tab.c"
    break;

  case 28:
#line 235 "exprtree.y"
                     { (yyval.type) = TLookup("int"); }
#line 2009 "y.tab.c"
    break;

  case 29:
#line 236 "exprtree.y"
                     { (yyval.type) = TLookup("str"); }
#line 2015 "y.tab.c"
    break;

  case 30:
#line 237 "exprtree.y"
                     { 
                  struct Typetable *t = TLookup((yyvsp[0].varname));
                  if (!t) {
                      printf("Semantic Error: Unknown type '%s'.\n", (yyvsp[0].varname));
                      exit(1);
                  }
                  (yyval.type) = t;
              }
#line 2028 "y.tab.c"
    break;

  case 36:
#line 260 "exprtree.y"
                      { current_type = (yyvsp[0].type); }
#line 2034 "y.tab.c"
    break;

  case 40:
#line 263 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), current_type, 1, NULL); }
#line 2040 "y.tab.c"
    break;

  case 41:
#line 264 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), current_type, (yyvsp[-1].val), NULL); }
#line 2046 "y.tab.c"
    break;

  case 42:
#line 265 "exprtree.y"
                                     { GInstall((yyvsp[-3].varname), current_type, 0, (yyvsp[-1].param)); }
#line 2052 "y.tab.c"
    break;

  case 43:
#line 266 "exprtree.y"
                                     { GInstall((yyvsp[0].varname), current_type, 1, NULL); }
#line 2058 "y.tab.c"
    break;

  case 44:
#line 269 "exprtree.y"
                                 {
                struct ParamNode *temp = (yyvsp[-2].param);
                while(temp->next != NULL) temp = temp->next;
                temp->next = (yyvsp[0].param);
                (yyval.param) = (yyvsp[-2].param);
           }
#line 2069 "y.tab.c"
    break;

  case 45:
#line 275 "exprtree.y"
                   { (yyval.param) = (yyvsp[0].param); }
#line 2075 "y.tab.c"
    break;

  case 46:
#line 276 "exprtree.y"
                         { (yyval.param) = NULL; }
#line 2081 "y.tab.c"
    break;

  case 47:
#line 279 "exprtree.y"
                         {
                struct ParamNode *temp = (struct ParamNode *)malloc(sizeof(struct ParamNode));
                temp->name = (yyvsp[0].varname);
                temp->type = (yyvsp[-1].type);
                temp->next = NULL;
                (yyval.param) = temp;
           }
#line 2093 "y.tab.c"
    break;

  case 50:
#line 296 "exprtree.y"
                { 
                current_func_type = current_type; 
                (yyval.varname) = (yyvsp[0].varname); 
           }
#line 2102 "y.tab.c"
    break;

  case 51:
#line 302 "exprtree.y"
                                                                {
                struct GST_Node *g = GLookup((yyvsp[-5].varname));
                if (g == NULL) { 
                    printf("Semantic Error: Function '%s' not declared.\n", (yyvsp[-5].varname)); 
                    exit(1); 
                }
                current_func_type = g->type; 

                InstallParameters((yyvsp[-3].param));
           }
#line 2117 "y.tab.c"
    break;

  case 52:
#line 311 "exprtree.y"
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
#line 2136 "y.tab.c"
    break;

  case 58:
#line 330 "exprtree.y"
                 { current_type = (yyvsp[0].type); }
#line 2142 "y.tab.c"
    break;

  case 60:
#line 333 "exprtree.y"
                      {
        LInstall((yyvsp[0].varname), current_type, local_binding);

        if (CLookup(current_type->name) != NULL)
            local_binding += 2;
        else
            local_binding += 1;
    }
#line 2155 "y.tab.c"
    break;

  case 61:
#line 341 "exprtree.y"
                          {
        LInstall((yyvsp[0].varname), current_type, local_binding);
        if (CLookup(current_type->name) != NULL) local_binding += 2;
        else local_binding += 1;
    }
#line 2165 "y.tab.c"
    break;

  case 62:
#line 346 "exprtree.y"
         {
        LInstall((yyvsp[0].varname), current_type, local_binding);

        if (CLookup(current_type->name) != NULL)
            local_binding += 2;
        else
            local_binding += 1;
    }
#line 2178 "y.tab.c"
    break;

  case 63:
#line 354 "exprtree.y"
             {
        LInstall((yyvsp[0].varname), current_type, local_binding);
        if (CLookup(current_type->name) != NULL) local_binding += 2;
        else local_binding += 1;
    }
#line 2188 "y.tab.c"
    break;

  case 64:
#line 366 "exprtree.y"
                                                  {
                current_func_type = TLookup("int"); 
           }
#line 2196 "y.tab.c"
    break;

  case 65:
#line 368 "exprtree.y"
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
#line 2223 "y.tab.c"
    break;

  case 66:
#line 392 "exprtree.y"
                                     { (yyval.no) = (yyvsp[-1].no); }
#line 2229 "y.tab.c"
    break;

  case 67:
#line 393 "exprtree.y"
                                     { (yyval.no) = NULL; }
#line 2235 "y.tab.c"
    break;

  case 68:
#line 396 "exprtree.y"
                   { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[-1].no), (yyvsp[0].no)); }
#line 2241 "y.tab.c"
    break;

  case 69:
#line 397 "exprtree.y"
                   { (yyval.no) = (yyvsp[0].no); }
#line 2247 "y.tab.c"
    break;

  case 70:
#line 400 "exprtree.y"
                               { 
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_READ, (yyvsp[-2].no), NULL); 
       }
#line 2255 "y.tab.c"
    break;

  case 71:
#line 403 "exprtree.y"
                              { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_WRITE, (yyvsp[-2].no), NULL); }
#line 2261 "y.tab.c"
    break;

  case 72:
#line 404 "exprtree.y"
                              { 
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, (yyvsp[-3].no), (yyvsp[-1].no)); 
       }
#line 2269 "y.tab.c"
    break;

  case 73:
#line 407 "exprtree.y"
                               {
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_FREE, (yyvsp[-2].no), NULL);
     }
#line 2277 "y.tab.c"
    break;

  case 74:
#line 410 "exprtree.y"
                                 {
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_DELETE, (yyvsp[-2].no), NULL);
     }
#line 2285 "y.tab.c"
    break;

  case 75:
#line 413 "exprtree.y"
                                                       { 
            struct tnode *then_else = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[-4].no), (yyvsp[-2].no));
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_IF_ELSE, (yyvsp[-7].no), then_else); 
       }
#line 2294 "y.tab.c"
    break;

  case 76:
#line 417 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_IF, (yyvsp[-5].no), (yyvsp[-2].no)); }
#line 2300 "y.tab.c"
    break;

  case 77:
#line 418 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_WHILE, (yyvsp[-5].no), (yyvsp[-2].no)); }
#line 2306 "y.tab.c"
    break;

  case 78:
#line 419 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_DO_WHILE, (yyvsp[-2].no), (yyvsp[-5].no)); }
#line 2312 "y.tab.c"
    break;

  case 79:
#line 420 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_REPEAT_UNTIL, (yyvsp[-2].no), (yyvsp[-5].no)); }
#line 2318 "y.tab.c"
    break;

  case 80:
#line 421 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_BREAK, NULL, NULL); }
#line 2324 "y.tab.c"
    break;

  case 81:
#line 422 "exprtree.y"
                                                     { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONTINUE, NULL, NULL); }
#line 2330 "y.tab.c"
    break;

  case 82:
#line 423 "exprtree.y"
                       {
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_RET, (yyvsp[-1].no), NULL);
       }
#line 2338 "y.tab.c"
    break;

  case 83:
#line 426 "exprtree.y"
                                                              { 
        struct tnode *body_update = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[-1].no), (yyvsp[-4].no));
        struct tnode *while_loop = createTree(0,TLookup("void"), NULL, NODE_WHILE, (yyvsp[-6].no), body_update);
        (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[-7].no), while_loop);
     }
#line 2348 "y.tab.c"
    break;

  case 84:
#line 432 "exprtree.y"
                     {
            struct tnode *one = createTree(1, TLookup("int"), NULL, NODE_NUM, NULL, NULL);
            struct tnode *add = createTree('+', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), one);
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, (yyvsp[-2].no), add);
       }
#line 2358 "y.tab.c"
    break;

  case 85:
#line 437 "exprtree.y"
                      {
            struct tnode *one = createTree(1, TLookup("int"), NULL, NODE_NUM, NULL, NULL);
            struct tnode *sub = createTree('-', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), one);
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, (yyvsp[-2].no), sub);
       }
#line 2368 "y.tab.c"
    break;

  case 86:
#line 442 "exprtree.y"
                                            {
          /* NODE_SWITCH: left = condition, right = linked list of cases */
          (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_SWITCH, (yyvsp[-4].no), (yyvsp[-1].no));
     }
#line 2377 "y.tab.c"
    break;

  case 87:
#line 446 "exprtree.y"
                               { 
            struct tnode *op = createTree('+', TLookup("int"), NULL, NODE_OP, (yyvsp[-3].no), (yyvsp[-1].no));
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, (yyvsp[-3].no), op); 
       }
#line 2386 "y.tab.c"
    break;

  case 88:
#line 450 "exprtree.y"
                                { 
            struct tnode *op = createTree('-', TLookup("int"), NULL, NODE_OP, (yyvsp[-3].no), (yyvsp[-1].no));
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, (yyvsp[-3].no), op); 
       }
#line 2395 "y.tab.c"
    break;

  case 89:
#line 454 "exprtree.y"
                              { 
            struct tnode *op = createTree('*', TLookup("int"), NULL, NODE_OP, (yyvsp[-3].no), (yyvsp[-1].no));
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, (yyvsp[-3].no), op); 
       }
#line 2404 "y.tab.c"
    break;

  case 90:
#line 458 "exprtree.y"
                              { 
            struct tnode *op = createTree('/', TLookup("int"), NULL, NODE_OP, (yyvsp[-3].no), (yyvsp[-1].no));
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, (yyvsp[-3].no), op); 
       }
#line 2413 "y.tab.c"
    break;

  case 91:
#line 462 "exprtree.y"
                              { 
            struct tnode *op = createTree('%', TLookup("int"), NULL, NODE_OP, (yyvsp[-3].no), (yyvsp[-1].no));
            (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, (yyvsp[-3].no), op); 
       }
#line 2422 "y.tab.c"
    break;

  case 92:
#line 467 "exprtree.y"
                             {
          (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[-1].no), (yyvsp[0].no));
     }
#line 2430 "y.tab.c"
    break;

  case 93:
#line 470 "exprtree.y"
                {
          (yyval.no) = (yyvsp[0].no);
     }
#line 2438 "y.tab.c"
    break;

  case 94:
#line 475 "exprtree.y"
                               {
          /* NODE_CASE: left = case value, right = body */
          (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CASE, (yyvsp[-2].no), (yyvsp[0].no));
     }
#line 2447 "y.tab.c"
    break;

  case 95:
#line 479 "exprtree.y"
                         {
          /* NODE_DEFAULT: left = body */
          (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_DEFAULT, (yyvsp[0].no), NULL);
     }
#line 2456 "y.tab.c"
    break;

  case 96:
#line 485 "exprtree.y"
            {
        (yyval.no) = createTree(0, NULL, (yyvsp[0].varname), NODE_VAR, NULL, NULL);

        if ((yyval.no)->type != NULL) {
            (yyval.no)->ctype = CLookup((yyval.no)->type->name);
        }
    }
#line 2468 "y.tab.c"
    break;

  case 97:
#line 492 "exprtree.y"
                                { (yyval.no) = createTree(0, (yyvsp[0].no)->type, NULL, NODE_PTR_DEREF, (yyvsp[0].no), NULL); }
#line 2474 "y.tab.c"
    break;

  case 98:
#line 493 "exprtree.y"
              {
    (yyval.no) = createTree(0, NULL, "self", NODE_SELF, NULL, NULL);
    (yyval.no)->Lentry = LLookup("self");
    (yyval.no)->ctype = Cptr;

    if ((yyval.no)->Lentry == NULL) {
        printf("Semantic Error: 'self' is not defined here.\n");
        exit(1);
    }
}
#line 2489 "y.tab.c"
    break;

  case 99:
#line 503 "exprtree.y"
                         {
            struct tnode *v = createTree(0, NULL, (yyvsp[-3].varname), NODE_VAR, NULL, NULL);
            (yyval.no) = createTree(0, v->type, NULL, NODE_ARRAY, v, (yyvsp[-1].no));
       }
#line 2498 "y.tab.c"
    break;

  case 100:
#line 507 "exprtree.y"
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
#line 2517 "y.tab.c"
    break;

  case 101:
#line 523 "exprtree.y"
                           {
            struct tnode *temp = (yyvsp[-2].no);
            while(temp->right != NULL) temp = temp->right;
            temp->right = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[0].no), NULL);
            (yyval.no) = (yyvsp[-2].no);
        }
#line 2528 "y.tab.c"
    break;

  case 102:
#line 529 "exprtree.y"
                           { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_CONN, (yyvsp[0].no), NULL); }
#line 2534 "y.tab.c"
    break;

  case 103:
#line 530 "exprtree.y"
                           { (yyval.no) = NULL; }
#line 2540 "y.tab.c"
    break;

  case 104:
#line 533 "exprtree.y"
                          { (yyval.no) = (yyvsp[0].no); }
#line 2546 "y.tab.c"
    break;

  case 105:
#line 534 "exprtree.y"
                             {(yyval.no) = createTree(0, (yyvsp[-2].no)->type, NULL,NODE_ASSIGN, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2552 "y.tab.c"
    break;

  case 106:
#line 535 "exprtree.y"
                          { (yyval.no) = createTree(0, TLookup("int"), NULL, NODE_INIT, NULL, NULL); }
#line 2558 "y.tab.c"
    break;

  case 107:
#line 536 "exprtree.y"
                          { (yyval.no) = createTree(0, TLookup("void"), NULL, NODE_ALLOC, NULL, NULL); }
#line 2564 "y.tab.c"
    break;

  case 108:
#line 537 "exprtree.y"
                          { (yyval.no) = createTree(0, TLookup("null"), NULL, NODE_NULL, NULL, NULL); }
#line 2570 "y.tab.c"
    break;

  case 109:
#line 538 "exprtree.y"
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
#line 2591 "y.tab.c"
    break;

  case 110:
#line 554 "exprtree.y"
                                        {
            struct Classtable *c = (yyvsp[-5].no)->ctype;
            if (c == NULL) {
                printf("Semantic Error: Left side is not an object.\n"); exit(1);
            }
            
            /* 1. Mangle the name using the arguments */
            char *mangled = mangleCall((yyvsp[-3].varname), (yyvsp[-1].no));
            
            /* 2. Look up the mangled name (e.g., "add_int_int") */
            struct Memberfunclist *m = ClassMLookup(c, mangled);
            if (m == NULL) {
                printf("Semantic Error: Overloaded Method '%s' not found in class.\n", mangled); exit(1);
            }
            
            /* 3. Pass the mangled name into the AST node */
            struct tnode *funcNode = createTree(0, m->type, mangled, NODE_OBJ_FUNC_CALL, (yyvsp[-5].no), (yyvsp[-1].no));
            funcNode->ctype = c;
            (yyval.no) = funcNode;
     }
#line 2616 "y.tab.c"
    break;

  case 111:
#line 574 "exprtree.y"
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
#line 2631 "y.tab.c"
    break;

  case 112:
#line 584 "exprtree.y"
                                    {
            if (Cptr == NULL || Cptr->parentptr == NULL) {
                printf("Semantic Error: 'super' can only be used inside a subclass.\n");
                exit(1);
            }
            
            struct Memberfunclist *m = ClassMLookup(Cptr->parentptr, (yyvsp[-3].varname));
            if (m == NULL) {
                printf("Semantic Error: Method '%s' not found in parent class.\n", (yyvsp[-3].varname));
                exit(1);
            }
            
            /* Create a 'self' node to act as the base object */
            struct tnode *selfNode = createTree(0, NULL, "self", NODE_SELF, NULL, NULL);
            selfNode->Lentry = LLookup("self");
            selfNode->ctype = Cptr;
            
            /* Construct the super call node, strictly pointing to the PARENT class type */
            struct tnode *funcNode = createTree(0, m->type, (yyvsp[-3].varname), NODE_SUPER, selfNode, (yyvsp[-1].no));
            funcNode->ctype = Cptr->parentptr;
            (yyval.no) = funcNode;
     }
#line 2658 "y.tab.c"
    break;

  case 113:
#line 606 "exprtree.y"
                        { (yyval.no) = createTree('+', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2664 "y.tab.c"
    break;

  case 114:
#line 607 "exprtree.y"
                        { (yyval.no) = createTree('-', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2670 "y.tab.c"
    break;

  case 115:
#line 608 "exprtree.y"
                        { (yyval.no) = createTree('*', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2676 "y.tab.c"
    break;

  case 116:
#line 609 "exprtree.y"
                        { (yyval.no) = createTree('/', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2682 "y.tab.c"
    break;

  case 117:
#line 610 "exprtree.y"
                        { (yyval.no) = createTree('%', TLookup("int"), NULL, NODE_OP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2688 "y.tab.c"
    break;

  case 118:
#line 611 "exprtree.y"
                        { (yyval.no) = createTree(LT, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2694 "y.tab.c"
    break;

  case 119:
#line 612 "exprtree.y"
                        { (yyval.no) = createTree(GT, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2700 "y.tab.c"
    break;

  case 120:
#line 613 "exprtree.y"
                        { (yyval.no) = createTree(LE, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2706 "y.tab.c"
    break;

  case 121:
#line 614 "exprtree.y"
                        { (yyval.no) = createTree(GE, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2712 "y.tab.c"
    break;

  case 122:
#line 615 "exprtree.y"
                        { (yyval.no) = createTree(EQ, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2718 "y.tab.c"
    break;

  case 123:
#line 616 "exprtree.y"
                        { (yyval.no) = createTree(NE, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2724 "y.tab.c"
    break;

  case 124:
#line 617 "exprtree.y"
                        { (yyval.no) = createTree(AND, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no)); }
#line 2730 "y.tab.c"
    break;

  case 125:
#line 618 "exprtree.y"
                    {
            (yyval.no) = createTree(OR, TLookup("boolean"), NULL, NODE_RELOP, (yyvsp[-2].no), (yyvsp[0].no));
        }
#line 2738 "y.tab.c"
    break;

  case 126:
#line 621 "exprtree.y"
                        { (yyval.no) = (yyvsp[-1].no); }
#line 2744 "y.tab.c"
    break;

  case 127:
#line 622 "exprtree.y"
                        { (yyval.no) = createTree((yyvsp[0].val), TLookup("int"), NULL, NODE_NUM, NULL, NULL); }
#line 2750 "y.tab.c"
    break;

  case 128:
#line 623 "exprtree.y"
                        { (yyval.no) = createTree(0, TLookup("str"), (yyvsp[0].varname), NODE_STR_VAL, NULL, NULL); }
#line 2756 "y.tab.c"
    break;

  case 129:
#line 624 "exprtree.y"
                      { (yyval.no) = createTree(0, TLookup("boolean"), NULL, NODE_NOT, (yyvsp[0].no), NULL); }
#line 2762 "y.tab.c"
    break;

  case 130:
#line 625 "exprtree.y"
                              {
            /* Group the true and false expressions into a CONN node, then attach to TERNARY */
            struct tnode *then_else = createTree(0, (yyvsp[-2].no)->type, NULL, NODE_CONN, (yyvsp[-2].no), (yyvsp[0].no));
            (yyval.no) = createTree(0, (yyvsp[-2].no)->type, NULL, NODE_TERNARY, (yyvsp[-4].no), then_else); 
       }
#line 2772 "y.tab.c"
    break;

  case 131:
#line 630 "exprtree.y"
                      { (yyval.no) = createTree(1, TLookup("boolean"), NULL, NODE_NUM, NULL, NULL); }
#line 2778 "y.tab.c"
    break;

  case 132:
#line 631 "exprtree.y"
                      { (yyval.no) = createTree(0, TLookup("boolean"), NULL, NODE_NUM, NULL, NULL); }
#line 2784 "y.tab.c"
    break;

  case 133:
#line 632 "exprtree.y"
                  { (yyval.no) = createTree(0, TLookup("int"), NULL, NODE_PTR_ADDR, (yyvsp[0].no), NULL); }
#line 2790 "y.tab.c"
    break;


#line 2794 "y.tab.c"

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
#line 635 "exprtree.y"


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
