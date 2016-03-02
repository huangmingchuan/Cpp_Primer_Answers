#include <iostream>
#include <string>

#include "exercise15_5.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"

class Base
{
public:
	void pub_mem();   // public member
protected:
	int prot_mem;     // protected member
private:
	char priv_mem;    // private member
};

struct Pub_Derv : public    Base
{
	void memfcn(Base &b) { b = *this; }
};
struct Priv_Derv : private   Base
{
	void memfcn(Base &b) { b = *this; }
};
struct Prot_Derv : protected Base
{
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
	void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private : public Priv_Derv
{
	//void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Protected : public Prot_Derv
{
	void memfcn(Base &b) { b = *this; }
};

int main()
{
	Pub_Derv d1;
	Base *p = &d1;

	Priv_Derv d2;
	//p = &d2;

	Prot_Derv d3;
	//p = &d3;

	Derived_from_Public dd1;
	p = &dd1;

	Derived_from_Private dd2;
	//p =& dd2;

	Derived_from_Protected dd3;
	//p = &dd3;


	return 0;
}