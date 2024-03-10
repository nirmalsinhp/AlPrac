#include <bits/stdc++.h>
using namespace std;

int ways_to_pass(int n, int t, int p, vector<vector<int>>& memo)
{
    cout << "Calling " << n << " " << t << endl;
    if(memo[n][t] != -1)
        return memo[n][t];
    if(n == 0 && t == 0)
        return 1;
    if(n == 0)
        return 0;
    int total  = 0;
    for(int i = p; i <= t; i++)
        total += ways_to_pass(n-1, t-i, p, memo);
    cout << n << " " << t << " : " << total << endl;
    memo[n][t] = total;
    return memo[n][t];
}

// TODO : ways to pass DP not working.
int ways_to_pass_dp(int n, int t, int p)
{
    vector<vector<int>> dp(n+1, vector<int>(t + 1, 0));
    dp[0][0] = 1;
    for(int i = p; i <= t; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int j = p; j <= t; j++)
        {
            dp[i][j] += dp[i-1][k] + dp[i][k-1];
        }
    }
    return dp[n][t];
}
int main()
{
    int n,t,p;
    cout << "Courses :";
    cin >> n;
    cout << endl << "total :";
    cin >> t;
    cout << endl << "passing marks :";
    cin >> p;
    vector<vector<int>> memo(n + 1, vector<int>(t + 1, -1));
    int wp = ways_to_pass(n, t, p, memo);
    cout << "Ways : " << wp << endl; 
    int dwp = ways_to_pass_dp(n, t, p);
    cout << "Dp Ways : " << dwp << endl; 

    return 0;
}