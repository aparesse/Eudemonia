#ifndef CH_13_EX_18_H
#define CH_13_EX_18_H

#include <string>
using std::string;

class Employee
{
public:
	Employee();
	Employee(const string& name);

	const int id() const
	{
		return id_;
	}

private:
	string name_;
	int id_;
	static int s_increment;
};

#endif
