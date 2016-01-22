#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

int main()
{
	std::ifstream file("H:/code/C++/Cpp_Primer_Answers/data/storyDataFile.txt");
	vector<string> input;
	std::map<string, std::set<decltype(input.size())>> dictionary;
	decltype(input.size()) lineNo{ 0 };

	for (string line; std::getline(file, line); ++lineNo)
	{
		input.push_back(line);
		std::istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear())
		{
			std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			dictionary[word].insert(lineNo);
		}
	}

	while (true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(std::cin >> s) || s == "q") break;
		auto found = dictionary.find(s);
		if (found != dictionary.end())
		{
			std::cout << s << " occurs " << found->second.size() << (found->second.size() > 1 ? " times" : " time") << std::endl;
			for (auto i : found->second)
				std::cout << "\t(line " << i + 1 << ") " << input.at(i) << std::endl;
		}
		else std::cout << s << " occurs 0 time" << std::endl;
	}
}