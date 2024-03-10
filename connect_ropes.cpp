#include <bits/stdc++.h>
using namespace std;

int conn_ropes(vector<int> ropes)
{
    cout << "in function " << endl;
    int len = 0;
    priority_queue<int,vector<int>, greater<>> pq(ropes.begin(), ropes.end());
    while(pq.size() > 1)
    {
        auto f = pq.top();
        pq.pop();
        auto s = pq.top();
        pq.pop();
        auto sum = f + s;
        pq.push(sum);
        len += sum;
        cout << sum << endl;
    }
    //ranges::sort(ropes);

    return len;
}

int main()
{
    vector<int> ropes = {70, 59, 41, 42, 75};
    priority_queue<int> pq3 {less<int>(), ropes};
    auto ret = conn_ropes(ropes);
    cout <<"cost : " << ret << endl;
    sort(ropes.begin(), ropes.end());
    vector<int> ps;
    partial_sum(ropes.begin(), ropes.end(), back_inserter(ps));
    copy(ps.begin(), ps.end(), ostream_iterator<int>(cout, ", "));
    return 0;
}