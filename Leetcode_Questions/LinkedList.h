#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <initializer_list>
#include "ListNode.h"

// The jankiest linked list ever
class LinkedList
{
private:
	ListNode* head{ nullptr };

public:
	LinkedList(ListNode* head):
		head(head)
	{}

	LinkedList(std::initializer_list<int> values)
	{
		if (values.size() > 0)
		{
			ListNode dummy{};
			ListNode* current{ &dummy };
			for (int value : values)
			{
				current->next = new ListNode{ value };
				current = current->next;
			}

			this->head = dummy.next;
		}
	}

	~LinkedList()
	{
		deleteList(this->head);
	}

	// If you use this, the list no longer assumes responsibility for deallocating the memory its' nodes occupy
	ListNode* getHead()
	{
		ListNode* head{ this->head };
		this->head = nullptr;
		return head;
	}

	bool operator==(LinkedList& list2)
	{
		ListNode* node1{ this->head };
		ListNode* node2{ list2.head };
		while (node1 && node2)
		{
			if (node1->val != node2->val)
				return false;

			node1 = node1->next;
			node2 = node2->next;
		}

		if (node1)
			return false;
		if (node2)
			return false;

		return true;
	}

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list)
	{
		out << '[';
		ListNode* node{ list.head };
		while (node)
		{
			if (!node->next)
			{
				out << node->val << " ]";
				break;
			}
			else
				out << node->val << ", ";
			
			node = node->next;
		}
		return out;
	}

	static void deleteList(ListNode* head)
	{
		while (head)
		{
			ListNode* nextNode{ head->next };
			delete head;
			head = nextNode;
		}
	}
};
#endif
