#include "ch_13_ex_49_String.h"
#include <iostream>

String baz()
{
	String ret("world");
	return ret; //函数返回一个非引用的数据类型的情况，返回值为右值，这里就使用了移动构造
}

String& bas(String& s)
{
	return s;
}

int main()
{
	String s1 = baz(); //因为baz()返回的是右值,初始化s5的时候用的也是移动构造
	std::cout << s1.c_str() << std::endl;
	
	bas(s1);
	std::cout << "=======" << std::endl;

	String s2 = bas(s1);
	std::cout << s2.c_str() << std::endl;
	return 0;
}
