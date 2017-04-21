#ifndef CH_7_EX_21_H
#define CH_7_EX_21_H

#include <string>
#include <iostream>

class Sales_data
{
	friend std::istream& read(std::istream& is, Sales_data& item);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

public:
	Sales_data() = default;
	Sales_data(const std::string& s) : bookNo(s)
	{
	};


};

#endif
