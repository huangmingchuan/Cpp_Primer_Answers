#include "exercise12_27.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

TextQuery::TextQuery(ifstream& ifs) : file(new vector<string>)
{
	string text;
	while (getline(ifs, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string& s) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(s);
	if (loc == wm.end())
		return QueryResult(s, nodata, file);
	else
		return QueryResult(s, loc->second, file);
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< "time" << (qr.lines->size() > 1 ? "s" : "") << endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}