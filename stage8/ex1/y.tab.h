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

#line 168 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
