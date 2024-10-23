#include <iostream>
#include <assert.h>

#include "ListNode.h"
#include "LinkedList.h"

//Merge sort algorithm
ListNode* sortList(ListNode* head)
{
    if (!head || !head->next)
        return head;

    // Finding the list's midpoint
    ListNode* slow{ head };
    ListNode* fast{ head };
    while (fast && fast->next)
    {
        fast = fast->next->next;
        if (fast)
            slow = slow->next;
    }
    // Splitting the list in two
    fast = slow;
    slow = slow->next;
    fast->next = nullptr;
    // Sorting the two halves
    head = sortList(head);
    slow = sortList(slow);
    // Merging the two halves
    ListNode dummy{};
    ListNode* current{ &dummy };
    while (head && slow)
    {
        if (head->val <= slow->val)
        {
            current->next = head;
            head = head->next;
        }
        else
        {
            current->next = slow;
            slow = slow->next;
        }
        current = current->next;
    }
    // For cases where one half is longer than the other
    // They'll never differ in length by more than one
    if (head)
        current->next = head;

    if (slow)
        current->next = slow;

    return dummy.next;
}

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 4, 2, 1, 3 };
    LinkedList correct1{ 1, 2, 3, 4 };
    test1.head = sortList(test1.head);
    assert(test1 == correct1);

    LinkedList test2{ -1, 5, 3, 4, 0 };
    LinkedList correct2{ -1, 0, 3, 4, 5 };
    test2.head = sortList(test2.head);
    assert(test2 == correct2);

    LinkedList test3{};
    LinkedList correct3{};
    test3.head = sortList(test3.head);
    assert(test3 == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif