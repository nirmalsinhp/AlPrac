#include <bits/stdc++.h>
using namespace std;

/*  steps"
1. find the simplest possible input.
2. relate hard case with simple case
3. generelize the pattern
4. write code.
*/

// recursion can be like dfs in graph, one function can call multiple recursive calls, explore it. 

// stack used to convert recusrsive to iterative solution.
// do not worry about multiple frames on stack.
long long Sum(long n)
{
    cout << "n : " << n << endl;
    if(n == 1)
        return 1;
    return n + Sum(n - 1);
}

int gridPaths(int n, int m)
{
    cout << "m , n : " << m << " " << n << endl;
    if(n == 1 || m  == 1)
        return 1;
    // paths for n,m --> n-1, m & move one step down, n, m-1 & move one right, so sum of both.
    return gridPaths(n - 1, m) + gridPaths(n, m - 1);
}

int gridPathsDP(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 1));
    // dp[0][0] is 1. so 1 way to reach start position
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n-1][m-1];
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

int ways_to_partition(int n, int m)
{
    if(n == 0 && m == 0)
        return 1;
    if(m == 0 || n < 0)
        return 0;
    return ways_to_partition(n-m, m) + ways_to_partition(n, m-1);
}


int main()
{
    auto val = Sum(10);
    cout << "sum :" << val << endl;
    auto paths = gridPaths(4, 3);
    auto bio = bionomian_coff(7, 4);
    auto paths2 = gridPaths(7, 5);
    auto pathsd2 = gridPathsDP(7, 5);

    auto bio2 = bionomian_coff(15, 9);

    cout << paths << endl;
    cout << bio << endl;
    cout << paths2 << endl;
    cout << pathsd2 << endl;
    cout << bio2 << endl;

    cout << "wp " << ways_to_partition(9,5) << endl;
    cout << "wp " << ways_to_partition(11,4) << endl;
    return 0;
}