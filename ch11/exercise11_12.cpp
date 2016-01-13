#include <vector>
#include <utility>
#include <string>
#include <iostream>

int main()
{
	std::vector<std::pair<std::string, int>> vec;
	std::string str;
	int i;
	while (std::cin >> str >> i)
		vec.push_back(std::pair<std::string, int>(str, i));

	for (const auto &p : vec)
		std::cout << p.first << ":" << p.second << std::endl;
}