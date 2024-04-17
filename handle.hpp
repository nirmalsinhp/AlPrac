#include <bits/stdc++.h>
using namespace std;

template <class T>
class Handle
{
    Handle() : p(0){};
    Handle(T *t) : p(t){};
    Handle(const Handle &other) : p(0)
    {
        if (other.p)
            other.p->clone();
    };

    Handle& operator=(const Handle& other)
    {
        if(this != &other)
        {
            delete p;
            p = (other.p) : p = other.p->clone() : 0;

        }
        return *this;    
    }

    operator bool() { return p;}

    Handle& operator*() 
    {
        if(p)
            return *p;
        throw runtime_error("unbound");
    }

    Handle* operator->() 
    {
        if(p)
            return p;
        throw runtime_error("unbound");
    }

private:
    T *p;
};

class F
{
    private:
    int f = 10;
};

class V
{
    private:
    int v = 11;
};

class T : public F,V
{
    private:
    int s = 5;
};

int main()
{

    shared_ptr<F> fs = make_shared<T>();
    shared_ptr<V> vs = fs;
    unique_ptr<int> u1 = make_unique<int>(30);
    unique_ptr<int> u2 = make_unique<int>(40);
    unique_ptr<int> u3 = u2;
    u1 = u3;
    shared_ptr<int> s1 = make_shared<int>(10);   
    shared_ptr<int> s2 = make_shared<int>(20);   
    shared_ptr<int> s3 = s1;
    s2 = s3;
    return 0;
}