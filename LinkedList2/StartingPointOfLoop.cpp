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
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    bool isCycle = false;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            isCycle = true;
            break;
        }
    }
    if (!isCycle)
    {
        return NULL;
    }
    ListNode *temp = head;
    while (temp != slow)
    {
        temp = temp->next;
        slow = slow->next;
    }
    return temp;
}