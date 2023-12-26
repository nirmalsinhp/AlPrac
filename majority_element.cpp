#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> mmap;
    for(auto n : nums)
    {
        mmap[n]++;
    }
    vector<int> res;
    int n3 = nums.size() / 3;
    for(auto & kv : mmap)
    {
        if(kv.second > n3)
            res.push_back(kv.first);
    }
    //  transform(map.begin(), map.end(), back_inserter(res), [n3](auto kv)  }
    return res;  
}

