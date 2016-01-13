#include <map>
#include <set>
#include <string>
#include <iostream>

using std::string;

int main()
{
	std::multimap<string, string> authors{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency" } };
	std::map<string, std::multiset<string>> order_authors;

	for (const auto &author : authors)
		order_authors[author.first].insert(author.second);

	for (const auto &author : order_authors)
	{
		std::cout << author.first << ": ";
		for (const auto &work : author.second)
			std::cout << work << " ";
		std::cout << std::endl;
	}

	return 0;
}