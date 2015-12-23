#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<int> ivec;
	int i;
	while (cin >> i)
	{
		ivec.push_back(i);
	}

	for (auto it = ivec.begin(); it != ivec.end() - 1; ++it)
	{
		cout << *it + *(it + 1) << endl;
	}

	//---------------------------------
	cout << "---------------------------------" << endl;

	auto it1 = ivec.begin();
	auto it2 = ivec.end() - 1;
	while (it1 < it2)
	{
		cout << *it1 + *it2 << endl;
		++it1;
		--it2;
	}
	return 0;
}