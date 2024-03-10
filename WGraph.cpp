#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int sv;
    int tv;
    double weight;

    Edge(int s, int t, double w) : sv(s), tv(t), weight(w)
    {
    }

    Edge() = default;
    ~Edge() = default;
    Edge(const Edge &oth) = default;
    Edge &operator=(const Edge &oth) = default;
    Edge(Edge &&oth) = default;
    Edge &operator=(Edge &&oth) = default;
};

ostream &operator<<(ostream &os, const Edge &E)
{
    os << E.sv << " -> " << E.tv << " with w : " << E.weight << endl;
    return os;
}

bool operator<(const Edge &lhs, const Edge &rhs)
{
    // priority queue is max heap, so reversing the comparison.
    return lhs.weight > rhs.weight;
}

using AL = vector<vector<Edge>>;

class Graph
{
public:
    Graph() = default;
    Graph(int num_v, bool d = false) : nv(num_v),
                                       al(AL(nv, vector<Edge>())),
                                       visited(vector<bool>(num_v, false)),
                                       directed(d)
    {
    }

    void insert_edge(int s, int t, double w)
    {
        al[s].push_back(Edge(s, t, w));
        if (!directed)
            al[t].push_back(Edge(t, s, w));
    }

    void init()
    {
        pre.clear();
        post.clear();
        topo_sort.clear();
        visited.assign(nv, false);
        MST.clear();
        parent.clear();
        parent.assign(nv, -1);
        dist.clear();
        dist.assign(nv, INT_MAX);
    }


    /* MST is lower bound for TSP, TSP creates spannig cycle & removing an edge creates Spanning tree, cost of spanning tree will be >= MST*/
    // Tree is connected Acyclic graph.
    // find an edge with minimum weight that connects tree vertex to non tree vertex and add it to tree, all edges are added to priority queue, weight of edge added to total weight.
    // mostly on undirected graph.
    double prim(int s)
    {
        double weight = 0;
        priority_queue<Edge> pq;
        scan(s, pq);
        while (!pq.empty())
        {
            auto me = pq.top();
            pq.pop();
            /*if(visited[me.sv] && visited[me.tv])
            {
                cout << "wrong !!!" << " Both nodes tree" << endl;
                cout << me;
                return -1;
            }*/
            if (!visited[me.tv])
            {
                weight += me.weight;
                MST.push_back(me);
                scan(me.tv, pq);
            }
        }
        return weight;
    }

    void printMST()
    {
        if (MST.empty())
        {
            cout << "run MST first" << endl;
        }
        cout << "MST" << endl;
        for (const auto e : MST)
        {
            cout << e << endl;
        }
    }

    void printG()
    {
        for (int i = 0; i < al.size(); ++i)
        {
            cout << i << " : ";
            for (auto e : al[i])
            {
                cout << e.tv << " ";
            }
            cout << endl;
        }
    }

    void visit(int v)
    {
        cout << v << " ";
    }

    void dfs(int start)
    {
        visit(start);
        visited[start] = true;
        pre.push_back(start);
        for (auto e : al[start])
        {
            auto v = e.tv;
            if (!visited[v])
            {
                parent[v] = start;
                dfs(v);
            }
        }
        post.push_back(start);
    }

    const vector<int> preorder() const
    {
        cout << "PreOrder : ";
        for (auto v : pre)
            cout << v << " ";
        cout << endl;
        return pre;
    }

    const vector<int> postorder() const
    {
        cout << "PostOrder : ";
        for (auto v : post)
            cout << v << " ";
        cout << endl;
        return post;
    }

    const vector<int> topological_order()
    {
        topo_sort.clear();
        copy(post.rbegin(), post.rend(), back_inserter(topo_sort));
        cout << "TopologicalOrder : ";
        for (auto v : topo_sort)
            cout << v << " ";
        cout << endl;
        return topo_sort;
    }

