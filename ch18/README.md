## 练习18.1

> 在下列 throw 语句中异常对象的类型是什么？
```cpp
(a) range_error r("error");
	throw r;
(b) exception *p = &r;
	throw *p;
```

（a）range_error；  
（b）exception。  
throw p，此时抛出的为指向局部对象的指针，我们几乎可以肯定这是一种错误行为。  
  
## 练习18.2

> 当在指定的位置发生了异常时将出现什么情况？
```cpp
void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	int *p = new int[v.size()];
	ifstream in("ints");
	//此处发生异常
}
```

p的内存将不会被释放，会出现内存泄漏。  
  
## 练习18.3

> 要想让上面的代码在发生异常时能正常工作，有两种解决方案。请描述这两种方法并实现它们。

使用shared_ptr；自己写个类来实现。  
```cpp
std::shared_ptr<int> p(new int[v.size()], [](int *p) {delete p});
```
```cpp
struct P {
	int *p = nullptr;
	P(std::size_t n):p(new int[n]){}
	~P()
	{
		delete []p;
	}
};
```
  
## 练习18.4

> 查看图18.1所示的继承体系，说明下面的 try 块有何错误并修改它。
```cpp
try {
	// 使用 C++ 标准库
} catch (exception) {
	// ...
} catch (const runtime_error &re) {
	// ...
} catch (overflow_error eobj) { /* ... */ }
```

应该把继承链最底端的类放在前面，而将继承链最顶端的类放在后面。  
```cpp
try{
	//使用C++标准库
}catch(overflow_error eobj){
	//...
}catch(const runtime_error &re){
	//...
}catch(exception){
	//...
}
```
  
## 练习18.5

> 修改下面的main函数，使其能捕获图18.1所示的任何异常类型：
```cpp
int main(){
	// 使用 C++标准库
}
```
处理代码应该首先打印异常相关的错误信息，然后调用 abort 终止函数。

```cpp
#include <exception>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <typeinfo>

using namespace std;

int main()
{
	try{
		//使用C++标准库
	}catch(bad_cast &r){
		cout << r.what();
		abort();
	}catch(range_error &r){
		cout << r.what();
		abort();
	}catch(underflow_error &r){
		cout << r.what();
		abort();
	}catch(overflow_error &r){
		cout << r.what();
		abort();
	}catch(runtime_error &r){
		cout << r.what();
		abort();
	}catch(length_error &r){
		cout << r.what();
		abort();
	}catch(out_of_range &r){
		cout << r.what();
		abort();
	}catch(invalid_argument &r){
		cout << r.what();
		abort();
	}catch(domain_error &r){
		cout << r.what();
		abort();
	}catch(logic_error &r){
		cout << r.what();
		abort();
	}catch(bad_alloc &r){
		cout << r.what();
		abort();
	}catch(exception &r){
		cout << r.what();
		abort();
	}

	return 0;
}
```
  
## 练习18.6

> 已知下面的异常类型和 catch 语句，书写一个 throw 表达式使其创建的异常对象能被这些catch语句捕获：
```cpp
(a) class exceptionType { };
	catch(exceptionType *pet) { }
(b) catch(...) { }
(c) typedef int EXCPTYPE;
	catch(EXCPTYPE) { }
```

（a）
```cpp
exceptionType *pet;
//...
throw pet;
```
（b）
 可以捕获所有的异常。  
（c）
```cpp
int a;
//...
throw a;
```
  
## 练习18.7

> 根据第16章的介绍定义你自己的Blob 和 BlobPtr，注意将构造函数写成函数try语句块。

```cpp
template <typename T>
Blob<T>::Blob()try :data(std::make_shared<vector<T>()>) {}
catch(const std::bad_alloc &e){
	handle_out_of_memory(e);
}
template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) try :data(make_shared<vector<T>>(il)) {}
catch(const std::bad_alloc &e){
	handle_out_of_memory(e);
}
```
```cpp
template <typename T>
BlobPtr<T>::BlobPtr()try:curr(0){}
catch (const std::bad_alloc& e) {
	handle_out_of_memory(e);
}
template <typename T>
BlobPtr<T>::BlobPtr(Blob<T> &a, size_t sz = 0)try : wptr(a.data), curr(sz) {}
catch (const std::bad_alloc& e) {
	handle_out_of_momory(e);
}
```
  
## 练习18.8

> 回顾你之前编写的各个类，为它们的构造函数和析构函数添加正确的异常说明。如果你认为某个析构函数可能抛出异常，尝试修改代码使得该析构函数不会抛出异常。

略。  
  
## 练习18.9

