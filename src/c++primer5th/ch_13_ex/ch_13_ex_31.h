#ifndef CH_13_EX_31_H
#define CH_13_EX_31_H

#include <string>
#include <iostream>

class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);

	HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
	{
	
	}

	HasPtr& operator=(HasPtr tmp)
	{
		this->swap(tmp);
		return *this;
	}

	~HasPtr()
	{
		delete ps;
	}

	void swap(HasPtr& rhs)
	{
		using std::swap;
		swap(ps, rhs.ps);
		swap(i, rhs.i);
		std::cout << "call swap(HasPtr& rhs)" << std::endl;
	}

	void show() const
	{
		std::cout << *ps << std::endl;
	}

private:
	std::string* ps;
	int i;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	lhs.swap(rhs);
}

bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
	return *lhs.ps < *rhs.ps;
}

#endif
