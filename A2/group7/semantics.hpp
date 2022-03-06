#include "ast.hpp"
#include <map>

typedef map<string, int> SymTab; 

#define IS_DEFINITION 1
#define IS_DECLARATION 0

class Function{
public:
    string Name;
    SymTab* Local_Symtab;
    SymTab* Param_List;
    Stmtlist* stmtlist;
    int return_type;
    bool decl_or_def;
};

class Program{
public:
    SymTab* Global_Symtab;
    vector<Function*> functions;
};
