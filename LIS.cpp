#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    auto n = nums.size();
    vector<int> DP(n, 1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
            {
                //   cout <<i << " - " << j << " : "  <<  DP[i] << " " << DP[j] << endl;
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    return *max_element(DP.begin(), DP.end());
}

int main()
{
    vector<int> vec{ 9, 10, 2, 3, 7, 5, 101, 18 };
    cout << lengthOfLIS(vec) << endl;
    return 0;
}