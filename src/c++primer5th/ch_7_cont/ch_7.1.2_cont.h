#ifndef CH_7_1_2_CONT_H
#define CH_7_1_2_CONT_H

#include <string>

struct Sales_data
{
	//定义在类内部的函数是隐式的inline函数
	std::string isbn() const 
	{
		return bookNo;
	}

	Sales_data& combine(const Sales_data&);

	double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


//Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
#endif
