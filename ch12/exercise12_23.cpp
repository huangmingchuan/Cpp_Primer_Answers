#include <iostream>
#include <string>

using namespace std;

int main()
{
	char *chs = new char[strlen("hello " "world") + 1]();
	strcat(chs, "hello ");
	strcat(chs, "world");
	cout << chs << endl;
	delete[] chs;

	string s1("hello "), s2("world");
	cout << s1 + s2 << endl;
	return 0;
}