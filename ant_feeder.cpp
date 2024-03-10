#include <bits/stdc++.h>
using namespace std;

// using binary search with predicate, without explicit array
// range here is min to max value.

struct edge
{
    int to;
    int pct;
    bool super;

    edge(int t, int p, bool s):to(t), pct(p), super(s)
    {}
};

using AL = vector<vector<edge>>;

const long MAX = 2000000000;
bool can_feed(int node, double lqd, AL& al, const vector<int>& need)
{
    if(need[node] != -1)
        return lqd >= need[node];
    for(const auto& e : al[node])
    {
        double dp = lqd * e.pct/100;
        if(e.super)
            dp = dp*dp;
        if(!can_feed(e.to, dp, al, need))
            return false;
    }
    return true;
}

double solve(AL& al, vector<int>& need)
{

    double lo = 1;
    double hi = MAX;
    while(hi - lo > 0.00001)
    {
        double mid = lo + (hi - lo)/2;
        if(can_feed(0, mid, al, need))
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}


int main()
{
    int nv;
    cout << "no of nodes :";
    cin >> nv;
    AL al(nv, vector<edge>());
    int to, from, pct;
    bool super;
    for(int i = 0; i < nv-1; i++)
    {
        cin >> from >> to >> pct >> super;
        edge e(to, pct, super);
        al[from].push_back(e);
    }
    vector<int> need;
    for(int i = 0; i < nv; i++)
    {
        int n;
        cin >> n;
        need.push_back(n);
    }

    auto ltr = solve(al, need);
    cout << ltr << endl;
    return 0;
}