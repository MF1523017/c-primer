#pragma once
#include<iostream>
/*一个类（无论是普通类还是类模板）可以包含本身是模板的成员函数。这种成员被称为成员模板。成员模板不能是虚函数*/
class DebugDelete
{
public:
	DebugDelete(std::ostream &s = std::cerr) :os(s) {};
	template<typename T>void operator()(T *p)const
	{
		os << "delete unique_ptr" << std::endl;
		delete p;
	}
private:
	std::ostream &os;
};

void testMemTemplate();
