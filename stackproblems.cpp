#include <bits/stdc++.h>
using namespace std;

bool validParans(string s)
{
    stack<char> S;
    for (auto c : s)
    {
        switch (c)
        {
        case '(':
            S.push(')');
            break;

        case '{':
            S.push('}');
            break;

        case '[':
            S.push(']');
            break;

        default:
            if (S.empty() || S.top() != c)
                return false;
            else
                S.pop();
            break;
        }
    }
    return S.empty(); // should be empty at end.
}

string simplifyPath(string path)
{

    // add first / to path, find the string till next path, add it to stack, if .. add ignore .,

    // /home/allscripts/../  --> /home/ignore ., ignore empty, .. pop from stack, or add to the stack
    stack<string> paths;
    int pos = 1;
    int fp = 1;
    while (fp != string::npos)
    {
        fp = path.find_first_of('/', pos);
        auto p = path.substr(pos, fp - pos);
        if (p != "." && p != "")
        {
            if (p == "..")
                paths.pop();
            else
                paths.push(p);
        }
        pos = fp + 1;
    }
    stack<string> SS;
    while (!paths.empty())
    {
        SS.push(paths.top());
        paths.pop();
    }
    string ret;
    while (!SS.empty())
    {
        ret += "/" + SS.top();
        SS.pop();
    }
    return ret;
}

int evalRPN(vector<string> &tokens)
{
    stack<int> S;
    unordered_set<string> Op{"+", "-", "*", "/"};
    for (const auto &c : tokens)
    {
        if (Op.find(c) != Op.end())
        {
            int n1 = S.top();
            S.pop();
            int n2 = S.top();
            S.pop();
            if (c == "+")
                S.push(n1 + n2);
            else if (c == "-")
                S.push(n2 - n1);
            else if (c == "*")
                S.push(n1 * n2);
            else if (c == "/")
                S.push(n2 / n1);
        }
        else
        {
            S.push(stoi(c));
        }
    }
    return S.top();
}

int main()
{
    bool isv = validParans("{[]{}()[]}");
    bool isvn = validParans("{[]{()[]}");
    auto sp = simplifyPath("/home//allscripts/../");
    vector<string> vs{"4","13","5","/","+"};
    auto val = evalRPN(vs);
    cout << boolalpha << isv << " " << isvn << endl;
}