#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v(begin(arr), end(arr));

	for (auto i : v) cout << i << " ";
	cout << endl;

	return 0;
}