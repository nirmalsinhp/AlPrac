#include <bits/stdc++.h>
using namespace std;

void move(int n, int start, int end)
{
    cout << "Move " << n << " " << start << "->" << end << endl;
}

int other(int start, int end)
{
    // assume rods are 1, 2, 3
    return 6 - (start + end);
}

void hanoi(int n, int start, int end)
{
    if (start < 1 || end < 1 || n < 1)
        throw logic_error(" wrong inputs");
    if (n == 1)
        move(n, start, end);
    else
    {
        auto oth = other(start, end);
        hanoi(n - 1, start, oth);
        move(n, start, end);
        hanoi(n - 1, oth, end);
    }
}

int main()
{
    hanoi(3, 1, 3);
    cout << " -------------- " << endl;
    hanoi(9, 3, 2);
    return 0;
}