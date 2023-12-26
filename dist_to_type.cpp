#include <bits/stdc++.h>
using namespace std;

int time_to_type(const string & alpha, const string& text)
{
    int dist = 0;
    unordered_map<char, int> index_map;
    for(int i = 0; i < alpha.size(); ++i)
    {
        index_map[alpha[i]] = i;
    }
    int prev = 0;
    for(auto c : text)
    {
        dist += abs(prev - index_map[c]);
        prev = index_map[c];
    }
    return dist;
}

int main()
{
    string alpha = "abcdefghijklmnopqrstuvwxy";
    string text = "cbaj";
    auto ret = time_to_type(alpha, text);
    cout << ret << endl;
    return 0;
}