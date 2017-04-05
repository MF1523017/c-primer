#pragma once
#include<iostream>
/*һ���ࣨ��������ͨ�໹����ģ�壩���԰���������ģ��ĳ�Ա���������ֳ�Ա����Ϊ��Աģ�塣��Աģ�岻�����麯��*/
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
