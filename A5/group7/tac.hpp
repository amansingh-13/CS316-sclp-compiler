#include <string>
using namespace std;

enum TAC_Op {
    Add_TAC_Op,
    Sub_TAC_Op,
    Div_TAC_Op,
    Mult_TAC_Op,
    GT_TAC_Op,
    LT_TAC_Op,
    GE_TAC_Op,
    LE_TAC_Op,
    EQ_TAC_Op,
    NE_TAC_Op,
    And_TAC_Op,
    Or_TAC_Op,
    Not_TAC_Op,
    UMinus_TAC_Op,
    Err_TAC_Op,
};

class TAC_Opd {
public:
    string val;
    int type;
    TAC_Opd(string v, int t){
        val = v;
        type = t;
    }
};

class Int_Const_Opd : public TAC_Opd {
public:
    Int_Const_Opd(string v, int t) : TAC_Opd(v, t) {}
};

class Float_Const_Opd : public TAC_Opd {
public:
    Float_Const_Opd(string v, int t) : TAC_Opd(v, t) {}
};

class String_Const_Opd : public TAC_Opd {
public:
    String_Const_Opd(string v, int t) : TAC_Opd(v, t) {}
};

class Label_Opd : public TAC_Opd {
public:
    Label_Opd(string v) : TAC_Opd(v, NULL) {}
};

class Temporary_Opd : public TAC_Opd {
public:
    Temporary_Opd(string v, int t) : TAC_Opd(v, t) {}
};

class Variable_Opd : public TAC_Opd {
public:
    Variable_Opd(string v, int t) : TAC_Opd(v, t) {}
};


class TAC_Stmt {
public:
};

class TAC_Compute_Stmt : public TAC_Stmt {
public:
    TAC_Opd* lval, *rval_lhs, *rval_rhs;
    TAC_Op rval_op;
    TAC_Compute_Stmt(TAC_Opd* l, TAC_Opd* rl, TAC_Op ro, TAC_Opd* rr) {
        lval = l;
        rval_lhs = rl;
        rval_rhs = rr;
        rval_op  = ro;
    }
};

class TAC_Asgn_Stmt : public TAC_Stmt {
public:
    Variable_Opd* lval;
    TAC_Opd* rval;
    TAC_Asgn_Stmt(Variable_Opd* l, TAC_Opd* r){
        lval = l;
        rval = r;
    }
};

class TAC_Goto_Stmt : public TAC_Stmt {
public:
    Label_Opd* label;
    TAC_Goto_Stmt(Label_Opd* l){
        label = l;
    }
};

class TAC_If_Stmt : public TAC_Stmt {
public:
    TAC_Opd* cond;
    Label_Opd* label;
    TAC_If_Stmt(TAC_Opd* c, Label_Opd* l){
        cond = c;
        label = l;
    }
};

class TAC_Read_Stmt : public TAC_Stmt {
public:
    Variable_Opd* var;
    TAC_Read_Stmt(Variable_Opd* v){
        var = v;
    }
};

class TAC_Write_Stmt : public TAC_Stmt {
public:
    TAC_Opd* expr;
    TAC_Write_Stmt(TAC_Opd* e){
        expr = e;
    }
};

class TAC_Label_Stmt : public TAC_Stmt {
public:
    Label_Opd* label;
    TAC_Label_Stmt(Label_Opd* l){
        label = l;
    }  
};
