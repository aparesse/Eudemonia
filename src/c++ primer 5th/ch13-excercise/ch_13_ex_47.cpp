#include "ch_13_ex_47.h"

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
	char* s1 = const_cast<char*>(s);
	while(*s1)
		++s1;
	range_initializer(s, ++s1);
}

String::String(const String& rhs)
{
	range_initializer(rhs.elements, rhs.end);
	std::cout << " copy constructor " << std::endl;
}

void String::free()
{
	if(elements) {
		std::for_each(elements, end, [this](char& c)
				{
					alloc.destroy(&c);
				});
		alloc.deallocate(elements, end - elements);
	}
}

String::~String()
{
	free();
}

String& String::operator=(const String& rhs)
{
	auto new_str = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = new_str.first;
	end = new_str.second;
	std::cout << " copy-assignment operator " << std::endl;
	return *this;
}
