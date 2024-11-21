#include <iostream>
#include <assert.h>
#include <stack>

#include "ListNode.h"
#include "LinkedList.h"

// Solution with stack 
#if 0
void reorderList(ListNode* head)
{
    if (!head || !head->next)
        return;

    // Dividing the list in half
    ListNode* slow{ head };
    ListNode* fast{ head };
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reversing the second half using a stack
    fast = slow->next;
    slow->next = nullptr;
    std::stack<ListNode*> s;
    while (fast)
    {
        s.push(fast);
        fast = fast->next;
    }
    // Reordering the list by alternating between the first and second halves
    // Reusing old ptrs to save a little memory
    slow = head;
    while (!s.empty())
    {
        fast = slow->next;
        slow->next = s.top();
        s.pop();
        slow->next->next = fast;
        slow = fast;
    }
}
#endif

// Solution with no stack (in place reverse instead)
# if 1
void reorderList(ListNode* head)
{
    if (!head || !head->next)
        return;
    
    // Dividing the list in half
    ListNode* slow{ head };
    ListNode* fast{ head };
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reversing the second half
    // Reusing old ptrs to save a little memory
    fast = slow->next;
    slow->next = nullptr;
    slow = nullptr;
    ListNode* next;
    while (fast)
    {
        next = fast->next;
        fast->next = slow;
        slow = fast;
        fast = next;
    }
    fast = slow;
    // Reordering the list by alternating between the first and second halves
    slow = head;
    while (slow && fast)
    {
        next = slow->next;
        slow->next = fast;
        fast = fast->next;
        slow->next->next = next;
        slow = next;
    }
}
#endif

#if 0
int main()
{
    // Provided test cases
    LinkedList test1{ 1, 2, 3, 4 };
    LinkedList correct1{ 1, 4, 2, 3 };
    reorderList(test1.head);
    assert(test1 == correct1);

    LinkedList test2{ 1, 2, 3, 4, 5 };
    LinkedList correct2{ 1, 5, 2, 4, 3 };
    reorderList(test2.head);
    assert(test2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif