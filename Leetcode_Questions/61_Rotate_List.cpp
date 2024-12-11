#include <iostream>
#include <assert.h>

#include "ListNode.h"
#include "LinkedList.h"

ListNode* rotateRight(ListNode* head, int k)
{
    if (!head)
        return head;

    ListNode* tail{ head };
    // Measuring the length of the list to avoid doing redundant rotations and getting the last node
    int length{ 1 };
    while (tail->next)
    {
        tail = tail->next;
        ++length;
    }
    // Making the list circular and calculating the necessary number of steps for the effective rotation
    tail->next = head;
    k = k % length;
    int steps{ length - k };
    // Advancing the tail to its new position
    while (steps--)
    {
        tail = tail->next;
    }
    // Capturing the new head and breaking the list cycle
    head = tail->next;
    tail->next = nullptr;
    return head;
}

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 3, 4, 5 };
    LinkedList correct1{ 4, 5, 1, 2, 3 };
    ListNode* test1Ptr{ test1.getHead() };
    test1Ptr = rotateRight(test1Ptr, 2);
    test1.setHead(test1Ptr);
    assert(test1 == correct1);

    LinkedList test2{ 0, 1, 2 };
    LinkedList correct2{ 2, 0, 1 };
    ListNode* test2Ptr{ test2.getHead() };
    test2Ptr = rotateRight(test2Ptr, 4);
    test2.setHead(test2Ptr);
    assert(test2 == correct2);

    LinkedList test3{ 1, 2, 3 };
    LinkedList correct3{ 2, 3, 1 };
    ListNode* test3Ptr{ test3.getHead() };
    test3Ptr = rotateRight(test3Ptr, 2000000000);
    test3.setHead(test3Ptr);
    assert(test3 == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif

