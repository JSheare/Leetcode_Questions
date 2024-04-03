#ifndef MINSTACK_H
#define MINSTACK_H

#include <stack>

class MinStack
{
    std::stack<int> main;
    std::stack<int> min;  // Essentialy a record of what the min value is at each main stack entry
public:
    MinStack()
    {}

    void push(int val)
    {
        if (min.empty() || val < min.top())
            min.push(val);
        else
            min.push(min.top());

        main.push(val);
    }

    void pop()
    {
        min.pop();
        main.pop();
    }

    int top()
    {
        return main.top();
    }

    int getMin()
    {
        return min.top();
    }
};
#endif
