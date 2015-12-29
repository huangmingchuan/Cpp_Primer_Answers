#include <iostream>
#include <vector>

using namespace std;

using Iter = vector<int>::const_iterator;

#define NDEBUG

void print(Iter first, Iter last)
{
#ifndef NDEBUG
	cout << "vector size: " << last - first << endl;
#endif
	if (first == last)
	{
		cout << "over!" << endl;
		return;
	}
	cout << *first << " ";
	print(++first, last);

}

int main()
{
	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print(vec.cbegin(), vec.cend());

	return 0;
}