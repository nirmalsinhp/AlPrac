#include <bits/stdc++.h>
#include "unique.hpp"
#include "shared.hpp"
using namespace std;

class test
{
    public:
    int val = 10;
    test(double ind): d(ind){}  
    double getD() const
    {
        return d;
    }

    void setD(double ind)
    {
        d = ind;
    }

    private:
    double d;
};

class dtest : public test
{
    public:
    dtest(double ind): test(ind){}  
};

ostream& operator<<(ostream& os, const test& t)
{
    
    os << "printing :" << "test" << endl;
    os << t.getD() << endl;
    os << t.val << endl;
    return os;
}

int main()
{

    //int i = 0;
    unique_ptr<int> u1 = make_unique<int>(30);
    unique_ptr<int> u2 = make_unique<int>(40);
    unique_ptr<int> u3 = move(u2);
    unique_ptr<test> utp = make_unique<dtest>(22.22);
    cout << utp->getD() << endl;
    u1 = move(u3);
    u3.reset(new int(0));
    auto iptr = u3.release();
    //cout << hex << "i : " << &i << endl;
    cout << hex << "iptr : " << iptr << endl;
    auto iptr2 = u3.get();
    cout << hex << "ar :" << iptr2 << endl;
    unique_ptr<int> u4;
    swap(u1, u4);
    shared_ptr<int> s1 = make_shared<int>(10);   
    shared_ptr<int> s2 = make_shared<int>(20);   
    shared_ptr<int> s3 = s1;   
    cout << "s1 :" << s1.use_count() << endl;
    cout << "s2 :" << s2.use_count() << endl;
    cout << "s3 :" << s3.use_count() << endl;
    s2 = s3;
    shared_ptr<int> s4 = move(u2);
    s4 = make_unique<int>(25);
    cout << "s4 :" << s4.use_count() << " " << s4.get() << endl;
    shared_ptr<int> s5 = move(s4);
    //s5.release() // no release for shared ptr
    //s5.reset();
    s4 = move(s1);
    
    //s3->value;
    cout << "s1 :" << s1.use_count() << " " << s1.get() << endl;
    cout << "s2 :" << s2.use_count() << " " << s2.get() << endl;
    cout << "s3 :" << s3.use_count() << " " << s3.get() << endl;
    cout << "s4 :" << s4.use_count() << " " << s4.get() << endl;
    cout << "s5 :" << s5.use_count() << " " << s5.get() << endl;

    cout << dec;
    // my unique
    // int i2 = 44;
    uniqueptr<int> ip(new int(44));
    auto ip2 = makeuniq<test>(11);
    auto dd = ip2->getD();
 
    cout << "dd :" << dd << endl;  
    cout << *ip << endl;
    cout << ip.get() << " :" << *(ip.get()) << endl;
    cout << ip2.get() << " :" << *(ip2.get()) << endl;
    // uniqueptr<int> ip2 = ip; do not compile deleted copy ctor
    uniqueptr<int> ip3 = move(ip);
    //cout << ip << endl;
    cout << *ip3 << endl;
    auto ipp = ip3.release();
    delete ipp;
    cout << hex << "ipp : " << ipp << endl;
 //   uniqueptr<test> tp = makeuniq<dtest>(23.3);

    sharedptr<double> msp = makeshared<double>(567.789);
    sharedptr<double> msp2 = makeshared<double>(56);
    sharedptr<double> msp3 = msp2; 
    sharedptr<double> msp4 = msp3;

    cout << "msp : " <<  msp.count() << " " << msp.get() << " : " << *msp << endl;    
    cout << "msp2 : " <<  msp2.count() << " " << msp2.get() << " : " << *msp2 <<endl;
    cout << "msp3 : " <<  msp3.count() << " " << msp3.get() <<" : " << *msp3 << endl;
    cout << "msp4 : " <<  msp4.count() << " " << msp4.get() << " : " << *msp4 <<endl;
 
    cout << "CTOR" << endl;
    msp2 = msp;
    cout << "msp : " <<  msp.count() << " " << msp.get() <<" : " << *msp << endl;    
    cout << "msp2 : " <<  msp2.count() << " " << msp2.get() <<" : " << *msp2 << endl;
    cout << "msp3 : " <<  msp3.count() << " " << msp3.get() <<" : " << *msp3 << endl;
    cout << "msp4 : " <<  msp4.count() << " " << msp4.get() << " : " << *msp4 <<endl;

    cout << "RESET :" << endl;

    msp2.reset();
    cout << "msp : " <<  msp.count() << " " << msp.get() << " : " << *msp <<endl;    
    
    msp3.reset(new double(222.222));
    cout << "msp : " <<  msp.count() << " " << msp.get() << " : " << *msp <<endl;    
   cout << msp2.get() << endl;
   // cout << "msp2 : " <<  msp2.count() << " " << msp2.get() <<" : " << *msp2 << endl;
    cout << "msp3 : " <<  msp3.count() << " " << msp3.get() << " : " << *msp3 <<endl;
    cout << "msp4 : " <<  msp4.count() << " " << msp4.get() << " : " << *msp4 <<endl;

    // MOVE
    cout << "MOVE" << endl;
    sharedptr<double> msp5 = move(msp4);
    msp4 = move(msp);
    //cout << "msp : " <<  msp.count() << " " << msp.get() << " : " << *msp <<endl;    
    cout << msp.get() << endl;
    cout << msp2.get() << endl;
    cout << "msp3 : " <<  msp3.count() << " " << msp3.get() << " : " << *msp3 <<endl;
    cout << "msp4 : " <<  msp4.count() << " " << msp4.get() << " : " << *msp4 <<endl;
    cout << "msp5 : " <<  msp5.count() << " " << msp5.get() << " : " << *msp5 <<endl;

    return 0;

}