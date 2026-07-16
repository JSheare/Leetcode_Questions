#include <iostream>
#include <cassert>

#include "ListNode.h"
#include "LinkedList.h"

ListNode* deleteDuplicates(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* curr{ head };
    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->val == curr->next->val)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return head;
}

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 1, 2 };
    LinkedList answer1{ 1, 2 };
    LinkedList result1{ deleteDuplicates(test1.getHead()) };
    assert(answer1 == result1);

    LinkedList test2{ 1, 1, 2, 3, 3 };
    LinkedList answer2{ 1, 2, 3 };
    LinkedList result2{ deleteDuplicates(test2.getHead()) };
    assert(answer2 == result2);

    std::cout << "Success!\n";

    return 0;
}
#endif