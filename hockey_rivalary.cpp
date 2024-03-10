#include <bits/stdc++.h>
using namespace std;

static int r_calls = 0;
int rival_r(vector<pair<char, int>> &t1, vector<pair<char, int>> &t2, int n1, int n2)
{
    r_calls++;
    // chec for < 0 or, start from one and check for 0.
    if (n1 == 0 || n2 == 0)
        return 0;
    int o1, o2, o3, o4;
    o1 = 0;
    if ((t1[n1].first == 'W' && t2[n2].first == 'L' && t1[n1].second > t2[n2].second) ||
        (t1[n1].first == 'L' && t2[n2].first == 'W' && t1[n1].second < t2[n2].second))
        o1 = rival_r(t1, t2, n1 - 1, n2 - 1) + t1[n1].second + t2[n2].second;

    o2 = rival_r(t1, t2, n1 - 1, n2 - 1);
    o3 = rival_r(t1, t2, n1 - 1, n2);
    o4 = rival_r(t1, t2, n1, n2 - 1);

    return max(o1, max(o2, max(o3, o4)));
}

int rival_m(vector<pair<char, int>> &t1, vector<pair<char, int>> &t2, int i, int j, vector<vector<int>> &memo)
{
    if (i == 0 || j == 0)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    int o1, o2, o3, o4;
    o1 = 0;
    if ((t1[i].first == 'W' && t2[j].first == 'L' && t1[i].second > t2[j].second) ||
        (t1[i].first == 'L' && t2[j].first == 'W' && t1[i].second < t2[j].second))
        o1 = rival_m(t1, t2, i - 1, j - 1, memo) + t1[i].second + t2[j].second;
    o2 = rival_m(t1, t2, i - 1, j - 1, memo);
    o3 = rival_m(t1, t2, i, j - 1, memo);
    o4 = rival_m(t1, t2, i - 1, j, memo);
    memo[i][j] = max(o1, max(o2, max(o3, o4)));
    return memo[i][j];
}

int rival_dp(vector<pair<char, int>> &t1, vector<pair<char, int>> &t2)
{
    int n1 = t1.size();
    int n2 = t2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    int o1, o2, o3, o4;
    for (int i = 0; i <= n1; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= n1; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j < n2 + 1; ++j)
        {
            o1 = 0;
            if ((t1[i].first == 'W' && t2[j].first == 'L' && t1[i].second > t2[j].second) ||
                (t1[i].first == 'L' && t2[j].first == 'W' && t1[i].second < t2[j].second))
                o1 = dp[i-1][j-1] + t1[i].second + t2[j].second;
            o2 = dp[i-1][j-1];
            o3 = dp[i][j-1];
            o4 = dp[i-1][j];
            dp[i][j] = max(o1, max(o2, max(o3,o4)));
        }
    }

    return dp[n1][n2];
}

// space optimization
// using only 2 rows instead of entire table.
int rival_dpso(vector<pair<char, int>> &t1, vector<pair<char, int>> &t2)
{
    int n1 = t1.size();
    int n2 = t2.size();
    vector<int> prev(n1+1, 0);
    vector<int> curr(n2+1, 0);
    int o1, o2, o3, o4;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j < n2 + 1; ++j)
        {
            o1 = 0;
            if ((t1[i].first == 'W' && t2[j].first == 'L' && t1[i].second > t2[j].second) ||
                (t1[i].first == 'L' && t2[j].first == 'W' && t1[i].second < t2[j].second))
                o1 = prev[j-1] + t1[i].second + t2[j].second;
            o2 = prev[j-1];
            o3 = prev[j];
            o4 = curr[j-1];
            curr[j] = max(o1, max(o2, max(o3,o4)));
        }
        prev = curr;
    }

    return curr[n1];
}

int main()
{
    vector<pair<char, int>> MI = {
        {' ', -1}, // dummy/sentinel
        {'W', 3},
        {'L', 4},
        {'W', 1},
        {'W', 8}
};
    vector<pair<char, int>> KKR = {
        {' ', -1}, // dummy/sentinel
        {'W', 5},
        {'L', 1},
        {'L', 2},
        {'L', 3}
        };
    vector<vector<int>> memo(MI.size(), vector<int>(KKR.size(), -1));
    for (int i = 0; i < memo.size(); ++i)
    {
        for (int j = 0; j < memo[0].size(); j++)
        {
            if (i == 0 || j == 0)
                memo[i][j] == 0;
        }
    }
    auto goals = rival_r(MI, KKR, MI.size() - 1, KKR.size() - 1);
    cout << "goals : " << goals << endl;
    cout << "calls : " << r_calls << endl;

    auto mgoals = rival_m(MI, KKR, MI.size() - 1, KKR.size() - 1, memo);
    cout << "mgoals : " << mgoals << endl;

    auto dgoals = rival_dp(MI, KKR);
    cout << "dgoals : " << dgoals << endl;

    auto sgoals = rival_dpso(MI, KKR);
    cout << "sgoals : " << sgoals << endl;

    return 0;
}