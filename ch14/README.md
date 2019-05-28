## 练习14.1

> 在什么情况下重载的运算符与内置运算符有所区别？在什么情况下重载的运算符又与内置运算符一样？

我们可以直接调用重载运算符函数。重置运算符与内置运算符有一样的优先级与结合性。

## 练习14.2 ： [hpp](exercise14_2.h) | [cpp](exercise14_2.cpp)

> 为 Sales_data 编写重载的输入、输出、加法和复合赋值运算符。

## 练习14.3

> string 和 vector 都定义了重载的==以比较各自的对象，假设 svec1 和 svec2 是存放 string 的 vector，确定在下面的表达式中分别使用了哪个版本的==？
```cpp
(a) "cobble" == "stone"
(b) svec1[0] == svec2[0]
(c) svec1 == svec2
(d) "svec1[0] == "stone"
``` 

* (a) 都不是。
* (b) string 
* (c) vector 
* (d) string

## 练习14.4

> 如何确定下列运算符是否应该是类的成员？
```cpp
(a) %
(b) %=
(c) ++
(d) ->
(e) <<
(f) &&
(g) ==
(h) ()
```

* (a) 不需要是成员。
* (b) 是成员。
* (c) 是成员。
* (d) 必须是成员。
* (e) 不需要是成员。
* (f) 不需要是成员。
* (g) 不需要是成员。
* (h) 必须是成员。

## 练习14.5

> 在7.5.1节中的练习7.40中，编写了下列类中某一个的框架，请问在这个类中应该定义重载的运算符吗？如果是，请写出来。
```cpp
(a) Book
(b) Date
(c) Employee
(d) Vehicle
(e) Object
(f) Tree
``` 	

`Book`

[hpp](exercise14_5.h) | [cpp](exercise14_5.cpp) | [test](exercise14_5_main.cpp)

## 练习14.6

> 为你的 Sales_data 类定义输出运算符。

## 练习14.7

> 你在13.5节的练习中曾经编写了一个String类，为它定义一个输出运算符。

[hpp](exercise14_7.h) | [cpp](exercise14_7.cpp) | [test](exercise14_7_main.cpp)

## 练习14.8

> 你在7.5.1节中的练习中曾经选择并编写了一个类，为它定义一个输出运算符。

## 练习14.9

> 为你的 Sales_data 类定义输入运算符。

## 练习14.10

> 对于 Sales_data 的输入运算符来说如果给定了下面的输入将发生什么情况？
```cpp
(a) 0-201-99999-9 10 24.95
(b) 10 24.95 0-210-99999-9
```

* (a) 格式正确。
* (b) 不合法的输入。因为程序试图将 `0-210-99999-9` 转换为 `float`。

## 练习14.11

> 下面的 Sales_data 输入运算符存在错误吗？如果有，请指出来。对于这个输入运算符如果仍然给定上个练习的输入将会发生什么情况？
```cpp
istream& operator>>(istream& in, Sales_data& s)
{
	double price;
	in >> s.bookNo >> s.units_sold >> price;
	s.revence = s.units_sold >> price;
	return in;
}
```

没有输入检查，什么也不会发生。

## 练习14.12

> 你在7.5.1节的练习中曾经选择并编写了一个类，为它定义一个输入运算符并确保该运算符可以处理输入错误。

## 练习14.13

> 你认为 Sales_data 类还应该支持哪些其他算术运算符？如果有的话，请给出它们的定义。

没有其他了。

## 练习14.14

> 你觉得为什么调用 operator+= 来定义operator+ 比其他方法更有效？

因为用 `operator+=` 会避免使用一个临时对象，而使得更有效。

## 练习14.15

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有其他算术运算符吗？如果是，请实现它们；如果不是，解释原因。

[hpp](exercise14_15.h) | [cpp](exercise14_15.cpp) | [test](exercise14_15_main.cpp)

## 练习14.16

> 为你的 StrBlob 类、StrBlobPtr 类、StrVec 类和 String 类分别定义相等运算符和不相等运算符。

## 练习14.17

> 你在7.5.1节中的练习7.40中曾经选择并编写了一个类，你认为它应该含有相等运算符吗？如果是，请实现它；如果不是，解释原因。

## 练习14.18

> 为你的 StrBlob 类、StrBlobPtr 类、StrVec 类和 String 类分别定义关系运算符。

