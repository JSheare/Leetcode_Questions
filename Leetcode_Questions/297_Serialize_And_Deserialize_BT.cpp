#include <iostream>
#include <cassert>
#include <string>

#include "TreeCodec.h"
#include "TreeNode.h"
#include "BinaryTree.h"

// See TreeCodec.h and TreeCodec.cpp for implementation details

#if 0
int main() 
{
    TreeCodec codec;

    // Provided test cases
    BinaryTree test1{ "1", "2", "3", "null", "null", "4", "5" };
    BinaryTree result1{ codec.deserialize(codec.serialize(test1.root)) };
    assert(test1 == result1);

    BinaryTree test2{};
    BinaryTree result2{ codec.deserialize(codec.serialize(test2.root)) };
    assert(test2 == result2);

    std::cout << "Success!\n";

    return 0;
}
#endif