#include <memory>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


class F
{
    public:
    F(int i):f(i){
        func();
    }
    virtual ~F() = default;
    F(const F& ) = default;

    protected:
    using X = double;

    F& operator=(const F& oth)
    {
        f = oth.f;
        cout << "F =" << endl;
        return *this;
    }

    virtual void func() 
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    private:
    int f = 10;
};

class V
{
    public:
    V(int i): v(i){}
    virtual ~V() = default;

    V(const V& ) = default;

    protected:
    V& operator=(const V& oth)
    {
        v = oth.v;
        cout << "V =" << endl;
        return *this;
    }

    private:
    int v = 11;
};

class T : public F, public V
{

    public:
    T(int t) : F(t), V(t), s(t){
        //func();
    }
    virtual ~T() = default;
    T(const T& o) = default;

    virtual void func() 
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    T& operator=(const T& o)
    {
        F::operator=(o);
        V::operator=(o);
        cout << "T =" << endl;
        s = o.s;
        return *this;
    }
    private:
    int X;
    vector<F::X> dx;
    // vector<X> dx; does not compile, name hiding.
    int s = 5;
};


int main(int argc, char** argv)
{
    // T* tm = new T();
    // shared_ptr<F> fs(tm);
    // //shared_ptr<V> vs(&tm);
    // shared_ptr<V> vs1(tm);

    T t(10);
    T t1(40);
    F* f1 = &t;
    F* f2 = &t1;
    cout << sizeof(*f2) << endl;
    cout << sizeof(t1) << endl;
    t = t1;
    //*f1 = *f2; // protected can not call

    /*cout << (void *) argv[argc] << endl;
    cout <<  argv[argc + 1] << endl;*/
    // this works because, environment variables are stored on stack like this.
    //*(char *) 0 = 0;
    // *reinterpret_cast<char*>(nullptr) = 0;
    // gcc puts a trap over here, so seg fault

    auto aup = make_unique<int []>(10);
    fill(aup.get(), aup.get() + 10, 22);
    copy(aup.get(), aup.get() + 10, ostream_iterator<int>(cout, " "));   
    return 0;
}