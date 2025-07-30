#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

#include "ListNode.h"
#include "LinkedList.h"

// Divide and conquer merge sort approach
#if 0
ListNode* mergeLists(ListNode* list1, ListNode* list2)
{
    if (!list1)
        return list2;

    ListNode dummy{};
    ListNode* curr{ &dummy };
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    if (list1)
        curr->next = list1;

    if (list2)
        curr->next = list2;

    return dummy.next;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    if (lists.empty())
        return nullptr;

    int len{ static_cast<int>(lists.size()) };
    while (len > 1)
    {
        for (int i{ 0 }; i < len / 2; ++i)
        {
            lists[i] = mergeLists(lists[i], lists[len - 1 - i]);
        }
        len = (len + 1) / 2;
    }
    return lists.front();
}
#endif

// Priority queue approach
#if 1
ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    auto comp{ [](ListNode* a, ListNode* b) {return a->val > b->val; } };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> pq(comp);
    for (ListNode* list : lists)
    {
        if (list)
            pq.push(list);
    }
    ListNode dummy{};
    ListNode* curr{ &dummy };
    while (!pq.empty())
    {
        ListNode* node = pq.top();
        pq.pop();
        curr->next = node;
        curr = curr->next;
        if (node->next)
            pq.push(node->next);
    }
    return dummy.next;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<ListNode*> test1{ LinkedList{1, 4, 5}.getHead(), LinkedList{1, 3, 4}.getHead(), LinkedList{2, 6}.getHead() };
    LinkedList result1{ mergeKLists(test1) };
    LinkedList correct1{ 1, 1, 2, 3, 4, 4, 5, 6 };
    assert(result1 == correct1);

    std::vector<ListNode*> test2{};
    LinkedList result2{ mergeKLists(test2) };
    LinkedList correct2{};
    assert(result2 == correct2);

    std::vector<ListNode*> test3{ nullptr };
    LinkedList result3{ mergeKLists(test3) };
    LinkedList correct3{};
    assert(result3 == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif