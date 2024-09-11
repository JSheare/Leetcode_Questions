#include <iostream>
#include <assert.h>
#include <vector>

#include "TreeNode.h"
#include "BinaryTree.h"

void pathSumDFS(TreeNode* root, int targetSum, std::vector<std::vector<int>>& paths, std::vector<int>& path)
{
    if (!root)
        return;

    path.push_back(root->val);
    targetSum -= root->val;
    // Only adding root-to-leaf paths
    if (!root->left && !root->right && targetSum == 0)
        paths.push_back(path);

    pathSumDFS(root->left, targetSum, paths, path);
    pathSumDFS(root->right, targetSum, paths, path);
    path.pop_back();
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum)
{
    if (!root)
        return {};

    std::vector<std::vector<int>> paths;
    std::vector<int> path{};
    pathSumDFS(root, targetSum, paths, path);
    return paths;
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "5", "4" , "8", "11", "null", "13", "4", "7", "2", "null", "null", "null", "null", "5", "1" };
    std::vector<std::vector<int>> correct1{ {5, 4, 11, 2}, {5, 8, 4, 5} };
    assert(pathSum(test1.root, 22) == correct1);

    BinaryTree test2{ "1", "2", "3" };
    std::vector<std::vector<int>> correct2{};
    assert(pathSum(test2.root, 5) == correct2);

    BinaryTree test3{ "1", "2" };
    std::vector<std::vector<int>> correct3{};
    assert(pathSum(test3.root, 0) == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif