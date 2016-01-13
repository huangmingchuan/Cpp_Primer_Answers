#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

void word_transform(ifstream&, ifstream&);
unordered_map<string, string> buildMap(ifstream&);
string transform(const string&, unordered_map<string, string>&);

int main()
{
	ifstream ifs_rules("H:/code/C++/Cpp_Primer_Answers/data/transform_rules.txt");
	ifstream ifs_txt("H:/code/C++/Cpp_Primer_Answers/data/for_transform.txt");

	word_transform(ifs_rules, ifs_txt);
	return 0;
}

void word_transform(ifstream& rule_file, ifstream& input)
{
	auto rule_map = buildMap(rule_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, rule_map);
		}
		cout << endl;
	}
}

unordered_map<string, string> buildMap(ifstream& rule_file)
{
	unordered_map<string, string> m;
	string key;
	string value;
	while (rule_file >> key && getline(rule_file, value))
	{
		if (value.size() > 1)
			m[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	}
	return m;
}

string transform(const string& s, unordered_map<string, string>& m)
{
	auto it = m.find(s);
	if (it != m.cend())
		return it->second;
	else
		return s;
}