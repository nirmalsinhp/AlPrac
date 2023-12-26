#include <bits/stdc++.h>

using namespace std;

class Base
{
    public:
    void of1(int i)
    {
        cout << i << endl;
    }

    void of1(double d)
    {
        cout << d << endl;
    }

    virtual void vf1(string s)
    {
        cout << "base vf1" << endl;
    }

    virtual void nh(string s)
    {
        cout << "base nh" << endl;
    }

};

class Derived : public Base
{
    public:

    void vf1(string s) override
    {
        cout << "derived vf1" << endl;
    }

    using Base::nh;
    void nh(double d)
    {
        cout << "derived nh" << endl;
    }
};

// if a =  2, 0, 5, 9

// b = 45, 90, , 

vector<int> fun(vector<int> vec)
{
    
    vector<int> ret;
    long long prd = 1;
    for(auto n : vec)
    {
        if(n == 0)
            continue;
        prd *= n;
    }
    for(int i = 0; i < vec.size(); ++i)
    {
        if(vec[i]==0)
            ret.push_back(prd);
        else
            ret.push_back(prd / vec[i]);
    }
    return ret;
}

int main()
{

    Derived D;
    D.nh("name");
    return 0;
}