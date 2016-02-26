#ifndef CP5_ex13_11_h
#define CP5_ex13_11_h

#include <string>
#include <iostream>

class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(const HasPtr &hp)
	{
		auto new_p = new std::string(*hp.ps);
		delete ps;
		ps = new_p;
		i = hp.i;
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}

	void show() { std::cout << *ps << std::endl; }
private:
	std::string *ps;
	int i;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

#endif