#ifndef _MSTACK_HPP
#define _MSTACK_HPP


#include <memory>
#include <vector>
#include <type_traits>
#include <iostream>


template<typename T>
class mstack
{

public:

static const int DEFAULT_SIZE = 20;
explicit mstack(int size = DEFAULT_SIZE);
~mstack() = default;
mstack(const mstack& rhs);
mstack(mstack&& rhs);
mstack& operator=(const mstack& rhs);
mstack& operator=(mstack && rhs);

 const T& top() const;
T top();

void pop();

void push(const T& val);

bool empty() const;

bool full() const;

int size() const;
void swap(mstack & rhs);

private:

size_t _size;
size_t _top;
std::unique_ptr<T[]> _data;

};

#include "mstack.inl"
#include "mstack.cpp"

#endif 