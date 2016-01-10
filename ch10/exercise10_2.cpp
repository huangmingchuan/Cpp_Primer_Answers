#include <iostream>
#include <string>
#include <algorithm>
#include <list>


int main()
{
	std::list<std::string> l = { "aa", "aaa", "aa", "cc" };
	std::cout << std::count(l.cbegin(), l.cend(), "aa") << std::endl;

	return 0;
}