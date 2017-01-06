#pragma once
#include<iostream>
using std::ostream;
class friendClass;
class Foo
{	//����������
	friend ostream &operator<<(ostream &os, const Foo &rhs);//���
	friend Foo operator+(const Foo &lhs, const Foo &rhs);//+
	friend bool operator==(const Foo &lhs, const Foo &rhs);//==
	//��Ԫ
	friend void friendFunc();//friendFunc()�������Է���_privateVal
	friend class friendClass;// friendClass�Ķ�����Է���_privateVal
	//friend void friendClass::f();//friendClass��f()�������Է���_privateVal
public:
	Foo() = default;
	Foo(int v) :_privateVal(v) {};//��ʼ���б�
	Foo(const Foo &rhs);// �������캯��
	Foo & operator=(const Foo &rhs);// ������ֵ������
	~Foo() { ; };//��������
	Foo &operator++();//ǰ�������
	Foo operator++(int);//���������
	int get_PrivateVal()const { return _privateVal; };//const ��Ա����
	static int staticVal;//��̬��Ա
	static int getStaticVal() { return staticVal; }//��̬��Ա����
private:
	int  _privateVal;
};
//ostream &operator<<(ostream &os, const Foo &rhs);