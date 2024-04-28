#include <bits/stdc++.h>
using namespace std;

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{

    using point = array<int, 2>;
    deque<point> DQ;
    int out = 0;
    DQ.push_back({startRow, startColumn});
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    while (!DQ.empty())
    {
        if (--maxMove < 0)
            return out;
        cout << maxMove << " " << out << " " << DQ.size() << endl;
        deque<point> LQ(move(DQ));
        for (auto p : LQ)
        {
            for (auto d : dirs)
            {
                point p1 = {p[0] + d[0], p[1] + d[1]};
                
                if (p1[0] < 0 || p1[1] < 0 || p1[0] >= m || p1[1] >= n)
                {
                    out++;
                }
                else
                    DQ.push_back(p1);
            }
        }
        cout << maxMove << " " << out << " " << DQ.size() << endl;
    }
    return out;
}

int add(int x, int y)
{
    return x + y;
}

int mul(int x, int y)
{
    return x * y;
}

int main()
{
    auto af = add;
    cout << af(1,2) << endl;
    af = mul;
    cout << af(1,2) << endl;
    auto paths = findPaths(7,6,12,0,2);
    return 0;
}