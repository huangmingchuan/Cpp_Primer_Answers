#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::make_pair;
using std::pair;
using std::vector;
using std::map;

class Families
{
public:
	using Child = pair<string, string>;
	using Children = vector<Child>;
	using Data = map<string, Children>;

	void add(string const& last_name, string const& first_name, string birthday)
	{
		auto child = make_pair(first_name, birthday);
		_data[last_name].push_back(child);
	}

	void print() const
	{
		for (auto const& pair : _data)
		{
			cout << pair.first << ":\n";
			for (auto const& child : pair.second)
				cout << child.first << " " << child.second << endl;
			cout << endl;
		}
	}

private:
	Data _data;
};

int main()
{
	Families families;
	auto msg = "Please enter last name, first name and birthday:\n";
	for (string l, f, b; cout << msg, cin >> l >> f >> b; families.add(l, f, b));
	families.print();

	return 0;
}