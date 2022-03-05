#include <iostream>
#include <string>
using namespace std;

class AST{

}

class Expression_Ast : public AST {
    virtual string print(int num_spaces)=0;
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
    Expression_Ast* Expression_Ast;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, " ");
        string total = ws1 + "Read: " \
                     + var_name->print();
        return total;
    }
}
