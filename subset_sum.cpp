#include <bits/stdc++.h>
#include <limits.h>
using namespace std;


bool subset_sum(const vector<int>& S, int k)
{
    int n = S.size();

    vector<vector<bool>> sum(n + 1, vector<bool>(k + 1, false));

    sum[0][0] = true;
    for(int r = 1; r <= k; ++r)
    {
        sum[0][r] = false;
    }

    for(int i = 1; i < n+1; ++i)
    {
        for(int j = 0; j < k + 1; ++j)
        {
            sum[i][j] = sum[i - 1][j];

            if(j >= S[i-1] && (sum[i-1][j - S[i -1]] == true))
            {
                cout << "i : " << i << ", j : " <<  j << endl;
                cout << "set value :" << S[i - 1] << endl;
                sum[i][j] = true;
            }
        }
    }

    return sum[n][k];
}


int main()
{
    vector<int> S = {1,2,4,8};
    int k = 11;

    auto solve = subset_sum(S, k);
    cout << "is knapsack solved :" <<  solve << endl; ;
}