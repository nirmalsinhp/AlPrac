#include <bits/stdc++.h>
using namespace std;

int solve_k(vector<int> &units, vector<int> &prices, int k)
{
    int minp = INT_MAX;
    if (k == 0)
        return 0;
    for (int i = 0; i < units.size(); ++i)
    {
        if (k >= units[i])
        {
            auto res = solve_k(units, prices, k - units[i]);
            minp = min(minp, res + prices[i]);
        }
    }
    return minp;
}
const int MAX_S = 200;
vector<double> memo(MAX_S, -1);

double solve_m(vector<int> &units, vector<double> &prices, int k)
{
    double minp = INT_MAX;
    if (k == 0)
    {
        memo[0] = 0;
        return memo[0];
    }
    if (memo[k] != -1)
        return memo[k];
    for (int i = 0; i < units.size(); ++i)
    {
        if (k >= units[i])
        {
            auto res = solve_m(units, prices, k - units[i]);
            minp = min(minp, res + prices[i]);
        }
    }
    memo[k] = minp;
    return memo[k];
}

double solve_d(vector<int> &units, vector<double> &prices, int k)
{
    vector<double> dp(k + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= k; ++i)
    {
        for (int u = 0; u < units.size(); ++u)
        {
            if(u >= k)
                dp[i] = min(dp[i], dp[i - u] + prices[u]);
        }
    }
    return dp[k];
}