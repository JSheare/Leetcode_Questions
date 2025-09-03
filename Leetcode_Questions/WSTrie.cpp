#include "WSTrie.h"

WSTrie::WSTrie()
{
	for (int i{ 0 }; i < 26; ++i)
	{
		children[i] = nullptr;
	}
}

WSTrie::~WSTrie()
{
	for (WSTrie* ptr : children)
	{
		delete ptr;
	}
}