#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string name;
    bool is_file = false;
    unordered_map<string, Node *> childs;
    int files_count = 1;

    Node(string iname):
        name(iname)
    {}
};

class Trie
{
private:
    Node *root;

public:

    Trie()
    {
        root = new Node("/");
    }
    void insert(string file)
    {
        string ofile = file;
        if(file.front() != '/')
        {
            cout << "wrongg " << endl;
            return;
        }
        // TODO : need to make it recusrsive. to handle count.
        file.erase(0,1);
        auto node = root;
        string dir;
        stringstream ffs(file);
        while (getline(ffs, dir, '/'))
        {
            if(node->childs.find(dir) == node->childs.end())
            {
                node->childs[dir] = new Node(dir);
            }
            node = node->childs[dir];
            node->files_count = accumulate(node->childs.begin(), node->childs.end(), 0, [](const auto sum, const auto & c)
                        {
                            return sum + c.second->files_count;
                        });
        }
        node->is_file = true;
        node->name = ofile;
    }

    bool search(string file, bool decr = false)
    {
        auto node = root;
        int pos;
        string dir;
        while ((pos = file.find("/")) != std::string::npos)
        {
            dir = file.substr(0, pos);
            if(node->childs.find(dir) == node->childs.end())
                return false;
            node->files_count--;
            node = node->childs[dir];
            file.erase(0, pos + 1);
        }

        return node->is_file;
    }

    vector<string> collect()
    {
        vector<string> out;
        collect(root, out);
        return out;
    }

    void collect(Node * root, vector<string>& out)
    {
        if(!root)
            return;
        for(auto nd : root->childs)
        {
            if(nd.second->files_count == 0 || nd.second->is_file)
            {
                out.push_back(nd.first);
                return;
            }
            collect(nd.second, out);
        }
    }

};

vector<string> filePathCompress(vector<string> &all_files, vector<string> &selected)
{
    vector<string> out;
    unordered_map<string, set<string>> fmap;
    set<string> sset(selected.begin(), selected.end());
    for (const string &file : all_files)
    {
        string dir = file.substr(0, file.find_last_of("/"));
        fmap[dir].insert(file);
    }
    for (const auto &[dir, files] : fmap)
    {
        set<string> file_inter;
        set_intersection(files.begin(), files.end(), sset.begin(), sset.end(), inserter(file_inter, file_inter.begin()));
        if (file_inter.size() == files.size())
        {
            cout << " adding dir" << dir << endl;
            out.push_back(dir);
        }
        else
        {
            copy(files.begin(), files.end(), back_inserter(out));
        }
    }
    return out;
}

