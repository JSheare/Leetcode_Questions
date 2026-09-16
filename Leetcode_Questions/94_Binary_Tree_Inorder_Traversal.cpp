#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

#include "TreeNode.h"
#include "BinaryTree.h"

// Recursive solution
#if 0
void inorderTraversalHelper(std::vector<int>& values, TreeNode* root)
{
    if (!root)
        return;

    inorderTraversalHelper(values, root->left);
    values.push_back(root->val);
    inorderTraversalHelper(values, root->right);
}

std::vector<int> inorderTraversal(TreeNode* root)
{
    std::vector<int> values;
    inorderTraversalHelper(values, root);
    return values;
}
#endif

// Iterative solution
#if 1
std::vector<int> inorderTraversal(TreeNode* root)
{
    std::vector<int> values;
    std::stack<TreeNode*> st;
    while (true)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            break;

        root = st.top();
        st.pop();
        values.push_back(root->val);
        root = root->right;
    }
    return values;
}
#endif

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "1", "null", "2", "null", "null", "3" };
    std::vector<int> answer1{ 1, 3, 2 };
    assert(inorderTraversal(test1.root) == answer1);

    BinaryTree test2{ "1", "2", "3", "4", "5", "null", "8", "null", "null", "6", "7", "null", "null", "9" };
    std::vector<int> answer2{ 4, 2, 6, 5, 7, 1, 3, 9, 8 };
    assert(inorderTraversal(test2.root) == answer2);

    BinaryTree test3{};
    std::vector<int> answer3{};
    assert(inorderTraversal(test3.root) == answer3);

    BinaryTree test4{ "1" };
    std::vector<int> answer4{ 1 };
    assert(inorderTraversal(test4.root) == answer4);

    std::cout << "Success!\n";

    return 0;
}
#endif