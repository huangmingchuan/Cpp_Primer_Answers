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
        if (!result.empty())
            result += " ";
		result += s;
	}
	cout << result << endl;

	return 0;
}