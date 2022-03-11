#include "std_lib_facilities.h"

class B1 {
public:
    virtual void vf() { cout << "B1::vf()" << endl; }
    void f() { cout << "B1::f()" << endl; }
    virtual void pvf() = 0;
};

class D1 : public B1 {
public:
    void vf() override { cout << "D1::vf()" << endl; }
    void f() { cout << "D1::f()" << endl; }
};

class D2 : public D1 {
public:
    void pvf() override { cout << "D2::pvf()" << endl; }
};

class B2 {
public:
    virtual void pvf() =0;
};

class D21 : public B2 {
public:
    void pvf() override { cout << s << endl; }
    string s;
};

class D22 : public B2 {
public:
    void pvf() override { cout << n << endl;}
    int n;
};

void f(B2& b2)
{
    b2.pvf();
}

int main() {
    //B1 b1;
    //b1.vf();
    //b1.f();

    //D1 d1;
    //d1.vf();
    //d1.f();

    //B1& bref = d1;
    //bref.vf();
    //bref.f();

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    D21 d21;
    d21.s = "D21 string";
    
    D22 d22;
    d22.n = 100;
    f(d21);
    f(d22);
        
}
