## [练习7.1](exercise7_1.cpp)

> 使用2.6.1节定义的Sales_data类为1.6节的交易处理程序编写一个新版本。

## [练习7.2](exercise7_2.h)

> 曾在2.6.2节的练习中编写了一个Sales_data类，请向这个类添加combine函数和isbn成员。

## [练习7.3](exercise7_3.cpp)

> 修改7.1.1节的交易处理程序，令其使用这些成员。

## [练习7.4](exercise7_4.h)

> 编写一个名为Person的类，使其表示人员的姓名和地址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。

## [练习7.5](exercise7_5.h)

> 在你的Person类中提供一些操作使其能够返回姓名和地址。这些函数是否应该是const的呢？解释原因。

应该是const的。因为常量的Person对象也需要使用这些函数操作。

## [练习7.6](exercise7_6.h)

> 对于函数add、read和print，定义你自己的版本。

## [练习7.7](exercise7_7.cpp)

> 使用这些新函数重写7.1.2节练习中的程序。

## 练习7.8

> 为什么read函数将其Sales_data参数定义成普通的引用，而print函数将其参数定义成常量引用？

因为read函数会改变对象的内容，而print函数不会。

## [练习7.9](exercise7_9.h)

> 对于7.1.2节练习中代码，添加读取和打印Person对象的操作。

## 练习7.10

> 在下面这条if语句中，条件部分的作用是什么？
```cpp
if (read(read(cin, data1), data2))
```

read 函数的返回值是 istream 对象，if语句中条件部分的作用是从输入流中读取数据给两个data对象。

## 练习7.11 : [头文件](exercise7_11.h) | [主函数](exercise7_11.cpp)

> 在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。

## [练习7.12](exercise7_12.h)

> 把只接受一个istream 作为参数的构造函数移到类的内部。

## [练习7.13](exercise7_13.cpp)

> 使用istream构造函数重写第229页的程序。

## 练习7.14

> 编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。

```cpp
Sales_data() : units_sold(0) , revenue(0) { }
```

## [练习7.15](exercise7_15.h)

> 为你的 Person 类添加正确的构造函数。

