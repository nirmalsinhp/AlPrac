#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int k)
{
    int sz = prices.size();
    if (sz < 2)
        return 0;
    int res = 0, i = 0;
    multiset<int, greater<int>> ms;
    while(i < sz)
    {
        while(i < sz && prices[i+1] <= prices[i])
            i++;
        int pb = prices[i];
        while(i < sz && prices[i+1] > prices[i])
            i++;
        int ps = prices[i];
     ms.insert(ps - pb);
    }

    auto iter = ms.begin();
    for(int i = 0; i < k; ++i)
    {
        cout << *iter << endl;
        res += *iter;
        iter++;
    }
    // for (i = 1; i < prices.size(); i++)
    // {
    //     res += max(0, prices[i] - prices[i - 1]);
    // }
    return res;

}

int main()
{
    vector vi{3,3,5,0,0,3,1,4};
    auto res = maxProfit(vi, 2);
    cout << res << endl;
    return 0;
}