template <typename T>
sharedptr<T>::~sharedptr()
{
    // if rc is 0, delete rc and ptr
    if(rc && *rc > 0)
        decr_count();
}

template <typename T>
sharedptr<T>::sharedptr(const sharedptr& rhs):ptr(rhs.ptr), rc(rhs.rc)
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
sharedptr<T>::sharedptr(sharedptr&& rhs):
    sharedptr()
{
    swap(*this, rhs);
}

template <typename T>
sharedptr<T>& sharedptr<T>::operator=(sharedptr&& rhs)
{
    auto tmp(move(rhs));
    swap(*this, tmp);
    /*decr_count();
    ptr = rhs.ptr;
    rc = rhs.rc;
    rhs.rc = nullptr;
    rhs.ptr = nullptr;    */
    return *this;
}

