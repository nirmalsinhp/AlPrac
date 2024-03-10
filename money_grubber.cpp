#include <bits/stdc++.h>
using namespace std;


double apple_c(vector<int>& nums, vector<double>& prices, int ka, vector<double>& memo)
{
    if(memo[ka] != -1.0)
        return memo[ka];
    double best = 999999.0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(ka - nums[i] >= 0)
        {
            auto res = apple_c(nums, prices, ka - nums[i], memo);
            best = min(best, res + prices[i]);
        }
    }
    memo[ka] = best;
    return memo[ka];
}

double apple_d(vector<int>& nums, vector<double>& prices, int k)
{
    vector<double> dp(k+1, 999999);
    dp[0] = 0;
    for(int i = 0; i <= k; i++)
    {
        for(int j = 0; j < nums.size(); ++j)
        {
            if(i - nums[j] >= 0)
                dp[i] = min(dp[i], dp[i - nums[j]] + prices[j]);
        }
    }

    return dp[k];
}

int main()
{
    vector<int> aps{1,2,3,5};
    vector<double> prices{1.75, 2.5, 4,8};
    vector<double> memo(100, -1.0);
    memo[0] = 0.0;
    auto ret = apple_c(aps,prices, 11, memo);
    cout << ret << endl;

    auto retd = apple_d(aps,prices, 11);
    cout << retd << endl;

    return 0;
}