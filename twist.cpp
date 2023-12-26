#include <bits/stdc++.h>
using namespace std;

void rollString(string& s, vector<int>& vec)
{ 
    for(auto r: vec)
    {
        for(int i = 0; i < r; ++i)
        {
            if(s[i] == 'z')
                s[i] = 'a';
            else
                s[i] = s[i] + 1;
        }
        //cout << s << endl;
    }    
    //return s;
}

int errp(vector<int> vec, int pr, int q)
{
    int pj = 0, div, mod, modq;
    while(any_of(vec.begin(), vec.end(), [](int x) {return x > 0;}))
    {
       // pj++;
        auto m = max_element(vec.begin(), vec.end());
        // if(*m <= p)
        // {
        //     *m = 0;
        //     modq = q; 
        //     div=1;
        // }
        // else
        // {
        //     div = *m / p;
        //     mod = *m % p;
        //     *m = mod;
        //     modq = div * q;

        // }
        pj++;
        
        for(int i = 0; i < vec.size(); ++i)
        {
            cout<< vec[i] <<" ";
            if(i == m - vec.begin())
                vec[i] -= pr;
            else
                vec[i] -= q;
        }
        cout<<endl;
    }

    return pj;

}

string shiftingLetters(string s, vector<int>& shifts) 
{
    vector<int> pts;
    partial_sum(shifts.rbegin(), shifts.rend(), pts.rbegin());
    
    for(int i = 0 ; i < pts.size(); ++i)
    {
        s[i] = (s[i] - 'a' + pts[i] % 26) + 'a'; 
    }
    return s;
}


class B
{
    public:
    B()
    {
        f(2);
    }

    protected:
    virtual void f(int a)
    {
        cout << a << endl;
    }
};

class D final : public B
{
    public:
    D()
    {
        f(3);
    }
    
    protected:
    void f(int a) override
    {
        cout << a << endl;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    
    
    
    //int runs; 
    //cin >> runs;
    
    // for(int i = 0; i < runs; ++i)
    // {
    //     int sz;
    //     string s;
    //     vector<int> vec;
    //     cin >> sz;
    //     cin >> s;
    //     for(int j = 0; j < sz; ++j)
    //     {
    //         int roll;
    //         cin >> roll;
    //         vec.push_back(roll);
    //     }
    //     rollString(s, vec);
    //     cout << s << endl;
    // }

    vector<int> v = {1000, 600, 800};
   // {800,550,750}
    //{744,536,736}
   // vector<int> v = {6, 4, 1};
   // list<int> l = {6, 4, 1};
    auto ret = errp(v, 4, 1);
    cout << ret << endl;

    //sort(v.begin(), v.end());
    //sort(l.begin(), l.end());
   // l.sort();
    //l.splice(l.begin(), 4);
    // void * vptr = &runs;
    // cout << vptr << endl;
    
    return 0;
}