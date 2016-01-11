#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

int main()
{
	std::vector<int> vec{ 1, 1, 3, 3, 5, 5, 7, 7, 9 };
	std::list<int> lst;

	std::unique_copy(vec.begin(), vec.end(), back_inserter(lst));
	for (auto i : lst)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}