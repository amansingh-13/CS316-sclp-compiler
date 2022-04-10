#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "tac.hpp"
using namespace std;
extern int yyerror(char *);

#define TYPE_FLOAT  1
#define TYPE_BOOL   2
#define TYPE_STRING 3
#define TYPE_VOID   4
#define TYPE_FUNCTION 5
#define TYPE_INT    6

int tempIndex = 0;
int labelIndex = 0;
int specialTempIndex = 0;

string getNewTemp(){
	return "temp"+to_string(tempIndex++);
}

string getNewLabel(){
	return "Label"+to_string(labelIndex++);
}

string getNewSpecialTemp(){
	return "stemp"+to_string(specialTempIndex++);
}



typedef map<string, int> SymTab; 


class AST {
public:
	string place;
	string code;
	vector<TAC_Stmt*> tac_stmt_list;

	virtual string print(int num_spaces) = 0;
	virtual int infer_type(SymTab* symtab) = 0;
	virtual void generate_tac() = 0;
};

class Expression : public AST {
public:
	TAC_Opd* tac_result;
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

	virtual void generate_tac(){
		this->code = "";
		this->place = this->value+"_";

		this->tac_result = new Variable_Opd(this->place, this->type);
	}
};

class Number_Expr_Int : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		int parsed_val = atoi(value.c_str()); // TODO
		return "Num : " + to_string(parsed_val) + "<int>";
	}

	virtual int infer_type(SymTab* symtab){
		this->type = TYPE_INT;
		return TYPE_INT;
	}

	virtual void generate_tac(){
		this->code = "";
		this->place = to_string(atoi(value.c_str()));

		this->tac_result = new Int_Const_Opd(value, TYPE_INT);
	}
};

