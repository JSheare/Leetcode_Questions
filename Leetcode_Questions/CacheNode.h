#ifndef CACHENODE_H
#define CACHENODE_H

class CacheNode
{
public:
	int key;
	int val;
	CacheNode* prev{ nullptr };
	CacheNode* next{ nullptr };
	CacheNode(int key, int val) :
		key(key), val(val) {}
};

#endif
