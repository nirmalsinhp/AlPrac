#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    int ps = 0;
    unordered_map<int, int> mmap;
    mmap[0] = -1; // sentinel for array starting at 0.
    for (int i = 0; i < nums.size(); ++i)
    {
        ps += nums[i];
        ps %= k;
        cout << ps << " " << i << " " << mmap.count(ps) << endl;
        if (mmap.count(ps))
        { if(i - mmap[ps] > 1)
            return true;
        }
        else
            mmap[ps] = i;
    }
    return false;
}

int main()
{
    vector<int> arr {5,0,0,0};
    auto found = checkSubarraySum(arr, 3);
    return 0;
}