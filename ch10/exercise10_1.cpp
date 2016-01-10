#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 6, 6, 2 };
	std::cout << std::count(v.cbegin(), v.cend(), 6) << std::endl;

	return 0;
}