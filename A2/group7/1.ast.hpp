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
}


class Statement_Ast : public AST {
    
}

class Base_Expr : public Expression_Ast {
public:
	virtual string print(int num_spaces) = 0;
}

class Name_Expr : public Base_Expr {
public:
	string name;
	virtual string print(int num_spaces)
	{
		string ret = "Name : " + name + "_";
		switch(type){
			case(TYPE_INT)    : { ret += "<int>"   ; break; }
			case(TYPE_FLOAT)  : { ret += "<float>" ; break; }
			case(TYPE_BOOL)   : { ret += "<bool>"  ; break; }
			case(TYPE_STRING) : { ret += "<string>"; break; }
			default           : { exit(1); } // should be UNREACHABLE
		}
		return ret;
	}
}

class Number_Expr_Int : public Base_Expr {
public:
	int value;	
	virtual string print(int num_spaces)
	{
		return "Num : " + to_string(value) + "<int>";
	}
}

class Number_Expr_Float : public Base_Expr {
public:
	float value;	
	virtual string print(int num_spaces)
	{
		return "Num : " + to_string(value) + "<float>";
	}
}

class String_Expr : public Base_Expr {
public:
	string value;
	virtual string print(int num_spaces)
	{
		return "String : " + value + "<string>";
	}
}

class Binary_Expr : public Expression_Ast {
public:
	virtual string print(int num_spaces) = 0;
}

class Ternary_Expr : public Expression_Ast {
public:
	virtual string print(int num_spaces) = 0;
}

class Unary_Expr : public Expression_Ast {
public:
	virtual string print(int num_spaces) = 0;
}
