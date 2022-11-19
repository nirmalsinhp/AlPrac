#include <bits/stdc++.h>
using namespace std;

enum v_state
{
    UNDISCOVERED = 0,
    DISCOVERED,
    PROCESSED
}; 

enum color
{
    UNCOLORED = 0,
    WHITE,
    BLACK
}; 

enum edge_class
{
    TREE = 0,
    FORWARD,
    BACK,
    CROSS,
    INVALID
}; 

class Graph
{

    class EdgeNode
    {
        public:
        int val;
        int weight;
        EdgeNode *next;

        EdgeNode(int v, int w = 0, EdgeNode *n = nullptr)
        {
            val = v;
            weight = w;
            next = n;
        }
    };

public:
    Graph(int num, bool di = false) : num_vertices(num)
    {
        directed = di;
        num_edges = 0;
        time = 0;
    };

    Graph() = default;
    Graph(const Graph &) = delete;
    Graph &operator=(const Graph &) = delete;
    ~Graph() = default;

    void print_graph() const;
    void init_search();
    void process_vertex_early(int);
    void process_vertex_late(int);
    void process_edge(int, int);
    void process_edge_tp(int, int);
    void find_path(int x, int u);
    void connected_components();
    bool two_color();
    unique_ptr<Graph> transpose();
    edge_class edge_classification(int x, int y);
    color rev(color c)
    {
        if(c = WHITE)
            return BLACK;
        else if(c = BLACK)
            return WHITE;
        
        return UNCOLORED;
    }

    inline int get_ver_num() { return num_vertices;}
    inline int get_edges_num() { return num_edges;}
    int get_degree(int n)
    {
        return degree[n];
    }
    int Dijkstra(int start);
    int prim(int start);
    int primQ(int start);
    void bfs(int start ) ;
    void dfs(int start);
    void TopoSort();
    void insert_edge(int x, int y, int w = 0)
    {
        edges[x].push_back(move(make_unique<EdgeNode>(y, w)));
        num_edges++;
        (degree[x])++;
        if (!directed)
        {
            edges[y].push_back(move(make_unique<EdgeNode>(x, w)));
            (degree[y])++;
        }
    }

private:
    unordered_map<int, vector<unique_ptr<EdgeNode>>> edges;
    unordered_map<int, int> degree;
    unordered_map<int, int> parents;
    unordered_map<int, int> state;
    unordered_map<int, color> colors;
    unordered_map<int, int> entry_t;
    unordered_map<int, int> exit_t;
    stack<int> sorted;
    int num_vertices;
    bool directed;
    int num_edges;
    bool bi_part;
    int time; // dfs
};