#include <bits/stdc++.h>
using namespace std;

int trapWater(vector<int>& height)
{
    int l = 0;
    int r = height.size() - 1;
    int level = 0;
    int water = 0;
    cout << " I  LH  LV  ++ TW" << endl;
    while(l < r)
    {
        int index = height[l] < height[r] ? l++ : r--;
        int lower = height[index];
        level = max(level, lower);
        water += level - lower;
        cout <<index << " "  << lower << " " <<  level << " " << (level - lower) << " "<< water << endl;
    }

    return water;
}

int main()
{

    vector<int> h{0,1,0,2,1,0,1,3,2,1,2,1};
    auto water = trapWater(h);
    cout << "water :" << water << endl;
     return 0;
}