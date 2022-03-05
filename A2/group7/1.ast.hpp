#define TYPE_INT    0
#define TYPE_FLOAT  1
#define TYPE_BOOL   2
#define TYPE_STRING 3

class AST{

}

class Expression_Ast : public AST {
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
			default           : { exit(1); } // should be UNREACHABLE
		}
		return rv;
	}
}


class Statement_Ast : public AST {
    
}

class Base_Expr : public Expression_Ast {
public:
	string value;
	virtual string print(int num_spaces) = 0;
}

class Name_Expr : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		string rv = "Name : " + value + "_" + print_type();
		return ret;
	}
}

class Number_Expr_Int : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		int parsed_val = ; // TODO
		return "Num : " + to_string(parsed_val) + "<int>";
	}
}

class Number_Expr_Float : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		float parsed_val = ; // TODO
		return "Num : " + to_string(parsed_val) + "<float>";
	}
}

class String_Expr : public Base_Expr {
public:
	virtual string print(int num_spaces)
	{
		return "String : " + value + "<string>";
	}
}

class Binary_Expr : public Expression_Ast {
public:
	Expression *left, *right;
	virtual string print(int num_spaces) = 0;
}

class Div_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, " ");
        	string ws2 = string(num_spaces+2, " ");
        	string total = ws1 + "Arith: Div" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
}
class Mult_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, " ");
        	string ws2 = string(num_spaces+2, " ");
        	string total = ws1 + "Arith: Mult" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
}
class Minus_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, " ");
        	string ws2 = string(num_spaces+2, " ");
        	string total = ws1 + "Arith: Minus" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
}
class Plus_Expr : public Binary_Expr {
public:
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, " ");
        	string ws2 = string(num_spaces+2, " ");
        	string total = ws1 + "Arith: Plus" + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
}
class Boolean_Expr : public Binary_Expr {
public:
	string op;
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, " ");
        	string ws2 = string(num_spaces+2, " ");
        	string total = ws1 + "Condition: " + op + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
}
class Relational_Expr : public Binary_Expr {
public:
	string op;
	virtual string print(int num_spaces){
		string ws1 = string(num_spaces, " ");
        	string ws2 = string(num_spaces+2, " ");
        	string total = ws1 + "Condition: " + op + print_type() + "\n" \
		             + ws2 + "L_Opd (" + left->print(num_spaces+4) + ")\n" \
                             + ws2 + "R_Opd (" + right->print(num_spaces+4) + ")\n" ;
		return total;
	}	
}

class Ternary_Expr : public Expression_Ast {
public:
	virtual string print(int num_spaces) = 0;
}

class Unary_Expr : public Expression_Ast {
public:
	virtual string print(int num_spaces) = 0;
}
