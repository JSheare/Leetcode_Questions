#include <iostream>
#include <cassert>
#include <stack>

#include "TreeNode.h"
#include "BinaryTree.h"

// Recursive solution (O(n) space)
#if 0
void flattenHelper(std::stack<TreeNode*>& st, TreeNode* root)
{
    // Doing a pre-order traversal of the tree and keeping track of the order with a stack
    st.push(root);
    if (root->left)
        flattenHelper(st, root->left);

    if (root->right)
        flattenHelper(st, root->right);
}

void flatten(TreeNode* root)
{
    if (!root)
        return;

    std::stack<TreeNode*> st;
    flattenHelper(st, root);
    // Flattening the tree based on the traversal
    TreeNode* prev{ nullptr };
    while (!st.empty())
    {
        TreeNode* curr{ st.top() };
        st.pop();
        curr->left = nullptr;
        curr->right = prev;
        prev = curr;
    }
}
#endif

// In-place Morris-traversal-like solution (O(1) space)
#if 1
void flatten(TreeNode* root)
{
    TreeNode* curr{ root };
    while (curr)
    {
        if (curr->left)
        {
            TreeNode* temp{ curr->left };
            while (temp->right)
            {
                temp = temp->right;
            }
            temp->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}
#endif

#if 0
int main()
{
    //Provided test cases
    BinaryTree test1{ "1", "2", "5", "3", "4", "null", "6" };
    BinaryTree answer1{ "1", 
        "null", "2",
        "null", "null", "null", "3", "null", "null", "null", "null", "null", "null", "null", "4",
        "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "5",
        "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", 
        "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "6"};
    flatten(test1.root);
    assert(test1 == answer1);

    BinaryTree test2;
    BinaryTree answer2;
    flatten(test2.root);
    assert(test2 == answer2);

    BinaryTree test3{ "0" };
    BinaryTree answer3{ "0" };
    flatten(test3.root);
    assert(test3 == answer3);

    std::cout << "Success!\n";

    return 0;
}
#endif