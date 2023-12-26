#include <bits/stdc++.h>
using namespace std;


int detm(vector<vector<int>> mat)
{
    long det = 0;
    int n = mat.size();
    int m = mat[0].size();

    if(n != m)
        return -1;
    
    if(n == 1)
        return mat[0][0];
    if(n == 2)
    {
        det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
        return det;
    }

    for(int i = 0; i < n; i++)
    {
        vector<vector<int>> sub;
        for(int r = 1; r < n; r++)
        {
            vector<int> irow;
            for(int c = 0; c < n; c++)
            {
                if(c != i)
                {
                    irow.push_back(mat[r][c]);
                }
            }
            sub.push_back(irow);
        }
        det += pow(-1, i) * detm(sub);
    }
    return det;
}

int main()
{

    vector<vector<int>> m{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    auto de = detm(m);
    cout <<de << endl;
    return 0;
}