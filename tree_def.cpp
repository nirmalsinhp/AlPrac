#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <numeric>
#include <bits/stdc++.h>
struct tree
{
    int item;            /* data item */
    struct tree *parent; /* pointer to parent */
    struct tree *left;   /* pointer to left child */
    struct tree *right;  /* pointer to right child */
};

/*
- Recursive solution to tree problems.
base case -  where solution can be achieved without any recusrion. (may be at leaf node.)
recursive case - where solution can be achieved using recusrsion to solve smaller subproblems.
*/

/*
when solving tree problems, consider various tree properties and traversals, check which fits best in problem.
traversals - inorder(sorted), preorder, postorder(expression evaluation), level order, morris traversal
properties - height of tree, rank, size of tree, parent pointer, search property, complete tree,
index of childs in complete tree, ancestors,
succesor - left most in right subtree.
predecessor - right most in left subtree.
deletion - habbard deletion.
left rotation, right rotation, flip colors,
- check order statistics binary tree
- one sided binary search - search for 2, 4, 8, 16
- tombstone, laze deletion approach.
-- validateBST -- remember all left values to be less than root & all right values greater than root.

LCA of Binary tree & BST are diff. 

- Trees are graph
  - connected & acyclic
  - adding edge creates cycle
  - removing edge disconnects the graph

a binary tree, where every nonleaf node has exactly two children, is referred to as a full binary tree.
*/

tree *parent; /* last node visited */

tree *init_tree(void)
{
    return (NULL);
}

bool empty_tree(tree *t)
{
    if (t == NULL)
    {
        return (true);
    }
    return (false);
}

/* [[[ search_tree_cut */
tree *search_tree(tree *l, int x)
{
    if (l == NULL)
    {
        return (NULL);
    }

    if (l->item == x)
    {
        return (l);
    }

    if (x < l->item)
    {
        return (search_tree(l->left, x));
    }
    else
    {
        return (search_tree(l->right, x));
    }
}
/* ]]] */

/* [[[ insert_tree_cut */
void insert_tree(tree **l, int x, tree *parent)
{
    tree *p; /* temporary pointer */

    if (*l == NULL)
    {
        p = new tree();
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;
        return;
    }

    if (x < (*l)->item)
    {
        insert_tree(&((*l)->left), x, *l);
    }
    else
    {
        insert_tree(&((*l)->right), x, *l);
    }
}
/* ]]] */

void print_tree(tree *l)
{
    if (l != NULL)
    {
        print_tree(l->left);
        printf("%d ", l->item);
        print_tree(l->right);
    }
}

// number of nodes
int num_nodes(tree *root)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    return 1 + num_nodes(root->left) + num_nodes(root->right);
}

int num_leaves(tree *root)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    return  num_leaves(root->left) + num_leaves(root->right);
}


/* [[[ sucessor_descd_cut */
tree *successor_descendant(tree *t)
{
    tree *succ; /* successor pointer */

    if (t->right == NULL)
    {
        return (NULL);
    }
    succ = t->right;
    while (succ->left != NULL)
    {
        succ = succ->left;
    }
    return (succ);
}
/* ]]] */

/* [[[ find_minimum_cut */
tree *find_minimum(tree *t)
{
    tree *min; /* pointer to minimum */

    if (t == NULL)
    {
        return (NULL);
    }

    min = t;
    while (min->left != NULL)
    {
        min = min->left;
    }
    return (min);
}
/* ]]] */

tree *predecessor_descendant(tree *t)
{
    tree *pred; /* predecessor pointer */

    if (t->left == NULL)
    {
        return (NULL);
    }

// changing orignal a bit for morris traversal.
    pred = t->left;
    while (pred->right != NULL && pred->right != t)
    {
        pred = pred->right;
    }
    return (pred);
}

