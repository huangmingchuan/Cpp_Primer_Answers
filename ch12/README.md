## 练习12.1

> 在此代码的结尾，b1 和 b2 各包含多少个元素？
```cpp
StrBlob b1;
{
	StrBlob b2 = {"a", "an", "the"};
	b1 = b2;
	b2.push_back("about");
}
```

## 练习12.2

> 编写你自己的StrBlob 类，包含const 版本的 front 和 back。

## 练习12.3

> StrBlob 需要const 版本的push_back 和 pop_back吗？如需要，添加进去。否则，解释为什么不需要。

## 练习12.4

> 在我们的 check 函数中，没有检查 i 是否大于0。为什么可以忽略这个检查？

## 练习12.5

> 我们未编写接受一个 initializer_list explicit 参数的构造函数。讨论这个设计策略的优点和缺点。

## 练习12.6

> 编写函数，返回一个动态分配的 int 的vector。将此vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。

## 练习12.7

> 重做上一题，这次使用 shared_ptr 而不是内置指针。

## 练习12.8

> 下面的函数是否有错误？如果有，解释错误原因。
```cpp
bool b() {
	int* p = new int;
	// ...
	return p;
}
```

## 练习12.9

> 解释下面代码执行的结果。
```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

## 练习12.10

> 下面的代码调用了第413页中定义的process 函数，解释此调用是否正确。如果不正确，应如何修改？
```cpp
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

## 练习12.11

> 如果我们像下面这样调用 process，会发生什么？
```cpp
process(shared_ptr<int>(p.get()));
```

## 练习12.12

> p 和 sp 的定义如下，对于接下来的对 process 的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因：
```cpp
auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
```

## 练习12.13

> 如果执行下面的代码，会发生什么？
```cpp
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```

## 练习12.14

> 编写你自己版本的用 shared_ptr 管理 connection 的函数。

## 练习12.15

> 重写第一题的程序，用 lambda 代替end_connection 函数。

## 练习12.16

> 如果你试图拷贝或赋值 unique_ptr，编译器并不总是能给出易于理解的错误信息。编写包含这种错误的程序，观察编译器如何诊断这种错误。

## 练习12.17

> 下面的 unique_ptr 声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。
```cpp
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
(a) IntP p0(ix);
(b) IntP p1(pi);
(c) IntP p2(pi2);
(d) IntP p3(&ix);
(e) IntP p4(new int(2048));
(f) IntP p5(p2.get());
```

## 练习12.18

> shared_ptr 为什么没有 release 成员？

## 练习12.19

> 定义你自己版本的 StrBlobPtr，更新 StrBlob 类，加入恰当的 friend 声明以及 begin 和 end 成员。

## 练习12.20

> 编写程序，逐行读入一个输入文件，将内容存入一个 StrBlob 中，用一个 StrBlobPtr 打印出 StrBlob 中的每个元素。

## 练习12.21

> 也可以这样编写 StrBlobPtr 的 deref 成员：
```cpp
std::string& deref() const {
	return (*check(curr, "dereference past end"))[curr];
}
```
你认为哪个版本更好？为什么？

## 练习12.22

> 为了能让 StrBlobPtr 使用 const StrBlob，你觉得应该如何修改？定义一个名为ConstStrBlobPtr 的类，使其能够指向 const StrBlob。

## 练习12.23

> 编写一个程序，连接两个字符串字面常量，将结果保存在一个动态分配的char数组中。重写这个程序，连接两个标准库string对象。

## 练习12.24

> 编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度的字符串。

## 练习12.25

> 给定下面的new表达式，你应该如何释放pa？
```cpp
int *pa = new int[10];
```

## 练习12.26

> 用 allocator 重写第427页中的程序。

## 练习12.27

> TextQuery 和 QueryResult 类只使用了我们已经介绍过的语言和标准库特性。不要提前看后续章节内容，只用已经学到的知识对这两个类编写你自己的版本。

## 练习12.28

> 编写程序实现文本查询，不要定义类来管理数据。你的程序应该接受一个文件，并与用户交互来查询单词。使用vector、map 和 set 容器来保存来自文件的数据并生成查询结果。

## 练习12.29

> 我们曾经用do while 循环来编写管理用户交互的循环。用do while 重写本节程序，解释你倾向于哪个版本，为什么？

## 练习12.30

> 定义你自己版本的 TextQuery 和 QueryResult 类，并执行12.3.1节中的runQueries 函数。

## 练习12.31

> 如果用vector 代替 set 保存行号，会有什么差别？哪个方法更好？为什么？

## 练习12.32

> 重写 TextQuery 和 QueryResult类，用StrBlob 代替 vector<string> 保存输入文件。

## 练习12.33

> 在第15章中我们将扩展查询系统，在 QueryResult 类中将会需要一些额外的成员。添加名为 begin 和 end 的成员，返回一个迭代器，指向一个给定查询返回的行号的 set 中的位置。再添加一个名为 get_file 的成员，返回一个 shared_ptr，指向 QueryResult 对象中的文件。
