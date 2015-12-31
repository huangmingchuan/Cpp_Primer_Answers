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

## 练习7.16

> 在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public 说明符之后？什么样的成员应该定义在private 说明符之后？

在类的定义中对于访问说明符出现的位置和次数没有限定。每个访问说明符指定了接下来的成员的访问级别，其有效范围直到出现下一个访问说明符或者达到类的结尾处为止。

如果某个成员能够在整个程序内都被访问，那么它应该定义为 public; 如果某个成员只能在类内部访问，那么它应该定义为 private。

## 练习7.17

> 使用class 和 struct 时有区别吗？如果有，是什么？

class 和 struct 的唯一区别是默认的访问级别不同。

## 练习7.18

> 封装是何含义？它有什么用处？

将类内部分成员设置为外部不可见，而提供部分接口给外面，这样的行为叫做封装。封装隐藏了具体的实现，当我们使用某个抽象数据类型时，只需要考虑它提供什么接口操作，而不用去考虑它的具体实现。

## 练习7.19

> 在你的Person 类中，你将把哪些成员声明成public 的？哪些声明成private 的？解释你这样做的原因。

构造函数、`getName()`、`getAddress()` 函数将设为 public。`name` 和 `address` 将设为private。函数是暴露给外部的接口，因此要设为public；而数据则应该隐藏让外部不可见。

## 练习7.20

> 友元在什么时候有用？请分别举出使用友元的利弊。

当其他类或者函数想要访问当前类的私有变量时，这个时候应该用友元。

**利**：
* 与当前类有关的接口函数能直接访问类的私有变量。

**弊**：
* 牺牲了封装性与可维护性。

## [练习7.21](exercise7_21.h)

> 修改你的Sales_data 类使其隐藏实现的细节。你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其正常工作。

## [练习7.22](exercise7_22.h)

> 修改你的Person 类使其隐藏实现的细节。

## [练习7.23](exercise7_23.h)

> 编写你自己的Screen 类型。

## [练习7.24](exercise7_24.h)

> 给你的Screen 类添加三个构造函数：一个默认构造函数；另一个构造函数接受宽和高的值，然后将contents 初始化成给定数量的空白；第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化后屏幕的内容。

## 练习7.25

> Screen 能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能？为什么？

能。Screen 的成员只有内置类型和 string，因此能安全地依赖于拷贝和赋值操作的默认版本。管理动态内存的类则不能依赖于拷贝和赋值操作的默认版本，而且也应该尽量使用string 和 vector 来避免动态管理内存的复杂性。

## [练习7.26](exercise7_26.h)

> 将Sales_data::avg_price 定义成内联函数。

## 练习7.27 : [头文件](exercise7_27.h) | [主函数](exercise7_27.cpp)

> 给你自己的Screen 类添加move、set 和display 函数，通过执行下面的代码检验你的类是否正确。
```cpp
Screen myScreen(5, 5, 'X');
myScreen.move(4, 0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

## 练习7.28

> 如果move、set和display函数的返回类型不是Screen& 而是Screen，则在上一个练习中奖会发生什么？

如果返回类型是Screen，那么move返回的是 *this 的一个副本，因此set函数只能改变临时副本而不能改变myScreen的值。

## 练习7.29

> 修改你的Screen 类，令move、set和display函数返回Screen并检查程序的运行结果，在上一个练习中你的推测正确吗？

推测正确。
```
//返回 Screen& 的结果
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
					^  <- 这里

//返回 Screen 的结果
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
					^  <- 这里
```

## 练习7.30

> 通过this指针使用成员的做法虽然合法，但是有点多余。讨论显示使用指针访问成员的优缺点。

**优点**：
* 程序的意图更明确
* 函数的参数可以与成员同名，如 

		void setAddr(const std::string &addr) { this->addr = addr; }

**缺点**：
* 有时候显得有点多余，如

		std::string getAddr() const { return this->addr; }

## 练习7.31

> 定义一对类X 和Y，其中X 包含一个指向 Y 的指针，而Y 包含一个类型为 X 的对象。

```cpp
class Y;

class X{
	Y* y = nullptr;	
};

class Y{
	X x;
};
```

## [练习7.32](exercise7_32.h)

> 定义你自己的Screen 和 Window_mgr，其中clear是Window_mgr的成员，是Screen的友元。

## 练习7.33

> 如果我们给Screen 添加一个如下所示的size成员将发生什么情况？如果出现了问题，请尝试修改它。
```cpp
pos Screen::size() const
{
	return height * width;
}
```

未定义标识符 pos。应该改为：
```cpp
Screen::pos Screen::size() const
{
	return height * width;
}
```

## 练习7.34

> 如果我们把第256页Screen类的pos的typedef放在类的最后一行会发生什么情况？

在 `dummy_fcn(pos height)` 函数中会出现 **未定义的标识符pos**。
```
类型名的定义通常出现在类的开始处，这样就能确保所有使用该类型的成员都出现在类名的定义之后。
```

## 练习7.35

> 解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。
```cpp
typedef string Type;
Type initVal(); 
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal(); 
private:
    int val;
};
Type Exercise::setVal(Type parm) { 
    val = parm + initVal();     
    return val;
}
```

**书上255页中说**：
> 然而在类中，如果成员使用了外层作用域中的某个名字，而该名字代表一种类型，则类不能在之后重新定义该名字。

因此重复定义 Type 是错误的行为。