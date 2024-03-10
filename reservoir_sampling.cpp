#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int k;
    int i = 0;
    cout << " how many samples : ";
    cin >> k;
    vector<int> vec(k, -1);
    while(cin >> n)
    {
    
    i++;
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(0,i);
    int r = dist(rng);
    if(r < k)
        vec[r] = n;
    }

    for(auto v : vec)
        cout << v << endl;
}