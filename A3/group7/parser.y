%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "semantics.hpp"
#include <string>
using namespace std;

#define pairr pair<vector<Function*> *, SymTab*>

extern FILE *yyin, *yyout;
char *tok_file, *ast_file;
bool show_tokens, show_ast, sa_parse;
int yyerror(char*);
int yylex();
FILE* ast_file_desc;
%}
%union{
    class AST* node;
    class Expression* exp;
    class Statement* stmt;
    class Stmtlist* stmtlist;
    char* str;
    int var_type;
    void* pointer;
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
    : global_decl_statement_list func_def   { 
        pairr* K = (pairr *) $<pointer>1;
        auto P = new Program();
        P->Global_Symtab = K->second;
        P->functions = (*(K->first));
        delete K->first;
        delete K;
        P->functions.push_back((Function *)$<pointer>2);
        if(!sa_parse){
            P->infer_type();
            P->weird_check_for_A2();
            if(show_ast){
                string k = P->print();
                fprintf(ast_file_desc, k.c_str());
            }
        }
        
        $<pointer>$ = P;
     }
    | func_def                              { 
        auto P = new Program();
        P->Global_Symtab = new SymTab();
        P->functions = vector<Function*>();
        P->functions.push_back((Function *)$<pointer>1);
        if(!sa_parse){
            P->infer_type();
            P->weird_check_for_A2();
            if(show_ast){
                string k = P->print();
                fprintf(ast_file_desc, k.c_str());
            }
        }
        $<pointer>$ = P;
     }
;

global_decl_statement_list 
    : global_decl_statement_list func_decl 
        {  
            pairr* K = (pairr *)$<pointer>1;
            K->first->push_back((Function *)$<pointer>2);
            $<pointer>$ = K;
        }
    | global_decl_statement_list var_decl_stmt 
        {
            pairr* K = (pairr *)$<pointer>1;
            SymTab* X = K->second;
            SymTab* Y = (SymTab *)$<pointer>2;

            for(auto vars : *Y){
                auto ret = X->insert(pair<string, int>(vars.first, vars.second));
                if (ret.second == false){
                    //TODO
                    yyerror("Variable declared more than once in the same scope");
                }
            }
            delete Y;
            $<pointer>$ = K;
        }
    | var_decl_stmt         { 
        auto S = new pair<vector<Function*> *, SymTab*>();
        S->second = (SymTab *)$<pointer>1;   
        S->first = new vector<Function*>();
        $<pointer>$ = S;  
     }
    | func_decl             {   
        auto S = new pair<vector<Function*> *, SymTab*>();
        S->second = new SymTab();
        S->first = new vector<Function*>();
        S->first->push_back((Function *)$<pointer>1);
        $<pointer>$ = S;
     }  //TODO
;

func_decl 
    : func_header LEFT_ROUND_BRACKET formal_param_list RIGHT_ROUND_BRACKET SEMICOLON    {
		
		Function* func = (Function *)$<pointer>1;
        func->decl_or_def = IS_DECLARATION;	
        vector<pair<string, int>>* params = (vector<pair<string, int>>*)$<pointer>3;
        func->Param_List   = params;
		$<pointer>$ = func; 
	}
    | func_header LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET SEMICOLON      {
		
		Function* func = (Function *)$<pointer>1;
        func->decl_or_def = IS_DECLARATION;	
        func->Param_List   = new vector<pair<string, int>>;
		$<pointer>$ = func; 

	}
;

func_header
    : named_type var_decl_item 
            {
                auto func = new Function(); 
				func->return_type = $<var_type>1;
                string* name = (string*)$<pointer>2;
				func->Name = *name;
                delete name;
				$<pointer>$ = func;
            }
;

func_def 
    : func_header LEFT_ROUND_BRACKET formal_param_list RIGHT_ROUND_BRACKET  LEFT_CURLY_BRACKET optional_local_var_decl_stmt_list statement_list   RIGHT_CURLY_BRACKET   
	{
		
		SymTab* locals = (SymTab *)$<pointer>6;
		vector<pair<string, int>>* params = (vector<pair<string, int>>*)$<pointer>3;
		for(auto vars : *params){
		    auto ret = locals->insert({vars.first, vars.second});
		    if (ret.second == false){
                //TODO
                yyerror("Variable declared more than once in the same scope");
		    }
		}

		Function* func = (Function *)$<pointer>1;
		func->stmtlist = $<stmtlist>7;
		func->Local_Symtab = locals;
		func->Param_List   = params;
        func->decl_or_def = IS_DEFINITION;
		
		$<pointer>$ = func; 
	}
    | func_header LEFT_ROUND_BRACKET  RIGHT_ROUND_BRACKET  LEFT_CURLY_BRACKET optional_local_var_decl_stmt_list statement_list   RIGHT_CURLY_BRACKET  
    {
		
		SymTab* locals = (SymTab *)$<pointer>5;

		Function* func = (Function *)$<pointer>1;
		func->stmtlist = $<stmtlist>6;
		func->Local_Symtab = locals;
		func->Param_List   = new vector<pair<string, int>>;
        func->decl_or_def = IS_DEFINITION;
		
		$<pointer>$ = func; 
	}
;

formal_param_list
    : formal_param_list COMMA formal_param 
		{ 
			vector<pair<string, int>>* X = (vector<pair<string, int>>*)$<pointer>1;
			pair<string, int>* Y = (pair<string, int> *)$<pointer>3;
			X->push_back({Y->first, Y->second});
			delete Y; 
        	$<pointer>$ = X;
		}
    | formal_param		
        {
            auto ret = new vector<pair<string, int>>;
            pair<string, int>* elem = (pair<string, int>*) $<pointer>1;
            ret->push_back({elem->first, elem->second});
            delete elem;
            $<pointer>$ = ret;
        }
;

formal_param 
    : param_type var_decl_item 	
        { 
            auto ret = new pair<string, int>;
            string* add = (string*)$<pointer>2;
            ret->first = *add;
            delete add;
            ret->second = $<var_type>1;
            $<pointer>$ = ret; 
        }
;

param_type 
    : INTEGER                   {   $<var_type>$ = TYPE_INT;    }
    | FLOAT                     {   $<var_type>$ = TYPE_FLOAT;    }
    | BOOL                      {   $<var_type>$ = TYPE_BOOL;    }
    | STRING                    {   $<var_type>$ = TYPE_STRING;    }
;

optional_local_var_decl_stmt_list
    : %empty                                        {    $<pointer>$ = new SymTab();   }
    | var_decl_stmt_list                            {    $<pointer>$ = $<pointer>1;   }
;

var_decl_stmt_list
    : var_decl_stmt                                 {    $<pointer>$ = $<pointer>1;   }
    | var_decl_stmt_list var_decl_stmt {
        SymTab* X = (SymTab *)$<pointer>1;
        SymTab* Y = (SymTab *)$<pointer>2;

        for(auto vars : *Y){
            auto ret = X->insert(pair<string, int>(vars.first, vars.second));
            if (ret.second == false){
                //TODO
                yyerror("Variable declared more than once in the same scope");
            }
        }
        delete Y;
        $<pointer>$ = X;
    }
;

var_decl_stmt
    : named_type var_decl_item_list SEMICOLON {
        auto X = new SymTab();
        vector<string>* K = (vector<string>*)$<pointer>2;
        int type = $<var_type>1;
        if(type == TYPE_VOID){
            yyerror("Variable type cannot be void\n");
        }
        for(auto var_name : *K){
            auto ret = X->insert(pair<string, int>(var_name, type));
            if (ret.second == false){
                //TODO
                yyerror("Variable declared more than once in the same scope\n");
            }
        }
        delete K;
        $<pointer>$ = X;
    }
;

var_decl_item_list
    : var_decl_item_list COMMA var_decl_item   
                                {   
                                    vector<string>* K = (vector<string>*)$<pointer>1;
                                    string* add = (string*)$<pointer>3;
                                    K->push_back(*add);
                                    delete add;
                                    $<pointer>$ = K;
                                }
    | var_decl_item             {   
                                    auto K = new vector<string>;
                                    string* add = (string*)$<pointer>1;
                                    K->push_back(*add);
                                    delete add;
                                    $<pointer>$ = K;
                                }
;

var_decl_item 
    : NAME                      {  $<pointer>$ = new string(yylval.str); }
;

named_type 
    : INTEGER                   {   $<var_type>$ = TYPE_INT;    }
    | FLOAT                     {   $<var_type>$ = TYPE_FLOAT;    }
    | VOID                      {   $<var_type>$ = TYPE_VOID;    }
    | BOOL                      {   $<var_type>$ = TYPE_BOOL;    }
    | STRING                    {   $<var_type>$ = TYPE_STRING;    }
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
    : variable_name     {  $<exp>$ = $<exp>1;     }
;

variable_name
    : NAME              {  auto i = new Name_Expr();  i->value = string(yylval.str);  $<exp>$ = i;   }
;

print_statement
    : WRITE expression SEMICOLON	
                    {   auto Ws = new Write_Stmt();
					    Ws->expression = $<exp>2;
					    $<stmt>$ = Ws;
					}
;

read_statement
    : READ variable_name SEMICOLON	
                    {   auto Rs = new Read_Stmt();
					    Rs->var_name = $<exp>2;
					    $<stmt>$ = Rs;
					}
;

expression
    : expression PLUS expression	 { auto e = new Plus_Expr()  ; e->left = $<exp>1; e->right = $<exp>3; $<exp>$ = e; }
    | expression MINUS expression    { auto e = new Minus_Expr() ; e->left = $<exp>1; e->right = $<exp>3; $<exp>$ = e; }
    | expression MULT expression     { auto e = new Mult_Expr()  ; e->left = $<exp>1; e->right = $<exp>3; $<exp>$ = e; }
    | expression DIV expression      { auto e = new Div_Expr()   ; e->left = $<exp>1; e->right = $<exp>3; $<exp>$ = e; }
    | MINUS expression      %prec UMINUS 
                                     { auto e = new UMinus_Expr(); e->expression = $<exp>2; $<exp>$ = e; }
    | LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET		
                                     { $<exp>$ = $<exp>2; }
    | expression QUESTION_MARK expression COLON expression	
                                {
									auto e = new Conditional_Expr(); 
                                    e->expression1 = $<exp>1;   e->expression2 = $<exp>3;   e->expression3 = $<exp>5;
                                    $<exp>$ = e;
								}
    | expression AND expression { 
                                    auto e = new Boolean_Expr(); 
					                e->left = $<exp>1; e->right = $<exp>3; e->op = string("AND");
					                $<exp>$ = e; 
                                }
    | expression OR expression	{
                                    auto e = new Boolean_Expr(); 
					                e->left = $<exp>1; e->right = $<exp>3; e->op = string("OR");
				                    $<exp>$ = e; 
					            }
    | NOT expression			{ auto e = new Not_Expr(); e->expression = $<exp>2; $<exp>$ = e; }
    | rel_expression			{ $<exp>$ = $<exp>1; }
    | variable_as_operand		{ $<exp>$ = $<exp>1; }
    | constant_as_operand		{ $<exp>$ = $<exp>1; } 
;

rel_expression
    : expression LT expression		 
                    {  auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("LT");
					   $<exp>$ = e; 
					}
    | expression LE expression		 
                    {  auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("LE");
					   $<exp>$ = e; 
					}	
    | expression GT expression		 
                    {  auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("GT");
					   $<exp>$ = e; 
					}
    | expression GE expression		 
                    {  auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("GE");
					   $<exp>$ = e; 
					}
    | expression NE expression		 
                    {  auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("NE");
					   $<exp>$ = e; 
					}
    | expression EQ expression		 
                    {  auto e = new Relational_Expr(); 
					   e->left = $<exp>1; e->right = $<exp>3; e->op = string("EQ");
					   $<exp>$ = e; 
					}

constant_as_operand 
    : INT_NUM       {  auto i = new Number_Expr_Int();  i->value = string(yylval.str);  $<exp>$ = i;   }
    | FLOAT_NUM     {  auto i = new Number_Expr_Float();  i->value = string(yylval.str);  $<exp>$ = i;   }
    | STR_CONST     {  auto i = new String_Expr();  i->value = string(yylval.str);  $<exp>$ = i;   }
;

%%

int main(int argc, char* argv[]){
    show_tokens = 0;
    sa_parse = 0;
    show_ast = 0;
    bool file_found = false;
    char* filename = NULL;

    for(int i=1; i<argc; i++){
        if(strcmp("--show-tokens", argv[i]) == 0){
            show_tokens = 1;
        }
        else if(strcmp("--sa-parse", argv[i]) == 0){
            sa_parse = 1;
        }
        else if(strcmp("--show-ast", argv[i]) == 0){
            show_ast = 1;
        }
        else{
            if(!file_found){
                filename = argv[i]; 
                file_found = true;    
            }
            else{
                fprintf(stderr, "only one filename allowed\n");
                exit(1);
            }
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

    if(show_ast && (!sa_parse)){
        ast_file = (char*)malloc(strlen(filename)+4+1);
        strncpy(ast_file, filename, strlen(filename));
        strcat(ast_file, ".ast");
        ast_file_desc = fopen(ast_file, "w+");
    }

    yyparse();

    return 0;
}

int yyerror(char *mesg){
    fprintf(stderr, "%s\n", mesg);
    if(show_tokens){ 
        fclose(yyout); 
        fopen(tok_file, "w");
	}
    if(show_ast && (!sa_parse)){
        fclose(ast_file_desc);
        fopen(ast_file, "w");
    }
    exit(1);
}


