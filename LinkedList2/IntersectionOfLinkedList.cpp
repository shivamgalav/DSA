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

int getLen(ListNode *head)
{
    int temp = 0;
    while (head)
    {
        head = head->next;
        temp++;
    }
    return temp;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *t1 = headA;
    ListNode *t2 = headB;
    int l1 = getLen(headA);
    int l2 = getLen(headB);
    int k = abs(l1 - l2);
    while (k--)
    {
        if (l1 > l2)
        {
            t1 = t1->next;
        }
        if (l2 > l1)
        {
            t2 = t2->next;
        }
    }
    while (t1 && t2)
    {
        if (t1 == t2)
        {
            return t1;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return NULL;
}