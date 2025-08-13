#include <unordered_map>
#include <stack>
#include <algorithm>

#include "FreqStack.h"

FreqStack::FreqStack()
{}

void FreqStack::push(int val)
{
	maxFreq = std::max(maxFreq, ++freq[val]);
	stacks[freq[val]].push(val);
}

int FreqStack::pop()
{
	int top{ stacks[maxFreq].top() };
	stacks[maxFreq].pop();
	if (stacks[freq[top]--].empty())
		--maxFreq;
	
	return top;
}