#include <iostream>
#include <assert.h>

#include "ListNode.h"
#include "LinkedList.h"

// Recursive solution
#if 0
ListNode* swapPairs(ListNode* head)
{
    if (!head || !head->next)
        return head;

    ListNode* next{ head->next };
    head->next = next->next;
    next->next = head;
    head->next = swapPairs(head->next);
    return next;
}
#endif

// Iterative solution
#if 1
ListNode* swapPairs(ListNode* head)
{
    ListNode* prev{ nullptr };
    ListNode* curr{ head };
    ListNode* curr1{ nullptr };
    ListNode* next{ nullptr };
    while (curr && curr->next)
    {
        curr1 = curr->next;
        next = curr1->next;
        if (curr == head)
            head = curr1;
        else
            prev->next = curr1;

        curr1->next = curr;
        curr->next = next;
        prev = curr;
        curr = prev->next;
    }
    return head;
}
#endif

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 3, 4 };
    LinkedList correct1{ 2, 1, 4, 3 };
    test1.setHead(swapPairs(test1.getHead()));
    assert(test1 == correct1);

    LinkedList test2{};
    LinkedList correct2{};
    test2.setHead(swapPairs(test2.getHead()));
    assert(test2 == correct2);

    LinkedList test3{ 1 };
    LinkedList correct3{ 1 };
    test3.setHead(swapPairs(test3.getHead()));
    assert(test3 == test3);

    LinkedList test4{ 1, 2, 3 };
    LinkedList correct4{ 2, 1, 3 };
    test4.setHead(swapPairs(test4.getHead()));
    assert(test4 == correct4);

    std::cout << "Success!\n";

    return 0;
}
#endif