#include <bits/stdc++.h>
using namespace std;

int maxfish = 0;

void dfs(vector<vector<int>> &G, int sr, int sc, int fish)
{
    cout << sr << " " << sc << " " << fish << endl;
    int mr = G.size();
    int mc = G[0].size();
    if (sr >= 0 && sr < mr && sc >= 0 && sc < mc && G[sr][sc] != 0)
    {
        cout << "inloop " << sr << " " << sc << " " << fish << endl;

        fish += G[sr][sc];

        G[sr][sc] = 0;
        maxfish = max(fish, maxfish);
        dfs(G, sr, sc + 1, fish);
        dfs(G, sr, sc - 1, fish);
        dfs(G, sr + 1, sc, fish);
        dfs(G, sr - 1, sc, fish);
    }
}


int findMaxFish(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; i < n; ++j)
        {
            if (grid[i][j] > 0)
            {
                cout << " dfs " << i << " " << j << endl;
                dfs(grid, i, j, 0);
            }
        }
    }
    return maxfish;
}



int main()
{

    vector<vector<int>> G = {
                            {0,2,1,0},
                            {4,0, 0,3},
                            {1,0,0,4},
                            {0,3,2,0}
    };
    auto mf =findMaxFish(G);
    cout << mf << endl;
    return 0;
}