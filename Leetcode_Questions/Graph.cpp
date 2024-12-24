#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

#include "Graph.h"
#include "Node.h"

// Makes a graph from an adjacency list
Graph::Graph(std::initializer_list<std::vector<int>> adjacency)
{
	if (adjacency.size() > 0)
	{
		int currentVal{ 1 };
		for (std::vector<int> neighbors : adjacency)
		{
			if (!nodes.count(currentVal))
				nodes[currentVal] = new Node(currentVal);

			Node* currentNode{ nodes[currentVal] };
			for (int newVal : neighbors)
			{
				if (!nodes.count(newVal))
					nodes[newVal] = new Node(newVal);

				currentNode->neighbors.push_back(nodes[newVal]);
			}
			++currentVal;
		}
		maxVal = currentVal - 1;
	}
}

Graph::~Graph()
{
	for (auto element : nodes)
	{
		delete element.second;
	}
}

Node* Graph::getNode(int val)
{
	if (!nodes.count(val))
		return nullptr;

	Node* temp{ nodes[val] };
	nodes.clear();
	return temp;
}

// Adds the provided node to the graph and then adds any other nodes found via a bfs
void Graph::addNodes(Node* node)
{
	if (node)
	{
		nodes[node->val] = node;
		std::queue<Node*> q;
		q.push(node);
		while (!q.empty())
		{
			Node* currentNode{ q.front() };
			q.pop();
			maxVal = std::max(maxVal, currentNode->val);
			for (Node* neighbor : currentNode->neighbors)
			{
				if (!nodes.count(neighbor->val))
				{
					nodes[neighbor->val] = neighbor;
					q.push(neighbor);
				}
			}
		}
	}
}

bool Graph::operator==(Graph& graph2)
{
	if (nodes.size() == 0 && graph2.nodes.size() == 0)
		return true;

	for (auto element : nodes)
	{
		Node* currentNode{ element.second };
		if (!graph2.nodes.contains(currentNode->val))
			return false;

		Node* otherNode{ graph2.nodes[currentNode->val] };
		if (currentNode->neighbors.size() != otherNode->neighbors.size())
			return false;

		std::sort(currentNode->neighbors.begin(), currentNode->neighbors.end(),
			[](Node* a, Node* b) {return a->val > b->val; });
		std::sort(otherNode->neighbors.begin(), otherNode->neighbors.end(),
			[](Node* a, Node* b) {return a->val > b->val; });
		for (int i{ 0 }; i < currentNode->neighbors.size(); ++i)
		{
			if (currentNode->neighbors[i]->val != otherNode->neighbors[i]->val)
				return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, Graph& graph)
{
	out << '[';
	for (int i{ 1 }; i <= graph.maxVal; ++i)
	{
		if (!graph.nodes.count(i))
			out << "[]";
		else
		{
			Node* currentNode{ graph.nodes[i] };
			int numNeighbors{ static_cast<int>(currentNode->neighbors.size()) };
			out << '[';
			for (int j{ 0 }; j < numNeighbors; ++j)
			{
				out << currentNode->neighbors[j]->val;
				if (j != numNeighbors - 1)
					out << ", ";
			}
			out << ']';
		}

		if (i != graph.maxVal)
			out << ", ";
	}
	out << ']';
	return out;
}