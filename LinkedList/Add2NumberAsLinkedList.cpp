#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // if reversed list not given
    // ListNode* rl1 = reverseList(l1);
    // ListNode* rl2 = reverseList(l2);
    ListNode *tl1 = l1;
    ListNode *tl2 = l2;
    int carry = 0;
    ListNode *result = new ListNode(0);
    ListNode *res = result;
    while (tl1 != NULL && tl2 != NULL)
    {
        int tempsum = tl1->val + tl2->val + carry;
        carry = tempsum / 10;
        int toStore = tempsum % 10;
        ListNode *temp = new ListNode(0);
        result->val = toStore;
        result->next = temp;
        result = result->next;
        tl2 = tl2->next;
        tl1 = tl1->next;
    }

    while (tl2 != NULL)
    {
        int tempsum = tl2->val + carry;
        carry = tempsum / 10;
        int toStore = tempsum % 10;
        ListNode *temp = new ListNode(0);
        result->val = toStore;
        result->next = temp;
        result = result->next;
        tl2 = tl2->next;
    }

    while (tl1 != NULL)
    {
        int tempsum = tl1->val + carry;
        carry = tempsum / 10;
        int toStore = tempsum % 10;
        ListNode *temp = new ListNode(0);
        result->val = toStore;
        result->next = temp;
        result = result->next;
        tl1 = tl1->next;
    }

    result = res;
    if (carry == 0)
    {
        while (result->next->next != NULL)
        {
            result = result->next;
        }
        result->next = NULL;
    }
    else
    {
        while (result->next->next != NULL)
        {
            result = result->next;
        }
        result->next->val = carry;
    }
    return res;
}