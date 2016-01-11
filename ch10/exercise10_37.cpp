#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> l;

	copy(v.crbegin() + 3, v.crbegin() + 8, back_inserter(l));

	for (auto i : l) std::cout << i << " ";
	cout << endl;
	return 0;
}