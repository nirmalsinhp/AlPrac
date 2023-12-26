#include <bits/stdc++.h>

using namespace std;

template <typename T>
void f(T, typename T::type x)
{
    cout << x << endl;
}

 // the point of SFINAE is to deactivate a piece of template code for some types.
template <typename T>
void f(T, typename T::other_type x)
{
    cout << x << endl;
}

class A
{
    public:
    using type = int;
  //  int x;
};

class B
{
    public:
    using type = double;
  //  int x;
};

int main(int argc, char** argv)
{
    f(A(), 42);
    f(B(), 42.23);

    // //int ** td = (int **) malloc(10 * sizeof(int *));
    // //int td[10][] = (int **) malloc(10 * sizeof(int *));
    // cout << "allocation done" << endl;
    // for(int i = 0 ;  i < 10; ++i)
    // {
    //     td[i] = (int *) malloc(sizeof(int) * i);
    //     td[i][i] = (i * i);
    // }

    // for(int i = 0; i < 10; ++i)
    // {
    //     cout << i << " " << td[i][i] << endl;
    // }

    return 0;
}

