#ifndef __MY_UNIQUE_HPP
#define __MY_UNIQUE_HPP

#include <memory>


template <typename T>
class uniqueptr
{
    public:
    uniqueptr():ptr(nullptr){}
    uniqueptr(T * inp) : ptr(inp){}
    ~uniqueptr() { delete ptr;}

    uniqueptr(uniqueptr&& rhs);
    uniqueptr& operator=(uniqueptr&& rhs);
    // public & deleted
    uniqueptr(const uniqueptr& rhs) = delete;
    uniqueptr& operator=(const uniqueptr& rhs) = delete;

    T& operator*()
    {
        return *ptr;
    }

    const T& operator*() const
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    const T* operator->() const
    {
        return ptr;
    }

    operator bool() 
    {
        return ptr;
    }

    T* release()
    {
        auto tmp = exchange(ptr, nullptr);
        return tmp;
        /*auto tmp = ptr;
        ptr = nullptr;
        return tmp;*/
    }

    void reset(T * iptr)
    {
        /*auto tmp = iptr;
        delete ptr;
        ptr = tmp;*/

        swap(iptr, ptr);
        delete iptr;
    }

    T* get()
    {
        return ptr;
    }

    template <typename U>
    friend void swap(uniqueptr<U>& lhs, uniqueptr<U>& rhs);
private:
    T * ptr;
};

template<typename T>
void swap(uniqueptr<T>& lhs, uniqueptr<T>& rhs)
{
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
}

template <typename T, typename ... Args>
uniqueptr<T> makeuniq(Args&&... args)
{
    using namespace std;
    return uniqueptr<T>(new T(forward<Args>(args)...));
}

#include "unique.cpp"
#endif