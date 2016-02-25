#ifndef ex13_27_h
#define ex13_27_h

#include <string>

class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) :ps(new std::string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr& hp) :ps(hp.ps), use(hp.use), i(hp.i) { ++*use; }
	HasPtr& operator=(const HasPtr& rhs)
	{
		++*rhs.use;
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}
	~HasPtr()
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}
private:
	std::string *ps;
	int i;
	size_t *use;
};

#endif