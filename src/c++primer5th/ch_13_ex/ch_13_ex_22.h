#ifndef CH_13_EX_22_H
#define CH_13_EX_22_H

#include <string>

class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()):ps(new std::string(s)), i(0)
	{
	
	}

	HasPtr(const HasPtr& hp):ps(new std::string(*hp.ps)), i(hp.i) //copy constructor with initializer
	{
	
	}

	HasPtr& operator=(const HasPtr& hp)
	{
		auto new_p = new std::string(*hp.ps);
		delete ps;
		ps = new_p;
		i = hp.i;
		return *this; // *this is the object of reference
	}

private:
	std::string* ps;
	int i;
};

#endif
