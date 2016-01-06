#include <iostream>
#include <string>

std::string add_pre_and_suffix(std::string name, std::string const& pre, std::string const& su)
{
	name.insert(0, pre);
	name.insert(name.size(), su);
	return name;
}

int main()
{
	std::string name("Huang");
	std::cout << add_pre_and_suffix(name, "Mr.", " Jr.");
	return 0;
}