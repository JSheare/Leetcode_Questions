#ifndef FREQSTACK
#define FREQSTACK

#include <unordered_map>
#include <stack>
#include <algorithm>

class FreqStack
{
public:
	FreqStack();
	void push(int val);
	int pop();

private:
	std::unordered_map<int, int> freq;
	std::unordered_map<int, std::stack<int>> stacks;
	int maxFreq{ 0 };
};
#endif
