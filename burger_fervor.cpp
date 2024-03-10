#include <bits/stdc++.h>
using namespace std;

long long total_calls;
long long m_total_calls;


/*Recursion in tree/list problems solve independent subproblems.
recursion in optimal solution problems like dynamic programming have overlapping subproblems.*/


int b_f_r(int m, int n, int t)
{
    //cout << "calling for " << t << endl;
    total_calls++;
    if(t == 0)
        return 0;
    int first = -1, second = -1;
    if(m <= t)
    {
        //cout << "SS" << endl;
        first = b_f_r(m, n, t-m);
    }
    if(n <= t)
    {
        //cout << "SS" << endl;
        second = b_f_r(m, n, t-n);
    }
    if(second == -1 && first == -1)
        return -1;
    return max(first, second) + 1;
}

int b_f_r_m(int m, int n, int t, vector<int>& memo)
{
    //cout << "calling for " << t << endl;
    m_total_calls++;
    if(memo[t] != -2)
        return memo[t];
    int first = -1, second = -1;
    if(m <= t)
    {
        //cout << "SS" << endl;
        first = b_f_r_m(m, n, t-m, memo);
    }
    if(n <= t)
    {
        //cout << "SS" << endl;
        second = b_f_r_m(m, n, t-n, memo);
    }
    if(second == -1 && first == -1)
        memo[t] = -1;
    memo[t] = max(first, second) + 1;
    return memo[t];
}

int b_f(int m, int n, int t)
{
    total_calls = 0;
    int result;
    int o = t;
    while(t > 0)
    {
        result = b_f_r(m, n, t);
        if(result == -1)
            t--;
        else
            break;
    }
    cout << "BG :" << result << endl;
    cout << "BR :" << o - t << endl; 
    return result;
}

int b_f_m(int m, int n, int t)
{
    vector<int> memo(t + 1, -2);
    memo[0] = 0;
    m_total_calls = 0;
    int result;
    int o = t;
    while(t > 0)
    {
        result = b_f_r_m(m, n, t, memo);
        if(result == -1)
            t--;
        else
            break;
    }
    cout << "BG :" << result << endl;
    cout << "BR :" << o - t << endl; 
    
    return result;
}

int b_f_dp(int m, int n, int t)
{
    vector<int> dp(t + 1, -1);
    dp[0] = 0;
    for(int i = 0; i <= t; ++i )
    {
        int first = -1, second = -1;
        if(i >= m)
            first = dp[i - m];
        if(i >= n)
            second = dp[i - n];
        if(first == -1 && second == -1)
            dp[i] = -1;
        dp[i] = max(first, second) + 1;
    }

    for(int i = t; i > 0; i--)
    {
        if(dp[i] != -1)
        {
            cout << i << endl;
            cout <<  t - i << endl;
            return dp[i];
        }
    }
    return -1;
}

int main()
{

    // auto bgr22 = b_f(4,9,22);
    // cout << bgr22 << " CALLS :" << total_calls <<endl;

    // auto bgr54 = b_f(4,9,54);
    // cout << bgr54 << " CALLS :" << total_calls << endl;

    // auto bgr80 = b_f(4,9,80);
    // cout << bgr80 << " CALLS :" << total_calls << endl;

    auto t1 = chrono::high_resolution_clock::now();
    auto bgr88 = b_f(4,2,88);
    auto t2 = chrono::high_resolution_clock::now();
    auto d1 = t2 - t1;
    cout << bgr88 << " CALLS :" << total_calls << " " << d1.count() << endl;

    auto t3 = chrono::high_resolution_clock::now();
    auto bgr88m = b_f_m(4,2,88);
    auto t4 = chrono::high_resolution_clock::now();
    auto d2 = t4 - t3;
    cout << bgr88m << " CALLS :" << m_total_calls << " " << d2.count() <<   endl;

    auto t5 = chrono::high_resolution_clock::now();
    auto bgrdp = b_f_dp(4,2,88);
    auto t6 = chrono::high_resolution_clock::now();
    auto d3 = t6 - t5;
    cout << bgrdp <<  " " << d3.count() <<   endl;

    return 0;
}