#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> cmap;
    for(auto c : s)
    {
        cmap[c]++;
    }
    priority_queue<pair<int, char>> pq; 
    string res;
    for(const auto &[c, freq] : cmap)
    {
        pq.push({freq, c});
    }
    while(!pq.empty())
    {
        auto kv = pq.top();
        res += string(kv.first, kv.second);
        pq.pop();
    }
    return res;
}

bool is_anagram(const string& s, const string& t)
{
    unordered_map<char, int> smap;
    unordered_map<char, int> tmap;
    if(s.length() != t.length())
        return false;
    for(auto i = 0; i < s.size(); ++i)
    {
        smap[s[i]]++;
        tmap[t[i]]++;
    }

    if(smap == tmap)
        return true;
    return false;
}

int brute_s(const string& text, const string& pattern)
{
    // O(n * m)
    // O(1) space
    int n = text.size();
    int m = pattern.size();
    for(int i = 0; i < n; ++i)
    {
        int j;
        // start search for pattern, starting with i, to i +j
        for(j = 0; j < m && i  + j < n; ++j)
        {
            if(text[i + j] != pattern[j])
                break;
        }
        if(j == m)
            return i;
    }
    return -1;
}

int len_last_word(string s)
{
    int iter = s.find_last_of(' ');
    auto len = s.size() -  iter -1;
}
 
string reverseWord(string s)
{
    string ret;
    auto start = s.rbegin();
    auto end = s.rend();
    while(start != end)
    {
    auto iter = find_if(start, end, [](auto c)
                                    {return !isspace(c);}); 
    auto iter2 = find_if(iter, end, [](auto c)
                                    {return isspace(c);});
    string token = string(iter2.base(), iter.base());
    ret += token + " ";
    start = iter2;
    }
    return ret;
}

int main()
{
    string text = "The “naive” approach is easy to understand and implement but it can be too slow in some cases. If the length of the text is n and the length of the pattern m, in the worst case it may take as much as (n * m) iterations to complete the task.";
    cout << "enter pattern to search for : ";
    string pat;
    text.find(pat);
    cin >> pat;
    auto found = brute_s(text, pat);
    cout << "pattern : " << pat << (found >= 0 ? " found" : " not found") << endl;

    bool anagram = is_anagram("anagram", "nagaram");
    bool ananot = is_anagram("anagrat", "nagaram");
    cout << anagram <<  endl;
    cout << ananot <<  endl;

    auto frs  = frequencySort("tree");
    cout << frs << endl;
    
}