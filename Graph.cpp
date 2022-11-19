#include "Graph.h"
#include <queue>

using namespace std;

void Graph::print_graph() const
{
    for(auto const& pair : edges)
    {
        cout << pair.first << ": ";
        for(auto const& e : pair.second)
        {
            cout << "->" << e->val;
        }
        cout << endl;
    }
}

void Graph::process_vertex_early(int v)
{
    cout << "early" << v << endl;
}

void Graph::process_vertex_late( int v)
{
    sorted.push(v);

}

void Graph::process_edge(int u, int v)
{
    if(colors[u] == colors[v])
    {
        cout << "not_bipartate" << endl;
        bi_part = false;
    }

    colors[v] = rev(colors[u]);

}


void Graph::process_edge_tp(int u, int v)
{
    edge_class eclass = edge_classification(u, v);
    if(eclass == BACK)
    {
        cout << "back_edge found, not a DAG" << endl;
    }    

    return;
}

void Graph::init_search()
{
    transform(edges.begin(), edges.end(), inserter(state, state.end()), [](const auto& s){ return pair<const int, v_state>(s.first, UNDISCOVERED); });
    transform(edges.begin(), edges.end(), inserter(parents, parents.end()), [](const auto& p){ return pair<const int, int>(p.first, -1); });
    for(const auto& e : edges)
    {
        colors[e.first] = UNCOLORED;
        entry_t[e.first] = -1;
        exit_t[e.first] = -1;
    }

}

void Graph::connected_components()
{
    int c = 0;
    for(auto const &v : state)
    {
        if(state[v.first] == UNDISCOVERED)
        {
            c++;
            cout << "connected component :" << c << endl;
            bfs(v.first);
        }
    }
}

bool Graph::two_color()
{
    bi_part = true;
    for(auto s : state)
    {
        if( state[s.first] == UNDISCOVERED )
        {
            colors[s.first] = WHITE;
            bfs(s.first);
        }
    }
    return bi_part;
}


void Graph::find_path(int start, int end)
{
    if(parents.empty())
    {
        cout << "not traversed" << endl;
        return;
    }
    if(start == end || end == -1)
        cout << start;
    else
    {
        find_path(start, parents[end]);
        cout << "->" << end ;
    }

}

void Graph::bfs(int start) 
{
    //unordered_map<int, v_state> state;
    //unordered_map<int, int> parent;
    queue<int> q;
    // intitialize for traversal.
    // for(auto v : degree)
    // {
    //     state[v.first] = UNDISCOVERED;
    //     parents[v.first] = -1;
    // }
    q.push(start);
    state[start] = DISCOVERED;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        state[v] = PROCESSED;
        process_vertex_early(v);
        for(auto const & en : edges[v])
        {
            int u = en->val;
            if((state[u] != PROCESSED) || directed)
            {
                process_edge(v, u);
            }
            if(state[u] == UNDISCOVERED)
            {
                q.push(u);
                state[u] = DISCOVERED;
                parents[u] = v;
            }
        }
        //process_vertex_late(v);
    }

    
}

edge_class Graph::edge_classification(int x, int y)
{
    if(parents[y] = x)
        return TREE;

    if(state[y] == DISCOVERED )
        return BACK;

    if(state[y] == PROCESSED && entry_t[y] > entry_t[x])
        return FORWARD;
    
    if(state[y] == PROCESSED && entry_t[y] < entry_t[x] )
        return CROSS;

    cout << "self loop" << endl;
    return INVALID;
}

void Graph::dfs(int start)
{
    state[start] = DISCOVERED;
    time++;
    entry_t[start] = time;
    process_vertex_early(start);
    for(auto const& en : edges[start])
    {
        int v = en->val;
        if(state[v] == UNDISCOVERED)
        {

            parents[v] = start;
            process_edge_tp(start, v);
            dfs(v);
        }
        else if((state[v] != PROCESSED && parents[start] != v) || directed)
        {
            process_edge_tp(start, v);
        }
    }   
    process_vertex_late(start);
    time++;
    exit_t[start] = time;
    state[start] = PROCESSED;

}

void Graph::TopoSort()
{
    init_search();
 //   stack<int> sorted;
    for(const auto& s : state)
    {
        if(state[s.first] == UNDISCOVERED)
        {
            dfs(s.first);
        }
    }

    cout << "topological sort" << endl;
    while(!sorted.empty())
    {
        cout << sorted.top() << endl;
        sorted.pop();
    }
    return;
}

