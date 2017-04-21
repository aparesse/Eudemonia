#ifndef CH_7_EX_9_H
#define CH_7_EX_9_H

#include <string>
#include <iostream>

struct Person {
	const std::string& getName() const
	{
		return name;
	}

	const std::string& getAddress() const
	{
		return address;
	}

	std::string name;
	std::string address;
};

std::istream& read(std::istream& is, Person& person)
{
	is >> person.name >> person.address;
	if(!is)
		person = Person();
	return is;
}

std::ostream& print(std::ostream& os, const Person& person)
{
	os << person.name << " " << person.address;
	return os;
}

#endif
