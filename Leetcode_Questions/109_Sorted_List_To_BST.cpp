#include <iostream>
#include <cassert>

#include "ListNode.h"
#include "LinkedList.h"
#include "TreeNode.h"
#include "BinaryTree.h"

// Recursive two-pointers approach
#if 0
TreeNode* sortedListToBST(ListNode* head)
{
    if (!head)
        return nullptr;

    if (!head->next)
        return new TreeNode(head->val);

    ListNode* prev{ nullptr };
    ListNode* slow{ head };
    ListNode* fast{ head };
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode* root{ new TreeNode(slow->val) };
    prev->next = nullptr;

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
}
#endif

// Node counting approach
#if 1
TreeNode* sortedListToBSTHelper(ListNode*& headRef, int n)
{
    if (n <= 0)
        return nullptr;

    TreeNode* left{ sortedListToBSTHelper(headRef, n / 2) };

    TreeNode* root{ new TreeNode(headRef->val) };
    root->left = left;

    headRef = headRef->next;

    root->right = sortedListToBSTHelper(headRef, n - n / 2 - 1);

    return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
    int count{ 0 };
    ListNode* curr{ head };
    while (curr)
    {
        ++count;
        curr = curr->next;
    }
    curr = head;
    return sortedListToBSTHelper(curr, count);
}
#endif

#if 0
int main()
{
    // Provided test cases
    LinkedList input1{ -10, -3, 0, 5, 9 };
    BinaryTree answer1{ "0", "-3", "9", "-10", "null", "5" };
    BinaryTree result1{ sortedListToBST(input1.getHead()) };
    assert(answer1 == result1);

    LinkedList input2{};
    BinaryTree answer2;
    BinaryTree result2{ sortedListToBST(input2.getHead()) };

    std::cout << "Success!\n";

    return 0;
}
#endif