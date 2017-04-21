#ifndef CH_13_22_CONT_H
#define CH_13_22_CONT_H

#include <string>
class HasPtr
{
public:
	//构造函数分配新的string和新的计数器，将计数器置为1
	HasPtr(const std::string&s = std::string()):
		ps(new std::string(s)), i(0), use(new std::size_t(1))
	{
	}

	HasPtr& operator=(const HasPtr& rhs);

	//拷贝构造函数拷贝所有三个数据成员，并递增计数器
	HasPtr(const HasPtr& p):
		ps(p.ps), i(p.i), use(p.use)
	{
		++*use;
	}

	~HasPtr();

private:
	std::string* ps;
	int i;
	std::size_t* use; //用来记录又多少个对象共享*ps的成员
};

#endif
