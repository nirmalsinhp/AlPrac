#include <bits/stdc++.h>

using namespace std;

// TODO : do all combination of private, protected, public inheritance and access specifiers.
class Shape
{
    public:
    Shape(int ip) : side(ip)
    {}
    Shape(const Shape&) = default;
    Shape& operator=(const Shape&) = default;
/*    Shape(int ip)
    {
        side  = ip; 
    }*/

    //shape(const int* i)
    virtual void print()
    {
        cout << "Shape P" << endl;
    }
    virtual void sides()
    {
        cout << "sides :" << side << endl;
    }

protected: 
    const int side;

};

class Rect : public Shape
{
    public:
    Rect() : Shape(4){}
    void print()
    {
        cout << "Derived P" << endl;
    }
    void sides()
    {
        cout << "rectangle has " << side << " side(s)" << endl;
    }

    Rect(const Rect& r) =  default;
    Rect& operator =(const Rect& r) =  default;

};

class Circle : public Shape
{
    public:
    Circle() : Shape(0), point(2){}
    Circle(const Circle& r) =  default;
    Circle& operator =(const Circle& r) =  default;

    void print()
    {
        cout << "Circle Point " << point  << endl;
    }

    private:
    int point;
};

int main()
{
    /*Shape s(0);
    Rect * rp = static_cast<Rect *>(&s);
    rp->print();*/

    Shape ss(2);
    //Rect rr(s);
    Rect r2;
    Circle c2;
    Shape& s2 = r2;
    // dynamic cast needs to be polimorphic
    // static case can work without polymorphism
//    auto rr = dynamic_cast<Circle&>(s2);
    auto rrs = static_cast<Circle&>(s2);
  //  rr.print();
    rrs.print();
    Shape * sptr = &c2;
    cout << " S " << sizeof(*sptr) << endl;
    cout <<"C " <<  sizeof(c2) << endl;
    // s = r2;
    /*Rect r;
    r.sides();   */
}