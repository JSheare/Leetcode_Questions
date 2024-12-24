#ifndef GRAPH_H
#define GRAPH_H

#include <initializer_list>
#include <queue>
#include <unordered_map>
#include <vector>

#include "Node.h"

class Graph
{
public:
	int maxVal{ 0 };
	std::unordered_map<int, Node*> nodes;

	Graph() {};
	// Adjacency list constructor
	Graph(std::initializer_list<std::vector<int>> adjacency);
	~Graph();
	// If you use this, the graph no longer assumes responsibility for deallocating the memory its nodes occupy
	Node* getNode(int val);
	// Adds the provided node to the graph and then adds any other nodes found via a bfs
	void addNodes(Node* node);
	bool operator==(Graph& graph2);
	friend std::ostream& operator<<(std::ostream& out, Graph& graph);
};
#endif