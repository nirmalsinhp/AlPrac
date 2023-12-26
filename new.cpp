#include <bits/stdc++.h>
using namespace std;

void exp() noexcept
{
    throw 42;
    return;
}

void f(int i)
{
    cout << "int" << endl;
}

void f(void * v)
{
    cout << "void" << endl;
}

void fs(const unique_ptr<int> & up)
{
    cout << "smart" << endl;
}

int main()
{
    // auto xx;  can not left uninitialized.
    unordered_map<int, int> umap;
    umap.insert({1,1});
    umap.equal_range(1);
    auto[iter, inserted] = umap.insert({1,2});
    cout << boolalpha << inserted << endl;
    cout << umap[1] << endl;
 
    unordered_multimap<int, int> ummap;
    ummap.insert({1, 1});
    ummap.insert({1, 2});
    auto[fiter, liter] = ummap.equal_range(1);

//    copy(fiter, liter, ostream_iterator<pair<int, int>>(cout, " "));

    for(auto i = fiter; i != liter; ++i)
    {
        cout << i->first << " " << i->second << endl;
    }

    vector<int> v1 {1,2,3,4,4};
    vector<int> v2;
    vector<int> v3(10);
    vector<int> v4 = move(v1);
    cout << endl;
    // reverse()
    copy(v1.begin(), v1.end(), back_inserter(v2));
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(v1.crbegin(), v1.crend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    iota(v3.begin(), v3.end(), 10);
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // auto array
    const char cr[] = "this is array!!";
    auto acr = cr; // deduced const char *
    auto & rcr = cr; // deduced const char(&)[size]
    auto di = {12.2}; // intitilizer_list <T>

    f(0);
    f(nullptr);
    auto dp =  new double(22.22);
    unique_ptr<double> up = nullptr;
    // unique_ptr<double> udp = dp; does not compile
    unique_ptr<double> uddp(dp);
    //up = dp; // does not compile
    
    fs(nullptr); // works only when passed by type or const ref, can not bind smart pointer ref to
    // f(NULL);
    auto ci =  v1.cbegin();
    //auto iit = static_cast<vector<int>::iterator>(ci);
    int x = 312;
    string s = to_string(x);
    reverse(begin(s), end(s));
    auto xx = stoi(s);
    cout << xx << endl;
    vector<regex> vr;
    vr.emplace_back(nullptr);
    try
    {
        //exp(); // terminates
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
 //   vr.push_back(nullptr);

    return 0;
}