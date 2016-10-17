#include <iostream>
#include <string>

using namespace std;

int main()
{
	string numbers("0123456789");
	string s("ab2c3d7R4E6");

	cout << "numeric characters: ";
	for (int pos = 0; (pos = s.find_first_of(numbers, pos)) != string::npos; ++pos)
	{
		cout << s[pos] << " ";
	}

	cout << "\nalphabetic characters: ";
	for (int pos = 0; (pos = s.find_first_not_of(numbers, pos)) != string::npos; ++pos)
	{
		cout << s[pos] << " ";
	}

	return 0;

}
