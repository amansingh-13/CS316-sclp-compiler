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
    vector<pair<string, int>>* Param_List;
    Stmtlist* stmtlist;
    int return_type;
    bool decl_or_def;

    int infer_type(SymTab* global_symtab){
        for(auto vars : *global_symtab){
            Local_Symtab->insert(pair<string, int>(vars.first, vars.second));
        }
        auto it = Local_Symtab->find("main");
        if( it != Local_Symtab->end()){
            yyerror("main cannot be a variable\n");
        }
        stmtlist->infer_type(Local_Symtab);
        return return_type;
    }

    virtual string print(int num_spaces=9){
		string rv = "**PROCEDURE: " + Name + "\n"; //TODO
        rv += "\tReturn Type: " + print_type(return_type) + "\n";
        rv += "\tFormal Parameters:\n";
		for(auto it : *Param_List){
			rv += "\t\t" + it.first + "_  Type:" + print_type(it.second) + "\n";
		}
		rv += stmtlist->print();
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

    int weird_check_for_A2(){
        switch(functions.size()){
            case(1) : { 
                if(functions[0]->Name != "main" || functions[0]->return_type != TYPE_VOID){
                    yyerror("something is wrong with the main function\n");
                    return -1;
                }
                break;
            }
            case(2) : { 
                if ( 
                    functions[0]->Name != "main" || 
                    functions[0]->return_type != TYPE_VOID || 
                    functions[0]->decl_or_def != IS_DECLARATION ||
                    functions[1]->Name != "main" || 
                    functions[1]->return_type != TYPE_VOID || 
                    functions[1]->decl_or_def != IS_DEFINITION ||
                    functions[0]->Param_List->size() != functions[1]->Param_List->size()
                ){
                    yyerror("something is wrong\n");
                    return -1;
                }

                //check param list
                for(int i=0; i<functions[0]->Param_List->size(); i++){
                    if(
                        (*(functions[0]->Param_List))[i].second != (*(functions[1]->Param_List))[i].second
                    ){
                        yyerror("something is wrong with parameter list\n");
                        return -1;
                    }
                }
                break;
            }
            default : {
                yyerror("something is wrong with # of functions\n");
                return -1;
            }
        }
    }
};
