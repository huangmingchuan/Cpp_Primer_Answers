#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string result, s;
	while (cin >> s)
	{
		result += s + " ";
	}
	cout << result << endl;

	return 0;
}