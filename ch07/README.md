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

* 虽然重复定义类型名字是错误的行为，但是编译器并不为此负责。所以我们要人为地遵守一些原则，在[这里](https://github.com/Mooophy/Cpp-Primer/issues/390)有一些讨论。

## 练习7.36

> 下面的初始值是错误的，请找出问题所在并尝试修改它。
```cpp
struct X {
	X (int i, int j): base(i), rem(base % j) {}
	int rem, base;
};
```

应该改为：
```cpp
struct X {
	X (int i, int j): base(i), rem(base % j) {}
	int base, rem;
};
```

## 练习7.37

> 使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有的数据成员的值。

```cpp
Sales_data first_item(cin); // 使用 Sales_data(std::istream &is) ; 各成员值从输入流中读取
int main() {
	Sales_data next; // 使用默认构造函数  bookNo = "", cnt = 0, revenue = 0.0

	// 使用 Sales_data(std::string s = "");   bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
	Sales_data last("9-999-99999-9"); 
}
```

## 练习7.38

> 有些情况下我们希望提供cin作为接受istream& 参数的构造函数的默认实参，请声明这样的构造函数。

```cpp
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```

## 练习7.39

> 如果接受string 的构造函数和接受 istream& 的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？

不合法。当你调用 `Sales_data()` 构造函数时，无法区分是哪个重载。

## 练习7.40

> 从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
```cpp
(a) Book
(b) Data
(c) Employee
(d) Vehicle
(e) Object
(f) Tree
```

(a) Book.
```cpp
class Book 
{
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    { }

    explicit Book(std::istream &in) 
    { 
        in >> isbn_ >> name_ >> author_ >> pubdate_;
    }

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};
```

## 练习7.41 : [头文件](exercise7_41.h) | [源文件](exercise7_41.cpp) | [主函数](exercise7_41_main.cpp)

> 使用委托构造函数重新编写你的Sales_data 类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建 Sales_data 对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。

## 练习7.42

> 对于你在练习7.40中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。

```cpp
class Book 
{
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    { }

    Book(unsigned isbn) : Book(isbn, "", "", "") {}

    explicit Book(std::istream &in) 
    { 
        in >> isbn_ >> name_ >> author_ >> pubdate_;
    }

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};
```

## 练习7.43

> 假定有一个名为 NoDefault 的类，它有一个接受 int 的构造函数，但是没有默认构造函数。定义类 C，C 有一个 NoDefault 类型的成员，定义C 的默认构造函数。

```cpp
class NoDefault {
public:
    NoDefault(int i) { }
};

class C {
public:
    C() : def(0) { } 
private:
    NoDefault def;
};
```

## 练习7.44

> 下面这条声明合法吗？如果不，为什么？
```cpp
vector<NoDefault> vec(10);
```

不合法。因为 NoDefault 没有默认构造函数。

## 练习7.45

> 如果在上一个练习中定义的vector的元素类型是C，则声明合法吗？为什么？

合法。因为 `C` 有默认构造函数。

## 练习7.46

> 下面哪些论断是不正确的？为什么？
```cpp
(a) 一个类必须至少提供一个构造函数。
(b) 默认构造函数是参数列表为空的构造函数。
(c) 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。
(d) 如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。
```

* (a) 不正确。如果我们的类没有显式地定义构造函数，那么编译器就会为我们隐式地定义一个默认构造函数，并称之为**合成的默认构造函数**。
* (b) 不完全正确。为每个参数都提供了默认值的构造函数也是默认构造函数。
* (c) 不正确。哪怕没有意义的值也需要初始化。
* (d) 不正确。只有当一个类没有定义任何构造函数的时候，编译器才会生成一个默认构造函数。

## 练习7.47

> 说明接受一个string 参数的Sales_data构造函数是否应该是explicit的，并解释这样做的优缺点。

是否需要从 string 到 Sales_data 的转换依赖于我们对用户使用该转换的看法。在此例中，这种转换可能是对的。null_book 中的 string 可能表示了一个不存在的 ISBN 编号。

优点：
* 可以抑制构造函数定义的隐式转换

缺点：
* 为了转换要显式地使用构造函数

## 练习7.48

> 假定Sales_data 的构造函数不是explicit的，则下述定义将执行什么样的操作？
```cpp
string null_isbn("9-999-9999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```

这些定义和是不是 explicit 的无关。

## 练习7.49

> 对于combine 函数的三种不同声明，当我们调用i.combine(s) 时分别发生什么情况？其中 i 是一个 Sales_data，而 s 是一个string对象。

```cpp
(a) Sales_data &combine(Sales_data); // ok
(b) Sales_data &combine(Sales_data&); // error C2664: 无法将参数 1 从“std::string”转换为“Sales_data &”	
(c) Sales_data &combine(const Sales_data&) const; // 该成员函数是const 的，意味着不能改变对象。而 combine函数的本意就是要改变对象
```

## 练习7.50

> 确定在你的Person 类中是否有一些构造函数应该是 explicit 的。

```cpp
explicit Person(std::istream &is){ read(is, *this); }
```

## 练习7.51

> vector 将其单参数的构造函数定义成 explicit 的，而string则不是，你觉得原因何在？

假如我们有一个这样的函数：
```cpp
int getSize(const std::vector<int>&);
```
如果vector没有将单参数构造函数定义成 explicit 的，我们就可以这样调用：
```cpp
getSize(34);
```
很明显这样调用会让人困惑，函数实际上会初始化一个拥有34个元素的vector的临时量，然后返回34。但是这样没有任何意义。而 string 则不同，string 的单参数构造函数的参数是 const char * ，因此凡是在需要用到 string 的地方都可以用 const char * 来代替（字面值就是 const char *）。如：
```cpp
void print(std::string);
print("hello world");
```

## 练习7.52

> 使用2.6.1节的 Sales_data 类，解释下面的初始化过程。如果存在问题，尝试修改它。
```cpp
	Sales_data item = {"987-0590353403", 25, 15.99};
```

Sales_data 类不是聚合类，应该修改成如下：
```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

## 练习7.53

> 定义你自己的 Debug。

```cpp
class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }

    constexpr bool any() { return hw || io || other; }
    void set_hw(bool b) { hw = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }
    
private:
    bool hw;        // runtime error
    bool io;        // I/O error
    bool other;     // the others
};
```

## 练习7.54
> Debug中以 set_ 开头的成员应该被声明成 constexpr 吗？如果不，为什么？

不能。constexpr 函数必须包含一个返回语句。

## 练习7.55

> 7.5.5节的 Data 类是字面值常量类吗？请解释原因。

不是。因为 std::string 不是字面值类型。 

## 练习7.56

> 什么是类的静态成员？它有何优点？静态成员与普通成员有何区别？

与类本身相关，而不是与类的各个对象相关的成员是静态成员。静态成员能用于某些场景，而普通成员不能。

## 练习7.57

> 编写你自己的 Account 类。

```cpp
class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
    
private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();
```

## 练习7.58

> 下面的静态数据成员的声明和定义有错误吗？请解释原因。
```cpp
//example.h
class Example {
public:
	static double rate = 6.5;
	static const int vecSize = 20;
	static vector<double> vec(vecSize);
};
//example.c
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```

rate 应该是一个常量表达式。而类内只能初始化整型类型的静态常量，所以不能在类内初始化vec。修改后如下：
```cpp
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};

// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```