/* [[[ delete_tree_cut */
tree *delete_tree(tree *t, int x)
{
    tree *d;     /* node with key to delete */
    tree *p;     /* node to be physically deleted */
    int new_key; /* key to overwrite deleted key */
    tree *child; /* d's only child, if any */

    d = search_tree(t, x);

    if (d == NULL)
    {
        printf("Warning: key to be deleted %d is not in tree.\n", x);
        return (t);
    }

    if (d->parent == NULL)
    { /* if d is the root */
        if ((d->left == NULL) && (d->right == NULL))
        {
            free(d);
            return NULL; /* root-only tree */
        }

        if (d->left != NULL)
        { /* find node to physically delete */
            p = predecessor_descendant(d);
        }
        else
        {
            p = successor_descendant(d);
        }
    }
    else
    {
        if ((d->left == NULL) || (d->right == NULL))
        {
            /* d has <=1 child, so try to find non-null child */
            if (d->left != NULL)
            {
                child = d->left;
            }
            else
            {
                child = d->right;
            }

            if ((d->parent)->left == d)
            { /* fill null pointer */
                d->parent->left = child;
            }
            else
            {
                d->parent->right = child;
            }
            if (child != NULL)
            {
                child->parent = d->parent;
            }
            free(d);
            return (t);
        }
        else
        {
            p = successor_descendant(d); /* p has 2 children */
        }
    }

    new_key = p->item; /* deal with simpler case of deletion */
    delete_tree(t, p->item);
    d->item = new_key;
    return (t);
}
/* ]]] */

void process_item(int x)
{
    printf("%d", x);
}

/* [[[ traverse_tree_cut */
void traverse_tree(tree *l)
{
    if (l != NULL)
    {
        traverse_tree(l->left);
        process_item(l->item);
        traverse_tree(l->right);
    }
}
/* ]]] */

int depth(tree *l)
{
    using namespace std;
    if (!l)
    {
        return 0;
    }
    auto left = depth(l->left);
    auto right = depth(l->right);
    if (abs(right - left) > 1)
        cout << "unbalanced tree" << endl; // TODO - can be made seperate functions.

    auto dp = std::max(left, right) + 1;
    return dp;
}

int maxWidth(tree *l)
{
    using namespace std;
    queue<pair<tree *, int>> Q;
    int width = 0;
    Q.push({l, 1});
    while (!Q.empty())
    {
        width = max(width, Q.back().second - Q.front().second + 1);
        cout << "width : " << width << endl;
        queue<pair<tree *, int>> q;
        int qsize = Q.size();
        for (int i = 0; i < qsize; ++i)
        {
            auto nd = Q.front();
            Q.pop();
            if (nd.first->left)
                q.push({nd.first->left, nd.second * 2});
            if (nd.first->right)
                q.push({nd.first->right, nd.second * 2 + 1});
        }
        Q = q;
    }
    return width;
}

/*
Base case : 
    1. leaf : visit self, finish
    2. no left subtree : tail recursion and move ahead
Recursive case:
    1. left subtree
        - find the root's preeccessor , pred(r).right = root. point it's right to root.
        - tail recurse on left side, not just a smaller version of same proble. eventually will visit the root.
        - if root is visited itself means back -edge was already set, delete it and recurse to right.

- no mutation of tree, no extra space.
*/

void MorrisTraversal(tree *root)
{
    using namespace std;
    if (!root)
        return;
    while (root)
    {
        if (!root->left)
        {
            cout << root->item << endl;
            //process_item(root->item);
            root = root->right;
        }
        else
        {
            auto pred = predecessor_descendant(root);
            if(pred->right == root)
            {
                pred->right = NULL;
                cout << root->item << endl;
                root = root->right;
            }
            else
            {
                pred->right = root;
                root = root->left;
            }
        }
    }
}


int main(void)
{
    char c;    /* input character */
    int d;     /* input item */
    tree *l;   /* tree under construction */
    tree *tmp; /* returned tree from search */

    l = init_tree();

    while (scanf("%c", &c) != EOF)
    {
        if (tolower(c) == 'p')
        {
            print_tree(l);
            printf("\n");
        }
        if (tolower(c) == 'i')
        {
            scanf("%d", &d);
            printf("new item: %d\n", d);
            insert_tree(&l, d, NULL);
        }
        if (tolower(c) == 's')
        {
            scanf("%d", &d);
            tmp = search_tree(l, d);
            if (tmp == NULL)
            {
                printf("item %d not found\n", d);
            }
            else
            {
                printf("item %d found\n", d);
            }
        }
        if (tolower(c) == 'd')
        {
            scanf("%d", &d);
            printf(" deleting item %d\n", d);
            l = delete_tree(l, d);
            print_tree(l);
            printf("\n");
        }
    }
    std::cout << "depth : " << depth(l) << std::endl;
    auto maxwd = maxWidth(l);
    std::cout << "max Width : " << maxwd << std::endl;
    MorrisTraversal(l);
    return 0;
}
