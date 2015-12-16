## 练习2.1

> 类型 int、long、long long 和 short 的区别是什么？无符号类型和带符号类型的区别是什么？float 和 double的区别是什么？

C++ 规定 `short` 和 `int` 至少16位，`long` 至少32位，`long long` 至少64位。
带符号类型能够表示正数、负数和 0 ，而无符号类型只能够表示 0 和正整数。

用法：
* 一般使用 `int` 做整数运算，`short` 因为太小在实际中用的少，`long` 通常和 `int` 有着相同的大小。如果数据非常大，可以使用 `long long` 。
* 如果你确认数据是非负的，那么就使用 `unsigned` 无符号类型。
* 执行浮点运算时用 `double` ，因为 `float` 通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几。

参考：
* [What are the criteria for choosing between short / int / long data types?](http://www.parashift.com/c++-faq/choosing-int-size.html)
* [Difference between float and double](http://stackoverflow.com/questions/2386772/difference-between-float-and-double)

## 练习2.2

> 计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

使用 `double` 或 `float` 。

## 练习2.3

> 读程序写结果。
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

输出：
```
32
4294967264
32
-32
0
0
```

## [练习2.4](exercise2_4.cpp)

> 编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

## 练习2.5

> 指出下述字面值的数据类型并说明每一组内几种字面值的区别：
- (a) 'a', L'a', "a", L"a"
- (b) 10, 10u, 10L, 10uL, 012, 0xC
- (c) 3.14, 3.14f, 3.14L
- (d) 10, 10u, 10., 10e-2

(a): 字符字面值，宽字符字面值，字符串字面值，宽字符串字面值。

(b): 十进制整型，十进制无符号整型，十进制长整型，八进制整型，十六进制整型。

(c): double, float, long double

(d): 十进制整型，十进制无符号整型，double, double

## 练习2.6

> 下面两组定义是否有区别，如果有，请叙述之：
```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

第一行定义的是十进制整型。
第二行定义的是八进制整型，但是 month 变量无效，因为八进制没有 9 。

## 练习2.7

> 下述字面值表示何种含义？它们各自的数据类型是什么？
- (a) "Who goes with F\145rgus?\012"
- (b) 3.14e1L
- (c) 1024f
- (d) 3.14L

(a): Who goes with Fergus?(换行)，string 类型

(b): long double

(c): 无效，因为后缀 f 只能用于浮点字面量，而 1024 是整型。

(d): long double

参考：
* [ASCII Table](http://www.asciitable.com/)

## 练习2.8

> 请利用转义序列编写一段程序，要求先输出 2M，然后转到新一行。修改程序使其先输出 2，然后输出制表符，再输出 M，最后转到新一行。

```cpp
#include <iostream>

int main()
{
    std::cout << 2 << "\115\012";
    std::cout << 2 << "\t\115\012";
    return 0;
}
```

## 练习2.9

> 解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。
- (a) std::cin >> int input_value;
- (b) int i = { 3.14 };
- (c) double salary = wage = 9999.99;
- (d) int i = 3.14;

(a): 应该先定义再使用。
```cpp
int input_value = 0;
std::cin >> input_value;
```

(b): 用列表初始化内置类型的变量时，如果存在丢失信息的风险，则编译器将报错。
```cpp
double i = { 3.14 };
```

(c): 在这里 wage 是未定义的，应该在此之前将其定义。
```cpp
double wage;
double salary = wage = 9999.99;
```

(d): 不报错，但是小数部分会被截断。
```cpp
double i = 3.14;
```

## 练习2.10

> 下列变量的初值分别是什么？
```cpp
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```

`global_str` 和 `global_int` 是全局变量，所以初值分别为空字符串和 0 。
`local_int` 是局部变量并且没有初始化，它的初值是未定义的。
`local_str` 是 string 类的对象，它的值由类确定，为空字符串。 

## 练习2.11

> 指出下面的语句是声明还是定义：
- (a) extern int ix = 1024;
- (b) int iy;
- (c) extern int iz;

```
(a): 定义
(b): 定义
(c): 声明
```

## 练习2.12

> 请指出下面的名字中哪些是非法的？
- (a) int double = 3.14;
- (b) int _;
- (c) int catch-22;
- (d) int 1_or_2 = 1;
- (e) double Double = 3.14;

`(a)`, `(c)`, `(d)` 非法。

## 练习2.13

> 下面程序中 j 的值是多少？
```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

`j` 的值是 `100` ，局部变量 `i` 覆盖了全局变量 `i` 。

## 练习2.14

> 下面的程序合法吗？如果合法，它将输出什么？
```cpp
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
```

合法。输出是 ` 100 45 ` 。

## 练习2.15

> 下面的哪个定义是不合法的？为什么？
- (a) int ival = 1.01;
- (b) int &rval1 = 1.01;
- (c) int &rval2 = ival;
- (d) int &rval3;

`(b)` 和 `(d)` 不合法，`(b)` 引用必须绑定在对象上，`(d)` 引用必须初始化。

## 练习2.16

> 考察下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了哪些操作？
```
int i = 0, &r1 = i; double d = 0, &r2 = d;
- (a) r2 = 3.14159;
- (b) r2 = r1;
- (c) i = r2;
- (d) r1 = d;
```

```
(a): 合法。给 d 赋值为 3.14159。
(b): 合法。会执行自动转换（int->double）。
(c): 合法。会发生小数截取。
(d): 合法。会发生小数截取。
```

## 练习2.17

> 执行下面的代码段将输出什么结果？
```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

输出：
```
10, 10
```

## 练习2.18

> 编写代码分别改变指针的值以及指针所指对象的值。

```cpp
int a = 0, b = 1;
int *p1 = &a, *p2 = p1;

// change the value of a pointer.
p1 = &b;
// change the value to which the pointer points
*p2 = b;
```

## 练习2.19

> 说明指针和引用的主要区别

1. 引用是另一个对象的别名，而指针本身就是一个对象。
2. 引用必须初始化，并且一旦定义了引用就无法再绑定到其他对象。而指针无须在定义时赋初值，也可以重新赋值让其指向其他对象。

## 练习2.20

> 请叙述下面这段代码的作用。
```cpp
int i = 42;
int *p1 = &i; 
*p1 = *p1 * *p1;
```

让指针 `pi` 指向 `i`，然后将 `i` 的值重新赋值为 42 * 42 (1764)。

## 练习2.21

> 请解释下述定义。在这些定义中有非法的吗？如果有，为什么？
```
int i = 0;
(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;
```

```
(a): 非法。不能将一个指向 `double` 的指针指向 `int` 。
(b): 非法。不能将 `int` 变量赋给指针。
(c): 合法。
```

## 练习2.22

> 假设 p 是一个 int 型指针，请说明下述代码的含义。
```cpp
if (p) // ...
if (*p) // ...
```
`if (p) // ...`  判断 p 是不是一个空指针, 
`if (*p) // ...` 判断 p 所指向的对象的值是不是为 0

## 练习2.23

> 给定指针 p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

不能，因为首先要确定这个指针是不是合法的，才能判断它所指向的对象是不是合法的。

## 练习2.24

> 在下面这段代码中为什么 p 合法而 lp 非法？
```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```

`void *` 是从 C语言那里继承过来的，可以指向任何类型的对象。而其他指针类型必须要与所指对象严格匹配。

## 练习2.25

> 说明下列变量的类型和值。
- (a) int* ip, i, &r = i;
- (b) int i, *ip = 0;
- (c) int* ip, ip2;

```
(a): ip 是一个指向 int 的指针, i 是一个 int, r 是 i 的引用。
(b): i 是 int , ip 是一个空指针。
(c): ip 是一个指向 int 的指针, ip2 是一个 int。
```

## 练习2.26

> 下面哪些语句是合法的？如果不合法，请说明为什么？
```cpp
const int buf;      // 不合法, const 对象必须初始化
int cnt = 0;        // 合法
const int sz = cnt; // 合法
++cnt; ++sz;        // 不合法, const 对象不能被改变
```