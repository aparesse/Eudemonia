#include "ch_13_ex_49_String.h"
#include <algorithm>
#include <iostream>

std::pair<char*, char*>
String::alloc_n_copy(const char* b, const char* e)
{
	auto str = alloc.allocate(e - b);
	return {str, std::uninitialized_copy(b, e, str)};
}

void String::range_initializer(const char* first, const char* last)
{
	auto new_str = alloc_n_copy(first, last);
	elements = new_str.first;
	end = new_str.second;
}

String::String(const char* s)
{
	//const char* s;是底层const，即指针s指向的对象是const的，而指针s本身是可以
	//改变的。const_cast只能改变运算对象底层的const属性
	//所以char* s1 = const_cast<char*>(s);之后，指针s1所指向的底层对象也可以改变
	char* s1 = const_cast<char*>(s);
	while(*s1)
		++s1;
	range_initializer(s, ++s1);
}

String::String(const String& rhs)
{
	std::cout << "copy constructor" << std::endl;
	range_initializer(rhs.elements, rhs.end);
}

void String::free()
{
	if(elements) {
		std::for_each(elements, end, [this](char& c)
				{
					alloc.destroy(&c);
				});
	}
}

String::~String()
{
	free();
}

String& String::operator=(const String& rhs)
{
	std::cout << "copy-assignment operator" << std::endl;
	auto new_str = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = new_str.first;
	end = new_str.second;
	return *this;
}

String::String(String&& s) NOEXCEPT : elements(s.elements), end(s.end)
{
	std::cout << "move constructor" << std::endl;
	s.elements = s.end = nullptr;
}

String& String::operator=(String&& rhs) NOEXCEPT
{
	std::cout << "move-assignment operator" << std::endl;
	if(this != &rhs) {
		free();
		elements = rhs.elements;
		end = rhs.end;
		rhs.elements = rhs.end = nullptr;
	}
	return *this;
}