## 练习14.19

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有关系运算符吗？如果是，请实现它；如果不是，解释原因。

## 练习14.20

> 为你的 Sales_data 类定义加法和复合赋值运算符。

## 练习14.21

> 编写 Sales_data 类的+ 和+= 运算符，使得 + 执行实际的加法操作而 += 调用+。相比14.3节和14.4节对这两个运算符的定义，本题的定义有何缺点？试讨论之。

缺点：使用了一个 `Sales_data` 的临时对象，但它并不是必须的。

## 练习14.22

> 定义赋值运算符的一个新版本，使得我们能把一个表示 ISBN 的 string 赋给一个 Sales_data 对象。

[hpp](exercise14_22.h) | [cpp](exercise14_22.cpp) | [test](exercise14_22_main.cpp)

## 练习14.23

> 为你的StrVec 类定义一个 initializer_list 赋值运算符。

[hpp](exercise14_23.h) | [cpp](exercise14_23.cpp) | [test](exercise14_23_main.cpp)

## 练习14.24

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有拷贝赋值和移动赋值运算符吗？如果是，请实现它们。

[hpp](exercise14_24.h) | [cpp](exercise14_24.cpp) | [test](exercise14_24_main.cpp)

## 练习14.25

> 上题的这个类还需要定义其他赋值运算符吗？如果是，请实现它们；同时说明运算对象应该是什么类型并解释原因。

是。如上题。

## 练习14.26

> 为你的 StrBlob 类、StrBlobPtr 类、StrVec 类和 String 类定义下标运算符。

## 练习14.27

> 为你的 StrBlobPtr 类添加递增和递减运算符。

## 练习14.28

> 为你的 StrBlobPtr 类添加加法和减法运算符，使其可以实现指针的算术运算。

## 练习14.29

> 为什么不定义const 版本的递增和递减运算符？

因为递增和递减会改变对象本身，所以定义 const 版本的毫无意义。

## 练习14.30

> 为你的 StrBlobPtr 类和在12.1.6节练习12.22中定义的 ConstStrBlobPtr 的类分别添加解引用运算符和箭头运算符。注意：因为 ConstStrBlobPtr 的数据成员指向const vector，所以ConstStrBlobPtr 中的运算符必须返回常量引用。

## 练习14.31

> 我们的 StrBlobPtr 类没有定义拷贝构造函数、赋值运算符以及析构函数，为什么？

因为使用合成的足够了。

## 练习14.32

> 定义一个类令其含有指向 StrBlobPtr 对象的指针，为这个类定义重载的箭头运算符。

```cpp
class StrBlobPtr;

class StrBlobPtr_pointer
{
public:
    StrBlobPtr_pointer() = default;
    StrBlobPtr_pointer(StrBlobPtr* p) : pointer(p) { }

    StrBlobPtr& operator *();
    StrBlobPtr* operator->();

private:
    StrBlobPtr* pointer = nullptr;
};
```

## 练习14.33

> 一个重载的函数调用运算符应该接受几个运算对象？

一个重载的函数调用运算符接受的运算对象应该和该运算符拥有的操作数一样多。

## 练习14.34

> 定义一个函数对象类，令其执行if-then-else 的操作：该类的调用运算符接受三个形参，它首先检查第一个形参，如果成功返回第二个形参值；如果不成功返回第三个形参的值。

```cpp
struct Test 
{
    int operator()(bool b, int iA, int iB) 
    {
        return b ? iA : iB;
    }
};
```

## [练习14.35](exercise14_35.cpp)

> 编写一个类似于 PrintString 的类，令其从 istream 中读取一行输入，然后返回一个表示我们所读内容的string。如果读取失败，返回空string。

## [练习14.36](exercise14_36.cpp)

> 使用前一个练习定义的类读取标准输入，将每一行保存为 vector 的一个元素。

## [练习14.37](exercise14_37.cpp)

> 编写一个类令其检查两个值是否相等。使用该对象及标准库算法编写程序，令其替换某个序列中具有给定值的所有实例。

## [练习14.38](exercise14_38.cpp)

> 编写一个类令其检查某个给定的 string 对象的长度是否与一个阈值相等。使用该对象编写程序，统计并报告在输入的文件中长度为1的单词有多少个，长度为2的单词有多少个、......、长度为10的单词有多少个。

