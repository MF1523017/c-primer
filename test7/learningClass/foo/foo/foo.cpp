#include"foo.h"
int Foo::staticVal = 0;//��̬��Ա��ʼ��

ostream &operator<<(ostream &os, const Foo &rhs)//���
{
	os << rhs._privateVal;
	return os;
}
Foo operator+(const Foo &lhs, const Foo &rhs)//+�����
{
	int sum = lhs._privateVal + rhs._privateVal;
	return Foo(sum);
}
bool operator==(const Foo &lhs, const Foo &rhs)//==�����
{
	return lhs._privateVal == rhs._privateVal;
}
Foo::Foo(const Foo &rhs)
{
	*this = rhs;
}
Foo & Foo::operator=(const Foo &rhs)//=��ֵ������
{
	_privateVal = rhs._privateVal;
	return *this;
}

Foo &Foo::operator++()//ǰ�������
{
	++_privateVal;
	return *this;
}
Foo Foo::operator++(int)//���������
{
	Foo tmp = *this;
	++*this;
	return tmp;
}
