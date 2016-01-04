## 练习8.1

> 编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。

```cpp
std::istream& func(std::istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}
```

## [练习8.2](exercise8_2.cpp)

> 测试函数，调用参数为cin。

## 练习8.3

> 什么情况下，下面的while循环会终止？
```cpp
while (cin >> i) /*  ...    */
```

如果 `badbit`、`failbit`、`eofbit` 的任一个被置位，那么检测流状态的条件会失败。                            

## 练习8.4

> 编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。

```cpp
void ReadFileToVec(const string& fileName, vector<string>& vec)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (getline(ifs, buf))
            vec.push_back(buf);
    }
}
```

## 练习8.5

> 重写上面的程序，将每个单词作为一个独立的元素进行存储。

```cpp
void ReadFileToVec(const string& fileName, vector<string>& vec)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (ifs >> buf)
            vec.push_back(buf);
    }
}
```

## [练习8.6](exercise8_6.cpp)

> 重写7.1.1节的书店程序，从一个文件中读取交易记录。将文件名作为一个参数传递给main。

## [练习8.7](exercise8_7.cpp)

> 修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给main函数。

## [练习8.8](exercise8_8.cpp)

> 修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。

## [练习8.9](exercise8_9.cpp)

> 使用你为8.1.2节第一个练习所编写的函数打印一个istringstream对象的内容。

## [练习8.10](exercise8_10.cpp)

> 编写程序，将来自一个文件中的行保存在一个vector<string>中。然后使用一个istringstream从vector读取数据元素，每次读取一个单词。

## [练习8.11](exercise8_11.cpp)

> 本节的程序在外层while循环中定义了istringstream 对象。如果record 对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将record的定义移到while 循环之外，验证你设想的修改方法是否正确。

## 练习8.12

> 我们为什么没有在PersonInfo中使用类内初始化？

因为这里只需要聚合类就够了，所以没有必要在 PersionInfo 中使用类内初始化。

## [练习8.13](exercise8_13.cpp)

> 重写本节的电话号码程序，从一个命名文件而非cin读取数据。

## 练习8.14

> 我们为什么将entry和nums定义为 const auto& ？

* 它们都是类类型，因此使用引用避免拷贝。
* 在循环当中不会改变它们的值，因此用 const。