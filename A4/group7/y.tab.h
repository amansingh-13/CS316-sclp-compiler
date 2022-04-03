/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    INTEGER = 258,
    VOID = 259,
    FLOAT = 260,
    STRING = 261,
    BOOL = 262,
    ASSIGN_OP = 263,
    SEMICOLON = 264,
    LEFT_ROUND_BRACKET = 265,
    RIGHT_ROUND_BRACKET = 266,
    LEFT_CURLY_BRACKET = 267,
    RIGHT_CURLY_BRACKET = 268,
    COMMA = 269,
    WRITE = 270,
    READ = 271,
    PLUS = 272,
    MINUS = 273,
    MULT = 274,
    DIV = 275,
    INT_NUM = 276,
    FLOAT_NUM = 277,
    NAME = 278,
    STR_CONST = 279,
    QUESTION_MARK = 280,
    COLON = 281,
    AND = 282,
    OR = 283,
    NOT = 284,
    LT = 285,
    LE = 286,
    GT = 287,
    GE = 288,
    NE = 289,
    EQ = 290,
    DO = 291,
    WHILE = 292,
    IF = 293,
    ELSE = 294,
    UMINUS = 295
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define VOID 259
#define FLOAT 260
#define STRING 261
#define BOOL 262
#define ASSIGN_OP 263
#define SEMICOLON 264
#define LEFT_ROUND_BRACKET 265
#define RIGHT_ROUND_BRACKET 266
#define LEFT_CURLY_BRACKET 267
#define RIGHT_CURLY_BRACKET 268
#define COMMA 269
#define WRITE 270
#define READ 271
#define PLUS 272
#define MINUS 273
#define MULT 274
#define DIV 275
#define INT_NUM 276
#define FLOAT_NUM 277
#define NAME 278
#define STR_CONST 279
#define QUESTION_MARK 280
#define COLON 281
#define AND 282
#define OR 283
#define NOT 284
#define LT 285
#define LE 286
#define GT 287
#define GE 288
#define NE 289
#define EQ 290
#define DO 291
#define WHILE 292
#define IF 293
#define ELSE 294
#define UMINUS 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "parser.y" /* yacc.c:1909  */

    class AST* node;
    class Expression* exp;
    class Statement* stmt;
    class Stmtlist* stmtlist;
    char* str;
    int var_type;
    void* pointer;

#line 144 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
