#include <bits/stdc++.h>
using namespace std;


// inner product can be very useful algo with custom ops. check out.
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

int main()
{
    try{

    vector<int> vec(20);
    fill(vec.begin(), vec.end(), 1);
    partial_sum(vec.begin(), vec.end(), vec.begin());
    shuffle(vec.begin(), vec.end(), default_random_engine(time(nullptr)));

    cout << "partial sum & shuffled" << endl;
    print_container(vec);

    // similar to partial sum, new in c++17
    // exclusinve scan, inclusive scan, 
    vector<int> av(5, 0);
    vector<int> temp;
    iota(av.begin(), av.end(), 1);
    partial_sum(av.begin(), av.end(), back_inserter(temp));
    cout << " partial sum " << endl;
    print_container(temp);
    temp.clear();
    inclusive_scan(av.begin(), av.end(), back_inserter(temp));
    cout << " inclusive scan " << endl;
    print_container(temp);

    temp.clear();
    exclusive_scan(av.begin(), av.end(), back_inserter(temp), 0);
    cout << " exclusive scan " << endl;
    print_container(temp);

    //inner product 
    srand(time(nullptr));
    vector<int> v1(10);
    generate_n(v1.begin(), 10, rand);
    //generate()

    vector<int> vm;
    vector<int> v2(10,20);
    transform(v1.begin(), v1.end(), v2.begin(), v1.begin(), modulus<>());
    print_container(v1);

    transform(v1.begin(), v1.end(), back_inserter(vm),
                        [](auto n) {return n * n;});
    cout << "generate and modules" << endl;
    print_container(v1);

    sort(v1.begin(), v1.end(), greater<int>());
    cout << "sorted " << endl;
    print_container(v1);
    cout << "rotate : ";
    vector<int> vn;
    rotate(vm.begin(), vm.begin() + 3, vm.end());
    print_container(vm);
    reverse(vm.begin(), vm.end());
    rotate_copy(vm.begin(), vm.begin() + 4, vm.end(), back_inserter(vn));
    cout << " vn : "  << endl;
    print_container(vn);

    auto rit = remove_if(vn.begin(), vn.end(), [](auto n){ return n % 2 == 0;});
    print_container_iter(vn.begin(), rit);
    vector<int> odds;
    copy_if(vn.begin(), vn.end(), back_inserter(odds), [](auto n) { return n % 2 == 0; });
    print_container(odds);
    print_container(vec);
    // replace if is inplace.
    replace_copy_if(vec.begin(), vec.end(), back_insert_iterator(odds), [](auto n){ return n % 2 == 0;}, 99999);
    print_container(odds);
    vn.erase(rit, vn.end());
    print_container(vn);

    // unordered_map<char, int> cmap;
    // sort(cmap.begin(), cmap.end()); does not work, unordered map does not support random access operator.

    int a[] = {1, 2, 3, 4, 23,12,43,2,32,231,32,32 };
    set<int> b = {1, 2, 3, 4, 32,231 };
    sort(begin(a), end(a));
    int ans[distance(begin(a), end(a))];
    // returned itr is type of last elements, 
    auto itr = set_difference(begin(a), end(a),
                            begin(b), end(b),
                            begin(ans));
    cout << "set diff number of elements :" << distance(begin(ans), itr) << endl;
    print_container_iter(begin(ans), itr);
    set<int> c = {1,2,3,4,5,6};
    vector<int> inter;
    vector<int> uni;
    auto uiter = set_union(begin(b), end(b),
                        begin(c), end(c),
                        back_inserter(uni));
    print_container(uni);
    auto iiter = set_intersection(begin(b), end(b),
                        begin(c), end(c),
                        back_inserter(inter));
    print_container(inter);
    
    cout << "heap" << endl;
    make_heap(uni.begin(), uni.end());
    sort_heap(uni.begin(), uni.end());
    print_container(uni);

//    inplace_merge(begin(a), end(a),)
  //  cout << "numerics" << endl;
    print_container(vec);

    auto oddsum = accumulate(vec.begin(), vec.end(), 0, [](int sum, int n) 
                                                {return n % 2 == 0 ? sum : n + sum; });

    long long multi = 1;
    auto sums = accumulate(vec.begin(), vec.end(), 0);
    auto multip = accumulate(vec.begin(), vec.end(), multi, multiplies<>());

    cout << " oddsum : " << oddsum << endl;
    cout << " sum : " << sums << endl;
    cout << " multi : " << multip << endl;

    // similar to accumulate, new in c++17
    // reduce, transform reduce

    adjacent_difference(inter.begin(), inter.end(), back_inserter(uni));
    print_container(uni);

    }
    catch(exception& e)
    {
        cout << "caught exception"  << endl;
        cout << e.what() << endl;
    }
    return 0;
}