#include <iostream>
#include <cassert>

#include "ListNode.h"
#include "LinkedList.h"

ListNode* partition(ListNode* head, int x)
{
    ListNode leftDummy;
    ListNode rightDummy;
    ListNode* leftCurr{ &leftDummy };
    ListNode* rightCurr{ &rightDummy };
    while (head)
    {
        if (head->val < x)
        {
            leftCurr->next = head;
            leftCurr = leftCurr->next;
        }
        else
        {
            rightCurr->next = head;
            rightCurr = rightCurr->next;
        }
        head = head->next;
    }
    leftCurr->next = rightDummy.next;
    rightCurr->next = nullptr;
    return leftDummy.next;
}

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 4, 3, 2, 5, 2 };
    LinkedList answer1{ 1, 2, 2, 4, 3, 5 };
    LinkedList result1{ partition(test1.getHead(), 3) };
    assert(result1 == answer1);

    LinkedList test2{ 2, 1 };
    LinkedList answer2{ 1, 2 };
    LinkedList result2{ partition(test2.getHead(), 2) };
    assert(result2 == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif