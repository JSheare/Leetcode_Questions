#include <stack>

#include "MinStack.h"

void MinStack::push(int val)
{
    if (min.empty() || val < min.top())
        min.push(val);
    else
        min.push(min.top());

    main.push(val);
}

void MinStack::pop()
{
    min.pop();
    main.pop();
}

int MinStack::top()
{
    return main.top();
}

int MinStack::getMin()
{
    return min.top();
}