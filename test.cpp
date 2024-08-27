#include <bits/stdc++.h>
using namespace std;


vector<bool> visited;
vector<int> pre;
vector<int> post;
void dfs(vector<vector<int>>& AL, int start)
{
    if(visited[start])
        return;
    visited[start] = true;
    pre.push_back(start);
    for(auto v : AL[start])
    {
        if(!visited[v])
            dfs(AL, v);
        else 
        {
            cout << "cycle" << endl;
            return;
        }
    }
    post.push_back(start);
}


int main()
{
    return 0;
}