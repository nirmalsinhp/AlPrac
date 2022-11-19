#include <bits/stdc++.h>
#include "Graph.h"





/*int main()
{
    ifstream inf("infile.txt");
    int x, y, n;
    inf >> n;
    cout << "number of vertices :" << n << endl;
    auto g = make_unique<Graph>(n);
    while(inf >> x >> y)
    {
        cout << "adding edge" << x << "->" << y << endl;
        g->insert_edge(x, y);
    }

    cout << "printing Graph" << endl;
 
    //g->print_graph();
    cout << "bfs" << endl;
    //g->bfs(1);
    //g->find_path(1,6);
    g->init_search();
    // g->connected_components();
    //cout << "colored :"<<  (g->two_color() ? "Yes" : "No") << endl;
    g->dfs(1);

}
*/