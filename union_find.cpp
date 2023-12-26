#include <bits/stdc++.h>

using namespace std;

class UF
{

    public:

    bool isconnected(int i, int j)
    {
        return root(i) == root(j);
    }

    void unionset(int i, int j)
    {
        _data[i] = _data[j];
    }
 
    int root(int i)
    {
        while(i != _data[i])
            i = _data[i];
        
        return _data[i];
    }

private:
    vector<int> _data;

};

int main()
{

    unique()
    return 0;
}
