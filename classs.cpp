#include <bits/stdc++.h>
using namespace std;

class B
{
    public:
    virtual void func()
    {
        cout << "BF" << __PRETTY_FUNCTION__ << endl;
    }
    void func(char c)
    {
        cout << "DF" << __PRETTY_FUNCTION__ << endl;
    }

    void hf(int hf)
    {
        cout << "BHF" << __PRETTY_FUNCTION__ << endl;
    }

    void vhf(int&& hf)
    {
        cout << "BHF" << __PRETTY_FUNCTION__ << endl;
    }

    int df() = delete;

};

class D : public B
{
    public:
    virtual void func()
    {
        cout << "VDF" << __PRETTY_FUNCTION__ << endl;
    }
    
    void hf(string shf)
    {
        cout << "DHF" << __PRETTY_FUNCTION__ << endl;
    }

    using B::vhf;
    void vhf(string shf)
    {
        cout << "vDHF" << __PRETTY_FUNCTION__ << endl;
    }

};

int main()
{
    map<int,int> m;
    auto it = m.begin();
    D d;
    B* b = new D();
    b->func();
    // b->hf("nirmal"); // function is not virtual so base class version is called, fails due to type mismatch
    d.hf("nira");
    //d.hf(3); // base class function not visible/hidden by derived class function with same name.
    int in = 3;
    d.vhf(in);
    d.vhf("3");
    // d.df(); can delete any functions
    mutex m1, m2;
 /* mutex copy ctor is deleted, and move ctor is not defined by default so move or copy does not work on it.
    mutex m3 = m1;
    mutex m4 = move(m2); */
    return 0;
}