int main()
{
    vector<string> allf = {"/d/e/aa.txt",
                           "/d/e/ab.txt", "/d/f/ab.txt", "/h/e/ab.txt", "/h/g/ab.txt", "/i/c/ab.txt", "/k/w/ab.txt",
                           "/d/e/ac.txt", "/d/f/ac.txt", "/h/e/ac.txt", "/h/g/ac.txt", "/i/c/ac.txt", "/k/w/ac.txt",
/*                           "/d/e/ad.txt", "/d/f/ac.txt", "/h/e/ac.txt", "/h/g/ac.txt", "/i/c/ac.txt", "/k/w/ac.txt",
                           "/d/e/ae.txt", "/d/f/ac.txt", "/h/e/ad.txt", "/h/g/ad.txt", "/i/c/ad.txt", "/k/w/ad.txt",
                           "/d/e/af.txt", "/d/f/ad.txt", "/h/e/ae.txt", "/h/g/ae.txt", "/i/c/ae.txt", "/k/w/ae.txt",
                           "/d/e/ag.txt", "/d/f/af.txt", "/h/e/af.txt", "/h/g/af.txt", "/i/c/af.txt", "/k/w/af.txt",
                           "/d/e/ah.txt", "/d/f/ah.txt", "/h/e/ah.txt", "/h/g/ah.txt", "/i/c/ah.txt", "/k/w/ah.txt",
                           "/d/e/ai.txt", "/d/f/ah.txt", "/h/e/ag.txt", "/h/g/ag.txt", "/i/c/ag.txt", "/k/w/ag.txt",
                           "/d/e/aj.txt", "/d/f/ai.txt", "/h/e/ai.txt", "/h/g/ai.txt", "/i/c/ai.txt", "/k/w/ai.txt",
                           "/d/e/ak.txt", "/d/f/aj.txt", "/h/e/aj.txt", "/h/g/aj.txt", "/i/c/aj.txt", "/k/w/aj.txt",
                           "/d/e/al.txt", "/d/f/ao.txt", "/h/e/ao.txt", "/h/g/ao.txt", "/i/c/ao.txt", "/k/w/ao.txt",
                           "/d/e/am.txt", "/d/f/ao.txt", "/h/e/am.txt", "/h/g/am.txt", "/i/c/am.txt", "/k/w/am.txt",
                           "/d/e/an.txt", "/d/f/am.txt", "/h/e/an.txt", "/h/g/an.txt", "/i/c/an.txt", "/k/w/an.txt",
                           "/d/e/ao.txt", "/d/f/ak.txt", "/h/e/ak.txt", "/h/g/ak.txt", "/i/c/ak.txt", "/k/w/ak.txt",
                           "/d/e/ap.txt", "/d/f/al.txt", "/h/e/al.txt", "/h/g/al.txt", "/i/c/al.txt", "/k/w/al.txt",
                           "/d/e/aq.txt", "/d/f/av.txt", "/h/e/av.txt", "/h/g/av.txt", "/i/c/av.txt", "/k/w/av.txt",
                           "/d/e/ar.txt", "/d/f/aq.txt", "/h/e/aq.txt", "/h/g/aq.txt", "/i/c/aq.txt", "/k/w/aq.txt",
                           "/d/e/as.txt", "/d/f/ap.txt", "/h/e/ap.txt", "/h/g/ap.txt", "/i/c/ap.txt", "/k/w/ap.txt",
                           "/d/e/ay.txt", "/d/f/au.txt", "/h/e/au.txt", "/h/g/au.txt", "/i/c/au.txt", "/k/w/au.txt",
                           "/d/e/at.txt", "/d/f/av.txt", "/h/e/av.txt", "/h/g/av.txt", "/i/c/av.txt", "/k/w/av.txt",
                           "/d/e/au.txt", "/d/f/aw.txt", "/h/e/aw.txt", "/h/g/aw.txt", "/i/c/aw.txt", "/k/w/aw.txt",
                           "/d/e/av.txt", "/d/f/ax.txt", "/h/e/ax.txt", "/h/g/ax.txt", "/i/c/ax.txt", "/k/w/ax.txt",
                           "/d/e/aw.txt", "/d/f/ay.txt", "/h/e/ay.txt", "/h/g/ay.txt", "/i/c/ay.txt", "/k/w/ay.txt",*/
                           "/d/e/ax.txt", "/d/f/ay.txt", "/h/e/az.txt", "/h/g/az.txt", "/i/c/az.txt", "/k/w/az.txt"};

    vector<string> selected = {"/d/e/ab.txt", "/d/f/ab.txt", "/h/e/ab.txt",
                               "/d/e/ac.txt", "/d/f/ac.txt", "/h/e/ac.txt",
                               "/d/e/ad.txt", "/d/f/ac.txt", "/h/e/ac.txt",
                               "/d/e/ae.txt", "/d/f/ac.txt", "/h/e/ad.txt",
                               "/d/e/af.txt", "/d/f/ad.txt", "/h/e/ae.txt",
                               "/d/e/ag.txt", "/d/f/af.txt", "/h/e/af.txt",
                               "/d/e/ah.txt", "/d/f/ah.txt", "/h/e/ah.txt",
                               "/d/e/ai.txt", "/d/f/ah.txt", "/h/e/ag.txt",
                               "/d/e/aj.txt", "/d/f/ai.txt", "/h/e/ai.txt",
                               "/d/e/ak.txt", "/d/f/aj.txt", "/h/e/aj.txt",
                               "/d/e/al.txt", "/d/f/ao.txt", "/h/e/ao.txt",
                               "/d/e/am.txt", "/d/f/ao.txt", "/h/e/am.txt",
                               "/d/e/an.txt", "/d/f/am.txt", "/h/e/an.txt",
                               "/d/e/ao.txt", "/d/f/ak.txt", "/h/e/ak.txt",
                               "/d/e/ap.txt", "/d/f/al.txt", "/h/e/al.txt",
                               "/d/e/aq.txt", "/d/f/av.txt", "/h/e/av.txt",
                               "/d/e/ar.txt", "/d/f/aq.txt", "/h/e/aq.txt",
                               "/d/e/as.txt", "/d/f/ap.txt", "/h/e/ap.txt",
                               "/d/e/ay.txt", "/d/f/au.txt", "/h/e/au.txt",
                               "/d/e/at.txt", "/d/f/av.txt", "/h/e/av.txt",
                               "/d/e/au.txt", "/d/f/aw.txt", "/h/e/aw.txt",
                               "/d/e/av.txt", "/d/f/ax.txt", "/h/e/ax.txt",
                               "/d/e/aw.txt", "/d/f/ay.txt", "/h/e/ay.txt",
                               "/d/e/ax.txt", "/d/f/ay.txt", "/h/e/az.txt"};
    // vector<string> dirs = filePathCompress(allf, selected);
    // copy(dirs.begin(), dirs.end(), ostream_iterator<string>(cout, ", "));
    Trie T;
    for(auto f : allf)
        T.insert(f);
    for(auto s : selected)
        T.search(s);
    vector<string> comp = T.collect();
    copy(comp.begin(), comp.end(), ostream_iterator<string>(cout, ", "));


    return 0;
}