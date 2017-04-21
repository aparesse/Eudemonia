#ifndef CH_13_EX_44_H
#define CH_13_EX_44_H

#include <memory>

class String
{
public:
	String() : String("")
	{
	}

	String(const char*); //a constructor,but not the default constructor

	String(const String&); //copy constructor

	String& operator=(const String&); //copy-assignment operator

	~String();

	const char* c_str() const
	{
		return elements;
	}

	size_t size() const
	{
		return end - elements;
	}

	size_t length() const
	{
		return end - elements - 1;
	}
private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);

	void range_initializer(const char*, const char*);

	void free();

private:
	char* elements;
	char* end;
	std::allocator<char> alloc;
};

#endif
