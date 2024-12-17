#include <iostream>
#include <cassert>

#include "ListNode.h"
#include "LinkedList.h"


// Cleaner, but apparently slightly slower, solution
#if 0
ListNode* oddEvenList(ListNode* head)
{
    if (!head || !head->next || !head->next->next)
        return head;

    ListNode* evenHead{ head->next };
    ListNode* even{ evenHead };
    ListNode* odd{ head };
    ListNode* curr{ evenHead->next };
    bool isOdd{ true };
    while (curr)
    {
        if (isOdd)
        {
            odd->next = curr;
            odd = odd->next;
        }
        else
        {
            even->next = curr;
            even = even->next;
        }
        isOdd = !isOdd;
        curr = curr->next;
    }
    odd->next = evenHead;
    even->next = nullptr;
    return head;
}
#endif

#if 1
ListNode* oddEvenList(ListNode* head)
{
    if (!head || !head->next)
        return head;

    ListNode* oddHead{ new ListNode(-1) };
    ListNode* odd{ oddHead };
    ListNode* evenHead{ new ListNode(-1) };
    ListNode* even{ evenHead };
    bool isOdd{ true };
    while (head)
    {
        if (isOdd)
        {
            odd->next = head;
            odd = odd->next;
        }
        else
        {
            even->next = head;
            even = even->next;
        }
        isOdd = !isOdd;
        head = head->next;
    }
    odd->next = evenHead->next;
    even->next = nullptr;
    head = oddHead->next;
    delete oddHead;
    delete evenHead;
    return head;
}
#endif

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 3, 4, 5 };
    LinkedList correct1{ 1, 3, 5, 2, 4 };
    test1.setHead(oddEvenList(test1.getHead()));
    assert(test1 == correct1);

    LinkedList test2{ 2, 1, 3, 5, 6, 4, 7 };
    LinkedList correct2{ 2, 3, 6, 7, 1, 5, 4 };
    test2.setHead(oddEvenList(test2.getHead()));
    assert(test2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif