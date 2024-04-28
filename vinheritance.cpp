#include <bits/stdc++.h>
using namespace std;

class A
{
    public:
    A()
    {
        std::cout << "Creating A" << endl;
    }

    int a;
};

class B : virtual public A
{
    public:
    B()
    {
        std::cout << "Creating B" << endl;
    }

    int b;
};

class C : virtual public A
{
    public:
    C()
    {
        std::cout << "Creating C" << endl;
    }
    void func1()
    {
        std::cout << "finc1 C" << endl;
    }

    int c;
};

class D : public B, public C
{
    public:
    D()
    {
        std::cout << "Creating D" << endl;
    }

    int func1();

    int d;
};

int D::func1()
{
    //using C::func1;
    C::func1();
    return 1;
}

int main()
{
    D d;
    // set<A> aset;
    // A a, b, c;
    // aset.insert(a);
    // aset.insert(b);
    // aset.insert(c);
    d.func1();

    return 0;

}