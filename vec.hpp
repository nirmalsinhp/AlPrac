#include <bits/stdc++.h>

template <class T>
class vec
{
public:

    using iterator = T*;
    using const_iterator = const T*;
    using value_type = T;
    using size_type = size_t;

    vec() {};
    vec(const vec & other){}
    vec& operator=(const vec& other) {}
    ~vec() {}
    explicit vec(size_t n, const T& init = T())
    {

    }

    size_t size() const { return limit - data;}
    T& operator[] (size_type i) { return data[i];}
    const T& operator[] (size_type i) const { return data[i];}

    iterator begin() {return data;}
    const_iterator begin() const {return data;}

    iterator end() { return limit;}
    const_iterator end() { return limit;}

private:
    // T* data;
    // T* limit;
    iterator data;
    iterator limit;

};