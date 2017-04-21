#ifndef CH_13_EX_11_H
#define CH_13_EX_11_H

#include <string>

class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()):ps(new std::string(s)), i(0) // a constructor
	{
	}
	
	HasPtr(const HasPtr& hp):ps(new std::string(*hp.s)), i(hp.i) //copy constructor
	{
	
	}

	HasPtr& operator=(const HasPtr& hp)
	{
		std::string* new_ps = new std::string(hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this; // the object of reference
	}
	~HasPtr()
	{
		delete ps;
	}

private:
	std::string* ps;
	int i;
};

#endif // CH_13_EX_11_H
