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
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int len = getLen(head);
    int tmp = k % len;
    if (tmp == 0)
    {
        return head;
    }
    tmp = len - tmp;
    ListNode *iter = head;

    while (--tmp)
    {
        iter = iter->next;
    }
    ListNode *temp = iter;
    ListNode *ans = iter->next;
    while (iter->next)
    {
        iter = iter->next;
    }
    iter->next = head;
    iter = temp;
    iter->next = NULL;
    return ans;
}