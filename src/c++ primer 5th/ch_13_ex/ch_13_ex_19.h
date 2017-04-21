#ifndef CH_13_EX_19_H
#define CH_13_EX_19_H

#include <string>
using std::string;

class Employee
{
public:
	Employee();
	Employee(const string& name);
	Employee(const Employee&) = delete; // forbid copy constructor
	Employee& operator=(const Employee&) = delete;

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