class Number_Expr_Float : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		double parsed_val = strtod(value.c_str(), NULL); // TODO
        ostringstream temp; 
        temp.precision(2);
        temp << fixed << parsed_val;
		return "Num : " + temp.str() + "<float>";
	}

	virtual int infer_type(SymTab* symtab){
		this->type = TYPE_FLOAT;
		return TYPE_FLOAT;
	}

	virtual void generate_tac(){
		this->code = "";
		double parsed_val = strtod(value.c_str(), NULL);
        ostringstream temp; 
        temp.precision(2);
        temp << fixed << parsed_val;
		this->place = temp.str();

		this->tac_result = new Float_Const_Opd(value, TYPE_FLOAT);
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

	virtual void generate_tac(){
		this->code = "";
		this->place = this->value;

		this->tac_result = new String_Const_Opd(value, TYPE_STRING);
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

	void binary_expr_generate_tac(string op_string, TAC_Op op_enum){
		this->left->generate_tac();
		this->right->generate_tac();
		string var = getNewTemp();
		string c3 = var + " = " + this->left->place + op_string + this->right->place + "\n";
		this->place = var;
		this->code = this->left->code + this->right->code + c3;

		for(auto x : this->left->tac_stmt_list){
			this->tac_stmt_list.push_back(x);
		}
		for(auto x : this->right->tac_stmt_list){
			this->tac_stmt_list.push_back(x);
		}
		// delete this->left->tac_stmt_list ?  --This method is not very optimal anyways

		this->tac_result = new Temporary_Opd(var, this->type);
		TAC_Stmt* stmt = new TAC_Compute_Stmt(
			this->tac_result, this->left->tac_result, op_enum, this->right->tac_result
		);
		this->tac_stmt_list.push_back(stmt);
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

	virtual void generate_tac(){
		binary_expr_generate_tac(" / ", Div_TAC_Op);
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

	virtual void generate_tac(){
		binary_expr_generate_tac(" * ", Mult_TAC_Op);	
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

	virtual void generate_tac(){
		binary_expr_generate_tac(" - ", Sub_TAC_Op);
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

	virtual void generate_tac(){
		binary_expr_generate_tac(" + ", Add_TAC_Op);
	}
};

class Boolean_Expr : public Binary_Expr {
private:
	string get_op_lexeme(){
		if      (op == "AND") return "&&";
		else if (op == "OR" ) return "||";
		else return "err"; // UNREACHABLE
	}
	TAC_Op get_tac_op_enum(){
		if      (op == "AND") return And_TAC_Op;
		else if (op == "OR" ) return Or_TAC_Op;
		else return Err_TAC_Op; // UNREACHABLE
	}
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

	virtual void generate_tac(){
		binary_expr_generate_tac(get_op_lexeme(), get_tac_op_enum());	
	}
};

class Relational_Expr : public Binary_Expr {
private:
	string get_op_lexeme(){
		if      (op == "LT") return "<" ;
		else if (op == "LE") return "<=";
		else if (op == "GT") return ">" ;
		else if (op == "GE") return ">=";
		else if (op == "NE") return "!=";
		else if (op == "EQ") return "==";
		else return "err"; // UNREACHABLE
	}
	TAC_Op get_tac_op_enum(){
		if      (op == "LT") return LT_TAC_Op;
		else if (op == "LE") return LE_TAC_Op;
		else if (op == "GT") return GT_TAC_Op;
		else if (op == "GE") return GE_TAC_Op;
		else if (op == "NE") return NE_TAC_Op;
		else if (op == "EQ") return EQ_TAC_Op;
		else return Err_TAC_Op; // UNREACHABLE
	}
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

	virtual void generate_tac(){
		binary_expr_generate_tac(get_op_lexeme(), get_tac_op_enum());	
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

	virtual void generate_tac(){
		this->expression->generate_tac();
		string var = getNewTemp();
		string c3 = var + " = " + " - " + this->expression->place + "\n";
		this->place = var;
		this->code = this->expression->code + c3;

		for(auto x : this->expression->tac_stmt_list){
			this->tac_stmt_list.push_back(x);
		}
		// delete this->expression->tac_stmt_list ?  --This method is not very optimal anyways

		this->tac_result = new Temporary_Opd(var, this->type);
		TAC_Stmt* stmt = new TAC_Compute_Stmt(
			this->tac_result, NULL, UMinus_TAC_Op, this->expression->tac_result
		);
		this->tac_stmt_list.push_back(stmt);
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

	virtual void generate_tac(){
		this->expression->generate_tac();
		string var = getNewTemp();
		string c3 = var + " = " + "!" + this->expression->place + "\n";
		this->place = var;
		this->code = this->expression->code + c3;

		for(auto x : this->expression->tac_stmt_list){
			this->tac_stmt_list.push_back(x);
		}
		// delete this->expression->tac_stmt_list ?  --This method is not very optimal anyways

		this->tac_result = new Temporary_Opd(var, this->type);
		TAC_Stmt* stmt = new TAC_Compute_Stmt(
			this->tac_result, NULL, Not_TAC_Op, this->expression->tac_result
		);
		this->tac_stmt_list.push_back(stmt);
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

	virtual void generate_tac(){
		expression1->generate_tac();
		
		string t2 = getNewSpecialTemp();
		string l1 = getNewLabel();
		string l2 = getNewLabel();

		expression2->generate_tac();
		expression3->generate_tac();
		
		string t1 = getNewTemp();

		this->code = expression1->code \
					+ t1 + " = !" + expression1->place + "\n" \
					+ "if (" + t1 + ") goto " + l1 + "\n"   \
					+ expression2->code \
					+ t2 + " = " + expression2->place + "\n"  \
					+ "goto " + l2 + "\n"  \
					+ l1 + ": \n" + expression3->code \
					+ t2 + " = " + expression3->place + "\n"  \
					+ l2 + ": \n";
		this->place = t2;

		TAC_Opd* cond = new Temporary_Opd(t1, TYPE_BOOL);
		Variable_Opd* result = new Variable_Opd(t2, this->type);
		Label_Opd* tac_l1 = new Label_Opd(l1);
		Label_Opd* tac_l2 = new Label_Opd(l2);

		this->tac_result = result;

		for(auto x : this->expression1->tac_stmt_list)
			this->tac_stmt_list.push_back(x);

		this->tac_stmt_list.push_back(new TAC_Compute_Stmt(cond, NULL, Not_TAC_Op, this->expression1->tac_result));
		this->tac_stmt_list.push_back(new TAC_If_Stmt(cond, tac_l1));

		for(auto x : this->expression2->tac_stmt_list)
			this->tac_stmt_list.push_back(x);

		this->tac_stmt_list.push_back(new TAC_Asgn_Stmt(result, this->expression2->tac_result));
		this->tac_stmt_list.push_back(new TAC_Goto_Stmt(tac_l2));
		this->tac_stmt_list.push_back(new TAC_Label_Stmt(tac_l1));

		for(auto x : this->expression2->tac_stmt_list)
			this->tac_stmt_list.push_back(x);
		
		this->tac_stmt_list.push_back(new TAC_Asgn_Stmt(result, this->expression3->tac_result));
		this->tac_stmt_list.push_back(new TAC_Label_Stmt(tac_l2));
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
        string total = "\n" + ws1 + "Asgn:\n" \
                     + ws2 + "LHS (" + LHS->print(num_spaces+4) + ")\n" \
                     + ws2 + "RHS (" + RHS->print(num_spaces+4) + ")" ;

        return total;
    }

	virtual int infer_type(SymTab* symtab){
		if(LHS->infer_type(symtab) != RHS->infer_type(symtab)){
			yyerror("Type mismatch\n");
			return -1;
		}
		return 0;
	}

	virtual void generate_tac(){
		LHS->generate_tac();
		RHS->generate_tac();
		string c1 = LHS->place + " = " + RHS->place + "\n";
		this->code = RHS->code + c1;
		this->place = "";
	}
};

class Read_Stmt : public Statement{
public:
    Expression* var_name;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
        string total = "\n" + ws1 + "Read: " \
                     + var_name->print(num_spaces+4);
        return total;
    }

	virtual int infer_type(SymTab* symtab){
		int t = var_name->infer_type(symtab);
		if( t!=TYPE_INT && t!=TYPE_FLOAT ){
			yyerror("Can't read \n");
		}
		return 0;
	}

	virtual void generate_tac(){
		var_name->generate_tac();
		this->place = "";
		this->code = "read " + var_name->place + "\n";
	}
};


class Write_Stmt : public Statement{

public:
    Expression* expression;

    virtual string print(int num_spaces){
        string ws1 = string(num_spaces, ' ');
        string total = "\n" + ws1 + "Write: " \
                     + expression->print(num_spaces+4);
        return total;
    }

	virtual int infer_type(SymTab* symtab){
		int t = expression->infer_type(symtab);
		if( t!=TYPE_INT && t!=TYPE_FLOAT && t!=TYPE_STRING ){
			yyerror("Can't Print \n");
		}
		return 0;
	}

	virtual void generate_tac(){
		expression->generate_tac();
		this->place = "";
		this->code = expression->code + "write " + expression->place + "\n";
	}
};


class If_Statement : public Statement{
public:
	Expression* if_condition;
	Statement* ThenPart;
	Statement* ElsePart;

	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
		string ws2 = string(num_spaces+2, ' ');
		string total = "\n" + ws1 + "If: \n" \
					+ ws2 + "Condition (" \
					+ if_condition->print(num_spaces+4) + ")\n" \
					+ ws2 + "Then (" \
					+ ThenPart->print(num_spaces+4) + ")";

		if(ElsePart != NULL){
			total += "\n" + ws2 + "Else (" + ElsePart->print(num_spaces+4) + ")";
		}

		return total;
	}

	virtual int infer_type(SymTab* symtab){
		
		if_condition->infer_type(symtab);
		ThenPart->infer_type(symtab);
		if(ElsePart != NULL){
			ElsePart->infer_type(symtab);
		}

		if(if_condition->type != TYPE_BOOL){
			yyerror("If Condition type must be boolean \n");
			return -1;
		}
		return 0;
	}

	virtual void generate_tac(){
		if_condition->generate_tac();
		ThenPart->generate_tac();
		
		string t1 = getNewTemp();

		this->place = "";
		this->code = if_condition->code + t1 + " = ! " + if_condition->place;
		
		string l1 = getNewLabel();
		string l2;
		

		if(ElsePart!=NULL){
			l2 = getNewLabel();
			ElsePart->generate_tac();
			
			this->code += "\nif(" + t1 + ") goto " + l2 + "\n";
		}
		else{
			this->code += "\nif(" + t1 + ") goto " + l1 + "\n";
		}

		
		this->code += ThenPart->code + "goto "+ l1 + "\n";

		if(ElsePart!=NULL){
			this->code += l2 + ":\n" + ElsePart->code;
		}
		this->code += l1 + ":\n";
	}

};



class While_Statement : public Statement{
public:
	Expression* condition;
	Statement* body;

	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
		string ws2 = string(num_spaces+2, ' ');
		string total = "\n" + ws1 + "While: \n" \
					+ ws2 + "Condition (" \
					+ condition->print(num_spaces+4) + ")\n" \
					+ ws2 + "Body (" \
					+ body->print(num_spaces+4) + ")";

		return total;
	}

	virtual int infer_type(SymTab* symtab){
		
		condition->infer_type(symtab);
		body->infer_type(symtab);
		

		if(condition->type != TYPE_BOOL){
			yyerror("If Condition type must be boolean \n");
			return -1;
		}

		return 0;
	}

	virtual void generate_tac(){
		condition->generate_tac();
		body->generate_tac();
		this->place = "";
		string t1 = getNewTemp();
		string l1 = getNewLabel();
		string l2 = getNewLabel();
		this->code = l1 + ":\n" + condition->code + t1 + " = !" + condition->place + "\nif(" + t1 + ") goto "+ l2 + "\n" + body->code + "goto " + l1 + "\n" + l2 + ":\n" ;
	}

};





class DoWhile_Statement : public Statement{
public:
	Expression* condition;
	Statement* body;

	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, ' ');
		string ws2 = string(num_spaces+2, ' ');
		string total = "\n" + ws1 + "Do:\n" \
					+ ws2 + "Body (" \
					+ body->print(num_spaces+4) + ")\n" \
					+ ws2 + "While Condition (" \
					+ condition->print(num_spaces+4) + ")";

		return total;
	}

	virtual int infer_type(SymTab* symtab){
		
		condition->infer_type(symtab);
		body->infer_type(symtab);
		
		if(condition->type != TYPE_BOOL){
			yyerror("If Condition type must be boolean \n");
			return -1;
		}

		return 0;
	}

	virtual void generate_tac(){
		
		body->generate_tac();
		this->place = "";
		
		string l1 = getNewLabel();
		this->code = l1 + ":\n" + body->code;
		condition->generate_tac();
		this->code += condition->code + "\nif (" + condition->place + ") goto "+ l1 + "\n";
	}

};

class Stmtlist : public AST {
public:
	vector<Statement*> statements;
	virtual string print(int num_spaces=9){
		string rv = "";
		for(Statement* it : statements){
			rv += it->print(num_spaces);
		}
		return rv;
	}

	virtual int infer_type(SymTab* symtab){
		for(auto i: statements){
            i->infer_type(symtab);
        }
		return 0;
	}

	virtual void generate_tac(){
		string s = "**BEGIN: Three Address Code Statements\n";
		for(Statement* it : statements){
			it->generate_tac();
			s += it->code;
		}
		s += "**END: Three Address Code Statements\n";
		if(statements.size() == 0){
			s = "";
		}
		this->code = s;
		this->place = "";
	}
};

class Compound_Statement : public Statement{
public:
	Stmtlist* stmts;

	virtual string print(int num_spaces){
		return stmts->print(num_spaces);
	}

	virtual int infer_type(SymTab* symtab){
		stmts->infer_type(symtab);
		return 0;
	}

	virtual void generate_tac(){
		string s = "";
		for(Statement* it : stmts->statements){
			it->generate_tac();
			s += it->code;
		}
		this->place = "";
		this->code = s;
	}

};