#include <bits/stdc++.h>
using namespace std;

void cutting_rode(vector<int>& prices, vector<int>& values, vector<int>& parents)
{
    int n = prices.size();
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j < i; ++j)
        {
            int val = values[i-j] + values[j];
            if( val > values[i])
            {
                values[i] = val;
                parents[i] = j;
            }
        }
    }
}


void fetch_parts(const vector<int>& values, const vector<int>& parents, int n)
{
    if(parents[n] == -1)
    {
        cout << values[n] << " ";
        return;
    }
    
    cout << values[parents[n]] << " ";
    fetch_parts(values, parents, n - parents[n]);


}

int main()
{
    vector<int> prices = {0, 1, 4, 8, 9, 10, 17, 17, 20};
    vector<int> values = prices;
    vector<int> parents(prices.size(), -1);

    cutting_rode(prices, values, parents);

    for(auto v : values)
        cout << v << " ";
    cout << endl;
    fetch_parts(prices, parents, 8);


    /*vector<vector<int>> inter = { {1,2,23,4,34} , {23, 34,23,23}};
    vector<int> newi;
    auto iter = upper_bound(inter.begin(), inter.end(), 34, [](const vector<int> si, int val) 
                                                        {
                                                            return si[0] < val;
                                                        });*/
    return 0;
}