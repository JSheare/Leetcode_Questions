#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <initializer_list>
#include <iostream>

#include "ListNode.h"

// The jankiest linked list ever
class LinkedList
{
public:
	ListNode* head{ nullptr };

	LinkedList(ListNode* head);
	LinkedList(std::initializer_list<int> values);
	~LinkedList();
	// If you use this, the list no longer assumes responsibility for deallocating the memory its nodes occupy
	ListNode* getHead();
	void setHead(ListNode* head);
	bool operator==(LinkedList& list2);
	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);
	static void deleteList(ListNode* head);
};
#endif
