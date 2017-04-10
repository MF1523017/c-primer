#pragma once
#include<iostream>
class Base
{
	//friend bool operator==(const Base &lhs, const Base &rhs);
public:
	Base() = default;
	Base(int a) :_base_a(a) {};
	int getData()const { return _base_a; }
	 
private:
	int _base_a;
};

/*
作为一个例子，我们将为标准库hash模板定义一个特例化版本，可以用它来保存Base
对象，默认情况下无序容器使用hash<key_type>来组织元素。
一个特例化hash类必须定义：
*** 一个重载的调用运算符，它接受一个容器关键字类型的对象，返回一个size_t
*** 两个类型成员，result_type,argument_type，分别调用运算符的返回类型和参数类型
*** 默认构造函数和拷贝赋值操作符（可以隐式定义）

*/
//打开std命名空间
namespace std
{
	template<>// 我们正在定义一个特例化的版本，模板参数为Base
	struct std::hash<Base>
	{
		typedef size_t result_type;
		typedef Base argument_type;
		size_t operator()(const Base &rhs)const
		{
			return std::hash<int>()(rhs.getData());
		}
	};

}//关闭std命名空间，没有"；"

void testSpecialTemplate();