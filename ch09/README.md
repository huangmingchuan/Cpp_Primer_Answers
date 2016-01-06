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

`begin` 返回的是普通迭代器，`cbegin` 返回的是常量迭代器。

## 练习9.10

> 下面4个对象分别是什么类型？
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

这里的代码在 VS2013 下是有错误的。
* 错误	1	error C3538: 在声明符列表中，“auto”必须始终推导为同一类型	
因此代码要改为

```cpp
auto it1 = v1.begin();
auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```

`it1` 是 `vector<int>::iterator`

`it2`，`it3` 和 `it4` 是 `vector<int>::const_iterator`


## 练习9.11

> 对6种创建和初始化 vector 对象的方法，每一种都给出一个实例。解释每个vector包含什么值。

```cpp
vector<int> vec;    // 0
vector<int> vec(10);    // 0
vector<int> vec(10, 1);  // 1
vector<int> vec{ 1, 2, 3, 4, 5 }; // 1, 2, 3, 4, 5
vector<int> vec(other_vec); // 拷贝 other_vec 的元素
vector<int> vec(other_vec.begin(), other_vec.end()); // 拷贝 other_vec 的元素
```

## 练习9.12

> 对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

* 接受一个容器创建其拷贝的构造函数，必须容器类型和元素类型都相同。
* 接受两个迭代器创建拷贝的构造函数，只需要元素的类型能够相互转换，容器类型和元素类型可以不同。

## [练习9.13](exercise9_13.cpp)

> 如何从一个list<int>初始化一个vector<double>？从一个vector<int>又该如何创建？编写代码验证你的答案。

```cpp
list<int> ilst(5, 4);
vector<int> ivc(5, 5);

vector<double> dvc(ilst.begin(), ilst.end());
vector<double> dvc2(ivc.begin(), ivc.end());
```

## 练习9.14

> 编写程序，将一个list中的char * 指针元素赋值给一个vector中的string。

```cpp
    std::list<const char*> l{ "hello", "world" };
    std::vector<std::string> v;
    v.assign(l.cbegin(), l.cend());
```

## 练习9.15

> 编写程序，判定两个vector<int>是否相等。

```cpp
    std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::vector<int> vec2{ 1, 2, 3, 4, 5 };
    std::vector<int> vec3{ 1, 2, 3, 4 };

    std::cout << (vec1 == vec2 ? "true" : "false") << std::endl;
    std::cout << (vec1 == vec3 ? "true" : "false") << std::endl;
```

## 练习9.16

> 重写上一题的程序，比较一个list<int>中的元素和一个vector<int>中的元素。

```cpp
    std::list<int>      li{ 1, 2, 3, 4, 5 };
    std::vector<int>    vec2{ 1, 2, 3, 4, 5 };
    std::vector<int>    vec3{ 1, 2, 3, 4 };

    std::cout << (std::vector<int>(li.begin(), li.end()) == vec2 ? "true" : "false") << std::endl;
    std::cout << (std::vector<int>(li.begin(), li.end()) == vec3 ? "true" : "false") << std::endl;
```

## 练习9.17

> 假定c1 和 c2 是两个容器，下面的比较操作有何限制？
```cpp
	if (c1 < c2)
```

* c1 和 c2 必须是相同类型的容器并且保存相同类型的元素
* 元素类型要支持关系运算符

## [练习9.18](exercise9_18.cpp)

> 编写程序，从标准输入读取string序列，存入一个deque中。编写一个循环，用迭代器打印deque中的元素。

## 练习9.19

> 重写上一题的程序，用list替代deque。列出程序要做出哪些改变。

只需要在声明上做出改变即可，其他都不变。
```cpp
deque<string> input; 
//改为
list<string> input;
```

## [练习9.20](exercise9_20.cpp)

> 编写程序，从一个list<int>拷贝元素到两个deque中。值为偶数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。

## 练习9.21

> 如果我们将第308页中使用 insert 返回值将元素添加到list中的循环程序改写为将元素插入到vector中，分析循环将如何工作。

