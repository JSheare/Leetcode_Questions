#include <iostream>
#include <assert.h>
#include "ListNode.h"
#include "LinkedList.h"

ListNode* makeCycle(LinkedList& list, int origin, int target)
{
    ListNode* head{ list.getHead() };
    ListNode* current{ head };
    ListNode* originNode{ nullptr };
    ListNode* targetNode{ nullptr };
    while (current)
    {
        if (current->val == origin)
            originNode = current;
        else if (current->val == target)
            targetNode = current;

        if (originNode && targetNode)
        {
            originNode->next = targetNode;
            break;
        }
        current = current->next;
    }
    return head;

}

void removeCycle(ListNode* head, int origin, LinkedList list)
{
    ListNode* current{ head };
    while (current)
    {
        if (current->val == origin)
        {
            current->next = nullptr;
            break;
        }
        current = current->next;
    }
    list.setHead(head);
}

bool hasCycle(ListNode* head)
{
    ListNode* slow{ head };
    ListNode* fast{ head };
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

#if 1
int main()
{
    // Provided test cases
    LinkedList list1{ 3, 2, 0, -4 };
    ListNode* head1{ makeCycle(list1, -4, 2) };
    assert(hasCycle(head1) == true);
    removeCycle(head1, -4, list1);

    LinkedList list2{ 1, 2 };
    ListNode* head2{ makeCycle(list2, 2, 1) };
    assert(hasCycle(head2) == true);
    removeCycle(head2, 2, list2);

    LinkedList list3{ 1 };
    ListNode* head3{ list3.getHead()};
    assert(hasCycle(head3) == false);
    list3.setHead(head3);

    std::cout << "Success!\n";

    return 0;
}
#endif