#ifndef CH_13_5_CONT_H
#define CH_13_5_CONT_H

#include <string>
#include <memory>
#include <utility>
//类vector类内存分配策略的简化实现
class StrVec
{
public:
	//allocator成员进行默认初始化
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr)
	{
	}

	StrVec(const StrVec&); //copy constructor

	StrVec& operator=(const StrVec&); //copy assinment operator

	~StrVec(); //deconstructor

	void push_back(const std::string&); //copy element

	size_t size() const
	{
		return first_free - elements;
	}

	size_t capacity() const
	{
		return cap - elements;
	}

	std::string* begin() const
	{
		return elements;
	}

	std::string* end() const
	{
		return first_free;
	}

private:
	static std::allocator<std::string> alloc; //分配元素

	//chk_n_alloc保证StrVec至少有容纳一个新元素的空间
	//如果没有空间添加新元素，chk_n_alloc会调用reallocate来分配更多的内存
	//该被添加元素的函数所使用
	void chk_n_alloc()
	{
		if(size() == capacity()) 
			reallocate();
	}

	//工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
	//alloc_n_copy会分配内存，并拷贝一个给定范围中的元素
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*,
			const std::string*); //pair include file is utility
	void free(); //销毁元素并释放内存
	void reallocate(); //获得更多内存并拷贝已有元素
	std::string* elements; //指向数组首元素的指针
	std::string* first_free; //指向数组第一个空闲元素的指针
	std::string* cap; //指向数组尾后位置的指针
};

#endif
