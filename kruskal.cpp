#include <bits/stdc++.h>
#include "Graph.h"
#include "UF.h"
#define MAXINT 9999999
namespace E1{

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

/*int main()
{
    ifstream inf("infilew.txt");
    int x, y, n, w;
    inf >> n;
    cout << "number of vertices :" << n << endl;
    // auto g = make_unique<Graph>(n);
    // while(inf >> x >> y >> w)
    // {
    //     cout << "adding edge" << x << "->" << y << endl;
    //     g->insert_edge(x, y, w);
    // }
    using namespace E1;
    vector<Edge> edges;
    cout << "printing Graph" << endl;
    while(inf >> x >> y >> w) 
    {
         cout << "adding edge" << x << "->" << y <<  "with weight" << w << endl;
         edges.emplace_back(Edge(x,y,w));
    }
 
    sort(edges.begin(), edges.end());
    // vector<bool> visited(n, false);
    // vector<int> distance(n, MAXINT);
    //g->print_graph();
    cout << "kruskal" << endl;
    //g->bfs(1);
    //g->find_path(1,6);
    //g->init_search();
    // g->connected_components();
    //cout << "colored :"<<  (g->two_color() ? "Yes" : "No") << endl;
    //g->dfs(1);
    int start = 1;
    int weight = 0;
//    int mst_weight = prim(pq, start, visited, distance);
    //int mst_w =  g->prim(start);
    //int mst_w =  g->primQ(start);
    //cout << "MST weight :" << mst_w << endl; 
    UF uf = UF(n);
    int ne = 0;
    for(const auto& e : edges)
    {
        if(!uf.same_component(e.s, e.d))
        {
            if(ne == n - 1)
                break;                
            cout << "added Edge" << e.s << "->" << e.d  << "with weight" << e.weight << endl; 
            weight += e.weight;
            uf.unions(e.s, e.d);
            ne++;
        }
    }

    cout << "MST weight kruskal" << weight <<  endl;
}*/
