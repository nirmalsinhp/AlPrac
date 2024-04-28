#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4294967295;
    int sum = 0;
    while(n)
    {
        int dig = n % 10;
        if(dig % 2 == 0)
            sum += dig;
        n = n /10;
    }
    return sum;
}