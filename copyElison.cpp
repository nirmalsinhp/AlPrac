#include <bits/stdc++.h>
using namespace std;

struct copyElison
{
    copyElison() = default;
    copyElison(const copyElison&) = delete;
    copyElison(copyElison&&) = delete;
    int i = 10;
};

auto getSt()
{
    return copyElison{}; 
}

int main()
{
    auto ce = getSt();
    cout << ce.i << endl;
    return 0;
}