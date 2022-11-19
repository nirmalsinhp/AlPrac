#include <bits/stdc++.h>
#include "Graph.h"
#define MAXINT 9999999
namespace EP{

class Edge{
    public:

    int s;
    int d;
    int weight;

    Edge() = default;
    ~Edge() = default;
    Edge(const Edge& ) = default;
    Edge& operator = (const Edge&) = default;
    Edge(int x, int y, int w) : s(x), d(y), weight(w)
    {
    }
};

bool operator <(const Edge& l , const Edge& r)
{
    return l.weight < r.weight;
}

};


using namespace EP;
int primpq(priority_queue<Edge>& pq, int start, vector<bool>& visited, vector<int>& distance)
{

    return 1;
}

/*int main()
{
    ifstream inf("infilew.txt");
    int x, y, n, w;
    inf >> n;
    cout << "number of vertices :" << n << endl;
    auto g = make_unique<Graph>(n);
    while(inf >> x >> y >> w)
    {
        cout << "adding edge" << x << "->" << y << endl;
        g->insert_edge(x, y, w);
    }
 
    // vector<bool> visited(n, false);
    // vector<int> distance(n, MAXINT);
    //g->print_graph();
    //cout << "bfs" << endl;
    //g->bfs(1);
    //g->find_path(1,6);
    g->init_search();
    // g->connected_components();
    //cout << "colored :"<<  (g->two_color() ? "Yes" : "No") << endl;
    //g->dfs(1);
    int start = 1;
//    int mst_weight = prim(pq, start, visited, distance);
    //int mst_w =  g->prim(start);
    //int mst_w =  g->primQ(start);
    int stp =  g->Dijkstra(start);
    // cout << "MST weight :" << mst_w << endl; 
    cout << "STP weight :" << stp << endl; 
    g->find_path(1,6);
}*/
