#include <iostream>
#include <assert.h>
#include "ListNode.h"
#include "LinkedList.h"

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (!list1)
        return list2;

    if (!list2)
        return list1;

    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

#if 0
int main()
{
    // Provided test cases
    LinkedList test1List1{ 1, 2, 4 };
    LinkedList test1List2{ 1, 3, 4 };
    LinkedList correctAnswer1{ 1, 1, 2, 3, 4, 4 };
    LinkedList answer1{ mergeTwoLists(test1List1.getHead(), test1List2.getHead())};
    assert(answer1 == correctAnswer1);


    LinkedList test2List1{};
    LinkedList test2List2{};
    LinkedList correctAnswer2{};
    LinkedList answer2{ mergeTwoLists(test2List1.getHead(), test2List2.getHead()) };
    assert(answer2 == correctAnswer2);

    LinkedList test3List1{};
    LinkedList test3List2{ 0 };
    LinkedList correctAnswer3{ 0 };
    LinkedList answer3{ mergeTwoLists(test3List1.getHead(), test3List2.getHead()) };
    assert(answer3 == correctAnswer3);

    std::cout << "Success!\n";

	return 0;
}
#endif
