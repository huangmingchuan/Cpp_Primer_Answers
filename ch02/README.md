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
```
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