## [练习14.39](exercise14_38.cpp)

> 修改上一题的程序令其报告长度在1到9之间的单词有多少个、长度在10以上的单词有多少个。

## [练习14.40](exercise14_40.cpp)

> 重新编写10.3.2节的biggies 函数，使用函数对象替换其中的 lambda 表达式。

## 练习14.41

> 你认为 C++ 11 标准为什么要增加 lambda？对于你自己来说，什么情况下会使用 lambda，什么情况下会使用类？

使用 lambda 是非常方便的，当需要使用一个函数，而这个函数不常使用并且简单时，使用lambda 是比较方便的选择。

## 练习14.42

> 使用标准库函数对象及适配器定义一条表达式，令其
```
(a) 统计大于1024的值有多少个。 
(b) 找到第一个不等于pooh的字符串。
(c)将所有的值乘以2。
```

```cpp
std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));
std::find_if(svec.cbegin(), svec.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies<int>(), _1, 2));
```

## [练习14.43](exercise14_43.cpp)

> 使用标准库函数对象判断一个给定的int值是否能被 int 容器中的所有元素整除。

## [练习14.44](exercise14_44.cpp)

> 编写一个简单的桌面计算器使其能处理二元运算。

## 练习14.45

> 编写类型转换运算符将一个 Sales_data 对象分别转换成 string 和 double，你认为这些运算符的返回值应该是什么？

[hpp](exercise14_45.h) | [cpp](exercise14_45.cpp) | [test](exercise14_45_main.cpp)

## 练习14.46

> 你认为应该为 Sales_data 类定义上面两种类型转换运算符吗？应该把它们声明成 explicit 的吗？为什么？

上面的两种类型转换有歧义，应该声明成 explicit 的。

## 练习14.47

> 说明下面这两个类型转换运算符的区别。
```cpp
struct Integral {
	operator const int();
	operator int() const;
}
```

第一个无意义，会被编译器忽略。第二个合法。

## 练习14.48 

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有向 bool 的类型转换运算符吗？如果是，解释原因并说明该运算符是否应该是 explicit的；如果不是，也请解释原因。

Date 类应该含有向 bool 的类型转换运算符，并且应该声明为 explicit 的。

## 练习14.49

> 为上一题提到的类定义一个转换目标是 bool 的类型转换运算符，先不用在意这么做是否应该。

```cpp
 explicit operator bool() { return (year<4000) ? true : false; }
```

## 练习14.50

> 在初始化 ex1 和 ex2 的过程中，可能用到哪些类类型的转换序列呢？说明初始化是否正确并解释原因。
```cpp
struct LongDouble {
	LongDouble(double = 0.0);
	operator double();
	operator float();
};
LongDouble ldObj;
int ex1 = ldObj;
float ex2 = ldObj;
```

ex1 转换不合法，没有定义从 `LongDouble` 到 `int` 的转换。ex2 合法。

## 练习14.51

> 在调用 calc 的过程中，可能用到哪些类型转换序列呢？说明最佳可行函数是如何被选出来的。
```cpp
void calc(int);
void calc(LongDouble);
double dval;
calc(dval);  //哪个calc？
```

最佳可行函数是 `void calc(int)`。

转换的优先级如下：

1. 精确匹配
2. const 转换。
3. 类型提升
4. 算术转换
5. 类类型转换

## 练习14.52

> 在下面的加法表达式中分别选用了哪个operator+？列出候选函数、可行函数及为每个可行函数的实参执行的类型转换：
```cpp
struct Longdouble {
	//用于演示的成员operator+;在通常情况下是个非成员
	LongDouble operator+(const SmallInt&);
	//其他成员与14.9.2节一致
};
LongDouble operator+(LongDouble&, double);
SmallInt si;
LongDouble ld;
ld = si + ld;
ld = ld + si;
```

`ld = si + ld;` 不合法。`ld = ld + si` 两个都可以调用，但是第一个调用更精确一些。

## 练习14.53

> 假设我们已经定义了如第522页所示的SmallInt，判断下面的加法表达式是否合法。如果合法，使用了哪个加法运算符？如果不合法，应该怎样修改代码才能使其合法？
```cpp
SmallInt si;
double d = si + 3.14;
```

不合法。应该该为：
```cpp
SmallInt s1;
double d = s1 + SmallInt(3.14);
```
