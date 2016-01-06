#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		cout << "capacity: " << v.capacity() << "  size: " << v.size() << endl;
		v.push_back(i);
	}
	return 0;
}