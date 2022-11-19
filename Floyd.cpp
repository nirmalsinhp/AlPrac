#include <bits/stdc++.h>
using namespace std;

#define MAX_INT 9999999
int main()
{

    ifstream inf("infilew.txt");
    int x, y, n, w;
    inf >> n;
    bool directed = false;
    cout << "number of vertices :" << n << endl;
    vector<vector<int>> fg(n, vector<int>(n, MAX_INT) );
    while(inf >> x >> y >> w)
    {
        cout << "adding edge" << x << "->" << y << endl;
        fg[x][y] = w;
        if(!directed)
            fg[y][x] = w;
    }
    int through_k;
    // floyd
    for(int k = 0 ; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {   
                if(i == j)
                    continue; 
                through_k = fg[i][k] + fg[k][j];
                if(through_k < fg[i][j])
                    fg[i][j] = through_k;
            }
        }
    }



    for( auto &x : fg)
    {
        cout << "[ ";
        for(auto & y : x )
        {
            cout << setw(3);
            cout << y << " ";
        }
        cout << " ]";
        cout << endl;
    }


    return 0;
}