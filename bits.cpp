#include <bits/stdc++.h>
using namespace std;

int main()
{
    int for2 = 42;
    float fl = 345.34;
//    cout << hex << for2 << " " << fl << endl;
    //cout << hex << fl << endl;

    for(int i = 0 ; i < 10 ; ++i)
    {
        cout << i << " << "  << (1 << i) << endl;
        cout << i << " >> "  << (2048 >> i) << endl;
        //cout << i << "  "  << (i << 1) << endl;
 //       cout << i << ": "  << std::hex << (1 << i) << endl;
    }
    return 0;
}