    //. Dijkstra's algorithm initializing dist[s] to 0 and all other distTo[] entries to positive infinity. Then, it repeatedly relaxes and adds to the tree a non-tree vertex with the lowest distTo[] value, continuing until all vertices are on the tree or no non-tree vertex has a finite distTo[] value.
    vector<int> Dijkstra(int s)
    {
        /* 2 steps
            1.  update the distances from current vertex
            2. choose best next vertex with smallest distnace & visited false;

        */
        vector<int> out_tree;

        dist[s] = 0;
        //visited[s] = true;
        auto v = s;
        while (!visited[v])
        {
            visited[v] = true;
            out_tree.push_back(v);
            for (const auto e : al[v])
            {
                relax(e);
            }

            // find next vertice.
            auto di = INT_MAX;
            int i = 0;
            for(int i =0 ; i < nv; i++)
            {
                if(!visited[i] && dist[i] < di)
                {
                    di = dist[i];
                    v = i;
                }
            }
        }
    return out_tree;
    }


    void bellman_ford(int s)
    {
        dist[s] = 0;
        for(int i = 0; i < nv; ++i)
        {
            for(int j = 0; j < nv; ++j)
            {
                for(auto e : al[j])
                    relax(e);
            }
        }
    }

    void relax(const Edge &e)
    {
        auto v = e.tv;
        if (dist[v] > dist[e.sv] + e.weight)
        {
            dist[v] = dist[e.sv] + e.weight;
            parent[v] = e.sv;
            // update distance set
        }
    }

    void bfs(int start)
    {
        deque<int> dq;
        dq.push_back(start);
        visited[start] = true;
        visit(start);

        while (!dq.empty())
        {
            auto v = dq.front();
            dq.pop_front();
            for (auto e : al[v])
            {
                auto u = e.tv;
                if (!visited[u])
                {
                    visited[u] = true;
                    dq.push_back(u);
                    visit(u);
                }
            }
        }
    }

    int components()
    {
        connected_components();
        return num_components;
    }

private:
    void connected_components()
    {
        for (int i = 0; i < nv; i++)
        {
            if (!visited[i])
            {
                num_components++;
                dfs(i);
                cout << endl;
            }
        }
    }

    void scan(int s, priority_queue<Edge> &pq)
    {
        assert(!visited[s]);
        visited[s] = true;
        for (const auto &e : al[s])
        {
            if (!visited[e.tv])
                pq.push(e);
        }
    }

    unsigned nv;
    unsigned ne;
    AL al;
    vector<bool> visited;
    vector<int> pre;
    vector<int> post;
    vector<int> topo_sort;
    vector<int> parent;
    vector<double> dist;
    int num_components;
    bool directed = false;
    vector<Edge> MST;
};

int main()
{
    fstream fs("./tinygw.txt", ios_base::in);
    int nv;
    fs >> nv;
    int ne;
    fs >> ne;
    Graph G(nv);
    int s, t;
    double w;
    // Graph G(nv, {});
    for (int i = 0; i < ne; ++i)
    {
        fs >> s >> t >> w;
        G.insert_edge(s, t, w);
    }
    G.printG();
    G.init();
    cout << "DFS 0 : ";
    G.dfs(0);
    cout << endl;
    auto pre = G.preorder();
    auto post = G.postorder();
    auto top = G.topological_order();
    G.init();
    cout << "components : " << G.components() << endl;
    auto prec = G.preorder();
    auto postc = G.postorder();
    auto topc = G.topological_order();

    cout << endl;

    cout << "BFS 0 :";
    G.init();
    G.bfs(0);
    cout << endl;

    G.init();
    cout << "DFS 7 : ";
    G.dfs(7);
    cout << endl;

    G.init();
    cout << "Prim" << endl;
    auto wg = G.prim(0);
    cout << "MST weight" << wg << endl;
    G.printMST();

    G.init();
    auto sp = G.Dijkstra(2);
    for(auto v : sp)
        cout << v << " ";
    cout << endl;
    return 0;
}