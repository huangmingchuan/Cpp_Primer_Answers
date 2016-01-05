#include <iostream>
#include <deque>
#include <list>
using std::deque; using std::list; using std::cout; using std::cin; using std::endl;

int main()
{
	list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	deque<int> odd, even;
	for (auto i : l)
		(i & 0x1 ? odd : even).push_back(i);

	for (auto i : odd) cout << i << " ";
	cout << endl;
	for (auto i : even)cout << i << " ";
	cout << endl;

	return 0;
}