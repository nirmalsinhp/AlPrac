#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;


template <typename T, template <typename ...> class container> 
static void print_container(const container<T>& C, std::string del = " ")
{
    for(const auto& c: C)
        cout << c << " ";
    cout << endl;
}

template <typename T, template <typename ...> class container> 
static void print_container_copy(const container<T>& C, ostream& stream=cout, string del = " ")
{
   copy(C.begin(), C.end(),
        ostream_iterator<T>(stream, del.c_str()));
    stream << endl;
}

template <typename inputIterator> 
static void print_container_iter(inputIterator first, inputIterator last, ostream& stream = cout, string del = " ")
{
   copy(first, last,
        ostream_iterator<decltype(*first)>(stream, del.c_str()));
    stream << endl;
    
}

class isEven: public unary_function<int, bool>
{
    public:
    bool operator()(int i)
    {
           return (i % 2 == 0);
    }
};

// functor, just define operator()
/* functors needs to be small, doing simple things, are copied by default, implement deep copy in case of state is there in funtions, do not add polymorphic elements like virtual functions.*/
template <typename T>
struct isOdd
{
    bool operator()(T t) const 
    {
        return (t % 2 == 1);
    }

};

class FN
{
    public:
    void f1(int a, int b)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void f2(int a, int b)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    
    void fc(int a, int b) const
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    static void fs(int a, int b)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

};

auto add(float a, float b)
{
    return a+b;
}

float sub(float a, float b)
{
    return a - b;
}

typedef float (*rfuc)(float, float);

rfuc give_funtion(char op)
{
    if(op == '+')
        return &add;
    else 
        return &sub;
}


bool less3(int i)
{
    return i < 3;
}

class Point
{
    public:
    Point(int ina = 0, int inb = 0):a(ina), b(inb)
    {

    }
    ~Point() =  default;
    bool isOrigin() const
    {
        return (a == 0 && b == 0);
    }

    void print()
    {
        cout << typeid(*this).name() << " :" << a << ", " << b << endl;
    }
    private:
    int a;
    int b;
};

