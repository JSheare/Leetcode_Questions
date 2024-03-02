#include <iostream>
#include <assert.h>
#include <string>
#include <stack>

bool isValid(std::string s)
{
	if (s.length() < 2)
		return false;

	std::stack<char> brackets;
	for (char bracket : s)
	{
		if (bracket == '(' || bracket == '{' || bracket == '[')
			brackets.push(bracket);
		else
		{
			if (brackets.empty())
				return false;
			else if (
				(bracket == ')' && brackets.top() != '(') ||
				(bracket == '}' && brackets.top() != '{') ||
				(bracket == ']' && brackets.top() != '['))
				return false;

			brackets.pop();
		}
	}

	return brackets.empty();
}

#if 0
int main()
{
	// Provided test cases
	std::string test1{ "()" };
	bool answer1{ true };
	assert(answer1 == isValid(test1));

	std::string test2{ "()[]{}" };
	bool answer2{ true };
	assert(answer2 == isValid(test2));

	std::string test3{ "(]" };
	bool answer3{ false };
	assert(answer3 == isValid(test3));

	std::cout << "Success!\n";

	return 0;
}
#endif