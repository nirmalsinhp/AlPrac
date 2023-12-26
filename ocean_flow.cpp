#include <bits/stdc++.h>
using namespace std;

// TODO complete this.
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<int>>

    }

    bool traverse(vector<vector<int>> & vec, int i, int j)
    {
        static int rows = vec.size();
        static int cols = vec[0].size();

        if(i < 0 || i > rows || j < 0 || i > cols)
            return false;

        if((i == 0 || j == 0) && (i == rows || j == cols))
        {
            return true;
        }
        return traverse(vec, i - 1, j) || 
        traverse(vec, i + 1, j) || 
        traverse(vec, i, j - 1) ||
        traverse(vec, i, j + 1);

    }

    private:
    vector<vector<int>> out;
};