#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Vec
{
    Vec():_data(nullptr), size(0), capacity(0)
    {
    }

    Vec(int size)
    {
        _data = unique_ptr<T[]>(new T[size]);
        size = size;
        capacity = capacity;
    }

    Vec(int size, T val)
    {
        _data = unique_ptr<T[]>(new T[size]);
        size = size;
        capacity = capacity;
        fill(begin(_data.get()), end(_data.get()), val);
    }

    Vec(const Vec& rhs)
    {
        _data = unique_ptr<T[]>(new T[rhs.size]);
        size = rhs.size;
        capacity = rhs.capacity;
        copy(begin(rhs._data.get()), end(rhs._data.get()), _data.begin());
    }

    Vec& operator=(const Vec& rhs)
    {
        auto tmp = rhs;
        swap(*this, rhs);
        return *this;
    }

    Vec(Vec && rhs)
    {
    }

    Vec& operator =(vec && rhs)
    {
    }

    void push_back(T val)
    {
        if(isFull)
        {
            capacity = 2 * size;
            auto tmp_data = unique_ptr<T>(new T[capacity]);
            copy(begin(_data.get()), end(_data.get()), begin(tmp_data.get()));
            _data.reset(tmp_data);
        }
        (*_data)[size++] = val;
    }

    bool isFull()
    {
        return (size == capacity);
    }

    friend void swap(vec& lhs, vec& rhs)
    
    private:
    unique_ptr<T[]> _data;
    int size;
    int capacity;

}