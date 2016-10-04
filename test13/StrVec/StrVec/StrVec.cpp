#include "StrVec.h"
#include<utility>
void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();//ȷ���пռ�������Ԫ��
	alloc.construct(first_free++, s);//��first_freeָ���Ԫ���й���s�ĸ���
}
std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);//����ռ䱣�������Χ�е�Ԫ��
	return{ data,std::uninitialized_copy(b,e,data) };//��ʼ��������һ��pair����pair��data��uninitialized_copy���ص�ֵ����

}
void StrVec::free()
{
	if (elements)//���ܴ��ݸ�deallocateһ����ָ�룬
	{//�������پ�Ԫ��
		for (auto p = first_free; p != elements; alloc.destroy(--p))
		{
			alloc.deallocate(elements, cap - elements);
		}
	}
}


StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());//����alloc_n_copy����ռ���������sһ�����Ԫ��
	elements = newdata.first;
	first_free = cap = newdata.second;

}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());//����alloc_n_copy�����ڴ�
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;//����������С
	auto newdata = alloc.allocate(newcapacity);//���ڴ�
	//�ƶ������ڴ�
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
