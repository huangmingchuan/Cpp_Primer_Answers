#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sum_of_int(const vector<string>& v)
{
	int sum = 0;
	for (auto i : v)
	{
		sum += stoi(i);
	}
	return sum;
}

float sum_of_float(const vector<string>& v)
{
	float sum = 0;
	for (auto i : v)
	{
		sum += stof(i);
	}
	return sum;
}

int main()
{
	vector<string> v = { "1", "2", "3", "4.5" };
	cout << sum_of_int(v) << endl;
	cout << sum_of_float(v) << endl;
	return 0;
}