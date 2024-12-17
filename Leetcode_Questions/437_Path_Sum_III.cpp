#include <iostream>
#include <cassert>
#include <unordered_map>

#include "TreeNode.h"
#include "BinaryTree.h"

void pathSumDFS(TreeNode* root, std::unordered_map<long, int>& ps, int& count, long sum, int targetSum)
{
    if (!root)
        return;

    sum += root->val;  // Sum from root to current node
    // Checking to see if root to current node path hits the target
    if (sum == targetSum)
        ++count;

    // Checking to see if there are any working subpaths that exist
    // If (sum - target) is already present in the prefix sum, it means that the vals from one after the corresponding
    // prefix sum node to the current node add up to the target, and that therefore a working subpath exists
    if (ps.find(sum - targetSum) != ps.end())
    {
        count += ps[sum - targetSum];
    }
    ++ps[sum];
    pathSumDFS(root->left, ps, count, sum, targetSum);
    pathSumDFS(root->right, ps, count, sum, targetSum);
    --ps[sum];  // Removing this node's prefix sum when we're done looking at all the paths that include it
}

int pathSum(TreeNode* root, int targetSum)
{
    std::unordered_map<long, int> ps;
    int count{ 0 };
    pathSumDFS(root, ps, count, 0, targetSum);
    return count;
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "10", "5", "-3", "3", "2", "null", "11", "3", "-2", "null", "1" };
    assert(pathSum(test1.root, 8) == 3);

    BinaryTree test2{ "5", "4", "8", "11", "null", "13", "4", "7", "2", "null", "null", "5", "1" };
    assert(pathSum(test2.root, 22) == 3);

    std::cout << "Success!\n";

    return 0;
}
#endif