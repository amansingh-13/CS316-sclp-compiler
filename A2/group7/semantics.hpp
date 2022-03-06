#include "ast.hpp"

#define IS_DEFINITION 1
#define IS_DECLARATION 0
extern int yyerror(char *);

string print_type(int type){
    string rv;
    switch(type){
        case(TYPE_INT)    : { rv = "<int>"   ; break; }
        case(TYPE_VOID)   : { rv = "<void>"  ; break; }
        case(TYPE_FLOAT)  : { rv = "<float>" ; break; }
        case(TYPE_BOOL)   : { rv = "<bool>"  ; break; }
        case(TYPE_STRING) : { rv = "<string>"; break; }
        default           : { return "<err>";  } // should be UNREACHABLE
    }
    return rv;
}

class Function{
public:
    string Name;
    SymTab* Local_Symtab;
    SymTab* Param_List;
    Stmtlist* stmtlist;
    int return_type;
    bool decl_or_def;

    int infer_type(SymTab* global_symtab){
        for(auto vars : *global_symtab){
            Local_Symtab->insert(pair<string, int>(vars.first, vars.second));
        }
        stmtlist->infer_type(Local_Symtab);
        return return_type;
    }

    virtual string print(int num_spaces=9){
		string rv = "**PROCEDURE: "+Name+"\n"; //TODO
        rv += "\tReturn Type: "+print_type(return_type)+"\n";
        rv += "\tFormal Parameters:"+"\n";
		for(auto it : *Param_List){
			rv += it->print(num_spaces);
		}
		rv += "**END: Abstract Syntax Tree\n";
		return rv;
	}

};

class Program{
public:
    SymTab* Global_Symtab;
    vector<Function*> functions;
    void infer_type(){
        for(auto i: functions){
            i->infer_type(Global_Symtab);
        }
    }

    string print(){
        string s = "";
        for(auto i: functions){
            s += i->print();
        }
        return s;
    }
};
