#include <bits/stdc++.h>

using namespace std;

int get_data()
{
    const int i= 5;
    return i;
}
struct S
{
    vector<int> data {1, 2, 3};
    const auto getData() const {return data;}
};

S getS(){ return {}; }

reference_wrapper<const int> get_data_rw()
{
    const int i= 5;
    return i;
}

int main()
{
    cout << get_data() << endl;
    cout << get_data_rw() << endl;
    for(const auto& s : getS().getData())
        cout << s << endl;
    return 0;
}