#include <bits/stdc++.h>

using namespace std;

class Graph
{
    vector<vector<int>> schedule()
    {
        vector<vector<int>> sv;
        for(int i = 0; i < AL.size(); i++)
        {
            if(!visited[i])
            {
                sortv.clear();
                dfs(i);
            }
            vector<int> ts(sortv.rbegin(), sortv.rend());
            sv.push_back(ts); // emplace also works
        }
        return sv;
    }


    void dfs(int start)
    {
        visited[start] = true;
        for(const auto & v : AL[start])
        {
            if(!visited[v])
            {
                dfs(v);
            }
            else if(visited[v])
            {
                cout << "cycle, stop now" << endl;
            }
        }
        sortv.push_back(start);
    }
    

    private:
    vector<bool> visited;
    vector<vector<int>> AL;
    vector<int> sortv;
}


