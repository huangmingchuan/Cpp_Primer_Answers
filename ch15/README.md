## 练习15.1

> 什么是虚成员？

## 练习15.2

> protected 访问说明符与 private 有何区别？

## 练习15.3

> 定义你自己的 Quote 类和 print_total 函数。

## 练习15.4

> 下面哪条声明语句是不正确的？请解释原因。
```cpp
class Base { ... };
(a) class Derived : public Derived { ... };
(b) class Derived : private Base { ... };
(c) class Derived : public Base;
```

## 练习15.5

> 定义你自己的 Bulk_quote 类。

## 练习15.6

> 将 Quote 和 Bulk_quote 的对象传给15.2.1节练习中的 print_total 函数，检查该函数是否正确。

## 练习15.7

> 定义一个类使其实现一种数量受限的折扣策略，具体策略是：当购买书籍的数量不超过一个给定的限量时享受折扣，如果购买量一旦超过了限量，则超出的部分将以原价销售。

## 练习15.8

> 给出静态类型和动态类型的定义。

## 练习15.9

> 在什么情况下表达式的静态类型可能与动态类型不同？请给出三个静态类型与动态类型不同的例子。

## 练习15.10

> 回忆我们在8.1节进行的讨论，解释第284页中将 ifstream 传递给 Sales_data 的read 函数的程序是如何工作的。

## 练习15.11

> 为你的 Quote 类体系添加一个名为 debug 的虚函数，令其分别显示每个类的数据成员。

## 练习15.12

> 有必要将一个成员函数同时声明成 override 和 final 吗？为什么？

## 练习15.13

> 给定下面的类，解释每个 print 函数的机理：
```cpp
class base {
public:
	string name() { return basename;}
	virtual void print(ostream &os) { os << basename; }
private:
	string basename;
};
class derived : public base {
public:
	void print(ostream &os) { print(os); os << " " << i; }
private:
	int i;
};
```
在上述代码中存在问题吗？如果有，你该如何修改它？

## 练习15.14

> 给定上一题中的类以及下面这些对象，说明在运行时调用哪个函数：
```cpp
base bobj; 		base *bp1 = &bobj; 	base &br1 = bobj;
derived dobj; 	base *bp2 = &dobj; 	base &br2 = dobj;
(a) bobj.print();	(b)dobj.print();	(c)bp1->name();
(d)bp2->name();		(e)br1.print();		(f)br2.print();
```

## 练习15.15

> 定义你自己的 Disc_quote 和 Bulk_quote。

## 练习15.16

> 改写你在15.2.2节练习中编写的数量受限的折扣策略，令其继承 Disc_quote。

## 练习15.17

> 尝试定义一个 Disc_quote 的对象，看看编译器给出的错误信息是什么？

## 练习15.18

> 假设给定了第543页和第544页的类，同时已知每个对象的类型如注释所示，判断下面的哪些赋值语句是合法的。解释那些不合法的语句为什么不被允许：
```cpp
Base *p = &d1;  //d1 的类型是 Pub_Derv
p = &d2;		//d2 的类型是 Priv_Derv
p = &d3;		//d3 的类型是 Prot_Derv
p = &dd1;		//dd1 的类型是 Derived_from_Public	
p = &dd2;		//dd2 的类型是 Derived_from_Private
p = &dd3;		//dd3 的类型是 Derived_from_Protected
```

## 练习15.19

> 假设543页和544页的每个类都有如下形式的成员函数：
```cpp
void memfcn(Base &b) { b = *this; }
```
对于每个类，分别判断上面的函数是否合法。

## 练习15.20

> 编写代码检验你对前面两题的回答是否正确。

## 练习15.21

> 从下面这些一般性抽象概念中任选一个（或者选一个你自己的），将其对应的一组类型组织成一个继承体系：
```cpp
(a) 图形文件格式（如gif、tiff、jpeg、bmp）
(b) 图形基元（如方格、圆、球、圆锥）
(c) C++语言中的类型（如类、函数、成员函数）
```

