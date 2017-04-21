#include "ch_13.6.3_cont_foo.h"
#include<algorithm> //sort

//本对象为右值，因此可以原址排序
Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	return *this;
}	

//本对象是const或是一个左值，哪种情况我们都不能对其进行原址排序
Foo Foo::sorted() const & 
{
	Foo ret(*this); //拷贝一个副本
	sort(ret.data.begin(), ret.data.end()); //排序副本
	return ret;
}
