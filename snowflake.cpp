#include <bits/stdc++.h>
using namespace std;

bool is_duplicate(vector<int>& s1, vector<int>& s2)
{
    for(int i = 0; i < s1.size(); i++)
    {
        rotate(s2.begin(), s2.begin() + 1, s2.end());
        if(s1 == s2)
            return true;
    }
    return false;
}

void duplicate_snowflake(vector<vector<int>>& snowflakes)
{
    unordered_map<int, vector<vector<int>>> smap;
    for(const auto& s : snowflakes)
    {
        int sum = reduce(s.begin(), s.end(), 0);
        smap[sum].push_back(s);
    }

    for(auto&[sum,sv] : smap)
    {
        for(int i = 0; i < sv.size(); i++)
        {
            auto s1 = sv[i];
            for(int j = i + 1; j < sv.size(); j++)
            {
                cout << "checking" << endl;
                bool isd = is_duplicate(s1, sv[j]);
                if(isd)
                    cout << "duplicates" << endl;
            }
        }
    }

}

int main()
{
    vector<vector<int>> ss = {
        {1,2,3,4,5,6},
        {2,3,4,5,6,7},
        {3,4,5,6,1,2},
        {99, 22, 34, 12, 23, 11}
    };

    duplicate_snowflake(ss);
    return 0;
}