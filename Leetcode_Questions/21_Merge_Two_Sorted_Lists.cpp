#include <iostream>
#include <assert.h>
#include <initializer_list>

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (!list1)
        return list2;

    if (!list2)
        return list1;

    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

ListNode* makeLinkedList(std::initializer_list<int> values)
{
    ListNode dummy{};
    ListNode* current{ &dummy };
    for (int value : values)
    {
        ListNode* newNode{ new ListNode{value} };
        current->next = newNode;
        current = current->next;
    }

    return dummy.next;
}

void deleteLinkedList(ListNode* list)
{
    while (list)
    {
        ListNode* nextNode{ list->next };
        delete list;
        list = nextNode;
    }
}

bool isSameList(ListNode* list1, ListNode* list2)
{
    while (list1 && list2)
    {
        if (list1->val != list2->val)
            return false;

        list1 = list1->next;
        list2 = list2->next;
    }

    if (list1)
        return false;
    if (list2)
        return false;

    return true;
}

#if 1
int main()
{
    ListNode* list1;
    ListNode* list2;
    ListNode* correctAnswer;
    ListNode* answer;

    // Provided test cases

    list1 = makeLinkedList({ 1, 2, 4 });
    list2 = makeLinkedList({ 1, 3, 4 });
    correctAnswer = makeLinkedList({ 1, 1, 2, 3, 4, 4 });
    answer = mergeTwoLists(list1, list2);
    assert(isSameList(correctAnswer, answer));
    deleteLinkedList(answer);
    deleteLinkedList(correctAnswer);

    list1 = makeLinkedList({});
    list2 = makeLinkedList({});
    correctAnswer = makeLinkedList({});
    answer = mergeTwoLists(list1, list2);
    assert(isSameList(correctAnswer, answer));
    deleteLinkedList(answer);
    deleteLinkedList(correctAnswer);

    list1 = makeLinkedList({});
    list2 = makeLinkedList({0});
    correctAnswer = makeLinkedList({0});
    answer = mergeTwoLists(list1, list2);
    assert(isSameList(correctAnswer, answer));
    deleteLinkedList(answer);
    deleteLinkedList(correctAnswer);

    std::cout << "Success!\n";

	return 0;
}
#endif
