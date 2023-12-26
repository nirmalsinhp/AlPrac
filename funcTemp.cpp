#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

template <typename T>
void f(T a, T b)
{
    cout << "Temp " << __PRETTY_FUNCTION__ << endl;
}

template <typename T, typename U = char>
void f1(T a, U b)
{
    cout << "Temp  f2 " << __PRETTY_FUNCTION__ << endl;
}

// this is partial specializarion of function, it is not allowed.
// template <typename T>
// void f1<T, string>(T a, string b)
// {
//     cout << "Temp string " << __PRETTY_FUNCTION__ << endl;
// }

template <>
void f1<string, string>(string a, string b)
{
    cout << "Temp  SS " << __PRETTY_FUNCTION__ << endl;
}

template<typename T>
void f2(T&& x)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename T>
void f3(T& x)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename T>
void f4(T* x)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void f(int a, int b)
{
    cout << "Non -Temp " << __PRETTY_FUNCTION__ << endl;
}

void allocate_vec()
{
    vector<int> vec(1000000, 20);
}

void allocate_deq()
{
    deque<int> vec(1000000, 20);
}

template <typename T, typename U>
void foo1(array<T, sizeof(U)> x, array<U, sizeof(T)> y)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

template <typename T,
          template <typename ...> class seq_container = vector>
class seq_con_wrapper
{
    public:
    template <typename ...Args>
    explicit seq_con_wrapper(Args&&... args):
    _container(std::forward<Args>(args)...)
    {}

    seq_container<T> _container;

};

template <typename T,
          template <typename ...> class seq_container>
ostream& operator<<(ostream& os, seq_con_wrapper<T, seq_container> con)
{
    os << __PRETTY_FUNCTION__ << endl;

    for(auto& c : con._container)
        os << c << " ";
    os << endl;
    return os;
}

template<int N>
struct abss
{
    static_assert(N != INT_MIN);
    static constexpr auto value = N < 0 ? -N : N;
};

template <typename T>
struct type_is
{
    using type = T;
};

template <typename T>
enable_if_t<is_integral_v<T>, int>
falgo(T val)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

template <typename T>
enable_if_t<is_floating_point_v<T>, int>
falgo(T val)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

template <typename T>
struct remove_volatile : type_is<T>
{};

void falgo(string al)
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << "normal function" << endl;
}

template <typename T, typename U>
struct is_same_type : false_type
{};

template <typename T>
struct is_same_type<T,T> : true_type
{};

// constexpr if
template <typename T>
void printh(const T & t)
{
    if constexpr (is_pointer_v<T>)
    {
        cout << "printing pointer : " << *t << endl;
    }
    else
    {
        cout << "printing val : " << t << endl;

    }
}

void pr(...)
{
    cout << "..." << endl;
}

void pr(string s)
{
    cout << "s :" << s << endl;
}

auto autoff(auto i)
{
    cout << i << endl;
}

int main()
{

    int aa = abss<1>::value;
    int ab = abss<-10>::value;
    cout << aa << endl;
    cout << ab << endl;


    auto db = 12.3;
    cout << typeid(db).name() << endl;
    f(1,2);
    f('a','b');
    //f("str", 2);
    f(1.2,1);
    f(1.2f,1);

    auto t1 = chrono::high_resolution_clock::now();
    allocate_vec();
    auto t2 = chrono::high_resolution_clock::now();
    auto d1 = t2 - t1;

    cout << "Vec " << d1.count() << endl;
    auto t3 = chrono::high_resolution_clock::now();
    allocate_deq();
    auto t4 = chrono::high_resolution_clock::now();
    auto d2 = t4 - t3;
    cout  << "deq " << d2.count() << endl;

    seq_con_wrapper<string> sv(5, "Hello");
    //print_container(cout, sv);s
    cout << sv << endl;

    vector<int> vec1 {1,2,3,4,5,6,6,7,7,8,8};
    seq_con_wrapper<int, deque> dq(vec1.begin(), vec1.end());;
    cout << dq << endl;

    // for(int i = 0;;++i)
    //     cout << vec1[i] << endl;

    // vector<int> v;
    // copy(istream_iterator<int> (cin),
    //      istream_iterator<int> (),
    //      back_inserter(v));


    set<int, greater<>> iset({1,2,3,42,23,23,12});
    copy(iset.begin(), iset.end(), ostream_iterator<int>(cout,", "));
    cout << "val " <<  bool((iset.insert(12)).second) << endl;
    auto it = iset.find(4);
    cout << *it << endl;
    auto it1 = iset.find(3);
    cout << *it1 << endl;

    vector<int> uq{1,1,1,1,2,22,22,2,1,1,2,2,23,12};
    unique(uq.begin(), uq.end());
    for(int i : uq)
        cout << i << ", ";
    cout << endl;

    foo1(array<int, 8>{}, array<double, 4>{});

    short s = 2;
    int im = 3;

     // max(s, im); can't deduce
    max<int>(s, im); // parameters do not participate in type deduction any more.
    f1<int, int>( 'c' , 4);
    f1<int>( 'c', 'c');
    f1<>( 'c' , 4);
    f1( 'c' , 4);

    string s1 = "s1", s2 = "s3";
    f1( s1, s2);

    const int ic = 45;
    const int ic1 = 45;

    f2(im);

    f2(42);
    f2(ic);
    f2(std::move(ic));
    f3(im);
    f3(std::move(ic1));
    // f3(42); // compile time error, can not bind T& to temporary.
     // f4(43); - compile time error, cant mach T*
    f4(&s);

    sizeof(ic1);
    sizeof(int);
    // foo1(array<int, 7>{}, array<double, 4>{}); fails deduction 

    type_is<int>::type func4;
    falgo(2);
    falgo(3.3);
    falgo('c');
    falgo("c");
    shared_ptr<int> pi = make_shared<int>(10);

    auto same = is_same_type<int, int>::value;
    auto same1 = is_same_type<int, decltype(ic1)>::value;
    cout << boolalpha << same << " " << same1 << endl;

    // constexptr

    printh(10);
    printh(&same);
    pr(10);
    pr("....");

    //  auto vs decltype(auto) - auto uses type deduction, decltype always gives declared type.
    const int& wi = 10;
    auto aw = wi;
    decltype(auto) daw = wi;
//     auto x2; auto needs to be initialized
    unique_ptr<string> us(nullptr);
    return 0;


}