一样的。如书上所说：
> 第一次调用 `insert` 会将我们刚刚读入的 `string` 插入到 `iter` 所指向的元素之前的位置。`insert` 返回的迭代器恰好指向这个新元素。我们将此迭代器赋予 `iter` 并重复循环，读取下一个单词。只要继续有单词读入，每步 while 循环就会将一个新元素插入到 `iter` 之前，并将 `iter` 改变为新加入元素的尾置。此元素为（新的）首元素。因此，每步循环将一个元素插入到 `list` 首元素之前的位置。

## 练习9.22

> 假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？
```cpp
vector<int>::iterator iter = iv.begin(),
					  mid = iv.begin() + iv.size() / 2;
while (iter != mid)
	if (*iter == some_val)
		iv.insert(iter, 2 * some_val);
```

* 循环不会结束
* 迭代器可能会失效

要改为下面这样：
```cpp
while (iter != mid)
{
	if (*iter == some_val)
	{
		iter = v.insert(iter, 2 * some_val);
		++iter;
    }
	++iter;
}
```

## 练习9.23

> 在本节第一个程序中，若 c.size() 为1，则val、val2、val3和val4的值会是什么？

都会是同一个值（容器中仅有的那个）。

## [练习9.24](exercise9_24.cpp)

> 编写程序，分别使用 at、下标运算符、front 和 begin 提取一个vector中的第一个元素。在一个空vector上测试你的程序。

## 练习9.25

> 对于第312页中删除一个范围内的元素的程序，如果 elem1 与 elem2 相等会发生什么？如果 elem2 是尾后迭代器，或者 elem1 和 elem2 皆为尾后迭代器，又会发生什么？

* 如果 elem1 和 elem2 相等，那么不会发生任何操作。
* 如果elem2 是尾后迭代器，那么删除从 elem1 到最后的元素。
* 如果两者皆为尾后迭代器，也什么都不会发生。

## 练习9.26

> 使用下面代码定义的ia，将ia 拷贝到一个vector和一个list中。是用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。
```cpp
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
```

```cpp
vector<int> vec(ia, end(ia));
list<int> lst(vec.begin(), vec.end());

for (auto it = lst.begin(); it != lst.end(); )
	if (*it & 0x1)
		it = lst.erase(it);
	else 
		++it;

for (auto it = vec.begin(); it != vec.end(); )
	if (!(*it & 0x1))
		it = vec.erase(it);
	else
		++it;			
```

## [练习9.27]()

> 编写程序，查找并删除forward_list<int>中的奇数元素。

## 练习9.28

> 编写函数，接受一个forward_list<string>和两个string共三个参数。函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string之后的位置。若第一个string未在链表中，则将第二个string插入到链表末尾。

## 练习9.29

> 假定vec包含25个元素，那么vec.resize(100)会做什么？如果接下来调用vec.resize(10)会做什么？

## 练习9.30

> 接受单个参数的resize版本对元素类型有什么限制（如果有的话）？

## 练习9.31

> 第316页中删除偶数值元素并复制奇数值元素的程序不能用于list或forward_list。为什么？修改程序，使之也能用于这些类型。

## 练习9.32

> 在第316页的程序中，向下面语句这样调用insert是否合法？如果不合法，为什么？
```cpp
iter = vi.insert(iter, *iter++);
```

## 练习9.33

> 在本节最后一个例子中，如果不将insert的结果赋予begin，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

## 练习9.34

> 假定vi是一个保存int的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。

## 练习9.35

> 解释一个vector的capacity和size有何区别。

## 练习9.36

> 一个容器的capacity可能小于它的size吗？

## 练习9.37

> 为什么list或array没有capacity成员函数？

## 练习9.38

> 编写程序，探究在你的标准实现中，vector是如何增长的。

## 练习9.39

> 解释下面程序片段做了什么：
```cpp
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
	svec.push_back(word);
svec.resize(svec.size() + svec.size() / 2);
```

