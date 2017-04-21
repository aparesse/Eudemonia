#include "ch_13.6.3_cont.h"

using namespace std;

//specific 13.6.6
void StrVec::push_back(string&& s)
{
	chk_n_alloc(); //如果需要的话为StrVec重新分配内存
	alloc.construct(first_free++, std::move(s));
}

void StrVec::push_back(const string& s)
{
	chk_n_alloc(); //确保有空间容纳新元素

	//再first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);	
}

pair<string*, string*>
StrVec::alloc_n_copy(const string*b, const string* e)
{
	//分配空间保存给定范围中的元素
	//分配一段原始的、未构造的内存，保存e-b个类型未string的对象
	auto data = alloc.allocate(e - b);
	//初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
	return {data, uninitialized_copy(b, e, data)};
}

//specific 13.6.2
StrVec::StrVec(StrVec&& s) noexcept //移动操作不应该抛出任何异常
	//成员初始化器接管s中的资源
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	//令s进入这样的状态 -- 对其运行析构函数是安全的	
	//StrVec的析构函数是在first_free上调用deallocate，如果我们忘记了改变
	//s.firest_free，则销毁移后源对象就会释放掉我们刚刚移动的内存
	s.elements = s.first_free = s.cap = nullptr;
}

void StrVec::free()
{
	//不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
	if(elements) {
		//逆序销毁旧元素
		for(auto p = first_free; p != elements; /*空*/) {
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec& s)
{
	//调用alloc_n_copy分配空间以容纳与s中一样多的元素
	//new_data's type is pair<string*, string*>
	auto new_data = alloc_n_copy(s.begin(), s.end());
	elements = new_data.first;
	first_free = cap = new_data.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
	//调用alloc_n_copy分配内存，大小与rhs中元素占用空间一样多
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

//specific 13.6.2
//move-copy-assignment operator
StrVec& StrVec::operator=(StrVec&& rhs) noexcept
{
	//直接检测自赋值，如果是自赋值就什么也不做，就相当于移动拷贝赋值操作了
	if(this != &rhs) { //检测this指针的地址与rhs的地址是否相同
		free(); //释放已有元素
		elements = rhs.elements; //从rhs接管资源
		first_free = rhs.first_free;
		cap = rhs.cap;

		//将rhs置于可析构状态
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::reallocate()
{
	//分配当前大小两倍的内存空间
	auto new_capacity = size() ? 2*size() : 1;
	//分配新内存
	auto new_data = alloc.allocate(new_capacity);

	//将数据从旧内存移动到新内存
	auto dest = new_data; //指向新数组中下一个空闲位置
	auto elem = elements; //指向旧数组中下一个元素
	for(size_t i = 0; i != size(); ++i) 
		alloc.construct(dest++, std::move(*elem++));

	free(); //一旦移动完元素就释放旧内存空间

	//更新我们的数据结构，执行新元素
	elements = new_data;
	first_free = dest;

	cap = elements + new_capacity;
}
