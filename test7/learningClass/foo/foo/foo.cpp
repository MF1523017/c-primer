#include"foo.h"
int Foo::staticVal = 0;//静态成员初始化

ostream &operator<<(ostream &os, const Foo &rhs)//输出
{
	os << rhs._privateVal;
	return os;
}
Foo operator+(const Foo &lhs, const Foo &rhs)//+运算符
{
	int sum = lhs._privateVal + rhs._privateVal;
	return Foo(sum);
}
bool operator==(const Foo &lhs, const Foo &rhs)//==运算符
{
	return lhs._privateVal == rhs._privateVal;
}
Foo::Foo(const Foo &rhs)
{
	*this = rhs;
}
Foo & Foo::operator=(const Foo &rhs)//=赋值操作符
{
	_privateVal = rhs._privateVal;
	return *this;
}

Foo &Foo::operator++()//前置运算符
{
	++_privateVal;
	return *this;
}
Foo Foo::operator++(int)//后置运算符
{
	Foo tmp = *this;
	++*this;
	return tmp;
}
