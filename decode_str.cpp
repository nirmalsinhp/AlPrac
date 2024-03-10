#include <bits/stdc++.h>
using namespace std;

string decoder(string& s, int& i)
{
    cout << i << endl;
    string res;
    string num;
    for(; i < s.size(); i++)
    {
        cout << s[i] << endl;
        if(s[i] == '[')
        {
            string rs = decoder(s, ++i);
            int n = stoi(num);
            num = ""; // this handles case where multiple string inside single brackets.
            cout << "n is " << n << endl;
            while(n-- > 0)
                res += rs;
        }
        else if(isdigit(s[i]))
        {
            num += s[i];
        }
        else if(s[i] == ']')
        {
            cout << "R : " << res << endl; 
            return res;
        }
        else
            res += s[i];
    }
    
    cout << "R : " << res << endl;
    return res;
}


string decode_r(string s)
{
    int i = 0;
    return decoder(s, i);
}

string decodes(string s)
{
    string res;
    stack<char> S;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != ']')
            S.push(s[i]);
        else
        {
            string curr;
            while(S.top() != '[')
            {
                curr = S.top() + curr;
                S.pop();
            }
            S.pop();
            string num;
            while(!S.empty() && isdigit(S.top()))
            {
                num = S.top() + num;
                S.pop();
            }

            int n = stoi(num);
            cout << n << " " << curr << endl;
            for(int j = 0; j < n; j++)
            {
                for(auto c : curr)
                    S.push(c);
            }
        }
    }
    
    while(!S.empty())
    {
        res = S.top() + res;
        S.pop();
    }

    return res;
}

string repeat(string s, int n)
{
    string ans;
    while(n-- > 0)
        ans += s;
    return ans;
}
string decode2s(string s)
{
    stack<pair<string, int>> S;
    string ans;
    string num;
    string prev;    
    for(auto c: s)
    {
        if(isalpha(c))  ans += c;
        else if(isdigit(c))  num += c;
        else if(c == '[')
        {
            int n = stoi(num);
            num = "";
            S.push(make_pair(move(ans), n));
        }
        else
        {
            auto[prev, n] = S.top();
            S.pop();
            ans = prev + repeat(ans, n);
        }
    }
    return ans;
}

int main()
{
    string st = "3[a2[bc]2[d]f]";
    auto ds = decode_r(st);
    cout <<"decoded : " << ds << endl;
    auto dss = decodes(st);
    cout <<"decodeds : " << dss << endl;
    assert(ds == dss);
    auto d2s = decode2s(st);
    cout <<"decoded2 : " << d2s << endl;
    assert(ds == d2s);
    return 0;
}