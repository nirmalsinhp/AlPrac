#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


    TreeNode* traverse(TreeNode* root)
    {

        if (!root)
            return nullptr;
        cout << root->val << endl;
        auto right = root->right;
        auto ltail = traverse(root->left);
        cout << "ltail :" << (ltail ? ltail->val : -1) << endl;
        auto rtail = traverse(root->right);
        cout << "rtail :" <<(rtail ? rtail->val : -1) << endl;
        if(root->left)
        {
            ltail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        return rtail ? rtail : ltail ? ltail : root;
        // return root;
    }

void flatten(TreeNode *root)
{

    if (!root)
        return;
    if (!root->left && !root->right)
        return;
    traverse(root);
}


int main()
{
    TreeNode * n1 = new TreeNode(1);
    TreeNode * n2 = new TreeNode(2);
    TreeNode * n3 = new TreeNode(3);
    TreeNode * n4 = new TreeNode(4);
    TreeNode * n5 = new TreeNode(5);
    TreeNode * n6 = new TreeNode(6);
    n1->left = n2;
    n1->right = n5;
    n5->right = n6;
    n2->left = n3;
    n2->right = n4;
    flatten(n1);
    while(n1)
    {
        cout << n1->val << "->";
        n1 = n1->right;
    }


}