> 定义本节描述的书店程序异常类，然后为 Sales_data 类重新编写一个复合赋值运算符并令其抛出一个异常。

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
  
ex09.cpp
```cpp
#include <iostream>
#include <string>
#include "Sales_data.h"
#include <unordered_set>
#include <algorithm>
#include <utility>

namespace std
{
	template <>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data &s) const;
	};
	size_t hash<Sales_data>::operator()(const Sales_data &s) const
	{
		return hash<std::string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
	}
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

struct matches
{
	std::vector<Sales_data>::size_type index;
	std::vector<Sales_data>::const_iterator first;
	std::vector<Sales_data>::const_iterator last;
	matches(std::vector<Sales_data>::size_type index_, std::vector<Sales_data>::const_iterator first_, std::vector<Sales_data>::const_iterator last_) : index(index_), first(first_), last(last_) {}
};

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
{
	std::vector<matches> ret;
	for(auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = std::equal_range(it->cbegin(), it->cend(), Sales_data(book), compareIsbn);
		if(found.first != found.second)
			ret.push_back(matches(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

void reportResults(std::istream &in, std::ostream &os, const std::vector<std::vector<Sales_data>> &files)
{
	std::string s;
	while(in >> s)
	{
		auto trans = findBook(files, s);
		if(trans.empty())
		{
			std::cout << s << " not found in any stores" << std::endl;
			continue;
		}
		for(const auto &store : trans)
			os << "store " << store.index << " sales: " << std::accumulate(store.first, store.last, Sales_data(s)) << std::endl;
	}
}

int main()
{
    Sales_data sales_data1("001-01", 1, 100);
    Sales_data sales_data2("001-01", 2, 100);
    Sales_data sales_data3("001-02", 2, 80);

    try{
    	auto sum = sales_data1 + sales_data3;
    }catch(const isbn_mismatch &e){
    	std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << std::endl;
    }
    return 0;
}
```
  
## 练习18.10

> 编写程序令其对两个 ISBN 编号不相同的对象执行 Sales_data 的加法运算。为该程序编写两个不同的版本：一个处理异常，另一个不处理异常。观察并比较这两个程序的行为，用心体会当出现了一个未被捕获的异常时程序会发生什么情况。

程序详见18.9，出现一个未被捕获的异常时，程序将会执行terminate。  
  
## 练习18.11

> 为什么 what 函数不应该抛出异常？

what中如果抛出异常，需要try catch捕获，再调用what，一直循环，直达内存耗尽。  
  
## 练习18.12

> 将你为之前各章练习编写的程序放置在各自的命名空间中。也就是说，命名空间chapter15包含Query程序的代码，命名空间chapter10包含TextQuery的代码；使用这种结构重新编译Query代码实例。

Query.h  
```cpp
#ifndef QUERY_H_
#define QUERY_H_

#include <string>
#include <iostream>
#include "Query_base.h"
#include "WordQuery.h"
#include "TextQuery.h"

namespace chapter15
{
	class Query
	{
		friend Query operator~(const Query&);
		friend Query operator|(const Query&, const Query&);
		friend Query operator&(const Query&, const Query&);
	public:
		Query(const std::string&);
		chapter10::QueryResult eval(const chapter10::TextQuery &t) const { return q->eval(t); }
		std::string rep() const { std::cout << "Query::rep()" << std::endl; return q->rep(); }
	private:
		Query(std::shared_ptr<Query_base> query) : q(query) { std::cout << "Query(std::shared_ptr<Query_base> query)" << std::endl; }
		std::shared_ptr<Query_base> q;
	};

	std::ostream& operator<<(std::ostream &os, const Query &query)
	{
		return os << query.rep();
	}

	inline Query::Query(const std::string &s) : q(new WordQuery(s)) { std::cout << "Query::Query(const std::string &s)" << std::endl; }
}

#endif
```
  
TextQuery.h
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
	class QueryResult;

	class TextQuery
	{
	public:
		using line_no = std::vector<std::string>::size_type;
		TextQuery(std::ifstream&);
		QueryResult query(const std::string&) const;
	private:
		StrBlob file;
		std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map;
	};

	class QueryResult
	{
		friend std::ostream& print(std::ostream&, const QueryResult&);
	public:
		QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, StrBlob f) : sought(s), lines(p), file(f) { }
		std::set<StrBlob::size_type>::iterator begin() const { return lines->begin(); }
		std::set<StrBlob::size_type>::iterator end() const { return lines->end(); }
		// std::shared_ptr<StrBlob> get_file() const { return std::make_shared<StrBlob>(file); }
		const StrBlob& get_file() const { return file; }
	private:
		std::string sought;
		std::shared_ptr<std::set<TextQuery::line_no>> lines;
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

	QueryResult TextQuery::query(const std::string &sought) const
	{
		static std::shared_ptr<std::set<TextQuery::line_no>> nodata(new std::set<TextQuery::line_no>);
		auto loc = word_map.find(sought);
		if(loc == word_map.end())
			return QueryResult(sought, nodata, file);
		else
			return QueryResult(sought, loc->second, file);
	}

	std::ostream &print(std::ostream &os, const QueryResult &qr)
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
  
