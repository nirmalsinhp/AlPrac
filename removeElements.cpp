#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& vec, int limit)
{
    if(vec.size() <= limit)
        return -1;
    int i = 0;
    for(auto n:vec)
    {
        if(i < limit || n > vec[i-limit])
            vec[i++] = n;
    }
    return i;
}

int main()
{
    vector<int> vec{1,1,1,1,2,2,2,3,3,4,4,4,4,5,6,7,8,8,8,9};
    auto k = removeDuplicates(vec, 2);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", "));
    return 0;
}