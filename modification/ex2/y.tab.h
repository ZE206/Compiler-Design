/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 204 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
