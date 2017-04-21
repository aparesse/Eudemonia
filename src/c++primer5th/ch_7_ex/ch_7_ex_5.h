#ifndef CH_7_EX_5_H
#define CH_7_EX_5_H

#include <string>

class Person
{
	std::string name;
	std::string address;

public:
	const std::string& getName() const
	{
		return name;
	}

	const std::string& getAddress() const 
	{
		return address;
	}
};

#endif
