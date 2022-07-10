#include <bits/stdc++.h>
using namespace std;
class LRUCache
{

public:
    class node
    {
    public:
        int key;
        int value;
        node *next;
        node *prev;
        node(int _key, int _value)
        {
            key = _key;
            value = _value;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> mp;
    void addNode(node *add)
    {
        node *temp = head->next;
        add->next = temp;
        add->prev = head;
        head->next = add;
        temp->prev = add;
    }
    void deleteNode(node *del)
    {
        node *delprev = del->prev;
        node *delnext = del->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_)
    {
        if (mp.find(key_) != mp.end())
        {
            node *resNode = mp[key_];
            int res = resNode->value;
            mp.erase(key_);
            deleteNode(resNode);
            addNode(resNode);
            mp[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value)
    {
        if (mp.find(key_) != mp.end())
        {
            node *existingNode = mp[key_];
            mp.erase(key_);
            deleteNode(existingNode);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key_, value));
        mp[key_] = head->next;
    }
};
