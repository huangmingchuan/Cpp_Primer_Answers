#include <iostream>
#include <string>

int fact(int i)
{
	return i > 1 ? i * fact(i - 1) : 1;
}

void interactive_fact()
{
	std::string const prompt = "Enter a number within [1, 13) :\n";
	std::string const out_of_range = "Out of range, please try again.\n";
	for (int i; std::cout << prompt, std::cin >> i;)
	{
		if (i < 1 || i > 12)
		{
			std::cout << out_of_range;
			continue;
		}
		std::cout << fact(i) << std::endl;
	}
}

int main()
{
	interactive_fact();
	return 0;
}