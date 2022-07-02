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

ListNode *removeNthFromEnd(ListNode *head, int n)
{

    ListNode *temp = head;
    while (n--)
    {
        temp = temp->next;
    }
    ListNode *curr = head;
    // edgecases
    if (temp == NULL)
    {
        if (curr->next == NULL)
        {
            return NULL;
        }
        curr = curr->next;
        return curr;
    }
    while (temp && temp->next)
    {
        temp = temp->next;
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
}