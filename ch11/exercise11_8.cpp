#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<std::string> exclude = { "aa", "bb", "cc", "dd", "ee", "ff" };
	for (std::string word; std::cout << "Enter plz:\n", std::cin >> word;)
	{
		auto is_excluded = std::binary_search(exclude.cbegin(), exclude.cend(), word);
		auto reply = is_excluded ? "excluded" : "not excluded";
		std::cout << reply << std::endl;
	}

	return 0;
}