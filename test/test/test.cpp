#include<iostream>
class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
int main()
{
	//const test;const ���ϴ�������Ĺ��ɹ۲죬���Ͼͽ�ԭ��
	//��Ϊconst �޶������Ͳ��ܱ��ı䣬���ԣ��ñ������뱻��ʼ����Ȼ����Զ���ᱻ�ı䡣�����Ա�extern const int buff ����
	//const�����Ͳ��ܸ�ֵ����const���ͣ�
	int a=0;
	int c=1;
	int d=2;
	const int &b=a;//const�����ã�b���ܸı�
	//b=5;//error
	const int *p=&a;//const��pָ�����ֵ���ܱ�
	//*p=4;//error
	int const *q=&c;//const ��qָ�����ֵ���ܱ�
	//*q=d;//error
	const int *const r=&d;//�����ܱ�
	q=&b;
	std::cout<<a<<b<<c<<*q;

	//������������������������������������������������������������������


	//void ָ��.void ָ�����ڴ��ӽǣ�ֻ�����ڴ棬������ָ���κζ��󣬲����ܶ�voidָ��ֱ�Ӳ���

	double obj=3.214;
	void *pv=&obj;
	double *pj=&obj;
	pv=pj;
	//pj=pv; //error


	//*****************************************
	double *&op=pj;//op �Ƕ�ָ��pj�����ã����������Ķ�op�Ķ��壬ָ�������
	
	//********************************************

	typedef double d_next;
	d_next abc;
	typedef MyClass MCC;
	//using MC = MyClass;//why using does not work?
	MCC cdef;
	
	//***********************************************
	//auto 

	auto i=0,*pp=&i;//auto ���ͱ����г�ʼֵ



	return 0;
}