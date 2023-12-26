#include <bits/stdc++.h>
using namespace std;

bool word_break(string s,const vector<string>& dict)
{
    vector<bool> DP(s.size() + 1, false);
    // 0 length string can always be built.
    DP[0] =  true;
    // this is the length.. of string, 0 to n, so need n + 1
    for(int i = 1; i <= s.size(); ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(DP[j] && find(dict.begin(), dict.end(), s.substr(j, i- j)) != dict.end())
            {   
                DP[i] =  true;
            }
        }
    }
    return DP.back();
}

int main()
{
    string s = "applepenapplepenpenapple";
    vector<string> words{"apple", "pen"};
    auto create = word_break(s, words);
    cout << boolalpha << create << endl;
    return 0;
}