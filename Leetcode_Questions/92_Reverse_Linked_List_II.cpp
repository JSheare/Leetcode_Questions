#include <iostream>
#include <cassert>

#include "ListNode.h"
#include "LinkedList.h"

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if (!head || left == right)
        return head;

    ListNode dummy;
    dummy.next = head;
    ListNode* prev{ &dummy };
    while (left > 1)
    {
        prev = prev->next;
        head = head->next;
        --left;
        --right;
    }

    ListNode* next{ nullptr };
    while (right > 1)
    {
        next = head->next;
        head->next = next->next;
        next->next = prev->next;
        prev->next = next;
        --right;
    }
    return dummy.next;
}

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 3, 4, 5 };
    LinkedList answer1{ 1, 4, 3, 2, 5 };
    LinkedList result1{ reverseBetween(test1.getHead(), 2, 4) };
    assert(result1 == answer1);

    LinkedList test2{ 5 };
    LinkedList answer2{ 5 };
    LinkedList result2{ reverseBetween(test2.getHead(), 1, 1) };
    assert(result2 == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif