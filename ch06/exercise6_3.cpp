#include <iostream>

int fact(int i)
{
	return i > 1 ? i * fact(i - 1) : 1;
}

int main()
{
	std::cout << fact(5) << std::endl;
	return 0;
}