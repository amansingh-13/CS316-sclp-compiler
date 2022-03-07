#include<stdio.h>

class A {
    public:
    virtual void doit() = 0;
};

class B : public A {

};

class C : public B {
    public:
    virtual void doit(){
        printf("Hello\n");
    }
};

int main(){
    C c;
    c.doit();
}