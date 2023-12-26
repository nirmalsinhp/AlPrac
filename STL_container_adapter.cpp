#include <bits/stdc++.h>
#include <functional>
using namespace std;

class isEven: public unary_function<int, bool>
{
    bool operator()(int i)
    {
           return (i % 2 == 0);
    }
};

// functor, just define operator()
template <typename T>
struct isOdd
{
    bool operator()(int t) const 
    {
        return (t % 2 == 1);
    }

};

int main()
{
    //priority_queue<char> PQ;
    //stack<char> S;
    
    stack<char> S;
    queue<char> Q;
    //priority_queue<char> PQ;
    priority_queue<char, deque<char>, greater<>> PQ;
    S.push('A'); Q.push('a');PQ.emplace('A'); 
    S.push('B'); Q.push('b');PQ.emplace('B');
    S.push('X'); Q.push('X');PQ.emplace('Y');
    S.push('V'); Q.push('v');PQ.emplace('C');
    S.push('D'); Q.push('d');PQ.emplace('Q');

    while(!S.empty())
    {
        if(S.top() == 'X')
            S.top() = 'Y';
        cout << S.top() << endl;
        S.pop();
    }

    cout << "QQQ" << endl;
    while(!Q.empty())
    {
        if(Q.front() == 'X')
            Q.front() = 'Y';
        cout << Q.front() << endl;
        Q.pop();
    }

    cout << "PPP" << endl;
    while(!PQ.empty())
    {
        cout << PQ.top();
        PQ.pop();
    }

    isOdd<int> odd;
    isOdd<double> odb;
    bool odi = odd(6);
    bool od1 = odb(7.9);

    return 0;
}



