## 练习1.1

> 查阅你使用的编译器文档，确定它所使用的文件命名约定。编译并运行第2页的main程序。

* [为 Visual C++ 项目创建的文件类型](https://msdn.microsoft.com/zh-cn/library/3awe4781(v=vs.120).aspx)

## 练习1.2

> 改写程序，让它返回-1。返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。

![windows](https://github.com/huangmingchuan/Cpp_Primer_Answers/raw/master/data/exercise1_2.png)

## 练习1.3

> 编写程序，在标准输出上打印 Hello, World。

``` c++
#include <iostream>

int main()
{
	std::cout << "Hello, World" << std::endl;
	return 0;
}

```

## 练习1.4

> 我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符*，来打印两个数的积。

``` c++
#include <iostream>

int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The product of " << v1 << " and " << v2
				<< " is " << v1 * v2 << std::endl;
	return 0;
}

```

## 练习1.5

> 我们将所有输出操作放在一条很长的语句中。重写程序，将每个运算对象的打印操作放在一条独立的语句中。

``` c++
#include <iostream>

int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The product of ";
	std::cout << v1;
	std::cout << " and ";
	std::cout << v2;
	std::cout << " is ";
	std::cout << v1 * v2;
	std::cout << std::endl;
	return 0;
}

```

## 练习1.6

> 解释下面程序片段是否合法。
```
std::cout << "The sum of " << v1;
		  << " and " << v2;
		  << " is " << v1 + v2 << std::endl;
```
如果程序是合法的，它的输出是什么？如果程序不合法，原因何在？应该如何修正？

不合法。
**错误 error C2143: 语法错误 : 缺少“;”(在“<<”的前面)**
修正：移除掉多余的分号。
```c++
std::cout << "The sum of " << v1
		  << " and " << v2
		  << " is " << v1 + v2 << std::endl;
```

## 练习1.7

> 编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。

```c++
/*
*   注释在这里嵌套
*	/* 这里的嵌套是错的 */
*
*/

int main()
{
	return 0;
}
```
编译器错误信息：
![编译器错误信息](https://github.com/huangmingchuan/Cpp_Primer_Answers/raw/master/data/exercise1_7.png)

## 练习1.8

> 指出下列哪些输出语句是合法的(如果有的话)：
```c++
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
预测编译这些语句会产生什么样的结果，实际编译这些语句来验证你的答案(编写一个小程序，每次将上述一条语句作为其主体)，改正每个编译错误。

第三行编译出错，改正方法是增加一个引号。
```c++
std::cout << /* "*/" */";
```
输出：
```
/**/ */ /*
```
