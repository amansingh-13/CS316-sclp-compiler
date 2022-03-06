#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map <string, int> mymap;
    cout<<mymap["two"]<<endl;
    mymap["one"] = 5;
    cout<<mymap["one"]<<endl;
}


