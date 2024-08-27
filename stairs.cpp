#include <bits/stdc++.h>

using namespace std;
/*
if a problem has optimal substructure (it can be solved using recursion), and there are overlapping subproblems (the same recursive call is made multiple times), then we can use dynamic programming to handle the overlapping subproblems more efficiently.*/
// it is just fibonacci, with twist
long stairs(int n)
{
    vector<long> cnt(n + 1, -1);

    cnt[0] = 1;
    cnt[1] = 1;
    
    for(int i = 2; i < n + 1; ++i)
    {
        cnt[i] = cnt[i -1] + cnt[i -2];
    }

    return cnt[n];

}

int main()
{
    auto n = stairs(100);
    auto n5 = stairs(5);
    cout << n << " ways" <<  endl;
    cout << n5 << " ways" <<  endl;
    return 0;
}