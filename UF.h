#include <bits/stdc++.h>
using namespace std;

class UF
{
private:
    int n_v;
    vector<int> parents;
    vector<int> tree_size;

public:
    UF(int n)
    {
        n_v = n;
        for (int i = 0; i < n; ++i)
        {
            parents.push_back(i);
        }
        tree_size = vector<int>(n, 1);
    }
    UF() = default;
    ~UF() = default;
    UF(const UF &c) = default;
    UF &operator=(const UF &in) = default;

    bool same_component(int x, int y) const;
    int findp(int x) const;
    void unions(int x, int y);
};