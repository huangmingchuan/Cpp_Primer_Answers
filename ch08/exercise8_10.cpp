#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::vector; using std::string; using std::ifstream; using std::istringstream; using std::cout; using std::endl; using std::cerr;

int main()
{
	ifstream ifs("E:/code/cpp_primer_answer/Cpp_Primer_Answers/data/books.txt");
	if (!ifs)
	{
		cerr << "No data?" << endl;
		return -1;
	}

	vector<string> vecLine;
	string line;
	while (getline(ifs, line))
		vecLine.push_back(line);

	for (auto &s : vecLine)
	{
		istringstream iss(s);
		string word;
		while (iss >> word)
			cout << word << ", ";
		cout << endl;
	}

	return 0;
}