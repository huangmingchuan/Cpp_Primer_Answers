#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto it = std::prev(v.cend()); true; --it)
	{
		std::cout << *it << " ";
		if (it == v.cbegin()) break;
	}
	std::cout << std::endl;

	return 0;
}