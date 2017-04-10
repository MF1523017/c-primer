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
��Ϊһ�����ӣ����ǽ�Ϊ��׼��hashģ�嶨��һ���������汾����������������Base
����Ĭ���������������ʹ��hash<key_type>����֯Ԫ�ء�
һ��������hash����붨�壺
*** һ�����صĵ����������������һ�������ؼ������͵Ķ��󣬷���һ��size_t
*** �������ͳ�Ա��result_type,argument_type���ֱ����������ķ������ͺͲ�������
*** Ĭ�Ϲ��캯���Ϳ�����ֵ��������������ʽ���壩

*/
//��std�����ռ�
namespace std
{
	template<>// �������ڶ���һ���������İ汾��ģ�����ΪBase
	struct std::hash<Base>
	{
		typedef size_t result_type;
		typedef Base argument_type;
		size_t operator()(const Base &rhs)const
		{
			return std::hash<int>()(rhs.getData());
		}
	};

}//�ر�std�����ռ䣬û��"��"

void testSpecialTemplate();