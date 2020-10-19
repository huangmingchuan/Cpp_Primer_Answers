#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string s = "this is a string";

	for (auto &x : s)
	{
		x = 'X';
	}

	cout << s << endl;
	return 0;
}
