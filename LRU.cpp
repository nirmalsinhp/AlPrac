#include <bits/stdc++.h>
using namespace std;

// check LRU implementation.

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        
        auto it = _hash.find(key);
        if(it != _hash.end())
        {
            int val = _data[it->second].second;
            updateLR(it->second);
        }
    }
    
    void put(int key, int value) {
        if(_data.size() == cap)
        {
            deleteLR();
        }
        _data.push_back({key,value});
        _hash[key] = _data.size() - 1;
    }

    void updateLR(int index)
    {
        auto pair = *(_data.begin()+ index);
        _data.erase(_data.begin() + index);
        _data.emplace_back(pair);
        _hash[pair.first] = _data.size() - 1;
    }

    void deleteLR()
    {
        int key = _data.front().first;
        _hash.erase(key);
        _data.erase(_data.begin());
    }

    private:
    size_t cap;
    deque<pair<int, int>> _data;
    unordered_map<int, int> _hash;
};