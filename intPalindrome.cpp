#include <bits/stdc++.h>
using namespace  std;

bool isPalindromS(int num)
{
    string s = to_string(num);
    int i  = 0;
    int j = s.length() - 1;
    int mid = s.length() / 2 + 1;
    for (; i < mid ; ++i, --j )
    {
        if(s[i] != s[j])
            return false;
    }
    return true;
}

bool isPalindrom(int num)
{
    int mul  = 1;
    vector<int> las;
    int mod = 0;
    int orig_num = num;
    int rev = 0;
    while (num > 0)
    {
        rev = rev * 10 + num % 10;
        num = num / 10;
    }

    if(rev == orig_num)
        return true;
    else    
        return false;



}


// int main()
// {
//     int in; 
//     cout << "please enter integer :";
//     cin >> in;
//     cout << "entered number - " << in << endl; 
//     bool isPal = isPalindrom(in);
//     cout << ( isPal ? "Palindrom" : "Not Palindrom") << endl;
//     return 0;
// }