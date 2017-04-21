#include <iostream>
#include <vector>
#include <initializer_list>

struct X
{
	X()
	{
		std::cout << "X()" << std::endl;
	}

	X(const X&) //copy constructor
	{
		std::cout << "X(const X&)" << std::endl;
	}

	X& operator=(const X&) //copy operator
	{
		std::cout << "X& operator=(const X&)" << std::endl;
		return *this;
	}

	~X() 
	{
		std::cout << "~X()" << std::endl;
	}
};

// f function's param list, (X x)值传递,会调用拷贝构造
void f(const X& rx, X x)
{
	std::cout << "vector operating 1" << std::endl;
	std::vector<X> vec;
	std::cout << "vector operating 2" << std::endl;
	vec.reserve(2);
	std::cout << "vector operating 3" << std::endl;
	vec.push_back(rx);
	std::cout << "vector operating 4" << std::endl;
	vec.push_back(x);
}

int main()
{
	X* px = new X;
	std::cout << "call f" << std::endl;
	f(*px, *px);
	delete px;
	std::cout << "after delete px" << std::endl;

	return 0;
}
