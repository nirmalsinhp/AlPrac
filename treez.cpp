#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
    struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    vector<vector<int>> vec;
    queue<TreeNode*> lq;
    if(!root)
        return vec;
    
    auto start = root;
    lq.push(root);

    int count = 0;
    while(!lq.empty())
    {
        queue<TreeNode *> cq(move(lq));
        vector<int> ivec;
        while(!cq.empty())
        {
            auto current = cq.front();
            cq.pop();
            if(current)
            {
                ivec.push_back(current->val);
                lq.push(current->left);
                lq.push(current->right);
            }
        }
        if(count % 2 ==0)
            reverse(ivec.begin(), ivec.end());
        vec.push_back(ivec);
    }
    return vec;
}


// min in binary tree - goes left till nullptr
// max in binary tree - goes right till nullptr
// floor 
// ceiling 
// rank - how many elements less than K(node->val).

int main()
{
    int x = 100;
    auto&& i = 2;
    auto&& j = x;
    
    return 0;
}