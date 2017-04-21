#ifndef CH_13_EX_48_EXT_H
#define CH_13_EX_48_EXT_H

//This reference http://coolshell.cn/articles/10478.html

#include <utility>
#include <string.h>

class String
{
public:
	String()
		: data_(new char[1])
	{
		*data_ = '\0';
	}

	String(const char* str)
		: data_(new char(strlen(str) + 1))
	{
		strcpy(data_, str);
	}

	String(const String& rhs)
		: data_(new char[rhs.size() + 1])
	{
		strcpy(data_, rhs.c_str());
	}

	/**
	 * Delegate constructor in c++11
	 
	String(const String& rhs)
		:String(rhs.data_)
	{
	}

	**/

	~String()
	{
		delete[] data_;
	}

	/**
	 * Traditional:

	String& operator=(String rhs)
	{
		String tmp(rhs);
		swap(tmp);
		return *this;
	}

	 **/

	String& operator=(String rhs) //yes, pass-by-value
	{
		swap(rhs);
		return *this;
	}

	//c++11
	//以下构造函数可以接受左值，即需要右值的地方可以用左值替代，反之不行。实际使用的是左值的内容
	//rhs是一个rvalue，是一个即将销毁的对象，只能对它进行赋值和销毁。
	//我们也可以调用std::move(rhs)来转成右值
	String(String&& rhs)
		: data_(rhs.data_)
	{
		rhs.data_ = nullptr;
	}

	//c++11
	String& operator=(String&& rhs)
	{
		swap(rhs);
		return *this;
	}

	//Accessors
	size_t size() const
	{
		return strlen(data_);
	}

	const char* c_str() const
	{
		return data_;
	}

	void swap(String& rhs)
	{
		std::swap(data_, rhs.data_);
	}
private:
	char* data_;
};
/**
注意代码的几个要点：
    1.只在构造函数里调用 new char[]，只在析构函数里调用 delete[]。
	2.赋值操作符采用了《C++编程规范》推荐的现代写法。
	3.每个函数都只有一两行代码，没有条件判断。
	4.析构函数不必检查 data_ 是否为 NULL。
	5.构造函数 String(const char* str) 没有检查 str 的合法性，
	这是一个永无止境的争论话题。这里在初始化列表里就用到了 str，
	因此在函数体内用 assert() 是无意义的。
**/

#endif
