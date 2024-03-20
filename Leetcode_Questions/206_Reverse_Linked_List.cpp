#include <iostream>
#include <assert.h>
#include "ListNode.h"
#include "LinkedList.h"

ListNode* reverseList(ListNode* head)
{
    if (!head || !head->next)
        return head;

    ListNode* prev{ nullptr };
    ListNode* current{ head };
    ListNode* next{ nullptr };
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 3, 4, 5 };
    LinkedList answer1{};
    LinkedList correct1{ 5, 4, 3, 2, 1 };
    answer1.setHead(reverseList(test1.getHead()));
    assert(answer1 == correct1);

    LinkedList test2{ 1, 2 };
    LinkedList answer2{};
    LinkedList correct2{ 2, 1 };
    answer2.setHead(reverseList(test2.getHead()));
    assert(answer2 == correct2);

    LinkedList test3{};
    LinkedList answer3{};
    LinkedList correct3{};
    answer3.setHead(reverseList(test3.getHead()));
    assert(answer3 == correct3);

    std::cout << "Success!\n";

	return 0;
}
#endif