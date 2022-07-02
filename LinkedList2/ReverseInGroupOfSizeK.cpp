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
    int tmp = 0;
    while (head)
    {
        tmp++;
        head = head->next;
    }
    return tmp;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    int len = getLen(head);
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *cur;
    ListNode *nex;
    while (len >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            // shift prev to next
            pre->next = nex;
            // shifting nex
            nex = cur->next;
        }
        pre = cur;
        len -= k;
    }
    return dummy->next;
}