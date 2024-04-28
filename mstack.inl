#ifndef _MSTACK_INL
#define _MSTACK_INL
template< typename T>
inline
T mstack<T>::top()
{
    return _data[_top - 1];
}

template< typename T>
inline
const T& mstack<T>::top() const
{
    return _data[_top - 1];
}

template< typename T>
inline
void mstack<T>::pop()
{
    _top--;
}

template< typename T>
inline
void mstack<T>::push(const T& val)
{
    _data[_top++] = val;
}

template< typename T>
inline
bool mstack<T>::empty() const
{
    return _top == 0;
}

template< typename T>
inline
bool mstack<T>::full() const
{
    return _top == _size;
}

template< typename T>
inline
int mstack<T>::size() const
{
    return _size;
}


#endif