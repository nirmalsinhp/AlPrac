/**
 * Non-mutating algorithms don't change the contents of what is found.
 * These algorithms typically do lookup and counting operations, such as
 * 
 * . adjacent_find() - Finds two items adjacent to each other 
 * . count() - Returns a count of elements matching a given value
 * . count_if() - Returns a count of elements for which a predicate is true 
 * . equal() - Determines if two sets of elements are the same
 * . find() - Finds a specified value in a given range 
 * . find_if() - Finds the first element for which a predicate is true
 * . find_if_not() - Finds the first element for which a predicate is false
 * . find_end() - Finds last sequence of elements in a range
 * . find_first_of() - Finds first sequence of elements in a range
 * . for_each() - Applies a function to a range of elements
 * . mismatch() - Finds the first position where two ranges differ
 * . search() - Searches for a range of elements
 * . search_n() - Searches for n consecutive copies of an element within a
 *   range
 * 
 * Note that unexpected behavior can result if two sequences or
 * strings of unequal size are compared. STL will not warn one or
 * prevent this, so you need to have error checking in custom code.
 */


#include <bits/stdc++.h>
using namespace std;
template <typename T, template <typename ...> class container> 
static void print_container(const container<T>& C, std::string del = " ")
{
    for(const auto& c: C)
        cout << c << " ";
    cout << endl;
}

template <typename inputIterator> 
static void print_container_iter(inputIterator first, inputIterator last, ostream& stream = cout, string del = " ")
{
   copy(first, last,
        ostream_iterator<decltype(*first)>(stream, del.c_str()));
    stream << endl;
    
}


template <typename T>
class print : unary_function<T, void>
{
    public:
    print(ostream& out): os(out), _i(0)
    {
    }
    void operator()(const T& x)
    {
        os << x << " ";
        ++_i;
    }

    int count()
    {
            return _i;
    }


    private:
    ostream& os;
    int _i;
};

template <typename T>
class is_greater_than
{
    public:
    explicit is_greater_than(const T& value) : val(value) 
    {}

    bool operator()(const T& n) const
    {
        return n > val;
    }

private:
const T& val;
};

template <typename InputIter1, typename InputIter2>
void find_mismatch(InputIter1 first1, InputIter1 last1, InputIter2 first2, InputIter2 last2)
{
    if(distance(first1, last1) == distance(first2, last2) && equal(first1, last1, first2))
    {
        cout << "equal" << endl;
    }
    else 
    {
        auto res = mismatch(first1, last1, first2, last2);
        cout << "mismatch " << *res.first << " " << *res.second << endl;
    }
    return;
}

template <typename ForwardIter, typename T, typename Compare=less<>>
ForwardIter binary_find(ForwardIter first, ForwardIter last,
                        const T& val, Compare cmp={})
                    
{
    auto iter = lower_bound(first, last, val,cmp);
    return iter != last && !cmp(val, *iter) ? iter : last;
}


