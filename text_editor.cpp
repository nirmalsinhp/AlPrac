#include <bits/stdc++.h>

using namespace std;

using TE = vector<pair<int,list<char>>>;
void insertAtIndex(unsigned int index, TE& te, string in_string)
{
    TE::value_type row = make_pair(index, list<char>());
    auto ir =  lower_bound(te.begin(), te.end(), row);
    int si = ir->first;
    int il = index - si;
    auto li = ir->second.begin();
    advance(li, il);
    ir->second.insert(li, in_string.begin(), in_string.end());
}

int main()
{
    TE t;
    string s1 = "nimklwkvnewknvkew vnewknvek vnnewnvkew nvkewnew nkvwenkln nvkwenkewl nvkewkwel";
    string s2 = "nimklwkhhnewknhhkew hhnewknhhek hhnnewnhhkew nhhkewnew nkhhwenkln nhhkwenkewl nhhkewkwl";
    string s3 = "nimklwkhhnewknhhkew hhnewknhhek hhnnewnhhkew nhhkewnew nkhhwenkln nhhkwenkewl nhhkewkwel";
    string s4 = "nimblwbvnewbnvbew vnewbnveb vnnewnvbew nvbewnew nbvwenbln nvbwenbewl nvbewbwel";
    string s5 = "nimblwbvnewbnvbew vnewbnveb vnnewnvbew nvbewnew nbvwenbln nvbwenbewl nvbewbwel";
    vector<string> vs;
    vs.emplace_back(move(s1));
    vs.push_back(s2);
    vs.push_back(s3);
    vs.push_back(s4);
    vs.push_back(s5);
    for(const auto& s : vs)
    {
        t.push_back({s.size(), list<char>(s.begin(), s.end())});
    }
    insertAtIndex(120,t,"totoro");
    return 0;
}