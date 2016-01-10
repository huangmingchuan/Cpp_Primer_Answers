
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "exercise7_26.h"    

inline bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
	return sd1.isbn().size() < sd2.isbn().size();
}

int main()
{
	Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
	std::vector<Sales_data> v{ d1, d2, d3, d4, d5 };

	std::sort(v.begin(), v.end(), compareIsbn);

	for (const auto &element : v)
		std::cout << element.isbn() << " ";
	std::cout << std::endl;

	return 0;
}