## 练习18.13

> 什么时候应该使用未命名的命名空间？

在需要在其所在的文件中可见，在其所在的文件外不可见时；  
static只能用于变量与函数，不可用于用户自定义的类型。  
  
## 练习18.14

> 假设下面的operator*声明的是嵌套的命名空间 mathLib::MatrixLib 的一个成员：
```cpp
namespace mathLib {
	namespace MatrixLib {
		class matrix { /* ... */ };
		matrix operator* (const matrix &, const matrix &);
		// ...
	}
}
```
请问你应该如何在全局作用域中声明该运算符？

```cpp
mathLib::MatrixLib::matrix mathLib::MatrixLib::operator*(const matrix&, const matrix&);
```
  
## 练习18.15

> 说明 using 指示与 using 声明的区别。

using指示引入的名字的作用域远比using声明引入的名字的作用域复杂。它具有将命名空间成员提升到包含命名空间本身和using指示的最近作用域的能力。对于using声明来说，我们指示简单地领名字在局部作用域有效。using指示是令整个命名空间的所有内容变得有效。通常情况下，命名空间中会含有一些不能出现在局部作用域的定义，因此using指示一般被看作是出现在最近的外层作用域中。  
  
## 练习18.16

> 假定在下面的代码中标记为“位置1”的地方是对命名空间 Exercise中所有成员的using声明，请解释代码的含义。如果这些using声明出现在“位置2”又会怎样呢？将using声明变为using指示，重新回答之前的问题。
```cpp
namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
//位置1
void main() {
	//位置2
	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;
	++::ivar;
}
```

```cpp
namespace Exercise{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;

using Exercise::ivar;	//1
using Exercise::dvar;
using Exercise::limit;

// using namespace Exercise;	//3

void mainp(){
	// using Exercise::ivar;	//2
	// using Exercise::dvar;
	// using Exercise::limit;

	// using namespace Exercise;	//4

	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;
	++::ivar;
}

int main()
{
	return 0;
}
```
  
## 练习18.17

> 实际编写代码检验你对上一题的回答是否正确。

详见18.16。  

## 练习18.18

> 已知有下面的 swap 的典型定义，当 mem1 是一个 string 时程序使用 swap 的哪个版本？如果 mem1 是 int 呢？说明在这两种情况下名字查找的过程。
```cpp
void swap(T v1, T v2)
{
	using std::swap;
	swap(v1.mem1, v2.mem1);
	//交换类型的其他成员
}
```

前者使用string版本的swap；后者使用实例化为int的swap。
  
## 练习18.19

> 如果对 swap 的调用形如 std::swap(v1.mem1, v2.mem1) 将会发生什么情况？

将只使用标准库的swap，如果v1.mem1和v2.mem1为用户自定义类型，将无法使用用户定义的针对该类型的swap。
  
## 练习18.20

> 在下面的代码中，确定哪个函数与compute调用匹配。列出所有候选函数和可行函数，对于每个可行函数的实参与形参的匹配过程来说，发生了哪种类型转换？
```cpp
namespace primerLib {
	void compute();
	void compute(const void *);
}
using primerLib::compute;
void compute(int);
void compute(double, double = 3.4);
void compute(char*, char* = 0);
void f()
{
	compute(0);
}
```

候选函数：全部；  
可行函数：  
void compute(int)（最佳匹配）  
void compute(double, double = 3.4)（int->double）  
void compute(char*, char* = 0)（0->nullptr）  
void compute(const void *)（0->nullptr）  
改变后：  
void compute(const void *)为最佳匹配。  
  
## 练习18.21

> 解释下列声明的含义，在它们当作存在错误吗？如果有，请指出来并说明错误的原因。
```cpp
(a) class CADVehicle : public CAD, Vehicle { ... };
(b) class DbiList : public List, public List { ... };
(c) class iostream : public istream, public ostream { ... };
```

（a）CADVehicle公开继承了CAD，私有继承了Vehicle；  
（b）重复继承；  
（c）iostream公开继承了istream和ostream。  
  
