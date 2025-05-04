#include <bits/stdc++.h>
using namespace std;

struct  destroy_base
{
    virtual void operator()(void*) = 0;
    virtual ~destroy_base() {} // empty defination for virtual base class.
};

template <typename T>
class sharedptr
{

    template <typename U, typename Deleter>
    struct destroy : public destroy_base
    {
        destroy(Deleter D) : _del(D) {}
        ~destroy() = default;

        void operator()(void* ptr) override
        {
            cout << __PRETTY_FUNCTION__ << endl;
            _del(static_cast<U*>(ptr));
        }
        Deleter _del;
        /* data */
    };


public:
    sharedptr() : ptr(nullptr), rc(new size_t(0)) {}
    sharedptr(T* inp) : ptr(inp), rc(new size_t(1)) {}
    ~sharedptr();

    // adding custom deleter
    template <typename Deleter>
    sharedptr(T* ip, Deleter del) : ptr(ip), rc(new size_t(1)), d_(new destroy<T, Deleter>(del))
    {}

    template <typename U, typename = enable_if_t<is_convertible_v<U*, T*> > >
    sharedptr(U* ip) : ptr(ip), rc(new size_t(1)), d_(new destroy<U, default_delete<U>>(default_delete<U>{}))
    {}

    // template <typename U, typename = enable_if_t<is_base_of_v<T*, U*> > >
    // sharedptr(U* ip) : ptr(ip), rc(new size_t(1)), d_(new destroy<U, default_delete<U>>(default_delete<U>{}))
    // {}

    sharedptr(const sharedptr& rhs);
    sharedptr& operator=(const sharedptr& rhs);

    sharedptr(sharedptr&& rhs);
    sharedptr& operator=(sharedptr&& rhs);

//    does not work with void.
    template <typename U = T>
    enable_if_t<!is_void_v<U>, U&>
    operator*()
    {
        return *ptr;
    }

    template <typename U = T>
    enable_if_t<!is_void_v<U>, const U&>
    operator*() const
    {
        return *ptr;
    }

    /*
    // Specialization for void
    template <typename U = T>
    enable_if_t<is_void_v<U>, void>
    operator*()
    {
        throw runtime_error("Dereferencing void pointer is not allowed");
    }

    template <typename U = T>
    enable_if_t<is_void_v<U>, void>
    operator*() const
    {
        throw runtime_error("Dereferencing void pointer is not allowed");
    }
*/
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

    void reset()
    {
        //        decr_count();
        auto tmp = sharedptr();
        swap(tmp, *this);
    }

    void reset(T* iptr)
    {
        /*auto tmp = iptr;
        delete ptr;
        ptr = tmp;*/

        //      decr_count();
        auto tmp = sharedptr<T>(iptr);
        swap(tmp, *this);
    }

    T* get()
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
            if (d_) (*d_)(ptr);
            delete rc;
            // ptr = nullptr;
        }
    }

    template <typename U>
    friend void swap(sharedptr<U>& lhs, sharedptr<U>& rhs);

private:
    T* ptr;
    size_t* rc;
    destroy_base* d_ = new destroy<T, default_delete<T>>(default_delete<T>{});
};

template <typename T>
void swap(sharedptr<T>& lhs, sharedptr<T>& rhs)
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

template <typename T>
sharedptr<T>::~sharedptr()
{
    // if rc is 0, delete rc and ptr
    if (rc && *rc > 0)
        decr_count();
}

template <typename T>
sharedptr<T>::sharedptr(const sharedptr& rhs) :ptr(rhs.ptr), rc(rhs.rc)
{
    ++*rc;
}

template <typename T>
sharedptr<T>& sharedptr<T>::operator=(const sharedptr& rhs)
{
    // increment pointer of rhs, decrement of lhs.
    auto tmp(rhs);
    swap(*this, tmp);
    // swap with tmp , so when tmp goes out of scope, rc is decremented
/*    ++*rhs.rc;
    decr_count();
    ptr = rhs.ptr;
    rc = rhs.rc;*/
    return *this;
}


template <typename T>
sharedptr<T>::sharedptr(sharedptr&& rhs) :
    sharedptr()
{
    swap(*this, rhs);
}

template <typename T>
sharedptr<T>& sharedptr<T>::operator=(sharedptr&& rhs)
{
    auto tmp(std::move(rhs));
    swap(*this, tmp);
    /*decr_count();
    ptr = rhs.ptr;
    rc = rhs.rc;
    rhs.rc = nullptr;
    rhs.ptr = nullptr;    */
    return *this;
}

struct Base
{
    string mc = "string";
    virtual void func()
    {
        cout << "Base" << endl;
    }
    virtual ~Base()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << "Base Class dtor" << endl;
    }

};

struct Derived : public Base
{
    string mc = "string";
    virtual void func()
    {
        cout << "Derived" << endl;
    }
    virtual ~Derived()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << "Derived Class dtor" << endl;
    }

};


int main()
{
    auto dltr = [](auto ptr)
        {
            cout << __PRETTY_FUNCTION__ << endl;
            delete ptr;
        };
    auto ssp = makeshared<string>("string");
    // sharedptr<string> sp(new string("string is"), dltr);
    // sharedptr<int> spi(new int(1), dltr);
    // sharedptr<void> svi(new int(1));
    // sharedptr<void> svm(new myClass());
 //   cout << *svm << endl;  fails as expected.
    //sharedptr<Derived> dptr = makeshared<Derived>();
    sharedptr<Base> bptr(new Derived());
    //shared_ptr<Base> bptr = shared_ptr<Base>(new Derived());
    bptr->func();
    return 0;
}