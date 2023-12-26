template <typename T>
uniqueptr<T>::uniqueptr(uniqueptr&& rhs):
    uniqueptr()
{
    swap(*this, rhs);
}

template <typename T>
uniqueptr<T>& uniqueptr<T>::operator=(uniqueptr&& rhs)
{
    reset(rhs.release());
    return *this;
}
