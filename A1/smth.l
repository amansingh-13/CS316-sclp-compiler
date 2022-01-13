%{
    #include<stdio.h>
    int lineno=1;
    #define FUN(a, b) {  printf("\tToken Name: %s 	Lexeme: %s\tLineno: %d\n", a, yytext, lineno); return b; }
%}

digit [0-9]
letter [a-zA-Z_]
LINE \n
%%

int {  FUN("INTEGER", 304) }
void {  FUN("VOID", 305) }
float {  FUN("FLOAT", 306) }
string {  FUN("STRING", 307) }
bool {  FUN("BOOL", 308) }
=   {  FUN("ASSIGN_OP", 308) }
;   {  FUN("SEMICOLON", 308) }
\(   {  FUN("LEFT_ROUND_BRACKET", 308) }
\)   {  FUN("RIGHT_ROUND_BRACKET", 308) }
\{   {  FUN("LEFT_CURLY_BRACKET", 308) }
\}   {  FUN("RIGHT_CURLY_BRACKET", 308) }
,   {  FUN("COMMA", 308) }
print   {  FUN("WRITE", 308) }
read   {  FUN("READ", 308) } 
\+   {  FUN("PLUS", 308) } 
-   {  FUN("MINUS", 308) } 
\*   {  FUN("MULT", 308) } 
\/   {  FUN("DIV", 308) } 

{digit}+    {  FUN("INT_NUM", 308) } 
{digit}+\.{digit}*|{digit}*\.{digit}+  {  FUN("FLOAT_NUM", 308) } 
{letter}({letter}|{digit})* {  FUN("NAME", 308) } 

\".*\"   {  FUN("STR_CONST", 308) } 

\/\/.* {}
\n {lineno++;}
.

%%

int yywrap(){return 1;}
