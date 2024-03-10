#include <bits/stdc++.h>
using namespace std;

// Graph BFS
using point = pair<int, int>;

bool isvalid(point p, int r, int c, map<point, int>& visited)
{
    return (p.first >= 1 && p.first <= r && p.second >= 1 && p.second <= c && !visited.count(p));
}

vector<point> neightbours(point p, int r, int c, map<point, int>& visited, int level)
{
    vector<point> ns;
    vector<point> moves = {{2,1}, {2,-1}, {-2,1}, {-2, -1},
                            {1,2}, {1,-2}, {-1,2}, {-1, -2} };
    for(const auto& m : moves)
    {
        point mp = make_pair(p.first + m.first, p.second + m.second);
        if(isvalid(mp,r,c, visited))
        {
            ns.push_back(mp);
            visited[mp] = level + 1;
        }
    }
    return ns;
}

int bfs(point kn, point pn, int r, int c)
{
    deque<point> Q;
    Q.push_back(kn);
    map<point, int> visited;
    visited[kn] = 1;
    int level = 0;
    while(!Q.empty() && pn.first < r)
    {
        deque<point> lq(move(Q));
        while(!lq.empty())
        {
            point k = lq.front();
            lq.pop_front();
            if(k == pn || visited.count(pn) > 0)
                return visited[pn];
            vector<point> ns = neightbours(k, r, c, visited, level);
            copy(ns.begin(), ns.end(), back_inserter(Q));
        }
        level++;
        pn.first++;
    }
    if(pn.first == r)
    {
        cout << " pawn is queen" << endl;
        return -1;
    }
    return -1;
}

int main()
{
    int row, column, pr, pc, kr, kc;
    cout << " board :";
    cin >> row >> column;
    cout << endl << " pawn :";
    cin >> pr >> pc;
    cout << endl << " knight :";
    cin >> kr >> kc;
    point knight = make_pair(kr, kc);
    point pawn = make_pair(pr, pc);
    auto moves = bfs(knight, pawn, row, column);
    cout << moves << endl;
    return 0;
}

