#pragma once
#include<functional>
template<typename T>//模板类型参数
int compare(const T &lhs, const T &rhs)
{
#if 0
	if (lhs < rhs)
		return -1;
	if (rhs < lhs)
		return 1;
#endif 
	//使用less
	if (std::less<T>()(lhs, rhs))return -1;
	if (std::less<T>()(rhs, lhs))return 1;
	return 0;
}
//compare 函数说明了编写泛型代码的两个重要原则
//1 模板中的函数参数是const的引用
//2 函数体中的条件判断仅适用<比较运算
template<unsigned N,unsigned M>//非类型模板参数（必须是常量表达式，这里是常量数组）
int compare(const char(&p1)[N], const char(&p2)[M])
{
	return strcmp(p1, p2);
}

//inline
template<typename T> 
inline T min(const T &lhs, const T &rhs)
{
	//return lhs < rhs ? lhs : rhs;
	return std::less<T>()(lhs, rhs) ? lhs : rhs;
}

//函数模板和类模板成员函数的定义通常放在头文件中
void test_func();
