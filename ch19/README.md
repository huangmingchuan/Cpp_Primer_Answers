## 练习19.1

> 使用 malloc 编写你自己的 operator new(sizt_t)函数，使用 free 编写operator delete(void *)函数。

```cpp
#include <cstdlib>
#include <new>

void *operator new(size_t size)
{
	if(void *mem = malloc(size))
		return mem;
	else
		throw std::bad_alloc();
}

void operator delete(void *mem) noexcept { free(mem); }

int main()
{
	return 0;
}
```
  
## 练习19.2

> 默认情况下，allocator 类使用 operator new 获取存储空间，然后使用 operator delete 释放它。利用上一题中的两个函数重新编译并运行你的 StrVec 程序。

```cpp
#ifndef STRVEC_H_
#define STRVEC_H_

#include <string>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>

void *operator new(size_t size)
{
	std::cout << "void *operator new(size_t size)" << std::endl;
	if(void *mem = malloc(size))
		return mem;
	else
		throw std::bad_alloc();
}

void operator delete(void *mem) noexcept
{
	std::cout << "void operator delete(void *mem) noexcept" << std::endl;
	free(mem);
}

class StrVec
{
friend bool operator==(StrVec &lhs, StrVec &rhs);
friend bool operator!=(StrVec &lhs, StrVec &rhs);
friend bool operator<(StrVec &lhs, StrVec &rhs);
friend bool operator>(StrVec &lhs, StrVec &rhs);
friend bool operator<=(StrVec &lhs, StrVec &rhs);
friend bool operator>=(StrVec &lhs, StrVec &rhs);
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec(StrVec &&s) noexcept : alloc(std::move(s.alloc)), elements(std::move(s.elements)), first_free(std::move(s.first_free)), cap(std::move(s.cap)) { s.elements = s.first_free = s.cap = nullptr; }
	template <typename... Args>
	void emplace_back(Args&&... args);
	StrVec &operator=(const StrVec&);
	StrVec &operator=(StrVec&&) noexcept;
	std::string& operator[](std::size_t n) { return elements[n]; }
	const std::string& operator[](std::size_t n) const { return elements[n]; }
	~StrVec();
	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
	void reserve(size_t n);
	void resize(size_t n);
	void resize(size_t n, const std::string &s);
private:
	std::allocator<std::string> alloc;
	void chk_n_alloc() { if(size() == capacity()) reallocate(); }
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

StrVec::StrVec(std::initializer_list<std::string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename... Args>
inline void StrVec::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*,std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e-b);
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	if(elements)
	{
		std::for_each(elements, first_free, [this](std::string &p){ alloc.destroy(&p); });
		// for(auto p = first_free; p != elements; )
		// 	alloc.destroy(--p);
		alloc.deallocate(elements, cap-elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::reserve(size_t n)
{
	if(n > capacity()) return;
	auto newdata = alloc.allocate(n);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

void StrVec::resize(size_t n)
{
	resize(n,std::string());
}

void StrVec::resize(size_t n, const std::string &s)
{
	if(n < size())
	{
		while(n < size())
			alloc.destroy(--first_free);
	}else if(n > size())
	{
		while(n > size())
			push_back(s);
			// alloc.construct(first_free, s);
	}
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	if(this != &rhs)
	{
		free();
		alloc = std::move(rhs.alloc);
		elements = std::move(rhs.elements);
		first_free = std::move(rhs.first_free);
		cap = std::move(rhs.cap);
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

bool operator==(StrVec &lhs, StrVec &rhs)
{
	return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(StrVec &lhs, StrVec &rhs)
{
	return !(lhs == rhs);
}

bool operator<(StrVec &lhs, StrVec &rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(StrVec &lhs, StrVec &rhs)
{
	return rhs < lhs;
}

bool operator<=(StrVec &lhs, StrVec &rhs)
{
	return !(rhs < lhs);
}

bool operator>=(StrVec &lhs, StrVec &rhs)
{
	return !(lhs < rhs);
}

#endif
```
  
## 练习19.3

> 已知存在如下的类继承体系，其中每个类分别定义了一个公有的默认构造函数和一个析构函数：
```cpp
class A { /* ... */};
class B : public A { /* ... */};
class C : public B { /* ... */};
class D : public B, public A { /* ... */};
```
下面哪个 dynamic_cast 将失败？
```cpp
(a) A *pa = new C;
	B *pb = dynamic_cast<B*>(pa);
(b) B *pb = new B;
	C *pc = dynamic_cast<C*>(pb);
(c) A *pa = new D;
	B *pb = dynamic_cast<B*>(pa);
```

（a）成功；  
（b）失败，pb是指向B的指针，不能转换为指向C的指针；  
（c）失败，A *pa = new D具有二义性。  
  
## 练习19.4

> 使用上一个练习定义的类改写下面的代码，将表达式*pa 转换成类型C&：
```cpp
if (C *pc = dynamic_cast<C*>(pa))
{
	//使用C的成员
} else {
	//使用A的成员
}
```

```cpp
#include <typeinfo>
#include <iostream>

class A
{
public:
	virtual ~A() {}
};

class B : public A
{};

class C : public B
{};

class D : public B, public A
{};

int main(int argc, char const *argv[])
{
	// A *pa = new C;
	// B *pb = dynamic_cast<B*>(pa);
	// if(pb) std::cout << "success" << std::endl;
	// else std::cout << "fail" << std::endl;

	// B *pb = new B;
	// C *pc = dynamic_cast<C*>(pb);
	// if(pc) std::cout << "success" << std::endl;
	// else std::cout << "fail" << std::endl;

	// A *pa = new D;
	// B *pb = dynamic_cast<B*>(pa);
	// if(pb) std::cout << "success" << std::endl;
	// else std::cout << "fail" << std::endl;

	A *pa = new C;
	try{
		const C &c = dynamic_cast<const C&>(*pa);
	}catch(std::bad_cast &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
```
  
## 练习19.5

> 在什么情况下你应该用 dynamic_cast 替代虚函数？

我们想使用基类对象的指针或引用执行某个派生类操作并且该操作不是虚函数，则可以使用RTTI运算符（该类类型应该含有虚函数）。  
  
## 练习19.6

> 编写一条表达式将 Query_base 指针动态转换为 AndQuery 指针。分别使用 AndQuery 的对象以及其他类型的对象测试转换是否有效。打印一条表示类型转换是否成功的信息，确保实际输出的结果与期望的一致。

Query_base为抽象虚类，AndQuery的构造函数为private，暂时没想到方法来实现该题，目前使用19.3的继承体系来验证。  
```cpp
#include <typeinfo>
#include <iostream>

class A
{
public:
	virtual ~A() {}
};

class B : public A
{};

class C : public B
{};

class D : public B, public A
{};

int main(int argc, char const *argv[])
{
	A *pa1 = new C;
    if(C *qc = dynamic_cast<C*>(pa1))
    {
        std::cout << "success" << std::endl;
    }else
    {
        std::cout << "fail" << std::endl;
    }

	A *pa2 = new C;
	try{
		const C &rc = dynamic_cast<const C&>(*pa2);
	}catch(std::bad_cast &e){
		std::cout << e.what() << std::endl;
	}

	C c = C();
	if(typeid(*pa1) == typeid(*pa2)) std::cout << "same type" << std::endl;
	if(typeid(*pa1) == typeid(c)) std::cout << "same type as C" << std::endl;
	if(typeid(*pa1) == typeid(C)) std::cout << "same type as C" << std::endl;

	return 0;
}
```
  
## 练习19.7

> 编写与上一个练习类似的转换，这一次将 Query_base 对象转换为 AndQuery 的引用。重复上面的测试过程，确保转换能正常工作。

详见１9.6。  
  
## 练习19.8

> 编写一条 typeid 表达式检查两个 Query_base 对象是否指向同一种类型。再检查该类型是否是 AndQuery。

详见１9.6。  
  
## 练习19.9

> 编写与本节最后一个程序类似的代码，令其打印你的编译器为一些常见类型所起的名字。如果你得到的输出结果与本书类似，尝试编写一个函数将这些字符串翻译成人们更容易读懂的形式。

```cpp
#include <iostream>
#include <typeinfo>

class Base
{
	friend bool operator==(const Base&, const Base&);
public:
	Base() = default;
	Base(int i_) : i(i_) { }
protected:
	virtual bool equal(const Base&) const;
private:
	int i;
};

class Derived : public Base
{
public:
	Derived() = default;
	Derived(std::string s_, int i_) : s(s_), Base(i_) { }
protected:
	bool equal(const Base&) const;
private:
	std::string s;
};

bool operator==(const Base &lhs, const Base &rhs)
{
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Base::equal(const Base &rhs) const
{
	return this->i == rhs.i;
}

bool Derived::equal(const Base &rhs) const
{
	auto r = dynamic_cast<const Derived&>(rhs);
	return (this->s == r.s) && this->Base::equal(rhs);
}

int main()
{
	Base *pb1 = new Derived();
	Base *pb2 = new Derived();
	Base *pb3 = new Derived("a", 1);
	Base *pb4 = new Base();

	std::cout << std::boolalpha << (*pb1 == *pb2) << std::endl;
	std::cout << std::boolalpha << (*pb1 == *pb3) << std::endl;
	std::cout << std::boolalpha << (*pb1 == *pb4) << std::endl;

	int arr[10];
	Derived d;

	std::cout << typeid(42).name() << ", "
			  << typeid(arr).name() << ", "
			  << typeid(d).name() << ", "
			  << typeid(std::string).name() << ", "
			  << typeid(pb1).name() << ", "
			  << typeid(*pb1).name() << ", "
			  << typeid(*pb3).name() << std::endl;

	return 0;
}
```
```sh
$ ./ex09 true
false
false
i, A10_i, 7Derived, Ss, P4Base, 7Derived, 7Derived
```
  
## 练习19.10

> 已知存在如下的类继承体系，其中每个类定义了一个默认公有的构造函数和一个虚析构函数。下面的语句将打印哪些类型名字？
```cpp
class A { /* ... */ };
class B : public A { /* ... */ };
class C : public B { /*...*/ };
(a) A *pa = new C;
	cout << typeid(pa).name() << endl;
(b) C cobj;
	A& ra = cobj;
	cout << typeid(&ra).name() << endl;
(c) B *px = new B;
	A& ra = *px;
	cout << typeid(ra).name() << endl;
```

（a）P1A；  
（b）P1A；  
（c）1B。  
```cpp
#include <typeinfo>
#include <iostream>

class A
{
public:
	virtual ~A() {}
};

class B : public A
{};

class C : public B
{};

int main(int argc, char const *argv[])
{
	// A *pa = new C;
	// std::cout << typeid(pa).name() << std::endl;

	// C cobj;
	// A &ra = cobj;
	// std::cout << typeid(&ra).name() << std::endl;

	B *px = new B;
	A &ra = *px;
	std::cout << typeid(ra).name() << std::endl;

	return 0;
}
```
  
## 练习19.11

> 普通的数据指针和指向数据成员的指针有何区别？

普通的数据指针指向一个对象；类成员指针指向类的非静态成员。当初始化这样一个指针时，我们令其指向类的某个成员，但是不指定该成员所属的对象；直到使用成员指针时，才提供所属的对象。  
  
## 练习19.12

> 定义一个成员指针，令其可以指向 Screen 类的 cursor 成员。通过该指针获得 Screen::cursor 的值。

```cpp
#include <string>
#include <iostream>

class Screen {
    public:
        using pos = std::string::size_type;

        static const std::string Screen::*data() { return &Screen::contents; }
        static const pos Screen::*pcursor() { return &Screen::cursor; }
        Screen() = default;
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ }

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r*width+c]; }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

int main()
{
    // const std::string Screen::*pdata;
    // pdata = &Screen::contents;
    // auto pdata = &Screen::contents;  //contents is private

    const std::string Screen::*pdata = Screen::data();
    Screen myScreen(2, 2, 'c');
    auto s = myScreen.*pdata;
    std::cout << s << std::endl;

    const std::string::size_type Screen::*pcursor = Screen::pcursor();
    auto i = myScreen.*pcursor;
    std::cout << i << std::endl;

    return 0;
}
```
  
## 练习19.13

> 定义一个类型，使其可以表示指向 Sales_data 类的 bookNo 成员的指针。

```cpp
const std::string Sales_data::*pdata;
```
  
## 练习19.14

> 下面的代码合法吗？如果合法，代码的含义是什么？如果不合法，解释原因。
```cpp
auto pmf = &Screen::get_cursor;
pmf = &Screen::get;
```

不合法，Screen中get_cursor函数返回的为pos类型，get函数返回的为char类型。  
  
## 练习19.15

> 普通函数指针和指向成员函数的指针有何区别？

和普通函数指针不同的是，在成员函数和指向该成员的指针之间不存在自动转换规则。  
  
## 练习19.16

> 声明一个类型别名，令其作为指向 Sales_data 的 avg_price 成员的指针的同义词。

```cpp
using AvgPrice = double (Sales_data::*)() const;
AvgPrice avgprice = &Sales_data::avg_price;
```
  
## 练习19.17

> 为 Screen 的所有成员函数类型各定义一个类型别名。

```cpp
#include <string>
#include <iostream>

class Screen {
    public:
        using pos = std::string::size_type;

        static const std::string Screen::*data() { return &Screen::contents; }
        static const pos Screen::*pcursor() { return &Screen::cursor; }
        Screen() = default;
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ }

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r*width+c]; }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

int main()
{
    Screen myScreen(2, 2, 'c');
    char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
    pmf2 = &Screen::get;
    // char c1 = (myScreen.*pmf2)();
    char c2 = (myScreen.*pmf2)(0, 0);
    std::cout << c2 << std::endl;

    using Get1 = char (Screen::*)() const;
    using Get2 = char (Screen::*)(Screen::pos, Screen::pos) const;
    Get1 get1 = &Screen::get;
    Get2 get2 = &Screen::get;
    std::cout << (myScreen.*get1)() << std::endl;
    std::cout << (myScreen.*get2)(0, 0) << std::endl;

    return 0;
}
```
  
## 练习19.18

> 编写一个函数，使用 count_if 统计在给定的 vector 中有多少个空 string。

```cpp
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int main()
{
	std::vector<std::string> vs = {"a", "bb", "", "ccc", ""};
	std::function<bool (const std::string&)> fcn = &std::string::empty;

	auto it1 = std::find_if(vs.begin(), vs.end(), fcn);
	std::cout << "function: " << it1 - vs.begin() << std::endl;

	auto it2 = std::find_if(vs.begin(), vs.end(), std::mem_fn(&std::string::empty));
	std::cout << "mem_fn: " << it2 - vs.begin() << std::endl;

	auto it3 = std::find_if(vs.begin(), vs.end(), std::bind(&std::string::empty, std::placeholders::_1));
	std::cout << "bind: " << it3 - vs.begin() << std::endl;

	std::cout << "count_if: " << std::count_if(vs.begin(), vs.end(), fcn) << std::endl;

	return 0;
}
```
  
## 练习19.19

> 编写一个函数，令其接受vector<Sales_data>并查找平均价格高于某个值的第一个元素。

Sales_data.h
```cpp
#ifndef SALES_DATA_H_
#define SALES_DATA_H_

#include <string>
#include <stdexcept>

class isbn_mismatch : public std::logic_error
{
public:
	explicit isbn_mismatch(const std::string &s) : std::logic_error(s) { }
	isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs) :
		std::logic_error(s), left(lhs), right(rhs) { }
	const std::string left, right;
};

struct Sales_data;

std::istream &operator>>(std::istream &is, Sales_data &item);
std::ostream &operator<<(std::ostream &os, const Sales_data &item);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

struct Sales_data
{
friend std::istream& operator>>(std::istream&, Sales_data&);
friend std::ostream& operator<<(std::ostream&, const Sales_data&);
friend Sales_data operator+(const Sales_data&, const Sales_data&);
friend bool operator==(const Sales_data&, const Sales_data&);
friend class std::hash<Sales_data>;
public:
	Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n){std::cout << "Sales_data(const std::string &s, unsigned n, double p)" << std::endl;}
	Sales_data() : Sales_data("", 0, 0){std::cout << "Sales_data() : Sales_data(\"\", 0, 0)" << std::endl;}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0){std::cout << "Sales_data(const std::string &s) : Sales_data" << std::endl;}
	Sales_data(std::istream &is) : Sales_data(){/*read(is, *this);*/ is >> *this; std::cout << "Sales_data(std::istream &is) : Sales_data()" << std::endl;}
	std::string isbn() const {return bookNo;}
	Sales_data& operator=(const std::string&);
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);
    // bool higher_avg_price()
    // {
    // 	return this->avg_price() > 10;
    // }
    bool higher_avg_price(double ref_price)
    {
    	return this->avg_price() > ref_price;
    }
private:
	inline double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline double Sales_data::avg_price() const
{
	if(units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::operator=(const std::string &s)
{
	*this = Sales_data(s);
	return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	if(isbn() != rhs.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

Sales_data& Sales_data::operator-=(const Sales_data &rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;

	return *this;
}

std::istream &operator>>(std::istream &is, Sales_data &item)
{
	double price = 0;

	is >> item.bookNo >> item.units_sold >> price;
	if(is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();

	return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();

	return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;

	return sum;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() && 
		lhs.units_sold == rhs.units_sold && 
		lhs.revenue == rhs.revenue;
}

#endif
```
  
## 练习19.20

> 将你的 QueryResult 类嵌套在 TextQuery 中，然后重新运行12.3.2节中使用了 TextQuery 的程序。

```cpp
#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <set>
#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "StrBlob.h"

namespace chapter10
{
	class TextQuery
	{
	public:
		class QueryResult;
		using line_no = std::vector<std::string>::size_type;
		TextQuery(std::ifstream&);
		QueryResult query(const std::string&) const;
	private:
		StrBlob file;
		std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map;
	};

	class TextQuery::QueryResult
	{
		friend std::ostream& print(std::ostream&, const QueryResult&);
	public:
		QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, StrBlob f) : sought(s), lines(p), file(f) { }
		std::set<StrBlob::size_type>::iterator begin() const { return lines->begin(); }
		std::set<StrBlob::size_type>::iterator end() const { return lines->end(); }
		// std::shared_ptr<StrBlob> get_file() const { return std::make_shared<StrBlob>(file); }
		const StrBlob& get_file() const { return file; }
	private:
		std::string sought;
		std::shared_ptr<std::set<line_no>> lines;
		StrBlob file;
	};

	TextQuery::TextQuery(std::ifstream &ifs)
	{
		std::string text_line;

		while(std::getline(ifs, text_line))
		{
			file.push_back(text_line);
			int line_number = file.size() - 1;
			std::istringstream line(text_line);
			std::string text_word;
			while(line >> text_word)
			{
				std::string word;
				std::copy_if(text_word.begin(), text_word.end(), std::back_inserter(word), isalpha);
				// std::cout << word << std::endl;
				auto &wm_lines = word_map[word];
				if(!wm_lines)
					wm_lines.reset(new std::set<line_no>);
				wm_lines->insert(line_number);
			}
		}
	}

	TextQuery::QueryResult TextQuery::query(const std::string &sought) const
	{
		static std::shared_ptr<std::set<TextQuery::line_no>> nodata(new std::set<TextQuery::line_no>);
		auto loc = word_map.find(sought);
		if(loc == word_map.end())
			return QueryResult(sought, nodata, file);
		else
			return QueryResult(sought, loc->second, file);
	}

	std::ostream &print(std::ostream &os, const TextQuery::QueryResult &qr)
	{
		os << qr.sought << " occurs " << qr.lines->size() << " " /*<< make_plural(qr.lines->size(), "time", "s")*/ << std::endl;
		for(auto num : *qr.lines)
		{
			ConstStrBlobPtr p(qr.file, num);
			os << "\t(line " << num + 1 << ") " << p.deref() << std::endl;
		}
			
		return os;
	}
}

#endif
```
  
## 练习19.21

> 编写你自己的 Token 类。

```cpp
#include <string>
#include "Sales_data.h"
#include <iostream>

class Token
{
public:
	Token() : tok(INT), ival{0} { std::cout << "Token() : tok(INT), ival{0}" << std::endl; }
	Token(const Token &t) : tok(t.tok) { std::cout << "Token(const Token &t) : tok(t.tok)" << std::endl; copyUnion(t); }
	Token &operator=(const Token&);
	Token(Token &&t) noexcept : tok(t.tok)
	{
		std::cout << "Token(Token &&t) noexcept : tok(t.tok)" << std::endl;
		switch(t.tok)
		{
			case INT: ival = t.ival;break;
			case DBL: dval = t.dval;break;
			case CHAR: cval = t.cval;break;
			case STR: sval = t.sval;break;
			case SD: sdval = t.sdval;break;
		}
	}
	Token &operator=(Token&&) noexcept;
	~Token() { if(tok == STR) sval.std::string::~string(); }
	Token &operator=(const std::string&);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
	Token &operator=(const Sales_data &sd);
private:
	enum{INT, CHAR, DBL, STR, SD} tok;
	union{
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sdval;
	};
	void copyUnion(const Token&);
};

Token &Token::operator=(int i)
{
	std::cout << "Token &Token::operator=(int i)" << std::endl;
	if(tok == STR) sval.std::string::~string();
	else if(tok == SD) sdval.Sales_data::~Sales_data();
	ival = i;
	tok = INT;
	return *this;
}

Token &Token::operator=(char c)
{
	std::cout << "Token &Token::operator=(char c)" << std::endl;
	if(tok == STR) sval.std::string::~string();
	else if(tok == SD) sdval.Sales_data::~Sales_data();
	cval = c;
	tok = CHAR;
	return *this;
}

Token &Token::operator=(double d)
{
	std::cout << "Token &Token::operator=(double d)" << std::endl;
	if(tok == STR) sval.std::string::~string();
	else if(tok == SD) sdval.Sales_data::~Sales_data();
	dval = d;
	tok = DBL;
	return *this;
}

Token &Token::operator=(const std::string &s)
{
	std::cout << "Token &Token::operator=(const std::string &s)" << std::endl;
	if(tok == SD) sdval.Sales_data::~Sales_data();
	if(tok == STR) sval = s;
	else new(&sval) std::string(s);
	tok = STR;
	return *this;
}

Token &Token::operator=(const Sales_data &sd)
{
	std::cout << "Token &Token::operator=(const Sales_data &sd)" << std::endl;
	if(tok == STR) sval.std::string::~string();
	if(tok == SD) sdval = sd;
	else new(&sval) Sales_data(sd);
	tok = SD;
	return *this;
}

void Token::copyUnion(const Token &t)
{
	switch(t.tok)
	{
		case INT: ival = t.ival;break;
		case DBL: dval = t.dval;break;
		case CHAR: cval = t.cval;break;
		case STR: new(&sval) std::string(t.sval);break;
		case SD: new(&sdval) Sales_data(t.sdval);break;
	}
	
}

Token &Token::operator=(const Token &t)
{
	std::cout << "Token &Token::operator=(const Token &t)" << std::endl;
	if(tok == STR && t.tok != STR) sval.std::string::~string();
	else if(tok == STR && t.tok == STR) sval = t.sval;
	else if(tok == SD && t.tok != SD) sdval.Sales_data::~Sales_data();
	else if(tok == SD && t.tok == SD) sdval = t.sdval;
	else copyUnion(t);
	tok = t.tok;
	return *this;
}

Token &Token::operator=(Token&& t) noexcept
{
	std::cout << "Token &Token::operator=(Token&& t) noexcept" << std::endl;
	tok = t.tok;
	switch(t.tok)
	{
		case INT: ival = t.ival;break;
		case DBL: dval = t.dval;break;
		case CHAR: cval = t.cval;break;
		case STR: sval = t.sval;break;
		case SD: sdval = t.sdval;break;
	}
	return *this;
}

int main()
{
	std::cout << "---------1----------" << std::endl;
	Token s;
	std::cout << "---------2----------" << std::endl;
	Sales_data sales_data1("001-01", 1, 100);
	std::cout << "---------3----------" << std::endl;
	s = sales_data1;
	std::cout << "---------4----------" << std::endl;
	s = std::string("a");
	std::cout << "---------5----------" << std::endl;
	s = Token();
	std::cout << "---------6----------" << std::endl;
	Token s1(std::move(s));
	// Token s1(Token(s));
	std::cout << "---------7----------" << std::endl;

	return 0;
}
```
  
## 练习19.22

> 为你的 Token 类添加一个 Sales_data 类型的成员。

参见19.21。
  
## 练习19.23

> 为你的 Token 类添加移动构造函数和移动赋值运算符。

参见19.21。
  
## 练习19.24

> 如果我们将一个 Token 对象付给它自己将发生什么情况？

参见19.21。
  
## 练习19.25

> 编写一系列赋值运算符，令其分别接收 union 中各种类型的值。

参见19.21。
  
## 练习19.26

> 说明下列声明语句的含义并判断它们是否合法：
```cpp
extern "C" int compute(int *, int);
extern "C" double compute(double *, double);
```
不合法，C语言不支持函数重载。  