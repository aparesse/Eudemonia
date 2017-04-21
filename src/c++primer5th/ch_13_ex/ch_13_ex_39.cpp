#include "ch_13_ex_39.h"

void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
	auto data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	if(elements) {
		for(auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

 StrVec::StrVec(const StrVec& rhs)
{
	auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
	elements = new_data.first;
	first_free = cap = new_data.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::alloc_n_move(size_t new_cap)
{
	auto new_data = alloc.allocate(new_cap);
	auto dest = new_data;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = new_data;
	first_free = dest;
	cap = elements + new_cap;
}

void StrVec::reallocate()
{
	auto new_capacity = size() ? 2 * size() : 1;
	alloc_n_move(new_capacity);
}

void StrVec::reserve(size_t new_cap)
{
	if(new_cap <= capacity())
		return;
	alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
	resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string& s)
{
	if(count > size()) {
		if(count > capacity())
			reserve(count * 2);
		for(size_t i = size(); i != count; ++i) 
			alloc.construct(first_free++, s);
	} else if(count < size()) {
		while(first_free != elements + count)
			alloc.destroy(--first_free);
	}

}
