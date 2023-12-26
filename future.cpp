#include <bits/stdc++.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

long long factorial(int n)
{
    long long res = 1;
    for(int i = 1; i <= n; ++i )
        res *= i;

    return res;
}

long long fut_fact(future<int>& f)
{
    long long res = 1;
    cout << "future fetch" << endl;
    int n = f.get();
    for(int i = 1; i <= n; ++i )
        res *= i;

    return res;
}

int main()
{
    auto fut = async(factorial , 10);
    auto val = fut.get();
    cout << val << endl;

    thread tl([] (int z) {return z;}, 6);
    promise<int> p;
    auto f2 = p.get_future();

    packaged_task<long long(int)> pt(factorial);
    pt(6);
    cout << "pt :" << pt.get_future().get() << endl;

    auto f3 = async(launch::async, fut_fact, ref(f2));
    cout << "napping" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    auto tid = this_thread::get_id();
    cout << tid << endl;
    cout << "fulfilling promise" << endl;
    p.set_value(5);
    cout << f3.get() << endl;
     // fut.get(); can not get twice

    stack<string, vector<string>> s;
    return 0;
}