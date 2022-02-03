%{
#include <stdlib.h>
#include <stdio.h>
%}

%token INTEGER VOID FLOAT STRING BOOL ASSIGN_OP SEMICOLON LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET COMMA WRITE READ PLUS MINUS MULT DIV INT_NUM FLOAT_NUM NAME STR_CONST
%left PLUS MINUS 
%left MULT DIV

%%

program 
    : global_decl_statement_list func_def
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
    : statement_list statement 
    | %empty
;

statement:
    assignment_statement
    | print_statement
    | read_statement
;

assignment_statement
    : variable_as_operand ASSIGN_OP expression SEMICOLON
;

variable_as_operand
    : variable_name 
;

variable_name
    : NAME 
;

print_statement
    : WRITE expression SEMICOLON
;

read_statement
    : READ variable_name SEMICOLON
;

expression
    : expression PLUS expression
    | expression MINUS expression
    | expression MULT expression
    | expression DIV expression
    | MINUS expression
    | LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET
    | variable_as_operand
    | constant_as_operand 
;

constant_as_operand 
    : INT_NUM 
    | FLOAT_NUM 
    | STR_CONST
;

%%



int yyerror(char *mesg){
    fprintf(stderr, "%s\n", mesg);
    exit(1);
}


