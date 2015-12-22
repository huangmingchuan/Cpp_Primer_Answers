#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string s = "this, is. a :string!";
	string result;

	for (auto x : s)
	{
		if (!ispunct(x))
		{
			result += x;
		}
	}
	
	cout << result << endl;
	return 0;
}