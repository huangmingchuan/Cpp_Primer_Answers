#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"


int main()
{
	/**
	* @brief ex15.28   outcome == 9090
	*/
	std::vector<Quote> v;
	for (unsigned i = 1; i != 10; ++i)
		v.push_back(Bulk_quote("sss", i * 10.1, 10, 0.3));

	double total = 0;
	for (const auto& b : v)
	{
		total += b.net_price(20);
	}
	std::cout << total << std::endl;

	std::cout << "======================\n\n";

	/**
	* @brief ex15.29   outccome == 6363
	*/
	std::vector<std::shared_ptr<Quote>> pv;

	for (unsigned i = 1; i != 10; ++i)
		pv.push_back(std::make_shared<Bulk_quote>(Bulk_quote("sss", i * 10.1, 10, 0.3)));

	double total_p = 0;
	for (auto p : pv)
	{
		total_p += p->net_price(20);
	}
	std::cout << total_p << std::endl;

	return 0;

}