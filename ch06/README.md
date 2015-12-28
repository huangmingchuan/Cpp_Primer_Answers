## 练习6.1

> 实参和形参的区别的什么？

实参是函数调用的实际值，是形参的初始值。

## 练习6.2

> 请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
```cpp
(a) int f() {
          string s;
          // ...
          return s;
    }
(b) f2(int i) { /* ... */ }
(c) int calc(int v1, int v1) { /* ... */ }
(d) double square (double x)  return x * x; 
```

应该改为下面这样：
```cpp
(a) string f() {
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }
(c) int calc(int v1, int v2) { /* ... */ }
(d) double square (double x) { return x * x; }
```

## [练习6.3](exercise6_3.cpp)

> 编写你自己的fact函数，上机检查是否正确。

## [练习6.4](exercise6_4.cpp)

> 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。

## 练习6.5

> 编写一个函数输出其实参的绝对值。

```cpp
#include <iostream>

int abs(int i)
{
    return i > 0 ? i : -i;
}

int main()
{
    std::cout << abs(-5) << std::endl;
    return 0;
}
```

## 练习6.6

> 说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时达到这三种形式。

**形参**定义在函数形参列表里面；**局部变量**定义在代码块里面；**局部静态变量**在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止时才被销毁。
```cpp
// 例子
int count_add(int n)       // n是形参
{
    static int ctr = 0;    // ctr 是局部静态变量
    ctr += n;
    return ctr;
}

int main()
{
    for (int i = 0; i != 10; ++i)  // i 是局部变量
      cout << count_add(i) << endl;

    return 0;
}
```

## 练习6.7

> 编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。

```cpp
int generate()
{
    static int ctr = 0;
    return ctr++;
}
```

## [练习6.8](exercise6_8.cpp)

> 编写一个名为Chapter6.h 的头文件，令其包含6.1节练习中的函数声明。

## 练习6.9 : [fact.cc](fact.cpp) | [factMain.cc](factMain.cpp)

> 编写你自己的fact.cc 和factMain.cc ，这两个文件都应该包含上一小节的练习中编写的 Chapter6.h 头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。

