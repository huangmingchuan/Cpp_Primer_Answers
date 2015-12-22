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

	for (int i = 0; i < ivec.size() - 1; ++i)
	{
		cout << ivec[i] + ivec[i + 1] << endl;
	}
	
	//---------------------------------
	cout << "---------------------------------" << endl;
	
	int m = 0;
	int n = ivec.size() - 1;
	while (m < n)
	{
		cout << ivec[m] + ivec[n] << endl;
		++m;
		--n;
	}
	return 0;
}