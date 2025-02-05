#include <string>
#include <sstream>
#include <queue>

#include "TreeNode.h"
#include "TreeCodec.h"

std::string TreeCodec::serialize(TreeNode* root)
{
    if (!root)
        return "";

    std::ostringstream out;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* node{ q.front() };
        q.pop();
        if (!node)
            out << "# ";
        else
        {
            out << node->val << ' ';
            q.push(node->left);
            q.push(node->right);
        }
    }
    return out.str();
}

TreeNode* TreeCodec::deserialize(std::string data)
{
    if (data.length() == 0)
        return nullptr;

    std::istringstream in(data);
    std::string val;
    std::queue<TreeNode*> q;
    in >> val;
    TreeNode* root{ new TreeNode(stoi(val)) };
    q.push(root);
    while (!q.empty())
    {
        TreeNode* node{ q.front() };
        q.pop();
        in >> val;
        if (val == "#")
            node->left = nullptr;
        else
        {
            node->left = new TreeNode(stoi(val));
            q.push(node->left);
        }
        in >> val;
        if (val == "#")
            node->right = nullptr;
        else
        {
            node->right = new TreeNode(stoi(val));
            q.push(node->right);
        }
    }
    return root;
}