int main()
{

    int a[] = {10, 20, -30, -40, -10, 40, 0, 10};
    auto it = find(begin(a), end(a), 0);
    cout << *it << endl;
    // find first nagative number.
    auto iter = find_if(begin(a), end(a), bind(less<>(), placeholders::_1, 0));
    cout << *iter << endl;
    auto riter = find_if(rbegin(a), rend(a), bind(less<>(), placeholders::_1, 0));
    cout << *riter << endl;

    deque<double> dq = {35, 76, -10.5, 44.44, 32.232, 0.98};
    auto diter = find_if(dq.begin(), dq.end(), is_greater_than<double>(10.12));
    cout << *diter << endl;

    auto val = 30.33;
    auto it1 = find_if_not(dq.begin(), dq.end(),[val](const double& d){return d > val;} );
    cout << *it1 << endl;
    vector<int> vec{10, -10, 20, 30, 50, 10, 10, 20, 60};
    deque<int> dq2{10,20};
    deque<int> dq3{-10,20};
    auto it3 = find_end(vec.begin(), vec.end(), dq.begin(), dq.end());
    auto it4 = find_end(vec.begin(), vec.end(), dq.begin(), dq.end(), 
                [](auto a, auto b) { return abs(a) == abs(b);} );
    cout << " it3 " << distance(vec.begin(), it3) << endl;
    cout << " it4 " << distance(vec.begin(), it4) << endl;
    auto it5 = find_first_of(vec.begin(), vec.end(), dq3.begin(), dq3.end());
    cout << " it5 " << distance(vec.begin(), it4) <<  " :"  << *it5<<  endl;

    const int sz = 10;
    unique_ptr<int []> a1(new int[sz]{1,2,3,4,4,45,23,12,43,54});
    unique_ptr<int []> a2(new int[sz]);

    auto it2 = find(begin(vec), end(vec), 10);
    cout << " it2 " << *it2 << endl;

    auto c10 = count(vec.begin(), vec.end(), *it2);
    cout << "C10 " << c10 << endl;

    auto cabs10 = count_if(vec.begin(), vec.end(), [&it2](const auto& n)
                                                    {return abs(n) == *it2; });
    cout << "Cabs10 " << cabs10 << endl;
    array<int, 7> arr{2,3,4,10,12,1000,0};
    auto max = max_element(arr.begin(), arr.end());
    cout << "max " <<  *max << endl;

    auto min = min_element(arr.begin(), arr.end()
    );
    cout << "min " <<  *min << endl;

    auto ming = minmax_element(arr.begin(), arr.end(), greater<int>());
    // cout << "ming " <<  *ming << endl;

    // for each returns function object, if state needs to be maintained.
    auto fun1 = for_each(arr.begin(), arr.end(), print<int>(cout));
    cout << "print called :" << fun1.count() << " times" << endl;

    // for each using range for.    
    auto pf = print<int>(cout);
    for(auto a : arr)
        pf(a);
    cout << "pf called :" << pf.count() << " times" << endl;

    // for each with lambda with same final effect
    int ci = 0;
    auto funl = for_each(arr.begin(), arr.end(), 
                        [&ci](auto j) { cout << j << " "; ++ci;});
    cout << " lambda called" << ci << " times" << endl;

    find_mismatch(arr.begin(), arr.end(), vec.begin(), vec.end());

    // search, search for subseuence.
    vector<int> sr{30, 50};
    vector<int> sr3{30, 50};
    auto sit = search(vec.begin(), vec.end(), sr.begin(), sr.end());
    auto sit2 = search(vec.begin(), vec.end(), sr3.begin(), sr3.end());

    cout << boolalpha << "found :" << (sit != vec.begin()) << endl;
    cout << boolalpha << "found :" << (sit2 != vec.begin()) << endl;

    char ca[] = "0001110000111101010101001010101";
    // search_n search for consequitive values
    auto snit = search_n(begin(vec), end(vec), 2, 10);
    cout << " found it at " << distance(begin(vec), snit) << " " << *snit << endl;

    // adjacent find
    auto adit = adjacent_find(vec.begin(), vec.end());
    if(adit != vec.end())
        cout << "adjacent values found at " << distance(vec.begin(), adit) << " value :" << *adit << endl;

    vector<string> vs = {"vector", "is", "A", "STL", "STL", "data", "structure", "default"};
    sort(vs.begin(), vs.end());
    int i = 0;
    for(const auto & s: vs)
        cout << "[" << i++ << "]" << " - " << s << endl;
    bool fb = binary_search(vs.begin(), vs.end(), "is");
    cout << boolalpha << "binary found" << fb << endl;
    auto bfiter = binary_find(vs.begin(), vs.end(), "STL");

    cout << distance(vs.begin(), bfiter) << endl;
    auto upprt = upper_bound(vs.begin(), vs.end(), "STL");
    cout << distance(vs.begin(), upprt ) << endl;
    auto bfiter1 = binary_find(vs.begin(), vs.end(), "STLSTL");
    cout << (bfiter1 != vs.end() ? "found" : "not found")   << endl;

    // write nth element, partial sort, all of, none of, any of examples
    vector<double> vd {10, 9 ,8 , 5, 4, 3, 6, 7, 2, 1.0, 11, 11, 11, 6.5};
    nth_element(vd.begin(), vd.begin() + 3, vd.end());
    cout << "begin + 3 " << * (vd.begin() + 3) << endl;
    nth_element(vd.begin(), vd.begin() + 3, vd.end(), greater<>());
    cout << "begin + 3 greater " << * (vd.begin() + 3) << endl;

    vector<int> vc{-10, 10, 20, 30, 50, 10, 10, 20, 60};
    if(all_of(vc.begin(), vc.end(), [](const int& n){ return n % 2 == 0;}));
        cout << "all even" << endl;

    if(any_of(vc.begin(), vc.end(), [](const auto & n) {return n < 0; }));
        cout << "found a nagative" << endl;

    if(none_of(vc.begin(), vc.end(), [](const auto & n) {return n % 2 != 0; }));
        cout << "no odds" << endl;


    auto g6 = is_greater_than<double>(6.6);
    partition(vd.begin(), vd.end(), g6);
    stable_partition(vd.begin(), vd.end(), g6); // same as parition , keeps orignal order
    auto pt = partition_point(vd.begin(), vd.end(), g6);
    cout << "partitioned vector :" << endl;
    print_container(vd);
    cout << "partitions : " << endl;
    print_container_iter(vd.begin(), pt);
    print_container_iter(++pt, vd.end());

    auto ret = is_partitioned(vd.begin(), vd.end(), g6);
    cout << "is vd partitioned : " << boolalpha << ret << endl;

    auto sret = is_sorted(pt, vd.end(), greater<>());
    cout << "is vd sorted : " << boolalpha << sret << endl;

    auto suret = is_sorted_until(vd.begin(), pt);
    cout << "is vd sorted until: " << *suret << endl;


    //span s(v1.get(), v1.get() + size);
    return 0;
} 