#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
    istringstream iss(s);
    map<string, int> smap;
    map<char, int> pmap;
    int i = 0;
    int n = pattern.size();
    string word;
    
    for (; iss >> word; ++i)
    {
        // if i equal to n, before we stopped reading, there is length issue.
        if (i == n || pmap[pattern[i]] != smap[word])
            return false;
        // need to use, +1 , because using [] will just insert with 0 as index, which causes issues.
        pmap[pattern[i]] = smap[word] = i + 1;
    }

    return i == n;
}


int main()
{
    string s = "cat dog dog fish";
    string p = "abba";
    bool iso = wordPattern(p, s);
    return 0;
}