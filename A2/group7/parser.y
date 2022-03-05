%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.hpp"

extern FILE *yyin, *yyout;
char *tok_file;
int show_tokens;
int yyerror(char*);
int yylex();

%}
%union{
    class AST* node;
    class Expression* exp;
    class Statement* stmt;
    class Stmtlist* stmtlist;
}

%token INTEGER VOID FLOAT STRING BOOL ASSIGN_OP SEMICOLON LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET COMMA WRITE READ PLUS MINUS MULT DIV 
%token INT_NUM 
%token FLOAT_NUM 
%token NAME 
%token STR_CONST
%token QUESTION_MARK COLON
%token AND OR NOT
%token LT LE GT GE NE EQ
%right QUESTION_MARK COLON
%left OR
%left AND 
%right NOT
%nonassoc NE EQ LE LT GE GT
%left PLUS MINUS 
%left MULT DIV
%right UMINUS

%%

program 
    : global_decl_statement_list func_def
    | func_def
;

global_decl_statement_list 
    : global_decl_statement_list func_decl
    | global_decl_statement_list var_decl_stmt 
    | var_decl_stmt 
    | func_decl 
;

func_decl 
    : func_header LEFT_ROUND_BRACKET formal_param_list RIGHT_ROUND_BRACKET SEMICOLON
    | func_header LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET SEMICOLON
;

func_header
    : named_type NAME 
;

func_def 
    : func_header LEFT_ROUND_BRACKET formal_param_list RIGHT_ROUND_BRACKET  LEFT_CURLY_BRACKET optional_local_var_decl_stmt_list statement_list   RIGHT_CURLY_BRACKET 
    | func_header LEFT_ROUND_BRACKET  RIGHT_ROUND_BRACKET  LEFT_CURLY_BRACKET optional_local_var_decl_stmt_list statement_list   RIGHT_CURLY_BRACKET 
;

formal_param_list
    : formal_param_list COMMA formal_param 
    | formal_param 
;

formal_param 
    : param_type NAME
;

param_type 
    : INTEGER 
    | FLOAT 
    | BOOL 
    | STRING
;

optional_local_var_decl_stmt_list
    : %empty
    | var_decl_stmt_list 
;

var_decl_stmt_list
    : var_decl_stmt
    | var_decl_stmt_list var_decl_stmt
;

var_decl_stmt
    : named_type var_decl_item_list SEMICOLON
;

var_decl_item_list
    : var_decl_item_list COMMA var_decl_item 
    | var_decl_item
;

var_decl_item 
    : NAME 
;

named_type 
    : INTEGER 
    | FLOAT 
    | VOID
    | BOOL 
    | STRING
;

statement_list
    : statement_list statement  {
                                     $<stmtlist>$ = $<stmtlist>1;
                                     ($<stmtlist>$)->statements.push_back($<stmt>2);
                                }
    | %empty                    {    $<stmtlist>$ = new Stmtlist();    }
;

statement:
    assignment_statement        {    $<stmt>$ = $<stmt>1;    }
    | print_statement           {    $<stmt>$ = $<stmt>1;    }
    | read_statement            {    $<stmt>$ = $<stmt>1;    }
;

assignment_statement
    : variable_as_operand ASSIGN_OP expression SEMICOLON    {    auto As = new Assignment_Stmt();  
                                                                 As->LHS = $<exp>1;
                                                                 As->RHS = $<exp>3;
                                                                 $<stmt>$ = As;
                                                            }
;

variable_as_operand
    : variable_name 
;

variable_name
    : NAME 
;

print_statement
    : WRITE expression SEMICOLON	{   auto Ws = new Write_Stmt();
					    Ws->expression = $<exp>2;
					    $<stmt>$ = Ws;
					}
;

read_statement
    : READ variable_name SEMICOLON	{   auto Rs = new Read_Stmt();
					    Rs->var_name = $<exp>2;
					    $<stmt>$ = Rs;
					}
;

expression
    : expression PLUS expression	 { auto e = new Plus_Expr()  ; e->left = $<exp>1; e->right = $<exp>3; $<exp>$ = e; }
    | expression MINUS expression	 { auto e = new Minus_Expr() ; e->left = $<exp>1; e->right = $<exp>3; $<exp>$ = e; }
    | expression MULT expression	 { auto e = new Mult_Expr()  ; e->left = $<exp>1; e->right = $<exp>3; $<exp>$ = e; }
    | expression DIV expression 	 { auto e = new Div_Expr()   ; e->left = $<exp>1; e->right = $<exp>3; $<exp>$ = e; }
    | MINUS expression      %prec UMINUS { auto e = new UMinus_Expr(); e->expression = $<exp>2; $<exp>$ = e; }
    | LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET		{ $<exp>$ = $<exp>2; }
    | expression QUESTION_MARK expression COLON expression	{
									// TODO
								}
    | expression AND expression  	 { auto e = new Boolean_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("AND");
					   $<exp>$ = e; 
					 }         
    | expression OR expression		 { auto e = new Boolean_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("OR");
					   $<exp>$ = e; 
					 }
    | NOT expression			 { auto e = new Not_Expr(); e->expression = $<exp>2; $<exp>$ = e; }
    | rel_expression			 { $<exp>$ = $<exp>1; }
    | variable_as_operand		 { $<exp>$ = $<exp>1; }
    | constant_as_operand		 { $<exp>$ = $<exp>1; } 
;

rel_expression
    : expression LT expression		 { auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("LE");
					   $<exp>$ = e; 
					 }
    | expression LE expression		 { auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("LE");
					   $<exp>$ = e; 
					 }	
    | expression GT expression		 { auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("GT");
					   $<exp>$ = e; 
					 }
    | expression GE expression		 { auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("GE");
					   $<exp>$ = e; 
					 }
    | expression NE expression		 { auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("NE");
					   $<exp>$ = e; 
					 }
    | expression EQ expression		 { auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("EQ");
					   $<exp>$ = e; 
					 }

constant_as_operand 
    : INT_NUM 
    | FLOAT_NUM 
    | STR_CONST
;

%%

int main(int argc, char* argv[]){
    show_tokens = 0;
    char* filename = NULL;

    for(int i=1; i<argc; i++){
        if(strcmp("--show-tokens", argv[i]) == 0){
            show_tokens = 1;
        }
        else {
            filename = argv[i];        
        }
    }

    if(!filename || filename[strlen(filename)-1] != 'c' || filename[strlen(filename)-2] != '.'){
        fprintf(stderr, "Filename must end in .c\n");
        exit(1);
    }

    if((yyin = fopen(filename, "r"))==0){
        fprintf(stderr, "No such file exists\n");
        exit(1);
    }

    if(show_tokens){
        tok_file = (char*)malloc(strlen(filename)+5+1);
        strncpy(tok_file, filename, strlen(filename));
        strcat(tok_file, ".toks");
        yyout = fopen(tok_file, "w");
    }

    yyparse();

    return 0;
}

int yyerror(char *mesg){
    fprintf(stderr, "%s\n", mesg);
    if(show_tokens){ 
        fclose(yyout); 
        fopen(tok_file, "w+");
	}    
    exit(1);
}


