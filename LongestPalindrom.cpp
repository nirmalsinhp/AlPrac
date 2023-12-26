#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    vector<vector<string>> ret;
    unordered_map<string, vector<string>> umap;
    for (const auto &s : strs)
    {
        auto k = s;
        sort(k.begin(), k.end());
        umap[k].push_back(s);
    }

    for (const auto &vec : umap)
    {
        ret.push_back(vec.second);
    }

    return ret;
}

string expand(const string &S, int left, int right)
{
    while (left >= 0 && right < S.size() && S[left] == S[right])
    {
        left--;
        right++;
    }

    return S.substr(left + 1, right - left - 1);
}

string LongestPalindrom(string S)
{
    string res = "";
    for (int i = 0; i < S.size(); ++i)
    {
        auto odd = expand(S, i, i);
        if (odd.length() > res.length())
            res = odd;

        auto even = expand(S, i, i + 1);
        if (even.length() > res.length())
            res = even;
        cout << "res : " << res << endl;
    }

    return res;
}

int main()
{
    string S;
    cout << "enter string : ";
    cin >> S;
    while ("Q" != S)
    {
        auto longest = LongestPalindrom(S);
        cout << " Longest palindrom : " << longest << endl;
        cin >> S;
    }
    return 0;
}