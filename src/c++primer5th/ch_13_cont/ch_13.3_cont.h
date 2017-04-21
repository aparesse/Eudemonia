#ifndef CH_13_3_CONT_H
#define CH_13_3_CONT_H

#include <string>

class HasPtr
{
public:
	//我们首先将swap定义为friend，以便能访问HasPtr的(private的)数据成员
	friend void swap(HasPtr&, HasPtr&);

	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0)
	{
	}
	
	HasPtr(const HasPtr& p):
		ps(new std::string(*p.ps)), i(p.i)
	{
	}

	HasPtr& operator=(const HasPtr&);

	~HasPtr()
	{
		delete ps;
	}

private:
	std::string* ps;
	int i;

};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps); //交换指针，而不是string数据
	swap(lhs.i, rhs.i); //交换int成员
}

#endif
