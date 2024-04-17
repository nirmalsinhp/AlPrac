#ifndef __MY_SHARED_HPP
#define __MY_SHARED_HPP

#include <memory>

template <typename T>
class sharedptr
{
public:
    sharedptr() : ptr(nullptr), rc(new size_t(0)) {}
    sharedptr(T *inp) : ptr(inp), rc(new size_t(1)) {}
    ~sharedptr();

    sharedptr(const sharedptr &rhs);
    sharedptr &operator=(const sharedptr &rhs);

    sharedptr(sharedptr &&rhs);
    sharedptr &operator=(sharedptr &&rhs);

    T &operator*()
    {
        return *ptr;
    }

    const T &operator*() const
    {
        return *ptr;
    }

    T *operator->()
    {
        return ptr;
    }

    const T *operator->() const
    {
        return ptr;
    }

    operator bool()
    {
        return ptr;
    }

    void reset()
    {
        //        decr_count();
        auto tmp = sharedptr<T>();
        swap(tmp, *this);
    }

    void reset(T *iptr)
    {
        /*auto tmp = iptr;
        delete ptr;
        ptr = tmp;*/

        //      decr_count();
        auto tmp = sharedptr<T>(iptr);
        swap(tmp, *this);
    }

    T *get()
    {
        return ptr;
    }

    size_t count()
    {
        return *rc;
    }

    void decr_count()
    {
        if (--*rc == 0)
        {
            delete rc;
            delete ptr;
            // ptr = nullptr;
        }
    }

    template <typename U>
    friend void swap(sharedptr<U> &lhs, sharedptr<U> &rhs);

private:
    T *ptr;
    size_t *rc;
};

template <typename T>
void swap(sharedptr<T> &lhs, sharedptr<T> &rhs)
{
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.rc, rhs.rc);
}

template <typename T, typename... Args>
sharedptr<T> makeshared(Args &&...args)
{
    using namespace std;
    return sharedptr<T>(new T(forward<Args>(args)...));
}

#include "shared.cpp"
#endif