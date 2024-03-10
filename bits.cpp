#include <bits/stdc++.h>
using namespace std;

#define BIT_V(X, N) (((X) >> (N)) & 0x1)
int main()
{
    int for2 = -42;
    float fl = 42.34;
    constexpr size_t sz = sizeof(for2) * 8;
    cout << sz << endl;
    cout << for2 << " : " << bitset<sz>(for2) << endl;
    cout << BIT_V(for2, 3) << endl;
    cout << BIT_V(for2, 4) << endl;

    // set
    for2 |= 0x1 << 2;
    cout << for2 << " : " << bitset<sz>(for2) << endl;
    //clear
    for2 &= ~(0x1 << 2);
    cout << for2 << " : " << bitset<sz>(for2) << endl;
    // toggle
    for2 ^= 0x1 << 5;
    cout << for2 << " : " << bitset<sz>(for2) << endl;

    for2 ^= 0x1 << 5;
    cout << for2 << " : " << bitset<sz>(for2) << endl;

    cout << hex << for2 << " " << fl << endl;
    // cout << hex << fl << endl;

    /*for(int i = 0 ; i < 10 ; ++i)
    {
        cout << i << " << "  << (1 << i) << endl;
        cout << i << " >> "  << (2048 >> i) << endl;
        //cout << i << "  "  << (i << 1) << endl;
 //       cout << i << ": "  << std::hex << (1 << i) << endl;
    }*/




    return 0;
}