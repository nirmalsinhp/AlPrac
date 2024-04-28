#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    replace_if(
        nums.begin(), nums.end(), [](auto n)
        { return n <= 0; },
        n + 1);
    for (int i = 0; i < n; ++i)
    {
        cout << nums[i] << endl;
        if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0)
            nums[abs(nums[i]) - 1] *= -1;
    }

    for (int i = 0; i < n; ++i)
    {
        if (nums[i] > 0)
            return i + 1;
    }
    return n + 1;
}

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> out;

    // i will appear at index i - 1, so mark element at index i - 1 to -ve,
    // if any -ve is encountered again means it is duplicate
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[abs(nums[i]) - 1] < 0)
            out.push_back(abs(nums[i]));
        nums[abs(nums[i]) - 1] *= -1;
    }
    // for(int i = 0; i < nums.size(); ++i)
    // {
    //     if(nums[i] > 0)
    //         out.push_back(i + 1);
    // }
    return out;
}

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> out;
    // any element found is marked as -ve, all positive index are missing.
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[abs(nums[i]) - 1] > 0)
            nums[abs(nums[i]) - 1] *= -1;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > 0)
            out.push_back(i + 1);
    }
    return out;
}
int main()
{
    vector<int> nums = {3, 4, -1, 1};
    int msp = firstMissingPositive(nums);
    cout << msp << endl;
    return 0;
}
