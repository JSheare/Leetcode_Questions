#include <iostream>
#include <cassert>
#include "ListNode.h"
#include "LinkedList.h"

ListNode* middleNode(ListNode* head)
{
    ListNode* slow{ head };
    ListNode* fast{ head };
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 3, 4, 5 };
    ListNode* head1{ test1.getHead() };
    LinkedList answer1{};
    LinkedList correct1{3, 4, 5};
    answer1.setHead(middleNode(head1));
    assert(answer1 == correct1);
    answer1.setHead(head1);


    LinkedList test2{ 1, 2, 3, 4, 5, 6 };
    ListNode* head2{ test2.getHead() };
    LinkedList answer2{};
    LinkedList correct2{ 4, 5, 6 };
    answer2.setHead(middleNode(head2));
    assert(answer2 == correct2);
    answer2.setHead(head2);

    std::cout << "Success!\n";

    return 0;
}
#endif