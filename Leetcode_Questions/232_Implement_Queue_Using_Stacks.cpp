#include <iostream>
#include <assert.h>
#include <stack>

class MyQueue
{
private:
    std::stack<int> input;
    std::stack<int> output;

public:
    MyQueue()
    {}

    void push(int x)
    {
        this->input.push(x);
    }

    int pop()
    {
        if (this->output.empty())
            switchStack(this->input, this->output);

        int x{ this->output.top() };
        this->output.pop();
        return x;
    }

    int peek()
    {
        if (this->output.empty())
            switchStack(this->input, this->output);

        return this->output.top();
    }

    bool empty()
    {
        return this->input.empty() && this->output.empty();
    }

private:
    void switchStack(std::stack<int>& stack1, std::stack<int>& stack2)
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
};

#if 0
int main()
{
    // Provided test case
    MyQueue queue{};
    queue.push(1);
    queue.push(2);
    assert(queue.peek() == 1);
    assert(queue.pop() == 1);
    assert(queue.empty() == false);

    std::cout << "Success!\n";

	return 0;
}
#endif