## 练习18.22

> 已知存在如下所示的类的继承体系，其中每个类都定义了一个默认构造函数：
```cpp
class A { ... };
class B : public A { ... };
class C : public B { ... };
class X { ... };
class Y { ... };
class Z : public X, public Y { ... };
class MI : public C, public Z { ... };
```
对于下面的定义来说，构造函数的执行顺序是怎样的？
```cpp
MI mi;
```

A->B->C->X->Y->Z->MI。
  
## 练习18.23

> 使用练习18.22的继承体系以及下面定义的类 D，同时假定每个类都定义了默认构造函数，请问下面的哪些类型转换是不被允许的？
```cpp
class D : public X, public C { ... };
p *pd = new D;
(a) X *px = pd;
(b) A *pa = pd;
(c) B *pb = pd;
(d) C *pc = pd;
```

（a）允许；  
（b）允许；  
（c）允许；  
（d）允许。  
  
## 练习18.24

> 在第714页，我们使用一个指向 Panda 对象的 Bear 指针进行了一系列调用，假设我们使用的是一个指向 Panda 对象的 ZooAnimal 指针将会发生什么情况，请对这些调用语句逐一进行说明。

pe->print() 正确；  
pe->highlight() 错误；  
pe->toes() 错误；  
pe->duddle() 错误；  
delete pe 正确。  
  
## 练习18.25

> 假设我们有两个基类 Base1 和 Base2，它们各自定义了一个名为 print 的虚成员和一个虚析构函数。从这两个基类中文名派生出下面的类，它们都重新定义了 print 函数：
```cpp
class D1 : public Base1 { /* ... */};
class D2 : public Base2 { /* ... */};
class MI : public D1, public D2 { /* ... */};
```
通过下面的指针，指出在每个调用中分别使用了哪个函数：
```cpp
Base1 *pb1 = new MI;
Base2 *pb2 = new MI;
D1 *pd1 = new MI;
D2 *pd2 = new MI;
(a) pb1->print();
(b) pd1->print();
(c) pd2->print();
(d) delete pb2;
(e) delete pd1;
(f) delete pd2;
```

```cpp
struct Base1 {
	void print(int) const;
protected:
	int ival;
	double dval;
	char cval;
private:
	int *id;
};
struct Base2 {
	void print(double) const;
protected:
	double fval;
private:
	double dval;
};
struct Derived : public Base1 {
	void print(std::string) const;
protected:
	std::string sval;
	double dval;
};
struct MI : public Derived, public Base2 {
	void print(std::vector<double>);
protected:
	int *ival;
	std::vector<double> dvec;
};
```

（a）MI::print()；  
（b）MI::print()；  
（c）MI::print()；  
（d）MI析构函数（会依次调用基类析构函数）；  
（e）MI析构函数（会依次调用基类析构函数）；  
（f）MI析构函数（会依次调用基类析构函数）。  
  
## 练习18.26

> 已知如上所示的继承体系，下面对print的调用为什么是错误的？适当修改MI，令其对print的调用可以编译通过并正确执行。
```cpp
MI mi;
mi.print(42);
```

没有匹配的print调用，当注释void print(std;:vector<double>)时又会出现二义性；故为该函数定义一个新版本。  
```cpp
#include <iostream>
#include <vector>
struct Base1{
    void print(int) const{
        std::cout<<"Base1 Print Used"<<std::endl;
        };
protected:
        int ival;
        double dval;
        char cval;
private:
        int *id;
};
struct Base2 {
    void print(double) const;
protected:
    double fval;
private:
    double dval;
};

struct Derived : public Base1 {
void print(std::string) const;
protected:
    std::string sval;
    double dval;
};

struct MI : public Derived, public Base2{

void print(std::vector<double>){};
void print(int x){
    Base1::print(x);
}
protected:
    int *ival;
    std::vector<double> dvec;
};

using namespace std;

int main()
{
    MI mi;
    mi.print(42);
    return 0;
}
```
  
## 练习18.27

> 已知如上所示的继承体系，同时假定为MI添加了一个名为foo的函数：
```cpp
int ival;
double dval;
void MI::foo(double cval)
{
	int dval;
	//练习中的问题发生在此处
}
(a) 列出在MI::foo中可见的所有名字。
(b) 是否存在某个可见的名字是继承自多个基类的？
(c) 将Base1的dval成员与Derived 的dval 成员求和后赋给dval的局部实例。
(d) 将MI::dvec的最后一个元素的值赋给Base2::fval。
(e) 将从Base1继承的cval赋给从Derived继承的sval的第一个字符。
```

