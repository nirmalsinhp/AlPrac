#include <bits/stdc++.h>
using namespace std;


vector<bool> visited;
vector<int> pre;
vector<int> post;

bool hasCycle(vector<vector<int>>& AL, int start, int parent)
{
    //bool cycle = false;
    visited[start] = true;
    pre.push_back(start);
    for(auto v : AL[start])
    {
        if(visited[v] && parent != v)
            return false;
        else if(!visited[v])
        {
            if(hasCycle(AL, v, start))
                return true;
        }
    }
    post.push_back(start);
    return false;
}

bool graph_valid_tree(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> AL(n, vector<int>());
    visited = vector<bool>(n, false);
    for(auto e : edges)
    {
        AL[e[0]].push_back(e[1]);
        AL[e[1]].push_back(e[0]);
    }
    if(hasCycle(AL, 0, -1))
        return false;
    return all_of(visited.begin(), visited.end(), [](const auto & v)
                                                        {
                                                            return v;
                                                        });
}


int main()
{
    vector<vector<int>> edges {{0, 1}, {1, 2}, {2, 3},{1,3}, {1, 4}};
    auto valid = graph_valid_tree(5, edges);
    cout << valid << endl;
    return 0;
}