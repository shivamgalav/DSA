#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node *copyRandomList(Node *head)
{
    Node *iter = head;
    Node *front = head;
    // step 1
    // make copy node and put infront of original
    while (iter != NULL)
    {
        front = iter->next;
        Node *copy = new Node(iter->val);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }
    // step 2
    // mark random of copy Node
    iter = head;
    while (iter != NULL)
    {
        if (iter->random != NULL)
        {
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }
    // step 3
    // separate both list
    iter = head;
    Node *dummy = new Node(0);
    Node *copy = dummy;
    while (iter != NULL)
    {
        front = iter->next->next;
        copy->next = iter->next;
        iter->next = front;
        copy = copy->next;
        iter = front;
    }
    return dummy->next;
}