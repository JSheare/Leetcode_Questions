#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <unordered_map>

#include "CacheNode.h"

class LRUCache
{
public:
	LRUCache(int capacity);
	~LRUCache();
	int get(int key);
	void put(int key, int value);

private:
	int capacity;
	std::unordered_map<int, CacheNode*> valMap;
	CacheNode* head{ new CacheNode(-1, -1) };
	CacheNode* tail{ new CacheNode(-1, -1) };

	void addNode(CacheNode* newNode);
	void removeNode(CacheNode* node);
};

#endif