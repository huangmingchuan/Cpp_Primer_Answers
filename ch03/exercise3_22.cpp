#修改之前那个输出text第一段的程序，首先把text的第一段全都改成大写形式，然后再输出它。

#include <vector>
#include <iterator>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	vector<string>text;
	text.push_back("aaa bbb ccc ddd eee fff");
	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
	{
		for (auto it2 = it->begin(); !isspace(*it2); ++it2)
			if (isalpha(*it2))
				*it2 = toupper(*it2);
	}
	for (auto it : text)
		cout << it << endl;
	return 0;
}
