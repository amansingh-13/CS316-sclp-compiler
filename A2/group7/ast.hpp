#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
extern int yyerror(char *);

#define TYPE_FLOAT  1
#define TYPE_BOOL   2
#define TYPE_STRING 3
#define TYPE_VOID   4
#define TYPE_FUNCTION 5
#define TYPE_INT    6


typedef map<string, int> SymTab; 


class AST {
public:
	virtual string print(int num_spaces) = 0;
	virtual int infer_type(SymTab* symtab) = 0;
};

class Expression : public AST {
public:
	int type = -1;
	virtual string print(int num_spaces) = 0;
	virtual int infer_type(SymTab* symtab) = 0;
	string print_type(){
		string rv;
		switch(type){
			case(TYPE_INT)    : { rv = "<int>"   ; break; }
			case(TYPE_FLOAT)  : { rv = "<float>" ; break; }
			case(TYPE_BOOL)   : { rv = "<bool>"  ; break; }
			case(TYPE_STRING) : { rv = "<string>"; break; }
			default           : { return "<err>";  } // should be UNREACHABLE
		}
		return rv;
	}
};


class Base_Expr : public Expression {
public:
	string value;
	virtual string print(int num_spaces) = 0;
	virtual int infer_type(SymTab* symtab) = 0;
};

class Name_Expr : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		string rv = "Name : " + value + "_" + print_type();
		return rv;
	}

	virtual int infer_type(SymTab* symtab){
		auto it = symtab->find(value);
		if(it == symtab->end()){
			yyerror("variable not declared\n");
		}
		this->type = it->second;
		return it->second;
	}
};

class Number_Expr_Int : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		int parsed_val = stoi(value); // TODO
		return "Num : " + to_string(parsed_val) + "<int>";
	}

	virtual int infer_type(SymTab* symtab){
		this->type = TYPE_INT;
		return TYPE_INT;
	}
};

class Number_Expr_Float : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		float parsed_val = stof(value); // TODO
        ostringstream temp; 
        temp.precision(2);
        temp << fixed << parsed_val;
		return "Num : " + temp.str() + "<float>";
	}

	virtual int infer_type(SymTab* symtab){
		this->type = TYPE_FLOAT;
		return TYPE_FLOAT;
	}
};

class String_Expr : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		return "String : " + value + "<string>";
	}

	virtual int infer_type(SymTab* symtab){
		this->type = TYPE_STRING;
		return TYPE_STRING;
	}
};

class Binary_Expr : public Expression {
public:
	Expression *left, *right;
	virtual string print(int num_spaces) = 0;
	virtual int infer_type(SymTab* symtab){
		left->infer_type(symtab);
		right->infer_type(symtab);
		if(left->type == right->type){
			if(left->type != TYPE_INT && left->type != TYPE_FLOAT ){
				yyerror("Not supported operand type for binary expression\n");
				return -1;
			}
			this->type = left->type;
			return this->type;
		}
		yyerror("Type Mismatch\n");
		return -1;
	}
};

class Div_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = "\n" +  ws1 + "Arith: Div" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")" ;
		return total;
	}	
};

class Mult_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = "\n" +  ws1 + "Arith: Mult" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")" ;
		return total;
	}	
	
};

class Minus_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = "\n" +  ws1 + "Arith: Minus" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")" ;
		return total;
	}	
};

class Plus_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = "\n" +  ws1 + "Arith: Plus" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")" ;
		return total;
	}	
};

class Boolean_Expr : public Binary_Expr {
public:
	string op;
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = "\n" +  ws1 + "Condition: " + op + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")" ;
		return total;
	}

	virtual int infer_type(SymTab* symtab){
		left->infer_type(symtab);
		right->infer_type(symtab);
		if(left->type == right->type){
			if(left->type != TYPE_BOOL){
				yyerror("Not supported operand type for binary expression\n");
				return -1;
			}
			this->type = left->type;
			return this->type;
		}
		yyerror("Type Mismatch\n");
		return -1;
	}	
};

class Relational_Expr : public Binary_Expr {
public:
	string op;
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = "\n" + ws1 + "Condition: " + op + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")" ;
		return total;
	}	

	virtual int infer_type(SymTab* symtab){
		left->infer_type(symtab);
		right->infer_type(symtab);
		if(left->type == right->type){
			if(left->type != TYPE_INT && left->type != TYPE_FLOAT ){
				yyerror("Not supported operand type for binary expression\n");
				return -1;
			}
			this->type = TYPE_BOOL;
			return TYPE_BOOL;
		}
		yyerror("Type Mismatch\n");
		return -1;
	}
};

