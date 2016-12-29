#include"new.h"
#include<tuple>
void testauto()
{
	auto i = 0;
	auto d = 1.0;
	auto str = "hello world!";
	auto ch = 'A';
	auto p = new Foo;
	auto func = std::less<int>();
	std::cout << "int " << i << std::endl;
	std::cout << "double " << d << std::endl;
	std::cout << "string " << str << std::endl;
	std::cout << "char " << ch << std::endl;
	std::cout << "pointer " << p << std::endl;
	std::cout << "func is " << func(1, 2) << std::endl;
}
void testnullptr()
{
	int *p = nullptr;
	bool equal = (p == NULL);
	int a = NULL;//可以通过
	//int b = nullptr;//无法编译通过 "std::nullptr_t" 类型的值不能用于初始化 "int" 类型的实体	

	std::cout << "nullptr==NULL? " << equal << std::endl;
	std::cout << "nullptr is " << p << std::endl;
}
void testdecltype()
{
	int x = 3;
	decltype(x) y = 9;
	std::cout << "decltype x " << y << std::endl;
}
void testFor()
{
	int a[4] = { 1,0,2,3, };
	for (auto i : a)
		std::cout << i << " ";
	std::cout<<std::endl;
}

void testTuple()
{
	auto t1 = std::make_tuple(1, 2, '3');
	
	std::cout << std::get<2>(t1) << " ";
	std::cout << std::endl;
}