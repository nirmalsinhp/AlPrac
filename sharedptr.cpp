#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SP
{

    SP(): ptr(nullptr), *rc(0)
    {}

    SP(T* iptr):ptr(iptr), *rc(1)

    SP(const& SP rhs): ptr(rhs.ptr)
    {
        *rhs.rc++;
        rc = rhs.rc;
    }

    SP& operator=(const& SP rhs)
    {
        if(lhs != rhs)
        {
            decr_count();
            *rhs.rc++;
            ptr = rhs.ptr;
            rc = rhs.rc;
        }
        return *this;
    }

    SP& operator=(SP&& rhs)
    {
        decr_count();
        swap(*this, rhs);
        rhs.ptr = nullptr;
        rhs.rc = 0;
        return *this;
    }


    void decr_count()
    {
        if (--*rc == 0)
        {
            delete rc;
            delete ptr;
        }
    }

    ~sp()
    {
        if(rc && *rc > 0)
        {
            decr_count();
        }
    }

    T& operator*()
    {
        return *ptr;
    }

    const T& operator*() const
    {
        return *ptr;
    }

    T* get()
    {
        return ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    const T* operator->() const
    {
        return ptr;
    }

    private:
    T* ptr;
    size_t *rc;
};

// template <typename T>
void swap(const SP& lhs, const SP& rhs)
{
    using std::swap;
    swap(lhs.rc, rhs.rc);
    swap(lhs.ptr, rhs.ptr);
}

