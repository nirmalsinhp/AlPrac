#include <bits/stdc++.h>
using namespace std;

vector<string> compound(const vector<string>& svec)
{
    vector<string> out;
    unordered_set<string> sset(svec.begin(), svec.end());
    for(auto s : sset)
    {
        auto itr = s.begin();
        while(itr != s.end())
        {
            string s1(s.begin(), itr);
            string s2(itr, s.end());
            itr++;
            if(sset.count(s1) && sset.count(s2))
            {
                cout << s << " : " << s1 << " + " << s2 << endl;
                out.push_back(s);
            }
        }
    }
    return out;
}

int main()
{
    vector<string> svec = {"create", "creation", "adbhut", "asambhav", "asam", "cre", "ate", "rotate", "rot", "bhav", "sadbhav", "sad"};
    auto cvec = compound(svec);
    for(auto cv : cvec)
        cout << cv << endl;
    return 0;
} 