unique_ptr<Graph> Graph::transpose()
{
    init_search();
    unique_ptr<Graph> tg = make_unique<Graph>(num_vertices, directed);

    for(const auto & en : edges)
    {
        int v = en.first;
        for(const auto& nb : en.second)
        {
            int u = nb->val;
            tg->insert_edge(u, v);
        }
    }
    return move(tg);
}

int Graph::primQ(int start)
{

    cout << "Prim's Priority" << endl;
    struct ED
    {
        int x, y;
        int w;

        ED(int ix, int iy, int iw):x(ix), y(iy), w(iw)
        {

        }
    };
    
    static int MAXINT = 999999999;
    int weight = 0;
    int dist = 0;
    vector<int> distance(num_vertices, MAXINT);
    int n_e = num_vertices - 1;
    int ae = 0;
    auto compr = [](const ED& p1, const ED& p2){
        return p1.w > p2.w;
    };
    priority_queue<ED, vector<ED>, decltype(compr) > pq(compr);

    // add all the edges of start to the PQ.
    int v = start;
    state[v] = DISCOVERED;
    for(const auto & en : edges[v])
    {
        pq.push(ED(v, en->val, en->weight));
    }


    while( !pq.empty() && ae != n_e)
    {
        // fetch the minimum weight edge, and if destination vertex is not discovered, add the edge
        // add all edges of destination vertex to the queue, add weight to final.
        auto u = pq.top();
        pq.pop();
        int n = u.y;
        if(state[n] ==  DISCOVERED)
            continue;
        state[n] = DISCOVERED;
        cout << " added edge" << u.x << "->" << u.y << "of weight" << u.w << endl;
        weight = weight + u.w;
        ae++;
        for(const auto & en : edges[n])
        {
            pq.push(ED(n, en->val, en->weight));
        }
    }

    return weight;
}


int Graph::prim(int start)
{
    static int MAXINT = 999999999;
    int weight = 0;
    int dist = 0;
    vector<int> distance(num_vertices, MAXINT);
    int v = start;
    //start with any vertex, here given as input start.

    while(state[v] != DISCOVERED)
    {
        // mark discovered
        state[v] = DISCOVERED;
        if(v != start)
        {
            cout << "added Edge" << parents[v] << "->" << v << "with wight" << dist << endl;
            weight = weight +  dist;
        }

        // for all edges of v, update the distance of reachable vertexes if it is undiscovered.
        for(const auto & en : edges[v])
        {
            int u = en->val;
            if( (distance[u] > en->weight) && (state[u] != DISCOVERED ))
            {
                distance[u] = en->weight;
                parents[u] = v;
            }
        }

        // find the edge with the minimum weight, and set destination vertex as v, so start of loop will 
        // add edge to the tree, and we will continue above steps till MST created.
        dist = MAXINT;
        for(const auto u : state)
        {
            int n = u.first;
            if(state[n] != DISCOVERED && (dist > distance[n]) )
            {   
                dist = distance[n];
                v = n;
            }
        }

    }

    return weight;
}

int Graph::Dijkstra(int start)
{
    static int MAXINT = 999999999;
    int weight = 0;
    int dist = 0;
    vector<int> distance(num_vertices, MAXINT);
    int v = start;
    distance[v] = 0;
    //start with any vertex, here given as input start.

    while(state[v] != DISCOVERED)
    {
        // mark discovered
        state[v] = DISCOVERED;
        if(v != start)
        {
            cout << "added Edge" << parents[v] << "->" << v << "with distance " << dist << endl;
            weight = weight +  dist;
        }

        // for all edges of v, update the distance of reachable vertexes from start.
        for(const auto & en : edges[v])
        {
            int u = en->val;
            if( (distance[u] > (distance[v] + en->weight)))
            {
                distance[u] = distance[v] + en->weight;
                parents[u] = v;
            }
        }

        // find the undiscovered vertex with minimmum distance from start, and start the process again 
        // with all the edges outgoing from it.
        dist = MAXINT;
        for(const auto u : state)
        {
            int n = u.first;
            if(state[n] != DISCOVERED && (dist > distance[n]) )
            {   
                dist = distance[n];
                v = n;
            }
        }

    }

    return weight;
}
