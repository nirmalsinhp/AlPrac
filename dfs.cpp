#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void visit(int v)
{
    cout << v << "-->"; 
}

void dfs(const Graph& G, int v)
{
    static vector<bool> visited (G.size(), false);  
    visit(v);
    visited[v] = true;
    for(auto w : G[v])
    {
        if(!visited[w])
        {
            dfs(G, w);
        }
    }
}

int main()
{
    vector<vector<int>> G = {{1,2,3},
    {0,4},
    {3,1},
    {2,4},
    {3}
    };
    dfs(G, 0);
    cout << endl;
    return 0;
}