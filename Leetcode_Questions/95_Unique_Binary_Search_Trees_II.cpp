#include <iostream>
#include <cassert>
#include <vector>
#include <initializer_list>
#include <string>

#include "TreeNode.h"
#include "BinaryTree.h"

std::vector<TreeNode*> generateTreesHelper(int start, int end)
{
    if (start > end)
        return { nullptr };

    if (start == end)
        return { new TreeNode(start) };

    std::vector<TreeNode*> permutations;
    for (int i{ start }; i <= end; ++i)
    {
        std::vector<TreeNode*> leftPerms{ generateTreesHelper(start, i - 1) };
        std::vector<TreeNode*> rightPerms{ generateTreesHelper(i + 1, end) };
        for (TreeNode* l : leftPerms)
        {
            for (TreeNode* r : rightPerms)
            {
                permutations.push_back(new TreeNode(i, l, r));
            }
        }
    }
    return permutations;
}

std::vector<TreeNode*> generateTrees(int n)
{
    return generateTreesHelper(1, n);
}

// Testing helper functions
static TreeNode* copyTree(TreeNode* root)
{
    if (!root)
        return nullptr;

    return new TreeNode(root->val, copyTree(root->left), copyTree(root->right));
}

static std::vector<BinaryTree> convertTrees(std::vector<TreeNode*>& trees)
{
    std::vector<BinaryTree> converted;
    for (TreeNode* t : trees)
    {
        converted.push_back(BinaryTree(copyTree(t)));
    }
    return converted;
}

static bool compareTrees(std::vector<BinaryTree>& one, std::vector<BinaryTree>& two)
{
    if (one.size() != two.size())
        return false;

    for (int i{ 0 }; i < one.size(); ++i)
    {
        if (one[i] != two[i])
            false;

    }
    return true;
}

#if 1
int main()
{
    // Provided test cases
    std::vector<TreeNode*> intermediate1{ generateTrees(3) };
    std::vector<BinaryTree> result1{ convertTrees(intermediate1) };
    std::vector<BinaryTree> answer1;
    answer1.emplace_back(std::initializer_list<std::string>{"1", "null", "2", "null", "null", "null", "3"});
    answer1.emplace_back(std::initializer_list<std::string>{"1", "null", "3", "null", "null", "2"});
    answer1.emplace_back(std::initializer_list<std::string>{"2", "1", "3"});
    answer1.emplace_back(std::initializer_list<std::string>{ "3", "1", "null", "null", "2" });
    answer1.emplace_back(std::initializer_list<std::string>{"3", "2", "null", "1"});
    assert(compareTrees(result1, answer1) == true);

    std::vector<TreeNode*> intermediate2{ generateTrees(1) };
    std::vector<BinaryTree> result2{ convertTrees(intermediate2) };
    std::vector<BinaryTree> answer2;
    answer2.emplace_back(std::initializer_list<std::string>{ "1" });
    assert(compareTrees(result2, answer2));

    std::cout << "Success!\n";

    return 0;
}
#endif

