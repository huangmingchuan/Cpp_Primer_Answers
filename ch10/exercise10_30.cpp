#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	vector<int> v;
	istream_iterator<int> int_it(cin), int_eof;

	copy(int_it, int_eof, back_inserter(v));
	sort(v.begin(), v.end());

	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	return 0;
}