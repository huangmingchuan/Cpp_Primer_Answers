#ifndef ex13_11_h
#define ex13_11_h

#include <string>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(const HasPtr &hp)
	{
		std::string *new_ps = new std::string(*hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}
private:
	std::string *ps;
	int i;
};

#endif // !ex13_11_h
