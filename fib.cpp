#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
static long long count_r = 0;
static long long count_m = 0;

long long fibdp(int n)
{
    vector<long long> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < n + 1; ++i)
    {
        dp[i] = dp[i - 1] + dp[i-2];
    }

    return dp[n];
}

long long fib_r(int n)
{

    count_r++;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fib_r(n - 1) + fib_r(n - 2);
}

long long fib_c(int n, vector<long long> &C)
{

    count_m++;
    if (C[n] == -1)
        C[n] = fib_c(n - 1, C) + fib_c(n - 2, C);

    return (C[n]);
}

long long fib_d(int n)
{
    static vector<long long> cache(n + 1, -1); // 0 to n, so size is n + 1;
    cache[0] = 0;
    cache[1] = 1;

    return (fib_c(n, cache));
}

long long fib_dp(int n)
{
    static vector<long long> ca(n + 1, -1);
    ca[0] = 0;
    ca[1] = 1;

    for (int i = 2; i < n + 1; ++i)
    {
        ca[i] = ca[i - 1] + ca[i - 2];
    }

    return ca[n];
}

long long fib_u(int n)
{
    long long back1 = 0, back2 = 1, next;

    if (0 == n)
        return 0;
    for (int i = 2; i < n + 1; ++i)
    {
        next = back2 + back1;
        back2 = back1;
        back1 = next;
    }

    return (back1 + back2);
}

int bionomian_coff(int n, int k)
{
    vector<vector<int>> bc(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        bc[i][0] = 1;
        bc[i][i] = 1;
    }

    for (int i = 2; i < n + 1; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
        }
    }

    return bc[n][k];
}

int main()
{

    using chrono::duration;
    using chrono::duration_cast;
    using chrono::high_resolution_clock;
    using chrono::nanoseconds;

    auto t1 = high_resolution_clock::now();
    auto f = fib_r(10);
    cout << "fib " << f << endl;
    auto t2 = high_resolution_clock::now();

    cout << "_______________" << endl;
    auto t3 = high_resolution_clock::now();
    auto f1 = fib_d(10);
    cout << "fib d " << f1 << endl;
    auto t4 = high_resolution_clock::now();

    auto t7 = high_resolution_clock::now();
    auto fd = fib_dp(10);
    auto fdf = fibdp(10);

    cout << "fib dp " << fd << endl;
    cout << "fib ddp " << fdf << endl;
    auto t8 = high_resolution_clock::now();

    auto t5 = high_resolution_clock::now();
    auto fu = fib_u(10);
    cout << "fib du " << fu << endl;
    auto t6 = high_resolution_clock::now();

    cout << "recursion function called :" << count_r << endl;
    cout << "Cached function called :" << count_m << endl;
    auto g1 = duration_cast<nanoseconds>(t2 - t1);
    auto p1 = duration_cast<nanoseconds>(t4 - t3);
    auto d1 = duration_cast<nanoseconds>(t6 - t5);
    auto d2 = duration_cast<nanoseconds>(t8 - t7);
    cout << "recursion time " << g1.count() << endl;
    cout << "memoization time " << p1.count() << endl;
    cout << "dynamic time " << d1.count() << endl;
    cout << "dynamic  2 time " << d2.count() << endl;

    cout << "binomian coeff :" << bionomian_coff(4, 5) << endl;

    return 0;
}