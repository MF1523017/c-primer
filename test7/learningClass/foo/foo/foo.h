#pragma once
#include<iostream>
using std::ostream;
class friendClass;
class Foo
{	//操作符重载
	friend ostream &operator<<(ostream &os, const Foo &rhs);//输出
	friend Foo operator+(const Foo &lhs, const Foo &rhs);//+
	friend bool operator==(const Foo &lhs, const Foo &rhs);//==
	//友元
	friend void friendFunc();//friendFunc()函数可以访问_privateVal
	friend class friendClass;// friendClass的对象可以访问_privateVal
	//friend void friendClass::f();//friendClass的f()函数可以访问_privateVal
public:
	Foo() = default;
	Foo(int v) :_privateVal(v) {};//初始化列表
	Foo(const Foo &rhs);// 拷贝构造函数
	Foo & operator=(const Foo &rhs);// 拷贝赋值操作符
	~Foo() { ; };//析构函数
	Foo &operator++();//前置运算符
	Foo operator++(int);//后置运算符
	int get_PrivateVal()const { return _privateVal; };//const 成员函数
	static int staticVal;//静态成员
	static int getStaticVal() { return staticVal; }//静态成员函数
private:
	int  _privateVal;
};
//ostream &operator<<(ostream &os, const Foo &rhs);