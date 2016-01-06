#include <iostream>
#include <string>

using namespace std;

void replace(string& s, const string& oldVal, const string& newVal)
{
	auto curr = s.begin();
	while (curr != s.end() - oldVal.size())
	{
		if (oldVal == string(curr, curr + oldVal.size()))
		{
			curr = s.erase(curr, curr + oldVal.size());
			curr = s.insert(curr, newVal.begin(), newVal.end());
			curr += newVal.size();
		}
		else
		{
			++curr;
		}
	}
}

int main()
{
	string s("To drive straight thru is a foolish, tho courageous act.");
	replace(s,"tho","though");
	replace(s, "thru", "through");

	cout << s;
}