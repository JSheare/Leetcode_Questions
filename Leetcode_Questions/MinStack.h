#ifndef MINSTACK_H
#define MINSTACK_H

#include <stack>

class MinStack
{
public:
    MinStack() {}
    void push(int val);
    void pop();
    int top();
    int getMin();

private:
    std::stack<int> main;
    std::stack<int> min;  // Essentialy a record of what the min value is at each main stack entry
};
#endif
