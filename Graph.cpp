#include <bits/stdc++.h>
using namespace std;


// preorder vs postorder in dfs, just have one line diff, when you call process/visit.

// if vertex v is visited, means there is path from source to v, use parents pointers to get that path.
using AL = vector<vector<int>>;
class Graph
{
public:
    Graph() = default;
    Graph(int num_v) : nv(num_v),
                       al(AL(nv, vector<int>())),
                       visited(vector<bool>(num_v, false))
    {
    }

    void insert_edge(int s, int t)
    {
        al[s].push_back(t);
        if (!directed)
            al[t].push_back(s);
    }
    void init()
    {
        pre.clear();
        post.clear();
        topo_sort.clear();
        visited.assign(nv, false);
        parent.clear();
        parent.assign(nv, -1);
    }

    void printG()
    {
        for (int i = 0; i < al.size(); ++i)
        {
            cout << i << " : ";
            for (auto u : al[i])
            {
                cout << u << " ";
            }
            cout << endl;
        }
    }

    void visit(int v)
    {
        cout << v << " ";
    }


    /*
    Applications of dfs
    - cycle detection - if edge to already visited vertice
    - connected components -  run dfs till all visited
    - topologocal sort - DAG only, reverse DFS postorder
    - bipartite - when doing dfs = mark color as opposite of parent, if already visited, and color same as parent, not bipartite.
    */
    void dfs(int start)
    {
        visit(start);
        visited[start] = true;
        pre.push_back(start);
        for (auto v : al[start])
        {
            if (!visited[v])
            {
                parent[v] = start;
                dfs(v);
            }
            else if(parent[start] != v)
            {
                cout << " cycle detected " << endl;
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


    /*
    -- changing queue to stack in BFS, gives dfs order.
    BFS applications
    - shortest paths on unweighted graphs. as nodes visited in increasing distances.
    - flood fill
    */
    void bfs(int start)
    {
        deque<int> dq;
        dq.push_back(start);
        visited[start] = true;
        visit(start);

        while (!dq.empty())
        {
            auto v = dq.front();
            dq.pop_front(); // pick a node
            for (auto u : al[v]) // traverse all neighbours
            {
                if (!visited[u]) // if not visited
                {
                    visited[u] = true; // visit and push into queue.
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

    unsigned nv;
    unsigned ne;
    AL al;
    vector<bool> visited;
    vector<int> pre;
    vector<int> post;
    vector<int> topo_sort;
    vector<int> parent;
    int num_components;
    bool directed = false;
};

int main()
{
    fstream fs("./tinyG2.txt", ios_base::in);
    int nv;
    fs >> nv;
    int ne;
    fs >> ne;
    Graph G(nv);
    int s, t;
    // Graph G(nv, {});
    for (int i = 0; i < ne; ++i)
    {
        fs >> s >> t;
        G.insert_edge(s, t);
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
    return 0;
}