#include <bits/stdc++.h>
using namespace std;

const int R = 26;

/* char Ops:

Ops, 
prefix match
regex match(wildcard)
longest prefix
*/

struct node
{
    bool end = false;
    node* child[R];
};

class Trie
{
    private:
    node * root;

    public:
    Trie()
    {
        root = new node();
    }
    ~Trie() = default;

    void put(const string& s)
    {
        root = put(root, s, 0);
    }

    node * put(node * root, const string& s, int len)
    {
        if (!root) root = new node();
        if(s.length() == len) { root->end = true; return root;}
        int idx = s[len] - 'a';
        root->child[idx] = put(root->child[idx], s, len + 1 );
        return root;
    }

    bool get(const string& s)
    {
        auto node = get(root, s, 0);
        return (node);
    }

    node * get(node * root, const string& s, int len)
    {
        if(!root) return nullptr;
        if(s.length() == len && root->end) return root;
        int idx = s[len] - 'a';
        return get(root->child[idx], s, len + 1);
    }

    vector<string> keys()
    {
        vector<string> ks;
        string prefix;
        collect(root, prefix, ks);
        return ks;

    }

    void collect(node * root, string prefix, vector<string>& keys)
    {
        if(!root) return;
        if(root->end) keys.push_back(prefix);
        for(int i = 0; i < R; ++i)
        {
            char c = 'a' + i;
            collect(root->child[i], string(prefix + c), keys);
        }
    }

};

int main()
{
    Trie T;
    T.put("she");
    T.put("shell");
    T.put("share");
    T.put("shore");
    T.put("sell");
    T.put("nirmal");
    cout << boolalpha << endl;
    cout << T.get("sell") << endl;
    cout << T.get("sells") << endl;
    cout << T.get("nirmal") << endl;
   auto keys = T.keys();
    cout << "Keys" << endl;
    for(auto& k : keys)
        cout << k << " ";
    cout << endl;
}
