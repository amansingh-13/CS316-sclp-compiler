%{
	#include<stdio.h>
	#include "y.tab.h"
	int lineno = 1;
	#define FUN(a, b) {  printf("\tToken Name: %s\tLexeme: %s\tLineno: %d\n", a, yytext, lineno); return b; }
%}

digit [0-9]
letter [a-zA-Z_]
LINE \n
%%

int	{ FUN("INTEGER", INTEGER) }
void	{ FUN("VOID", VOID) }
float	{ FUN("FLOAT", FLOAT) }
string	{ FUN("STRING", STRING) }
bool	{ FUN("BOOL", BOOL) }
=	{ FUN("ASSIGN_OP", ASSIGN_OP) }
;	{ FUN("SEMICOLON", SEMICOLON) }
\(	{ FUN("LEFT_ROUND_BRACKET", LEFT_ROUND_BRACKET) }
\)	{ FUN("RIGHT_ROUND_BRACKET", RIGHT_ROUND_BRACKET) }
\{	{ FUN("LEFT_CURLY_BRACKET", LEFT_CURLY_BRACKET) }
\}	{ FUN("RIGHT_CURLY_BRACKET", RIGHT_CURLY_BRACKET) }
,	{ FUN("COMMA", COMMA) }
print	{ FUN("WRITE", WRITE) }
read	{ FUN("READ", READ) } 
\+	{ FUN("PLUS", PLUS) } 
-	{ FUN("MINUS", MINUS) } 
\*	{ FUN("MULT", MULT) } 
\/	{ FUN("DIV", DIV) } 

{digit}+				{ FUN("INT_NUM", INT_NUM) } 
{digit}+\.{digit}*|{digit}*\.{digit}+	{ FUN("FLOAT_NUM", FLOAT_NUM) } 
{letter}({letter}|{digit})*		{ FUN("NAME", NAME) } 

\".*\"	{ FUN("STR_CONST", STR_CONST) } 

\/\/.*	{}
\n	{ lineno++; }
[ \t\r\f]  {}
.	{ printf("%s", yytext); exit(1); }

%%

int yywrap(){return 1;}
