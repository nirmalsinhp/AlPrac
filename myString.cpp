#include <bits/stdc++.h>
using namespace std;

class MyString
{
    public:
    MyString() = default;
    MyString(const char * cptr)
    {
        auto len = strlen(cptr);
        sz = len;
        ptr = make_unique<char[]>(len);
 //       strncpy(ptr, cptr, len);
        copy(cptr, cptr + len, ptr.get());
    }

    MyString(const MyString& other)
    {
        cout << " copy ctor " << endl;
        sz = other.sz;
        ptr = make_unique<char[]>(sz);
        copy(other.ptr.get(), other.ptr.get() + sz, ptr.get());
        //strncpy(ptr, other.ptr, sz);
    }

    MyString& operator=(MyString other)
    {
        //MyString cp(other);
        cout << " copy = " << endl;
        (*this).swap(other);
        return *this;
    }

    // MyString& operator=(MyString&& other)
    // {
    //     MyString cp(move(other));
    //     cout << " moce = " << endl;
    //     //(*this).swap(other);
    //     (*this).swap(cp);
    //     return *this;
    // }

    MyString(MyString&& other) = default;
    // MyString(MyString&& other) : MyString()
    // {
    //     cout << " move ctor " << endl;
    //     (*this).swap(other);
    // }

    void swap(MyString& other)
    {
        using std::swap;
        swap(other.ptr, ptr);
        swap(other.sz, sz);
    }

    void print(ostream& os) const
    {
        if(!ptr)
            return;
        for(int i = 0; i < sz; ++i)
            os << ptr[i];
    }

    size_t size()
    {
        return sz;
    }

     ~MyString() = default;
    // ~MyString()
    // {
    //     delete [] ptr;
    // }
private:
    unique_ptr<char[]> ptr;
    //char * ptr = nullptr;
    size_t sz = 0;
};

ostream& operator<< (ostream& os, const MyString& s)
{
    s.print(os);
    return os;
}

int main()
{
 
    string s = "string";
    auto ei = s.end();
    cout << "end " << *ei << endl;
    list<int> li = {1,2,3,4,5,5};
    // cout << li[1] << endl; not allowed for list
    return 0;

    MyString s1("nirmal");
    MyString s2("nik");
    cout << s1.size() << " " << s2.size() << endl;
    s1 = s2;
    MyString s3 = s2;
    MyString s4 = move(s2);
    cout << "check move" << endl;
    s2 = move(s2);
    char * str = "string";
    cout << str << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}