（a）Base1中，ival、dval、cval、print；  
Base2中，fval、print；  
Derived中，sval、dval、print；  
MI中，ival、dvec、print、foo。  
（b）存在，ival、dval、print。  
（c）（d）（e）如下所示。  
```cpp
#include <iostream>
#include <vector>
struct Base1{
    void print(int) const{
        std::cout<<"Base1 Print Used"<<std::endl;
        };
protected:
        int ival;
        double dval;
        char cval = 'b';
private:
        int *id;
};
struct Base2 {
    void print(double) const;
protected:
    double fval;
private:
    double dval;
};

struct Derived : public Base1 {
void print(std::string) const;
protected:
    std::string sval = "aaa";
    double dval;
};

struct MI : public Derived, public Base2{

void print(std::vector<double>){};
void print(int x){
    Base1::print(x);
}
void foo(double);

protected:
    int *ival;
    std::vector<double> dvec = {1.0, 2.0, 3.0};
};

int iva;
double dval;
void MI::foo(double cval)
{
    int dval;
    dval = Base1::dval + Derived::dval;
    Base2::fval = dvec.back();
    sval.at(0) = Base1::cval;
}

int main()
{
    MI mi;
    mi.print(42);
    return 0;
}
```
  
## 练习18.28

> 已知存在如下的继承体系，在 VMI 类的内部哪些继承而来的成员无须前缀限定符就能直接访问？哪些必须有限定符才能访问？说明你的原因。
```cpp
struct Base {
	void bar(int);
protected:
	int ival;
};
struct Derived1 : virtual public Base {
	void bar(char);
	void foo(char);
protected:
	char cval;
};
struct Derived2 : virtual public Base {
	void foo(int);
protected:
	int ival;
	char cval;
};
class VMI : public Derived1, public Derived2 { };
```

无需限定符的成员：  
Derived1::bar（bar不仅是Base的成员，也是Derived1的成员，派生类的bar比共享虚机类的bar优先级更高）；  
Derived2::ival（派生类Derived2的ival比共享虚机类的ival优先级更高）；  
需要限定符的成员：  
foo（Derived1和Derived2都存在该成员）；  
cval（Derived1和Derived2都存在该成员）;  
其他需要限定符的原因为会被覆盖。  
  
## 练习18.29

> 已知有如下所示的类继承关系：
```cpp
class Class { ... };
class Base : public Class { ... };
class D1 : virtual public Base { ... };
class D2 : virtual public Base { ... };
class MI : public D1, public D2 { ... };
class Final : public MI, public Class { ... };
(a) 当作用于一个Final对象时，构造函数和析构函数的执行次序分别是什么？
(b) 在一个Final对象中有几个Base部分？几个Class部分？
(c) 下面的哪些赋值运算符将造成编译错误？
Base *pb; Class *pc; MI *pmi; D2 *pd2;
(a) pb = new Class;
(b) pc = new Final;
(c) pmi = pb;
(d) pd2 = pmi;
```

（a）构造函数执行次序Class、Base、D1、D2、MI、Class、Final，析构函数执行次数与上述相反；  
（b）一个Base两个Class；  
（c）（a）编译错误，（b）编译错误，（c）编译错误，（d）正确。  
  
## 练习18.30

> 在Base中定义一个默认构造函数、一个拷贝构造函数和一个接受int形参的构造函数。在每个派生类中分别定义这三种构造函数，每个构造函数应该使用它的形参初始化其Base部分。

```cpp
#include <iostream>

using namespace std;

class Class {
};

class Base : public Class {
public:
	// Base() = default;
	Base() { cout << "Base()" << endl; }
	Base(int) { cout << "Base(int)" << endl; }
	Base(const Base &b) {}
};

class D1 : virtual public Base {
public:
	D1() = default;
	D1(int i) : Base(i) { cout << "D1(int)" << endl; }
	D1(const D1 &d){}
};

class D2 : virtual public Base {
public:
	D2() = default;
	D2(int i) : Base(i) { cout << "D2(int)" << endl; }
	D2(const D2 &d) {}
};

class MI : public D1, public D2 {
public:
	MI() = default;
	MI(int i) : D1(i), D2(i) { cout << "MI(int)" << endl; }
	MI(const MI &m) {}
};

class Final : public MI, public Class {
public:
	Final() = default;
	// Final(int i) : MI(i) { cout << "Final(int)" << endl; }
	Final(int i) : MI(i), Base(i) { cout << "Final(int)" << endl; }
	Final(const Final &f) {}
};

int main(int argc, char const *argv[])
{
	Final f(1);

	return 0;
}
```