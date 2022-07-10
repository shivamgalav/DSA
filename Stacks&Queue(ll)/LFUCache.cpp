#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key, value, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};
struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache
{
    map<int, Node *> keyNode;
    map<int, List *> freqList;
    int maxSize;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxSize = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqList(Node *node)
    {
        keyNode.erase(node->key);
        freqList[node->cnt]->removeNode(node);
        if (node->cnt == minFreq && freqList[node->cnt]->size == 0)
        {
            minFreq++;
        }
        List *newFreqList = new List();
        if (freqList.find(node->cnt + 1) != freqList.end())
        {
            newFreqList = freqList[node->cnt + 1];
        }
        node->cnt += 1;
        newFreqList->addFront(node);
        freqList[node->cnt] = newFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *res = keyNode[key];
            int val = res->value;
            updateFreqList(res);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSize == 0)
        {
            return;
        }
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else
        {
            if (curSize == maxSize)
            {
                List *list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }

            curSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqList.find(minFreq) != freqList.end())
            {
                listFreq = freqList[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqList[minFreq] = listFreq;
        }
    }
};