#include "StrVec.h"
#include<utility>
void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();//确保有空间容纳新元素
	alloc.construct(first_free++, s);//在first_free指向的元素中构造s的副本
}
std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);//分配空间保存给定范围中的元素
	return{ data,std::uninitialized_copy(b,e,data) };//初始化并返回一个pair，该pair由data和uninitialized_copy返回的值构成

}
void StrVec::free()
{
	if (elements)//不能传递给deallocate一个空指针，
	{//逆序销毁旧元素
		for (auto p = first_free; p != elements; alloc.destroy(--p))
		{
			alloc.deallocate(elements, cap - elements);
		}
	}
}


StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());//调用alloc_n_copy分配空间以容纳与s一样多的元素
	elements = newdata.first;
	first_free = cap = newdata.second;

}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());//调用alloc_n_copy分配内存
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;//分配两倍大小
	auto newdata = alloc.allocate(newcapacity);//新内存
	//移动到新内存
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); i++)
	{
		alloc.construct(dest++,std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
StrVec::~StrVec()
{
	free();
}
