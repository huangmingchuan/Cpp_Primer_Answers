## 练习5.1

> 什么是空语句？什么时候会用到空语句？

只含义一个单独的分号的语句是空语句。如：
```cpp
;
```
如果在程序的某个地方，语法上需要一条语句但是逻辑上不需要，此时应该使用空语句。
```cpp
while (cin >> s && s != sought)
	;
```

## 练习5.2

> 什么是块？什么时候会用到块？

用花括号括起来的语句和声明的序列就是块。
```cpp
{
	// ...
}
```
如果在程序的某个地方，语法上需要一条语句，而逻辑上需要多条语句，此时应该使用块
```cpp
while (val <= 10) {
	sum += val;
	++val;
}
```

## 练习5.3

> 使用逗号运算符重写1.4.1节的 while 循环，使它不再需要块，观察改写之后的代码可读性提高了还是降低了。

```cpp
while (val <= 10)
    sum += val, ++val;
```
代码的可读性反而降低了。

## 练习5.4

> 说明下列例子的含义，如果存在问题，试着修改它。
```cpp
(a) while (string::iterator iter != s.end()) { /* . . . */ }
(b) while (bool status = find(word)) { /* . . . */ }
		if (!status) { /* . . . */ }
```

* (a) 这个循环试图用迭代器遍历string，但是变量的定义应该放在循环的外面，目前每次循环都会重新定义一个变量，明显是错误的。
* (b) 这个循环的 while 和 if 是两个独立的语句，if 语句中无法访问 status 变量，正确的做法是应该将 if 语句包含在 while 里面，

## [练习5.5](exercise5_5.cpp)

> 写一段自己的程序，使用if else 语句实现把数字转换为字母成绩的要求。

## [练习5.6](exercise5_6.cpp)

> 改写上一题的程序，使用条件运算符代替if else语句。

## 练习5.7

> 改写下列代码段中的错误。
```cpp
(a) if (ival1 != ival2) 
		ival1 = ival2
    else 
    	ival1 = ival2 = 0;
(b) if (ival < minval) 
		minval = ival;
    	occurs = 1;
(c) if (int ival = get_value())
    	cout << "ival = " << ival << endl;
    if (!ival)
    	cout << "ival = 0\n";
(d) if (ival = 0)
    	ival = get_value();
```

* (a) `ival1 = ival2` 后面少了分号。
* (b) 应该用花括号括起来。
* (c) `if (!ival)` 应该改为 `else`。
* (d) `if (ival = 0)` 应该改为 `if (ival == 0)`。

## 练习5.8

> 什么是“悬垂else”？C++语言是如何处理else子句的？

C++语言规定else与它最近的尚未匹配的if匹配。

## [练习5.9](exercise5_9.cpp)

> 编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母。

## [练习5.10](exercise5_10.cpp)

> 我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计元音字母的大写形式，也就是说，新程序遇到'a'和'A'都应该递增 aCnt 的值，以此类推。

## [练习5.11](exercise5_11.cpp)

> 修改统计元音字母的程序，使其也能统计空格、制表符、和换行符的数量。

## [练习5.12](exercise5_12.cpp)

> 修改统计元音字母的程序，使其能统计含以下两个字符的字符序列的数量： ff、fl和fi。

## 练习5.13

> 下面显示的每个程序都含有一个常见的编码错误，指出错误在哪里，然后修改它们。
```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

* (a) 少了 break语句。应该为：
```cpp
	unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
    	case 'a': aCnt++; break;
    	case 'e': eCnt++; break;
    	default: iouCnt++; break;
    }
```
* (b) 在 default 分支当中，ix 未定义。应该在外部定义ix。
```cpp
    unsigned index = some_value();
    int ix;
    switch (index) {
        case 1:
            ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = static_cast<int>(ivec.size())-1;
            ivec[ ix ] = index;
    }
```
* (c) case 后面应该用冒号而不是逗号。
```cpp
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1: case 3: case 5: case 7: case 9:
            oddcnt++;
            break;
        case 2: case 4: case 6: case 8: case 0:
            evencnt++;
            break;
    }
```
* (d) case 标签必须是整型常量表达式。
```cpp
    const unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

