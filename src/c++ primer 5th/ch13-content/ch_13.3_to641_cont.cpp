#include <string>
using std::string;

string read();

void print(const string&);

void print(double); // overload print function

void fooBar(int ival)
{
//	bool read = false; //新作用域：隐藏了外层的read
//	string s = read(); //错误:read是一个布尔值，而非函数
//  不好的习惯：通常来说，在局部作用域中声明函数不是一个好的选择
	void print(int); //新作用域：隐藏了之前的print
//	print("Value: "); //错误：print(const string&)被隐藏掉了
	print(ival); //正确：当前print(int)可见
//	print(3.14); //正确:调用print(int);print(double)被隐藏掉了
}
