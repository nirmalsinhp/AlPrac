#include <bits/stdc++.h>

using namespace std;

template <typename T>
decltype(auto) move(T&& t)
{
    return static_cast<remove_reference_t<T> &&>(t);
}*/

int bsearch(vector<int> vec, int target)
{
    int lo = 0;
    int hi = vec.size() - 1;

    while(lo<=hi)
    {
        int mid = lo + (hi -lo)/2;
        if(vec[mid] > target)
        {
            hi = mid - 1;
        }
        else if(vec[mid] < target)
        {
            lo = mid + 1;
        }
        else
            return mid;
    }
    return -1;
}

int main()
{
     vector<int> vec = {1,2,3,4};
    vector<int> lv, rv;
    exclusive_scan(vec.begin(), vec.end(), back_inserter(lv), 0);
    exclusive_scan(vec.rbegin(), vec.rend(), back_inserter(rv), 0);
    copy(lv.begin(), lv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(rv.begin(), rv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    auto it = find_first_of(lv.begin() + 1, lv.end(), rv.begin(), rv.end());
    if(it != lv.end())
        cout << *it << endl;
    //vector<int> vec = {0,0,0,0};
    string s;
    for(auto n : vec)
        s += to_string(n);
    cout << s << endl;
    cout << stoi(s) << endl;

    vector<int> arr{1,2,2,2,3,4,5,5};
    auto itr = lower_bound(vec.begin(), vec.end(), 1);
    auto [first, last] = equal_range(arr.begin(), arr.end(), 5);
    auto nums = distance(first, last);
    auto nms = last - first;
    auto f = distance(vec.begin(), first);
    auto l = distance(vec.begin(), last);
    cout << *first << "->"<< *last << endl;
    cout << *itr << endl;
    return 0;
}