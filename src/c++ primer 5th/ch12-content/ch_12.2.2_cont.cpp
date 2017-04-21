#include <iostream>
#include <string>
#include <memory>
#include <vector>

#define N = 1024

int new_string_cont(int);

int allocator_cont(int);

int main()
{
	allocator_cont(100);
	return 0;
}

int new_string_cont(int n)
{
	std::string* const p = new std::string[n]; //构造n个空string
	std::string s;
	std::string* q =p; //q指向第一个strinig
	while(std::cin >> s && q != p + n) {
		*q++ = s; //赋予*q一个新值  Post-increment prior to *
	}
	const size_t size = q - p; //记住我们读取了多少个string
	std::cout << size << std::endl;
	//使用数组
	delete[] p; //p指向一个数组;记得用delete[]来释放
	return 0;
}

int allocator_cont(int n)
{
	std::allocator<std::string> alloc; //可以分配string的allocator对象
	auto const p = alloc.allocate(n); //分配n个未初始化的string
	auto q = p; //q指向最后构造的元素之后的位置
	std::cout << "*p " << *p << std::endl; //correct:使用string的输出运算符
	std::cout << "*q" << *q << std::endl; //error:q指向未构造的内存
	alloc.construct(q++); //*q为空字符串
	std::cout << "1--*q" << *q << std::endl; 
	alloc.construct(q++, 10, 'c'); //*q为cccccccccc
	std::cout << "2--*q" << *q << std::endl; 
	alloc.construct(q++, "hi"); //*q为hi
	std::cout << "3--*q" << *q << std::endl; 
	
	//当我们用完对象后，必须对每个构造的元素调用destroy来销毁它们。
	//函数destroy
	while(q != p) {
		alloc.destroy(--q); //释放我们真正构造的string
	}

	alloc.deallocate(p, n);
	return 0;
}

int uninitialzed_operator_cont()
{
	std::vector<int> vi;
	int i = 5;
	vi.push_back(i);
	vi.push_back(i);
	vi.push_back(i);
	vi.push_back(i);
	std::cout << "vi.size()" << vi.size() << std::endl;

	std::allocator<int> alloc;
	//分配比vi中元素所占用空间大一倍的动态内存
	auto p = alloc.allocate(vi.size() * 2);
	//通过拷贝vi中的元素来构造从p开始的元素
	auto q = std::uninitialized_copy(vi.begin(), vi.end(), p);

	//将剩余元素初始化为42
	std::uninitialized_fill_n(q, vi.size(), 42);
	return 0;
}
