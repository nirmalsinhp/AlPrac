#include <bits/stdc++.h>
using namespace std;

using AL = vector<vector<int>>;

AL al;
vector<bool> visited(al.size(), false);

void dfs(int start)
{
    visited[start] = true;
    for (auto v : al[start])
    {
        if (!visited[v])
            dfs(v);
    }
}

void dfss(int start)
{
    stack<int> S;
    S.push(start);
    while (!S.empty())
    {
        auto v = S.top();
        S.pop();
        if (!visited[v])
            visited[v] = true;
        for (auto u : al[v])
        {
            if (!visited[u])
                S.push(u);
        }
    }
}

void bfs(int start)
{
    deque<int> Q;
    Q.push_back(start);
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop_front();
        visited[v] = true;
        for(auto u : al[v])
        {
            if(!visited[u])
                Q.push_back(u);
        }
    }
}

int main()
{
        vector<int> nums{1,2,2,5,3,5};
        set<int, greater<int>> is(nums.begin(), nums.end());
        for(auto i : is)
            cout << i << " ";
        cout << endl;
        if(is.size() < 3)
            return *is.begin();
        set<int>::iterator itr = is.begin();
        cout << *itr << " ";
        --itr;
        cout << *itr << " ";
        --itr;
        cout << *itr << " ";
        //--itr;

    vector<vector<int>> m = {{1}};
    cout << sizeof(m) / sizeof(int) << endl;
    cout << m.size() << endl;
    cout << m.capacity() << endl;
    return 0;
}