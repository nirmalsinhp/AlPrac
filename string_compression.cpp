#include <bits/stdc++.h>
using namespace std;

int string_compress(string & s)
{
    int sz = s.size();
    size_t a = 0;
    size_t p = 0;
    char c = s.front();
    while(p != string::npos)
    {
        c = s[p];
        auto nf = s.find_first_not_of(c, p);
        string count = to_string((nf != string::npos ? nf : sz) - p);
        s[a++] = c;
        for(auto cs : count)
            s[a++] = cs;
        p = nf;   
    }
    return a;
}


int main()
{
    string s = "abbbbbbbbbbb";
    auto cnt = string_compress(s);
    cout << cnt << endl;
    cout << s << endl;
    return 0;
}