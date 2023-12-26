#include <bits/stdc++.h>

using namespace std;

/*
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

    vector<int> vec = {2,3,4,5};
    auto itr = lower_bound(vec.begin(), vec.end(), 1);

    cout << *itr << endl;
    return 0;
}