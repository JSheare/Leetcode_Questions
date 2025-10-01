#include <iostream>
#include <cassert>

#include "ListNode.h"
#include "LinkedList.h"

// Recursive solution
# if 0
ListNode* reverseKGroup(ListNode* head, int k)
{
    if (!head)
        return head;

    ListNode* curr{ head };
    for (int i{ 0 }; i < k; ++i)
    {
        if (!curr)
            return head;

        curr = curr->next;
    }
    curr = head;
    ListNode* prev{ nullptr };
    ListNode* next{ nullptr };
    for (int i{ 0 }; i < k; ++i)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = reverseKGroup(curr, k);
    return prev;
}
#endif

// Iterative solution (O(1) memory usage)
#if 1
ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode dummy;
    ListNode* oldTail{ &dummy };
    ListNode* tail{ head };
    ListNode* curr{ head };
    ListNode* prev{ nullptr };
    ListNode* next{ nullptr };
    while (tail)
    {
        for (int i{ 0 }; i < k; ++i)
        {
            if (!curr)
            {
                oldTail->next = tail;
                return dummy.next;
            }
            curr = curr->next;
        }
        curr = tail;
        prev = nullptr;
        for (int i{ 0 }; i < k; ++i)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        oldTail->next = prev;
        oldTail = tail;
        tail = curr;
    }
    return dummy.next;
}
#endif

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 3, 4, 5 };
    LinkedList correct1{ 2, 1, 4, 3, 5 };
    LinkedList answer1{};
    answer1.setHead(reverseKGroup(test1.getHead(), 2));
    assert(answer1 == correct1);

    LinkedList test2{ 1, 2, 3, 4, 5 };
    LinkedList correct2{ 3, 2, 1, 4, 5 };
    LinkedList answer2{};
    answer2.setHead(reverseKGroup(test2.getHead(), 3));
    assert(answer2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif