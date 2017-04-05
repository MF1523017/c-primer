#pragma once
#include<functional>
template<typename T>//ģ�����Ͳ���
int compare(const T &lhs, const T &rhs)
{
#if 0
	if (lhs < rhs)
		return -1;
	if (rhs < lhs)
		return 1;
#endif 
	//ʹ��less
	if (std::less<T>()(lhs, rhs))return -1;
	if (std::less<T>()(rhs, lhs))return 1;
	return 0;
}
//compare ����˵���˱�д���ʹ����������Ҫԭ��
//1 ģ���еĺ���������const������
//2 �������е������жϽ�����<�Ƚ�����
template<unsigned N,unsigned M>//������ģ������������ǳ������ʽ�������ǳ������飩
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

//����ģ�����ģ���Ա�����Ķ���ͨ������ͷ�ļ���
void test_func();
