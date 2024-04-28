#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    map<char, int> smap;
    map<char, int> pmap;
    vector<int> ans;
    for (int i = 0; i < p.size(); ++i)
    {
        smap[s[i]]++;
        pmap[p[i]]++;
    }
    if (smap == pmap)
        ans.push_back(0);
    int ws = 0;
    int we = p.size();
    for (; we < s.size(); ++we, ++ws)
    {
        smap[s[we]]++;
        if(--smap[s[ws]] == 0)
            smap.erase(s[ws]);
        // cout << s[we] << " " << s[ws] << endl;
        if (smap == pmap)
            ans.push_back(ws);
    }
    return ans;
}

int main()
{
    string s = "cbaebabacd";
    string t = "abc";
    auto vs = findAnagrams(s,t);

    return 0;
}