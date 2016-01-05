## 练习9.1

> 对于下面的程序任务，vector、deque和list哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。
* (a) 读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
* (b) 读取未知数量的单词，总是将单词插入到末尾。删除操作在头部进行。
* (c) 从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。

* (a) `list` ，因为需要频繁的插入操作。
* (b) `deque` ，总是在头尾进行插入、删除操作。
* (c) `vector` ，不需要进行插入删除操作。

## 练习9.2

> 定义一个list对象，其元素类型是int的deque。

```cpp
std::list<std::deque<int>> l;
```

## 练习9.3

> 构成迭代器范围的迭代器有何限制？

两个迭代器 `begin` 和 `end`需满足以下条件：
* 它们指向同一个容器中的元素，或者是容器最后一个元素之后的位置。
* 我们可以通过反复递增 begin 来到达 end。换句话说，end 不在 begin 之前。

## 练习9.4

> 编写函数，接受一对指向vector<int>的迭代器和一个int值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。

```cpp
bool find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
{
	while (begin++ != end)
	{
		if (*begin == i) 
			return true;
    }	
    return false;
}
```

## 练习9.5

> 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

```cpp
vector<int>::const_iterator find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
{
	while (begin != end)
	{
		if (*begin == i) 
			return begin;
		++begin;
    }	
    return end;
}
```

## 练习9.6

> 下面的程序有何错误？你应该如何修改它？
```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
					iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

修改成如下：
```cpp
while (iter1 != iter2)
```

## 练习9.7

> 为了索引int 的 vector中的元素，应该使用什么类型？

```cpp
vector<int>::size_type
```

## 练习9.8

> 为了读取string 的list 中的元素，应该使用什么类型？如果写入list，又应该使用什么类型？

```cpp
list<string>::const_iterator // 读
list<string>::iterator // 写
```

## 练习9.9

> begin 和 cbegin 两个函数有什么不同？

## 练习9.10

> 下面4个对象分别是什么类型？
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

## 练习9.11

> 对6种创建和初始化 vector 对象的方法，每一种都给出一个实例。解释每个vector包含什么值。

## 练习9.12

> 对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

## 练习9.13

> 如何从一个list<int>初始化一个vector<double>？从一个vector<int>又该如何创建？编写代码验证你的答案。

## 练习9.14

> 编写程序，将一个list中的char * 指针元素赋值给一个vector中的string。

## 练习9.15

> 编写程序，判定两个vector<int>是否相等。

## 练习9.16

> 重写上一题的程序，比较一个list<int>中的元素和一个vector<int>中的元素。

## 练习9.17

> 假定c1 和 c2 是两个容器，下面的比较操作有何限制？
```cpp
	if (c1 < c2)
```

## 练习9.18

> 编写程序，从标准输入读取string序列，存入一个deque中。编写一个循环，用迭代器打印deque中的元素。

## 练习9.19

> 重写上一题的程序，用list替代deque。列出程序要做出哪些改变。

## 练习9.20

> 编写程序，从一个list<int>拷贝元素到两个deque中。值为偶数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。

## 练习9.21

> 如果我们将第308页中使用 insert 返回值将元素添加到list中的循环程序改写为将元素插入到vector中，分析循环将如何工作。

## 练习9.22

> 假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？
```cpp
vector<int>::iterator iter = iv.begin(),
					  mid = iv.begin() + iv.size() / 2;
while (iter != mid)
	if (*iter == some_val)
		iv.insert(iter, 2 * some_val);
```