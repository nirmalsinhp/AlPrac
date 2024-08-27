#include <bits/stdc++.h>
using namespace std;
    class UF
    {
        public:
        UF(int n)
            :par(n), sz(n, 1)
        {
            iota(par.begin(), par.end(), 0);
        }

        int find(int x)
        {
            if(x != par[x])
                return find(par[x]);
            return x;
        }

        void un(int x, int y)
        {
            //cout << " UN " << x << " " << y << endl;
            int fx = find(x);
            int fy = find(y);
            if(fx == fy)
                return;
            par[fy] = fx;
          //  cout << "US " << fx  << " "<< fy << " - "<<  sz[fx] << " " << sz[fy] << endl;
            sz[fx] += sz[fy];
//            sz[y] = 0;
        }
        vector<int> par;
        vector<int> sz;
    };


vector<int> getPrimes(int n)
{
    //     cout << "in " << n << endl;
    vector<int> out;
    int z = 2;
    while (z * z <= n)
    {
        if (n % z == 0)
        {
            out.push_back(z);
            n = n / z;
        }
        else
            z++;
    }
    if (n > 1)
        out.push_back(n);
    return out;
}

int largestComponentSize(vector<int> &nums)
{
    map<int, set<int>> umap;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto vi = getPrimes(nums[i]);
        for (auto p : vi)
        {
            umap[p].insert(i);
        }
    }
    cout << "distinct primes " << umap.size() << endl;
    for (auto [k, v] : umap)
    {
        cout << "P " << k << " : ";
        for (auto n : v)
            cout << n << " ";
        cout << endl;
    }
    // int ms = 0;
    // for (auto iitr = umap.begin(); iitr != umap.end(); iitr++) {
    //  //   cout << iitr->first << " " << endl;
    //     for (auto jitr = umap.begin() ; jitr != umap.end(); jitr++) {
    //         if(jitr == iitr)
    //             continue;
    //    //     cout << jitr->first << " ";
    //         set<int> si;
    //         set_intersection(iitr->second.begin(), iitr->second.end(),
    //                          jitr->second.begin(), jitr->second.end(),
    //                          insert_iterator(si, si.begin()));
    //         cout << si.size() << " ";
    //         if (!si.empty()) {

    //             set<int> su;
    //             set_union(iitr->second.begin(), iitr->second.end(),
    //                       jitr->second.begin(), jitr->second.end(),
    //                       insert_iterator(su, su.begin()));
    //      //       cout << su.size() << " ";

    //             iitr->second = su;
    //             ms = max(ms, int(su.size()));
    //         }
    //         cout << endl;
    //     }
    // }

    UF uf(nums.size());
    for (const auto &[k, c] : umap)
    {
        vector<int> v(c.begin(), c.end());
        for (int i = 1; i < v.size(); i++)
            uf.un(v[i - 1], v[i]);
    }

    int ms = *max_element(uf.sz.begin(), uf.sz.end());
    return ms;
}


int main()
{
    vector<int> vec {4,6,15,35};
    auto ss = largestComponentSize(vec);
    cout << ss << endl;
}
