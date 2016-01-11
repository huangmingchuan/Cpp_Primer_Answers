#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto it = v.crbegin(); it != v.crend(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}