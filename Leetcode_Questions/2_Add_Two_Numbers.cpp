#include <iostream>
#include <assert.h>

#include "ListNode.h"
#include "LinkedList.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode dummy{};
    ListNode* curr{ &dummy };
    int total{ 0 };
    int carry{ 0 };
    while (l1 || l2 || carry)
    {
        total = carry;
        if (l1)
        {
            total += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            total += l2->val;
            l2 = l2->next;
        }
        carry = total / 10;
        curr->next = new ListNode(total % 10);
        curr = curr->next;
    }
    return dummy.next;
}

#if 0
int main()
{
    // Provided test cases
    LinkedList test1List1{ 2, 4, 3 };
    LinkedList test1List2{ 5, 6, 4 };
    LinkedList correct1{ 7, 0, 8 };
    LinkedList answer1{};
    answer1.setHead(addTwoNumbers(test1List1.head, test1List2.head));
    assert(answer1 == correct1);

    LinkedList test2List1{ 0 };
    LinkedList test2List2{ 0 };
    LinkedList correct2{ 0 };
    LinkedList answer2{};
    answer2.setHead(addTwoNumbers(test2List1.head, test2List2.head));
    assert(answer2 == correct2);

    LinkedList test3List1{ 9, 9, 9, 9, 9, 9, 9 };
    LinkedList test3List2{ 9, 9, 9, 9 };
    LinkedList correct3{ 8, 9, 9, 9, 0, 0, 0, 1 };
    LinkedList answer3{};
    answer3.setHead(addTwoNumbers(test3List1.head, test3List2.head));
    assert(answer3 == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif