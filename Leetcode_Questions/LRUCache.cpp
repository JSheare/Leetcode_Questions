#include <unordered_map>

#include "CacheNode.h"
#include "LRUCache.h"

LRUCache::LRUCache(int capacity) :
    capacity(capacity)
{
    head->next = tail;
    tail->prev = head;
}

LRUCache::~LRUCache()
{
    CacheNode* temp{ head->next };
    CacheNode* prev{ head };
    while (temp)
    {
        delete prev;
        prev = temp;
        temp = temp->next;
    }
    delete prev;
}

int LRUCache::get(int key)
{
    if (valMap.contains(key))
    {
        CacheNode* keyNode{ valMap[key] };
        removeNode(keyNode);
        addNode(keyNode);
        return keyNode->val;
    }
    return -1;
}

void LRUCache::put(int key, int value)
{
    if (valMap.contains(key))
    {
        CacheNode* temp{ valMap[key] };
        temp->val = value;
        removeNode(temp);
        addNode(temp);
    }
    else
    {
        addNode(new CacheNode(key, value));
        valMap[key] = head->next;
        if (valMap.size() > capacity)
        {
            CacheNode* temp{ tail->prev };
            valMap.erase(temp->key);
            removeNode(temp);
            delete temp;
        }
    }
}

void LRUCache::addNode(CacheNode* newNode)
{
    CacheNode* temp{ head->next };
    newNode->next = temp;
    temp->prev = newNode;
    head->next = newNode;
    newNode->prev = head;
}

void LRUCache::removeNode(CacheNode* node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}