#include <iostream>
#include <vector>

using namespace std;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main()
{
	int func(int, int);
	vector<decltype(func)*> v;
	v.push_back(add);
	v.push_back(subtract);
	v.push_back(multiply);
	v.push_back(divide);
	
	for (auto i : v)
	{
		cout << i(6, 2) << ", "; // 8, 4, 12, 3
	}
	cout << endl;
	return 0;
}