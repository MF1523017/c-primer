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
	//const test;const 符合从右至左的规律观察，符合就近原则，
	//因为const 限定的类型不能被改变，所以，该变量必须被初始化，然后将永远不会被改变。但可以被extern const int buff 声明
	//const的类型不能赋值给非const类型，
	int a=0;
	int c=1;
	int d=2;
	const int &b=a;//const的引用，b不能改变
	//b=5;//error
	const int *p=&a;//const的p指向的数值不能变
	//*p=4;//error
	int const *q=&c;//const 的q指向的数值不能变
	//*q=d;//error
	const int *const r=&d;//都不能变
	q=&b;
	std::cout<<a<<b<<c<<*q;

	//×××××××××××××××××××××××××××××××××


	//void 指针.void 指针是内存视角，只能是内存，但可以指向任何对象，并不能对void指针直接操作

	double obj=3.214;
	void *pv=&obj;
	double *pj=&obj;
	pv=pj;
	//pj=pv; //error


	//*****************************************
	double *&op=pj;//op 是对指针pj的引用，从右往左阅读op的定义，指针的引用
	
	//********************************************

	typedef double d_next;
	d_next abc;
	typedef MyClass MCC;
	//using MC = MyClass;//why using does not work?
	MCC cdef;
	
	//***********************************************
	//auto 

	auto i=0,*pp=&i;//auto 类型必须有初始值



	return 0;
}