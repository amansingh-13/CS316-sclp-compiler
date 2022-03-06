#include <iostream>
#include <string>
#include <vector>
using namespace std;


#define TYPE_INT    0
#define TYPE_FLOAT  1
#define TYPE_BOOL   2
#define TYPE_STRING 3

// why are Expression and Statement inheriting from AST ? 


class AST {
public:
	virtual string print(int num_spaces) = 0;    
};

class Expression : public AST {
public:
	int type;
	virtual string print(int num_spaces) = 0;
	string print_type(){
		string rv;
		switch(type){
			case(TYPE_INT)    : { rv = "<int>"   ; break; }
			case(TYPE_FLOAT)  : { rv = "<float>" ; break; }
			case(TYPE_BOOL)   : { rv = "<bool>"  ; break; }
			case(TYPE_STRING) : { rv = "<string>"; break; }
			default           : { return "err";  } // should be UNREACHABLE
		}
		return rv;
	}
};


class Base_Expr : public Expression {
public:
	string value;
	virtual string print(int num_spaces) = 0;
};

class Name_Expr : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		string rv = "Name : " + value + "_" + print_type();
		return rv;
	}
};

class Number_Expr_Int : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		int parsed_val = stoi(value); // TODO
		return "Num : " + to_string(parsed_val) + "<int>";
	}
};

class Number_Expr_Float : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		float parsed_val = stof(value); // TODO
		return "Num : " + to_string(parsed_val) + "<float>";
	}
};

class String_Expr : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		return "String : " + value + "<string>";
	}
};

class Binary_Expr : public Expression {
public:
	Expression *left, *right;
	virtual string print(int num_spaces) = 0;
	virtual void infer_type(){
		if(left->type == right->type){
			
		}
	}
};

class Div_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = ws1 + "Arith: Div" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
};

class Mult_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = ws1 + "Arith: Mult" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
	
};

class Minus_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = ws1 + "Arith: Minus" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
};

class Plus_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = ws1 + "Arith: Plus" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
};

class Boolean_Expr : public Binary_Expr {
public:
	string op;
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = ws1 + "Condition: " + op + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
};

class Relational_Expr : public Binary_Expr {
public:
	string op;
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
        	string ws2 = string(num_spaces+2, ' ');
        	string total = ws1 + "Condition: " + op + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
};

class Unary_Expr : public Expression {
public:
	virtual string print(int num_spaces) = 0;
};

class UMinus_Expr : public Unary_Expr {
public:
	Expression* expression;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
        string ws2 = string(num_spaces+2, ' ');
        string ret;
        ret = print_type();
        string total = "Arith: Uminus"+ret+"\n" \
                     + ws2 + "L_Opd (" \
                     + expression->print(num_spaces+4) + ")";
        return total;
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
        string total = "Condition: NOT"+ret+"\n" \
                     + ws2 + "L_Opd (" \
                     + expression->print(num_spaces+4) + ")";
        return total;
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
        string total = expression1->print(num_spaces+4) \
                 + "True_Part ("+expression2->print(num_spaces+4)+")" \
                 + "False_Part ("+expression3->print(num_spaces+4)+")";
        return total;
    }
};


class Statement : public AST {
public:
	virtual string print(int num_spaces) = 0;    
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
};

class Read_Stmt : public Statement{
public:
    Expression* var_name;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
        string total = ws1 + "Read: " \
                     + var_name->print(num_spaces+4);
        return total;
    }

};


class Write_Stmt : public Statement{

public:
    Expression* expression;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
        string total = ws1 + "Read: " \
                     + expression->print(num_spaces+4);
        return total;
    }
};

class Stmtlist : public AST {
public:
	vector<Statement*> statements;
	virtual string print(int num_spaces=9){
		string rv = "**BEGIN: Abstract Syntax Tree\n";
		for(Statement* it : statements){
			rv += it->print(num_spaces);
		}
		rv += "**END: Abstract Syntax Tree\n";
		return rv;
	}
};