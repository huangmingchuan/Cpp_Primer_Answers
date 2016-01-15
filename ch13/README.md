## 练习13.1

> 拷贝构造函数是什么？什么时候使用它？

## 练习13.2

> 解释为什么下面的声明是非法的：
```cpp
Sales_data::Sales_data(Sales_data rhs);
```

## 练习13.3

> 当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？

## 练习13.4

> 假定 Point 是一个类类型，它有一个public的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：
```cpp
Point global;
Point foo_bar(Point arg)
{
	Point local = arg, *heap = new Point(global);
	*heap = local;
	Point pa[4] = { local, *heap };
	return *heap;
}
```

## 练习13.5

> 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。你的构造函数应该动态分配一个新的string，并将对象拷贝到ps所指向的位置，而不是拷贝ps本身：
```cpp
class HasPtr {
public:
	HasPtr(const std::string& s = std::string()):
		ps(new std::string(s)), i(0) { }

private:
	std::string *ps;
	int i;
}
```

## 练习13.6

> 拷贝赋值运算符是什么？什么时候使用它？合成拷贝赋值运算符完成什么工作？什么时候会生成合成拷贝赋值运算符？

## 练习13.7

> 当我们将一个 StrBlob 赋值给另一个 StrBlob 时，会发生什么？赋值 StrBlobPtr 呢？

## 练习13.8

> 为13.1.1节练习13.5中的 HasPtr 类编写赋值运算符。类似拷贝构造函数，你的赋值运算符应该将对象拷贝到ps指向的位置。

## 练习13.9

> 析构函数是什么？合成析构函数完成什么工作？什么时候会生成合成析构函数？

## 练习13.10

> 当一个 StrBlob 对象销毁时会发生什么？一个 StrBlobPtr 对象销毁时呢？

## 练习13.11

> 为前面练习中的 HasPtr 类添加一个析构函数。

## 练习13.12

> 在下面的代码片段中会发生几次析构函数调用？
```cpp
bool fcn(const Sales_data *trans, Sales_data accum)
{
	Sales_data item1(*trans), item2(accum);
	return item1.isbn() != item2.isbn();
}
```

## 练习13.13

> 理解拷贝控制成员和构造函数的一个好方法的定义一个简单的类，为该类定义这些成员，每个成员都打印出自己的名字：
```cpp
struct X {
	X() {std::cout << "X()" << std::endl;}
	X(const X&) {std::cout << "X(const X&)" << std::endl;}
}
```
