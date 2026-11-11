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

#line 142 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
