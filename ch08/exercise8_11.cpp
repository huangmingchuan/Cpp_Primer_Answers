#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::vector; using std::string; using std::cin; using std::istringstream;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(cin, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	for (auto &p : people)
	{
		std::cout << p.name << " ";
		for (auto &s : p.phones)
			std::cout << s << " ";
		std::cout << std::endl;
	}

	return 0;
}