#include <iostream>
#include <cassert>
#include <string>

bool isPalindrome(std::string& s)
{
	int left{ 0 };
	int right{ static_cast<int>(s.length()) - 1 };
	while (left <= right)
	{
		if (!std::isalnum(s[left]))
		{
			++left;
			continue;
		}
		if (!std::isalnum(s[right]))
		{
			--right;
			continue;
		}
		if (std::tolower(s[left]) != std::tolower(s[right]))
		{
			return false;
		}

		++left;
		--right;
	}
	return true;
}

#if 0
int main()
{
	// Provided test cases
	std::string test1{ "A man, a plan, a canal: Panama" };
	bool answer1{ true };
	assert(isPalindrome(test1) == answer1);

	std::string test2{ "race a car" };
	bool answer2{ false };
	assert(isPalindrome(test2) == answer2);

	std::string test3{ " " };
	bool answer3{ true };
	assert(isPalindrome(test3) == answer3);

	std::cout << "Success!\n";


	return 0;
}
#endif