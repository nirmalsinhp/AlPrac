#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) 
{
    size_t l = 0, r = height.size() - 1;
    size_t minHt = 0;
    int res = 0;

    while(l < r)
    {
        while(l < r && height[l] <= minHt)
        {
            res += minHt - height[l++]; 
        }
        while(l < r && height[r] <= minHt)
        {
            res += minHt - height[r--]; 
        }
        minHt = min(height[l], height[r]);
        return res;
    }    
}

int firstMissingPositive(vector<int>& nums) 
{
    auto ns = nums.size();
    vector<int> nv(ns + 1, -1);
    for(const auto n : nums)
    {
        if(n > 0 && n <= ns)
            nv[n] = 1;
    }
    auto in = find(nv.begin() + 1, nv.end(), -1) - nv.begin();
    return in;   
}

int main()
{
    unordered_map<int, bool> map;
    map.find(1);
    vector<int> vec = {1};
    auto in = firstMissingPositive(vec);
    cout << in << endl;
    vector<int> v1 {256741038, 623958417, 467905213, 714532089, 938071625};
    long long int sum = 0;
    auto sum = accumulate(v1.begin(), v1.end(), 0);
    cout << sum << endl;
}