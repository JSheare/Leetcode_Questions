#include <iostream>
#include <assert.h>

#include "ListNode.h"
#include "LinkedList.h"

// Faster and more memory-efficient, but leaks memory
# if 0
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* first{ head };
    ListNode* second{ head };
    while (n > 0)
    {
        first = first->next;
        if (!first)
            return head->next;

        --n;
    }
    while (first->next)
    {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return head;
}
#endif

#if 1
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* first{ head };
    ListNode* second{ head };
    while (n > 0)
    {
        first = first->next;
        if (!first)
        {
            ListNode* temp{ head->next };
            delete head;
            return temp;
        }
        --n;
    }
    while (first->next)
    {
        first = first->next;
        second = second->next;
    }
    ListNode* temp{ second->next };
    second->next = second->next->next;
    delete temp;
    return head;
}
#endif

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 3, 4, 5 };
    LinkedList correct1{ 1, 2, 3, 5 };
    test1.setHead(removeNthFromEnd(test1.getHead(), 2));
    assert(test1 == correct1);

    LinkedList test2{ 1 };
    LinkedList correct2{};
    test2.setHead(removeNthFromEnd(test2.getHead(), 1));
    assert(test2 == correct2);

    LinkedList test3{ 1, 2 };
    LinkedList correct3{ 1 };
    test3.setHead(removeNthFromEnd(test3.getHead(), 1));
    assert(test3 == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif