#include <bits/stdc++.h>
using namespace std;

int majority(const vector<int> &nums)
{
    int value = nums[0];
    int counter = 1;
    for (int i = 1; i < nums.size(); ++i)
    {
        if (value == nums[i])
            counter++;
        else if (counter == 0)
        {
            value = nums[i];
            counter = 1;
        }
        else
            counter--;
    }

    int cnt = count(nums.begin(), nums.end(), value);
    if (cnt < nums.size() / 2)
    {
        cout << " false positive " << endl;
        return -1;
    }
    return value;
}

vector<int> majorityElementHash(vector<int> &nums)
{
    //simple correct, just needs an extra space, if space is not an issue, go with it.
    unordered_map<int, int> mmap;
    for (auto n : nums)
    {
        mmap[n]++;
    }
    vector<int> res;
    int n3 = nums.size() / 3;
    for (auto &kv : mmap)
    {
        if (kv.second > n3)
            res.push_back(kv.first);
    }
    return res;
}

vector<int> majorityElementK(const vector<int> &nums, int k)
{
    // get a hash map to size of k first.
    int winners = k - 1;
    int needed =  ceil(nums.size() / k);
    unordered_map<int, int> kmap;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (kmap.size() < winners)
            kmap[nums[i]]++;
        else
        {
            // check if nums[i] is already in winners, if yes increment that counter.
            if (kmap.count(nums[i]))
                kmap[nums[i]]++;
            else
            {
                auto itr = find_if(kmap.begin(), kmap.end(), [](const auto &p)
                                   { return p.second == 0; });
                if (itr != kmap.end())
                {
                    // can not change key, so delete it
                    kmap.erase(itr);
                    // add new winner.
                    kmap[nums[i]] = 1;
                }
                else
                {
                    // decrement all by one. we are not deleting 0 count members here, as it will be taken care in if condition.
                    for (auto p : kmap)
                        p.second--;
                }
            }
        }
    }

    unordered_map<int, int> check_map;
    for (auto n : nums)
    {
        if (kmap.find(n) != kmap.end())
            check_map[n]++;
    }

    vector<int> result;
    /*
    transform(kmap.begin(), remove_if(kmap.begin(), kmap.end(), [needed](auto kv)
                                                {
                                                    return kv.second < needed;
                                                }), back_inserter(result), [](const auto p)
              { return p.first; });
              */
    for(const auto&[k,v] : check_map)
    {
        if(v > needed)
            result.push_back(k);
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 1};
    auto mj = majority(nums);
    cout << mj << endl;
    
    vector<int> nums3 = {3,3,3,3,1,1,2,2,4,4};
    auto hv = majorityElementHash(nums3);
    auto mee = majorityElementK(nums3, 2); // 3 means 1/3 here, may be confusing check.
    for(auto h : hv)
        cout << h << " ";
    cout << endl;
    for(auto h : mee)
        cout << h << " ";
    cout << endl;

    return 0;
}