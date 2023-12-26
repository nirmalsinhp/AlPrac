#include <bits/stdc++.h>
using namespace std;
class Something
{
public:
    Something()
    {
        topSecretValue = 42;
    }
    virtual void f1()
    {
    }
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;

private:
    int topSecretValue;
};

struct rein
{
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
    int topSecretValue;

    /* data */
};

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if(!root)
        return nullptr;

    while(root && root->left)
    {
        auto next = root->left;
        while(root)
        {
            root->left->next = root->right;
            root->right->next = root->next ? root->next->left : nullptr;
            next 
        }
    }
}

int main()
{
    Something s1;
    s1.somePublicString = "public_Stinrf";
    s1.somePublicInt = 24;
    rein r1 = *reinterpret_cast<rein *>(&s1);
    cout << r1.topSecretValue << endl;
    cout << r1.somePublicInt << endl;
    cout << r1.somePublicString << endl;
    return 0;
}