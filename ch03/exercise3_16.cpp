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
	vector<int> v1;         // size:0,  no values.
	vector<int> v2(10);     // size:10, value:0
	vector<int> v3(10, 42); // size:10, value:42
	vector<int> v4{ 10 };     // size:1,  value:10
	vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
	vector<string> v6{ 10 };  // size:10, value:""
	vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

	cout << "v1 size :" << v1.size() << endl;
	cout << "v2 size :" << v2.size() << endl;
	cout << "v3 size :" << v3.size() << endl;
	cout << "v4 size :" << v4.size() << endl;
	cout << "v5 size :" << v5.size() << endl;
	cout << "v6 size :" << v6.size() << endl;
	cout << "v7 size :" << v7.size() << endl;

	cout << "v1 content: ";
	for (auto i : v1)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v2 content: ";
	for (auto i : v2)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v3 content: ";
	for (auto i : v3)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v4 content: ";
	for (auto i : v4)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v5 content: ";
	for (auto i : v5)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v6 content: ";
	for (auto i : v6)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v7 content: ";
	for (auto i : v7)
	{
		cout << i << " , ";
	}
	cout << endl;
	return 0;
}