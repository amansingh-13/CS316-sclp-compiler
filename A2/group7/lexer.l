%{
	#include <stdio.h>
	#include "y.tab.h"
	int lineno = 1;
	extern bool show_tokens;
	extern int yyerror(char *);
	extern char *tok_file;
	#define FUN(a, b) { if(show_tokens) {fprintf(yyout, "\tToken Name: %s \tLexeme: %s \t Lineno: %d\n", a, yytext, lineno);} return b; }
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

\?	{ FUN("OP_FOR_TERNARY_EXPR", QUESTION_MARK) } 
:	{ FUN("OP_FOR_TERNARY_EXPR", COLON) } 

&&		{ FUN("AND", AND) } 
"||"	{ FUN("OR", OR) } 
!		{ FUN("NOT", NOT) } 

"<="		{ FUN("LESS_THAN_EQUAL", LE) } 
">="		{ FUN("GREATER_THAN_EQUAL", GE) } 
"!="		{ FUN("NE", NE) } 
"<"		{ FUN("LESS_THAN", LT) } 
">"		{ FUN("GREATER_THAN", GT) } 
"=="		{ FUN("EQUAL", EQ) } 


{digit}+								{ yylval.str = yytext; FUN("INT_NUM", INT_NUM) } 
{digit}+\.{digit}*|{digit}*\.{digit}+	{ yylval.str = yytext; FUN("FLOAT_NUM", FLOAT_NUM) } 
{letter}({letter}|{digit})*				{ yylval.str = yytext; FUN("NAME", NAME) } 

\"[^"\n\r]*\"							{ yylval.str = yytext; FUN("STR_CONST", STR_CONST) } 

\/\/.*	{}
\n	{ lineno++; }
[ \t\r\f]  {}
.	{ 	
		yyerror("Illegal Character somewhere\n");
	}

%%

int yywrap(){return 1;}
