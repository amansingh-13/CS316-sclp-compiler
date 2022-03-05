#include <iostream>
#include <string>
using namespace std;

class AST{

}

class Expression_Ast : public AST {
public:
	int type;
	virtual string print(int num_spaces) = 0;
}


class Statement_Ast : public AST {
    
}


class Assignment_Stmt_Ast : public Statement_Ast{
    
public:
    Expression_Ast* LHS;
    Expression_Ast* RHS;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, " ");
        string ws2 = string(num_spaces+2, " ");
        string total = ws1 + "Asgn:\n" \
                     + ws2 + "LHS (" + LHS->print(num_spaces+4) + ")\n" \
                     + ws2 + "RHS (" + RHS->print(num_spaces+4) + ")\n" ;

        return total;
    }
}

class Read_Stmt_Ast : public Statement_Ast{
public:
    Expression_Ast* var_name;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, " ");
        string total = ws1 + "Read: " \
                     + var_name->print(num_spaces+4);
        return total;
    }

}


class Write_Stmt_Ast : public Statement_Ast{

public:
    Expression_Ast* expression;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, " ");
        string total = ws1 + "Read: " \
                     + expression->print(num_spaces+4);
        return total;
    }
}



class Unary_Expr : public Expression_Ast {
public:
	virtual string print(int num_spaces) = 0;
}

class UMinus_Expr_Ast : public Unary_Expr {
	Expression_Ast* expression;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, " ");
        string ws2 = string(num_spaces+2, " ");
        string ret;
        ret = print_type(expression->type);
        string total = "Arith: Uminus"+ret+"\n" \
                     + ws2 + "L_Opd (" \
                     + expression->print(num_spaces+4) + ")";
        return total;
    }

}


class Ternary_Expr : public Expression_Ast {
public:
	virtual string print(int num_spaces) = 0;
}

class Conditional_Expr_Ast : public Ternary_Expr{
public:
    Expression_Ast* expression1;
    Expression_Ast* expression2;
    Expression_Ast* expression3;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, " ");
        string total = expression1->print() \
                 + "True_Part ("+expression2->print()+")" \
                 + "False_Part ("+expression3->print()+")";
        return total;
    }
}
