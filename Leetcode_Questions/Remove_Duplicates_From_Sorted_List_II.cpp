#include <iostream>
#include <cassert>
#include <climits>

#include "ListNode.h"
#include "LinkedList.h"

ListNode* deleteDuplicatesII(ListNode* head)
{
    if (!head || !head->next)
        return head;

    ListNode dummy(INT_MIN);
    dummy.next = head;
    ListNode* prev{ &dummy };
    ListNode* curr{ head };
    while (curr && curr->next)
    {
        if (curr->val == curr->next->val)
        {
            while (curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
            }
            prev->next = curr->next;
        }
        else
            prev = prev->next;

        curr = curr->next;
    }
    return dummy.next;
}

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 3, 3, 4, 4, 5 };
    LinkedList answer1{ 1, 2, 5 };
    LinkedList result1{ deleteDuplicatesII(test1.getHead()) };
    assert(result1 == answer1);

    LinkedList test2{ 1, 1, 1, 2, 3 };
    LinkedList answer2{ 2, 3 };
    LinkedList result2{ deleteDuplicatesII(test2.getHead()) };
    assert(result2 == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif