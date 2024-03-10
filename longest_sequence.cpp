#include <bits/stdc++.h>
using namespace std;

int lcns(const vector<int>& nums)
{
    set<int> is(nums.begin(), nums.end());
    vector<int> diff;
    adjacent_difference(is.begin(), is.end(), back_inserter(diff));
    auto itr = diff.begin();
    int mx = INT_MIN;
    while(itr != diff.end())
    {
        auto citr = find_if(itr, diff.end(), [](auto d)
                                                    {
                                                        return d > 1; 
                                                    });
        mx = max(mx, int(distance(itr, citr)));
        if(citr!=diff.end())
            itr = citr + 1;
    }
    return mx;
}

int main()
{
    vector<int> nums{9,1,4,7,3,-1,0,5,8,-1,6};
    auto mx = lcns(nums);
    return 0;
}