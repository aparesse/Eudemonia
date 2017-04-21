#include <iostream>
//without self defined copy constructor,instead of synthetic copy constructor
class numbered
{
public:
	numbered()
	{
		static int unique = 10;
		mysn = unique++;
	}

	int mysn;
};

void f(numbered s)
{
	std::cout << s.mysn << std::endl;
}

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}


