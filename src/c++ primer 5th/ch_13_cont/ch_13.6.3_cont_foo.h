#ifndef CH_13_6_3_CONT_FOO_H
#define CH_13_6_3_CONT_FOO_H

#include <vector>

class Foo
{
public:
	Foo sorted() &&; //用于可改变的右值

	//注意参数列表后的const修饰this，表示this指针不能改变，是顶层const
	//而参数列表后的&修饰*this，表示*this是一个左值
	//综合看，const & 可用于任何类型的Foo
	Foo sorted() const &; //用于任何类型的Foo
public:
	Foo& operator=(const Foo&) &; //只能向可修改的左值赋值

	//Comp是函数类型的类型别名
	//此函数类型可以用来比较int值
	using Comp = bool(const int&, const int&);
	Foo sorted(Comp*);
	Foo sorted(Comp*) const;
private:
	std::vector<int> data;
};

#endif
