#include <iostream>
#include <cassert>
#include <unordered_map>
#include <queue>

#include "Node.h"
#include "Graph.h"

Node* cloneGraph(Node* node)
{
    if (!node)
        return nullptr;

    std::unordered_map<int, Node*> clones;
    std::queue<Node*> q;
    clones[node->val] = new Node(node->val);
    q.push(node);
    while (!q.empty())
    {
        Node* currentNode{ q.front() };
        q.pop();
        Node* currentClone{ clones[currentNode->val] };
        for (Node* neighbor : currentNode->neighbors)
        {
            if (!clones.count(neighbor->val))
            {
                clones[neighbor->val] = new Node(neighbor->val);
                q.push(neighbor);
            }
            currentClone->neighbors.push_back(clones[neighbor->val]);
        }

    }
    return clones[node->val];
}

# if 0
int main()
{
    // Provided test cases
    Graph test1{ {2, 4}, {1, 3}, {2, 4}, {1, 3} };
    Graph answer1{};
    answer1.addNodes(cloneGraph(test1.nodes[1]));
    assert(answer1 == test1);

    Graph test2{ {} };
    Graph answer2{};
    answer2.addNodes(cloneGraph(test2.nodes[1]));
    assert(answer2 == test2);

    assert(cloneGraph(nullptr) == nullptr);

    std::cout << "Success!\n";

	return 0;
}
#endif