class Unary_Expr : public Expression {
public:
	virtual string print(int num_spaces) = 0;
	virtual int infer_type(SymTab* symtab) = 0;
};

class UMinus_Expr : public Unary_Expr {
public:
	Expression* expression;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
        string ws2 = string(num_spaces+2, ' ');
        string ret;
        ret = print_type();
        string total = "\n" + ws1 + "Arith: Uminus"+ret+"\n" \
                     + ws2 + "L_Opd (" \
                     + expression->print(num_spaces+4) + ")";
        return total;
    }

	virtual int infer_type(SymTab* symtab){
		expression->infer_type(symtab);
		if(expression->type != TYPE_INT && expression->type != TYPE_FLOAT ){
			yyerror("Not supported operand type for uminus expression\n");
			return -1;
		}
		this->type = expression->type;
		return this->type;
	}

};

class Not_Expr : public Unary_Expr {
public:
	Expression* expression;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
        string ws2 = string(num_spaces+2, ' ');
        string ret;
        ret = print_type();
        string total = "\n" + ws1 + "Condition: NOT"+ret+"\n" \
                     + ws2 + "L_Opd (" \
                     + expression->print(num_spaces+4) + ")";
        return total;
    }

	virtual int infer_type(SymTab* symtab){
		expression->infer_type(symtab);
		if(expression->type != TYPE_BOOL){
			yyerror("Not supported operand type for uminus expression\n");
			return -1;
		}
		this->type = TYPE_BOOL;
		return TYPE_BOOL;
	}

};


class Ternary_Expr : public Expression {
public:
	virtual string print(int num_spaces) = 0;
};

class Conditional_Expr : public Ternary_Expr{
public:
    Expression* expression1;
    Expression* expression2;
    Expression* expression3;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
		string ws2 = string(num_spaces+4, ' ');
        string total = expression1->print(num_spaces+4) + "\n" \
                 + ws2 + "True_Part ("+expression2->print(num_spaces+6)+")\n" \
                 + ws2 + "False_Part ("+expression3->print(num_spaces+6)+")";
        return total;
    }

	virtual int infer_type(SymTab* symtab){
		expression1->infer_type(symtab);
		expression2->infer_type(symtab);
		expression3->infer_type(symtab);

		if(expression1->type != TYPE_BOOL){
			yyerror("First expression in ?: must be boolean\n");
			return -1;
		}

		if(expression2->type != expression3->type){
			yyerror("Expressions on both sides of COLON must be of same type\n");
			return -1;
		}

		this->type = expression2->type;
		return this->type;
	}
};


class Statement : public AST {
public:
	virtual string print(int num_spaces) = 0;    
	virtual int infer_type(SymTab* symtab) = 0;
};


class Assignment_Stmt : public Statement{
    
public:
    Expression* LHS;
    Expression* RHS;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
        string ws2 = string(num_spaces+2, ' ');
        string total = ws1 + "Asgn:\n" \
                     + ws2 + "LHS (" + LHS->print(num_spaces+4) + ")\n" \
                     + ws2 + "RHS (" + RHS->print(num_spaces+4) + ")\n" ;

        return total;
    }

	virtual int infer_type(SymTab* symtab){
		if(LHS->infer_type(symtab) != RHS->infer_type(symtab)){
			yyerror("Type mismatch\n");
			return -1;
		}
		return 0;
	}
};

class Read_Stmt : public Statement{
public:
    Expression* var_name;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
        string total = ws1 + "Read: " \
                     + var_name->print(num_spaces+4)+ "\n";
        return total;
    }

	virtual int infer_type(SymTab* symtab){
		int t = var_name->infer_type(symtab);
		if( t!=TYPE_INT && t!=TYPE_FLOAT ){
			yyerror("Can't read \n");
		}
		return 0;
	}

};


class Write_Stmt : public Statement{

public:
    Expression* expression;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
        string total = ws1 + "Write: " \
                     + expression->print(num_spaces+4) + "\n";
        return total;
    }

	virtual int infer_type(SymTab* symtab){
		int t = expression->infer_type(symtab);
		if( t!=TYPE_INT && t!=TYPE_FLOAT && t!=TYPE_STRING ){
			yyerror("Can't Print \n");
		}
		return 0;
	}
};

class Stmtlist : public AST {
public:
	vector<Statement*> statements;
	virtual string print(int num_spaces=9){
		string rv = "**BEGIN: Abstract Syntax Tree \n";
		for(Statement* it : statements){
			rv += it->print(num_spaces);
		}
		rv += "**END: Abstract Syntax Tree \n";
		return rv;
	}

	virtual int infer_type(SymTab* symtab){
		for(auto i: statements){
            i->infer_type(symtab);
        }
		return 0;
	}
};