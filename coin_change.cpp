#include <bits/stdc++.h>
using namespace std;

int coin_change(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, amount+ 1);
    dp[0] = 0;
    for(int i = 1; i < amount + 1; ++i)
    {
        for(auto c : coins)
        {
            if(c <= i)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    
    return dp.back() > amount ? -1 : dp.back();

}

int main()
{
    vector<int> coins{1,2,5};
    auto cc = coin_change(coins, 11);
    cout << cc << endl;
    cout << " 12 : " << coin_change(coins, 12) << endl;
    cout << " 44 : " << coin_change(coins, 44) << endl;
    cout << " 24 : " << coin_change(coins, 24) << endl;
    cout << " 51 : " << coin_change(coins, 51) << endl;
    return 0;
}