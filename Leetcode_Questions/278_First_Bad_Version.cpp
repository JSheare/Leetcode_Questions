#include <iostream>
#include <assert.h>
#include <functional>

bool bad1(int version)
{
	return version >= 4;
}

bool bad2(int version)
{
	return version >= 1;
}

int firstBadVersion(int n, std::function<bool(int)> isBadVersion)
{
    int low{ 0 };
    int high{ n };
    while (low <= high)
    {
        int mid{ low + (high - low) / 2 };
        if (isBadVersion(mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

#if 0
int main()
{
	// Provided test cases
    assert(firstBadVersion(5, &bad1) == 4);

    assert(firstBadVersion(1, &bad2) == 1);

	std::cout << "Success!\n";

	return 0;
}
#endif