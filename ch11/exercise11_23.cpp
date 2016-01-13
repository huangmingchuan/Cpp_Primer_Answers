#include <map>
#include <string>
#include <iostream>

using std::string;
using std::multimap;
using std::cin;
using std::endl;

int main()
{
	multimap<string, string> families;
	for (string lname, cname; cin >> cname >> lname; families.emplace(lname, cname));
	for (auto const& family : families)
		std::cout << family.second << " " << family.first << endl;
}