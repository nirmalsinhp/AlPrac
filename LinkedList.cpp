#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode * head)
{
    // Floyd's cycle detection.
    if(!head)
        return false;
    auto slow = head, fast = head;
    while(slow->next && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

    ListNode* addTwoNumbers(ListNode* n1, ListNode* n2) {

    ListNode* rl = nullptr;
    ListNode * head =  nullptr;
    int carry = 0;
    while(n1 || n2)
    {
        int n1v = n1 ? n1->val : 0;
        int n2v = n2 ? n2->val : 0;
        int val = n1v +  n2v;
        val = val + carry;
        int nval = val % 10;
        //cout << n1v << " : " << n2v << " " << nval << " " << carry << endl;
        auto node = new ListNode(nval);
        if(!rl)
        {
            rl = node;
            head = rl;
        }
        else
        {
            rl->next = node;
            rl = rl->next;
        }

        carry = val / 10;
        n1 = n1 ? n1->next : nullptr;
        n2 = n2 ? n2->next : nullptr;
    }
    if(carry > 0)
    {
        auto node = new ListNode(carry);
        rl->next =  node;
    }
    return head;

    }

int main()
{
    return 0;
}