int main()
{
    isEven ie;
    isOdd<int> io;

    cout << std::boolalpha <<  ie(4) << endl;
    cout << std::boolalpha <<  io(4) << endl;
    float (*fopp)(float, float) = &add;
    float (*fopm)(float, float) = &sub;

    cout <<  fopp(4.3, 2.4) << endl;
    cout <<  (*fopm)(4.5, 2.5) << endl;


    FN fo;
    void (FN::*mb1)(int, int) = nullptr;
    void (FN::*mbc)(int, int) const = nullptr;
    void (*mbs)(int, int) = nullptr;

    cout << "calling f1" << endl;
    mb1 = &FN::f1;
    (fo.*mb1)(1, 2);
    cout << "calling f2" << endl;
    mb1 = &FN::f2;
    (fo.*mb1)(1, 2);

    cout << "calling fc" << endl;
    mbc = &FN::fc;
    (fo.*mbc)(1, 2);

    cout << "calling fs" << endl;
    mbs = &FN::fs;
    //(f1.*mbs)(1, 2);

    (*mbs)(1, 2);

    auto rf = give_funtion('c');
    cout << rf(1, 2) << endl;

    vector<int> v(20);
    vector<int> v2;
    vector<int> v3;
    deque<int> odds;
    iota(v.begin(), v.end(), 1);
    auto val = count_if(v.begin(), v.end(), isEven()); // functor
    // vector 1 element, a * a, vector 2 me insert.
    transform(v.begin(), v.begin() + 10, back_inserter(v2), [](const int& a) {return a * a;}); // lambda 
    // take 2 range
    transform(v.begin() + 10, v.end(), v.begin()+ 10, back_inserter(v3), multiplies<>()); // STL functor , binary
    // take 2 range, ith element - multiplies, 
    transform(v.begin(), v.end(), v2.begin(), back_inserter(v2), multiplies<>()); // STL functor , binary

    cout << "Evens :" << val << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " ,"));
    cout << endl;
    transform(v2.begin(), v2.end(), v2.begin(), bind(divides<int>(), placeholders::_1, 3)); // functor adaptor, bind
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " ,"));
    cout << endl;
    transform(v.begin(), v.end(), v2.begin(), v2.begin(), [](auto a, auto b) { return a + b;}); // generic lambda
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " ,"));
    cout << endl;

    string s = "string with spaces ";
    auto it = remove_if(s.begin(), s.end(), bind(equal_to<>(), placeholders::_1, ' ')); // bind
    cout << s << endl;
    s.erase(it, s.end());
    cout << s << endl;

    char ca[] = "string with spaces ";
    auto itx = remove_if(begin(ca), end(ca), [](auto c){return c == ' ';}); //lambda
    cout << ca << endl;
    //s.erase(itx, end(ca));

    // char* cp = "string with spaces ";
    // begin() end() does not work for pointers, you need array.
    // auto itp = remove_if(begin(cp), end(cp), [](auto c){return c == ' ';});
    // cout << cp << endl;

    cout << endl;
    //mb1 = &f1

    // use as comparater
    set<int, greater<>> aset{1,3,2,10,4,3};
    for(auto i : aset)
        cout << i << " ," ;
    cout << endl;

    // binders 
    auto p1 = bind1st(plus<int>(), 10); // deprecated
    auto p2 = bind2nd(plus<int>(), 10); // deprecated
    auto p3 = bind(plus<int>(), 10, placeholders::_1);
    auto p4 = bind(plus<int>(), placeholders::_1, 10);

    cout << p1(20) << endl;
    cout << p1(30) << endl;
    cout << p2(20) << endl;
    cout << p3(20) << endl;
    cout << p4(20) << endl;

    // nagators
    // auto riter = remove_copy_if(v.begin(), v.end(), back_inserter(odds), not1(isOdd<int>())); this fails as isOdd does not define argument_type, inherit from unary_function, may be check, as it is deprecated.
    auto riter1 = remove_copy_if(v.begin(), v.end(), back_inserter(odds), not_fn(isEven()));
    unordered_set<int> us;
    auto riter2 = copy_if(v.begin(), v.end(), inserter(us, us.end()), not_fn(isEven()));

    cout << "USSSSSS" << endl;
    print_container(us);
    cout << "DEQQ" << endl;
    for(auto i : odds)
        cout << i << " ";
    cout << endl;
    cout << "using generic function" << endl;
    print_container(odds);
    fstream fs("results.txt", ios_base::out | ios_base::trunc);
    fs << "vector : "; 
    print_container_copy(v, fs, " ,");
    fs << "set : "; 
    print_container_iter(aset.begin(), aset.end(),  fs, " ,");

    // member function adapters
    vector<Point> pvec(10);
    pvec[0] = std::move(Point(2, 3));
    pvec[2] = std::move(Point(1, 3));
    pvec[4] = std::move(Point(2, 2));
    pvec[6] = std::move(Point(2, 4));
    for_each(pvec.begin(), pvec.end(), mem_fun_ref(&Point::print));
    pvec.erase(remove_if(pvec.begin(), pvec.end(), mem_fn(&Point::isOrigin)), pvec.end());
    for_each(pvec.begin(), pvec.end(), mem_fun_ref(&Point::print));

    // using std::function
    using lf = function<bool(int)>;
    lf l3 = less3;
    cout << boolalpha << l3(2) << endl;
    print_container_copy(v2); 
    cout << "print less 3" << endl;
    copy_if(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "), l3);
    cout << endl;
    lf l100 = [](int i){return i < 100;};
    auto less10 = [](int i){return i < 10;};
    auto retbval = less10(6);

    v2.erase(remove_if(v2.begin(), v2.end(), l100), v2.end());
    cout << "after erase" << endl;
    print_container(v2);
    int iv = 10;
    print_container(iv);
    return 0;

}