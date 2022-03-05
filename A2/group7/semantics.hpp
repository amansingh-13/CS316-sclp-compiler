#include "ast.hpp"
#include <map>

typedef map<string, int> SymTab; 

class Function{
public:
    string Name;
    SymTab* Local_Symtab;
    SymTab* Param_List;
    Stmtlist* stmtlist;
    int return_type;
};

class Program{
public:
    SymTab Global_Symtab;
    vector<Function*> functions;
};
