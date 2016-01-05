#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	std::cout << v.at(0);       
	std::cout << v[0];        
	std::cout << v.front();    
	std::cout << *v.begin();   
	return 0;
}