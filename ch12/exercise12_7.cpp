#include <iostream>
#include <vector>
#include <memory>

using std::vector;

std::shared_ptr<vector<int>> alloc_vector()
{
	return std::make_shared<vector<int>>();
}

void assign_vector(std::shared_ptr<vector<int>> p)
{
	int i;
	while (std::cin >> i)
	{
		p->push_back(i);
	}
}

void print_vector(std::shared_ptr<vector<int>> p)
{
	for (auto i : *p)
	{
		std::cout << i << std::endl;
	}
}

int main()
{
	auto p = alloc_vector();
	assign_vector(p);
	print_vector(p);
	return 0;
}