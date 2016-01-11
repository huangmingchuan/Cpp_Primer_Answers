#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using std::string;

int main()
{
	std::ifstream ifs("H:/code/C++/Cpp_Primer_Answers/data/books.txt");
	std::istream_iterator<string> in(ifs), eof;
	std::vector<string> vec;
	std::copy(in, eof, back_inserter(vec));

	std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<string>(std::cout, "\n"));
	return 0;
}