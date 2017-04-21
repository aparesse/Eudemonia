#ifndef CH_13_EX_8_H
#define CH_13_EX_8_H

#include <string>

class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()):ps(new std::string(s)), i(0) // a constructor
	{
	}
	HasPtr(const HasPtr& hp):ps(new std::string(*hp.s), i(hp.i)) //copy constructor
	{
	}

	HasPtr& operator=(const HasPtr& hp) //copy operator
	{
		std::string* new_ps = new std::string(*hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this; //*this, the object of reference
	}

private:
	std::string* ps;
	int i;
};

#endif // CH_13_EX_8_H