## 练习15.22

> 对于你在上一题中选择的类，为其添加函数的虚函数及公有成员和受保护的成员。

## 练习15.23

> 假设第550页的 D1 类需要覆盖它继承而来的 fcn 函数，你应该如何对其进行修改？如果你修改之后 fcn 匹配了 Base 中的定义，则该节的那些调用语句将如何解析？

## 练习15.24

> 哪种类需要虚析构函数？虚析构函数必须执行什么样的操作？

## 练习15.25

> 我们为什么为 Disc_quote 定义一个默认构造函数？如果去掉该构造函数的话会对 Bulk_quote 的行为产生什么影响？

## 练习15.26

> 定义 Quote 和 Bulk_quote 的拷贝控制成员，令其与合成的版本行为一致。为这些成员以及其他构造函数添加打印状态的语句，使得我们能够知道正在运行哪个程序。使用这些类编写程序，预测程序将创建和销毁哪些对象。重复实验，不断比较你的预测和实际输出结果是否相同，直到预测完全准确再结束。

## 练习15.27

> 重新定义你的 Bulk_quote 类，令其继承构造函数。

## 练习15.28

> 定义一个存放 Quote 对象的 vector，将 Bulk_quote 对象传入其中。计算 vector 中所有元素总的 net_price。

## 练习15.29

> 再运行一次你的程序，这次传入 Quote 对象的 shared_ptr 。如果这次计算出的总额与之前的不一致，解释为什么;如果一直，也请说明原因。

## 练习15.30

> 编写你自己的 Basket 类，用它计算上一个练习中交易记录的总价格。

## 练习15.31

> 已知 s1、s2、s3 和 s4 都是 string，判断下面的表达式分别创建了什么样的对象：
```cpp
(a) Query(s1) | Query(s2) & ~Query(s3);
(b) Query(s1) | (Query(s2) & ~Query(s3));
(c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
```

## 练习15.32

> 当一个 Query 类型的对象被拷贝、移动、赋值或销毁时，将分别发生什么？

## 练习15.33

> 当一个 Query_base 类型的对象被拷贝、移动赋值或销毁时，将分别发生什么？

## 练习15.34

> 针对图15.3构建的表达式：
```cpp
(a) 例举出在处理表达式的过程中执行的所有构造函数。
(b) 例举出 cout << q 所调用的 rep。
(c) 例举出 q.eval() 所调用的 eval。
```

## 练习15.35

> 实现 Query 类和 Query_base 类，其中需要定义rep 而无须定义 eval。

## 练习15.36

> 在构造函数和 rep 成员中添加打印语句，运行你的代码以检验你对本节第一个练习中(a)、(b)两小题的回答是否正确。

## 练习15.37

> 如果在派生类中含有 shared_ptr<Query_base> 类型的成员而非 Query 类型的成员，则你的类需要做出怎样的改变？

## 练习15.38

> 下面的声明合法吗？如果不合法，请解释原因;如果合法，请指出该声明的含义。
```cpp
BinaryQuery a = Query("fiery") & Query("bird");
AndQuery b = Query("fiery") & Query("bird");
OrQuery c = Query("fiery") & Query("bird");
```

## 练习15.39

> 实现 Query 类和　Query_base 类，求图15.3中表达式的值并打印相关信息，验证你的程序是否正确。

## 练习15.40

> 在 OrQuery 的 eval 函数中，如果 rhs 成员返回的是空集将发生什么？

## 练习15.41

> 重新实现你的类，这次使用指向 Query_base 的内置指针而非 shared_ptr。请注意，做出上述改动后你的类将不能再使用合成的拷贝控制成员。

## 练习15.42

> 从下面的几种改进中选择一种，设计并实现它:
```cpp
(a) 按句子查询并打印单词，而不再是按行打印。
(b) 引入一个历史系统，用户可以按编号查阅之前的某个查询，并可以在其中添加内容或者将其余其他查询组合。
(c) 允许用户对结果做出限制，比如从给定范围的行中跳出匹配的进行显示。
```