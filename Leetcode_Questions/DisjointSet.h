#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <unordered_map>

template <typename T>
class DisjointSet
{
private:
	std::unordered_map<T, T> representatives;
	std::unordered_map<T, int> ranks;

public:
	DisjointSet()
	{}

	void addSet(T element)
	{
		representatives[element] = element;
		ranks[element] = 1;
	}

	// Path-compressed find
	T find(T element)
	{
		if (representatives[element] == element)
			return element;

		representatives[element] = find(representatives[element]);
		return representatives[element];
	}

	// Union by rank
	void unionSets(T element1, T element2)
	{
		T root1{ find(element1) };
		T root2{ find(element2) };
		if (root1 != root2)
		{
			if (ranks[root1] > ranks[root2])
				representatives[root2] = root1;
			else if (ranks[root2] > ranks[root1])
				representatives[root1] = root2;
			else
			{
				representatives[root2] = root1;
				++ranks[root1];
			}
		}
	}

	bool isConnected(T element1, T element2)
	{
		if (find(element1) == find(element2))
			return true;

		return false;
	}

};
#endif
