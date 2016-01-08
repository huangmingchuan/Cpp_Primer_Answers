## 练习10.1

> 头文件 algorithm 中定义了一个名为 count 的函数，它类似 find， 接受一对迭代器和一个值作为参数。 count 返回给定值在序列中出现的次数。编写程序，读取 int 序列存入vector中，打印有多少个元素的值等于给定值。

## 练习10.2

> 重做上一题，但读取 string 序列存入 list 中。

## 练习10.3

> 用 accumulate求一个 vector<int> 中元素之和。

## 练习10.4

> 假定 v 是一个vector<double>，那么调用 accumulate(v.cbegin(),v.cend(),0) 有何错误（如果存在的话）？

## 练习10.5

> 在本节对名册（roster）调用equal 的例子中，如果两个名册中保存的都是C风格字符串而不是string，会发生什么？

## 练习10.6

> 编写程序，使用 fill_n 将一个序列中的 int 值都设置为 0。

## 练习10.7

> 下面程序是否有错误？如果有，请改正：
```cpp
(a) vector<int> vec; list<int> lst; int i;
	while (cin >> i)
		lst.push_back(i);
	copy(lst.cbegin(), lst.cend(), vec.begin());

(b) vector<int> vec;
	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
```

## 练习10.8

> 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用 back_inserter 不会使这一断言失效？

## 练习10.9

> 实现你自己的 elimDups。分别在读取输入后、调用 unique后以及调用erase后打印vector的内容。

##　练习10.10

> 你认为算法不改变容器大小的原因是什么？

## 练习10.11

> 编写程序，使用 stable_sort 和 isShorter 将传递给你的 elimDups 版本的 vector 排序。打印 vector的内容，验证你的程序的正确性。

## 练习10.12

> 编写名为 compareIsbn 的函数，比较两个 Sales_data 对象的isbn() 成员。使用这个函数排序一个保存 Sales_data 对象的 vector。

## 练习10.13

> 标准库定义了名为 partition 的算法，它接受一个谓词，对容器内容进行划分，使得谓词为true 的值会排在容器的前半部分，而使得谓词为 false 的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为 true 的元素之后的位置。编写函数，接受一个 string，返回一个 bool 值，指出 string 是否有5个或更多字符。使用此函数划分 words。打印出长度大于等于5的元素。

