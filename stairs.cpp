#include <bits/stdc++.h>
using namespace std;


int stepPerms(int n) {

    static int count = 0;
    if(n < 0 )
    {
        return 0;
    }
    
    if(n == 0)
    {
        count++;
        return 0;
    }
    
    int one = stepPerms(n-1);
    int two = stepPerms(n-2);
    int three = stepPerms(n-3);
    
    cout << "count :" << count << endl;
   return count;
    
}

int main()
{
    unsigned int  in;
    cout << "enter number of stairs :";
    cin >> in;
    stepPerms(in);
    return 0;
}

