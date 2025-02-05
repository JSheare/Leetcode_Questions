#ifndef TREECODEC_H
#define TREECODEC_H

#include <string>
#include <sstream>

#include "TreeNode.h"

class TreeCodec
{
public:
	std::string serialize(TreeNode* root);
	TreeNode* deserialize(std::string data);
};

#endif
