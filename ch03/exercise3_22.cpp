#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int main()
{
	vector<string> text;
	text.push_back("aaaaaaaaaa aaaaaaaaa aaaaaa");
	text.push_back("");
	text.push_back("bbbbbbbbbbbbbb bbbbbbbbbbb bbbbbbbbbbbbb");

	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
	{
		for (auto &c : *it)
		{
			if (isalpha(c)) c = toupper(c);
		}
	}

	for (auto it : text)
	{
		cout << it << endl;
	}
	return 0;
}