#include <bits/stdc++.h>
#include "Graph.h"

using namespace std;

/*int main()
{

    ifstream inf("infilet.txt");
    if(!inf.is_open())
    {
        cout << "issue opening file" << endl;
        return -1;
    }
    int x, y, n;
    inf >> n;
    cout << "number of vertices :" << n << endl;
    auto g = make_unique<Graph>(n, true);
    while(inf >> x >> y)
    {
        cout << "adding edge" << x << "->" << y << endl;
        g->insert_edge(x, y);
    }

    cout << "printing Graph" << endl;
 
    //g->print_graph();
    cout << "dfs" << endl;
    //g->bfs(1);
    //g->find_path(1,6);
    g->init_search();
    //g->print_graph();
    g->TopoSort();
    auto tg = g->transpose();
    tg->TopoSort();

}*/