#ifndef _MSTACK_CPP
#define _MSTACK_CPP

#include <iostream>
template< typename T>
mstack<T>::mstack(int i_size)
    :_size(i_size),
    _top(0),
    _data(std::make_unique<T[]>(i_size))
{
    std::cout << "CTOR" << std::endl;
}

template< typename T>
mstack<T>::mstack(const mstack<T>& rhs)
    :_size(rhs._size),
    _top(rhs._top),
    _data(std::make_unique<T[]>(rhs._size))
{
    //std::copy(rhs._data, rhs._data + rhs._size; _data);
    for(int i = 0; i < _size; ++i)
    {
        _data[i] = rhs._data[i];
    }
    std::cout << "CP CTOR" << std::endl;

}

template< typename T>
mstack<T>::mstack(mstack<T>&& rhs)
    :_size(rhs._size),
    _top(rhs._top),
    _data(rhs._data.release())
{
    rhs._size = 0;
    rhs._top = 0;

    std::cout << "MV CTOR" << std::endl;

}

template< typename T>
void mstack<T>::swap(mstack<T>& rhs)
{
    using std::swap;
    swap(_size, rhs._size);
    swap(_top, rhs._top);
    std::swap(_data, rhs._data);
    std::cout << "SWAP" << std::endl;

}

template<typename T>
mstack<T>& mstack<T>::operator=(const mstack<T>& rhs)
{
    mstack<T>(rhs).swap(*this);
    std::cout << "CP =" << std::endl;

    return *this;
    
}

template< typename T>
mstack<T>& mstack<T>::operator=(mstack<T>&& rhs)
{
    _size = rhs._size;
    _top = rhs._top;
    _data.reset(rhs._data.release());
    rhs._data = nullptr;
    rhs._size = rhs._top = 0;
    std::cout << "MV =" << std::endl;

    return *this;
}

#endif 