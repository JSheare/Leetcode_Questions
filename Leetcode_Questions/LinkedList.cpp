#include <initializer_list>
#include <iostream>

#include "LinkedList.h"
#include "ListNode.h"

LinkedList::LinkedList(ListNode* head) :
	head(head)
{}

LinkedList::LinkedList(std::initializer_list<int> values)
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

		head = dummy.next;
	}
}

LinkedList::~LinkedList()
{
	deleteList(head);
}

ListNode* LinkedList::getHead()
{
	ListNode* head{ this->head };
	this->head = nullptr;
	return head;
}

void LinkedList::setHead(ListNode* head)
{
	this->head = head;
}

bool LinkedList::operator==(LinkedList& list2)
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

	if (node1 || node2)
		return false;

	return true;
}

std::ostream& operator<<(std::ostream& out, LinkedList& list)
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

void LinkedList::deleteList(ListNode* head)
{
	while (head)
	{
		ListNode* next{ head->next };
		delete head;
		head = next;
	}
}