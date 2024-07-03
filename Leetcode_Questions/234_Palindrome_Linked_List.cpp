#include <iostream>
#include <assert.h>
#include <stack>

#include "ListNode.h"
#include "LinkedList.h"

// Linear time solution
//bool isPalindrome(ListNode* head)
//{
//    if (!head || !head->next)
//        return true;
//
//    std::stack<int> half;
//    ListNode* ptr{ head };
//    half.push(ptr->val);
//    ptr = ptr->next;
//    head = head->next->next;
//    while (head && head->next)
//    {
//        half.push(ptr->val);
//        ptr = ptr->next;
//        head = head->next->next;
//    }
//    if (head)
//        ptr = ptr->next;
//
//    while (ptr)
//    {
//        if (ptr->val != half.top())
//            return false;
//
//        ptr = ptr->next;
//        half.pop();
//    }
//    return true;
//}

// Linear time and constant space solution (modifies list)
bool isPalindrome(ListNode* head)
{
    if (!head || !head->next)
        return true;

    ListNode* ptr{ head };
    ListNode* revPtr{ nullptr };
    ListNode* temp;
    // Reversing the first half of the linked list
    while (head && head->next)
    {
        head = head->next->next;
        temp = ptr->next;
        ptr->next = revPtr;
        revPtr = ptr;
        ptr = temp;
    }
    // Skipping the center element (if it exists)
    if (head)
        ptr = ptr->next;

    // Comparing the normal half with the reversed half
    while (ptr && revPtr)
    {
        if (ptr->val != revPtr->val)
        {
            return false;
        }

        ptr = ptr->next;
        revPtr = revPtr->next;
    }
    return true;
}

# if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 2, 1 };
    ListNode* test1H{ test1.getHead() };
    assert(isPalindrome(test1H) == true);
    test1.setHead(test1H);

    LinkedList test2{ 1, 2 };
    ListNode* test2H{ test2.getHead() };
    assert(isPalindrome(test2H) == false);
    test2.setHead(test2H);

    std::cout << "Success!\n";

    return 0;
}
#endif