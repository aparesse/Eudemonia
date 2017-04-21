#include "ch_13_ex_47.h"

#include <vector>
#include <iostream>

void foo(String x)
{
	std::cout << x.c_str() << std::endl;
}

void bar(const String& x)
{
	std::cout << x.c_str() << std::endl;
}

String baz()
{
	String ret("world");
	return ret;
}

int main()
{
	char text[] = "world";

	std::cout << "construct s0"<< std::endl;
	String s0;

	std::cout << "construct s1('hellow')" << std::endl;
	String s1("hello");

	std::cout << "constuct s2(s0)" << std::endl;
	String s2(s0);

	std::cout << "constuct s3 = s1" << std::endl;
	String s3 = s1;

	std::cout << "constuct s4(text)" << std::endl;
	String s4(text);

	std::cout << "assign s2 to s1" << std::endl;
	s2 = s1;

	foo(s1);
	std::cout << "==" << std::endl;
	bar(s1);

	//传了一个char*的数据类型来初始化一个String类型的变量作为foo的bar
	//调用的是String(const char*); 构造函数
	//此过程没有调用copy constructor
	foo("temporary");
	bar("temporary");

	std::cout << "aftere foo temporary and bar temporary" << std::endl;

	String s5 = baz();
	std::cout << "construct s5 = baz()" << std::endl;

	std::vector<String> svec;
	svec.reserve(8);
	std::cout << "after reserve(8) svec's size:" << svec.size() << "capacity: " << svec.capacity() << std::endl;
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(s2);
	svec.push_back(s3);
	svec.push_back(s4);
	svec.push_back(s5);
	svec.push_back(baz());
	svec.push_back("good job");


	for(const auto& s : svec) {
		std::cout << s.c_str() << std::endl;
	}
}
