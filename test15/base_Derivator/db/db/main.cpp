#include<iostream>
using std::cout;
using std::endl;
class Base
{
public:
	virtual void method1() { cout << "base::method1" << endl; }
	void method2() { cout << "base::method2" << endl; }
	virtual ~Base() { cout << "base::destroy" << endl; }
};
class D :public Base
{
public:
	void method1() { cout << "D::method1" << endl; }
	void method2() { cout << "D::method2" << endl; }
	~D() { cout << "D::destroy" << endl; }
};
template <class T>
void func1(T &t)
{
	t.method1();
	t.method2();
}
void func2(Base &t)
{
	t.method1();
	t.method2();
}
void testBaseD()
{
	D d;
	cout << "1" << endl;
	func1(d);
	cout << "2" << endl;
	//d 赋给Base &b时被切割，只有d中的Base部分，也就是只有一个虚指针被赋予b。所以能够动态绑定，访问到D中的method1，无法访问D中的method2，
	func2(d);//D::method1
			 //base::method2
	cout << "3" << endl;
	d.method1();
	d.method2();
	//result:
	//	1
	//	D::method1
	//	D::method2
	//	2
	//	D::method1
	//	base::method2
	//	3
	//	D::method1
	//	D::method2
}
void testDestroy()
{
	Base *b[3];
	b[0] = new D;
	b[1] = new D;
	b[2] = new D;
	for (int i = 0; i < 3; ++i)
		delete b[i];
//	result:由于~Base()不是虚函数，所以delete b[i]删除的是Base的对象，只会进入Base的析构函数
//	base::destroy
//	base::destroy
//	base::destroy
	//如果把析构函数设置为virtual ~Base()
	//result:会先析构派生类在进入基类里面析构
	/*	D::destroy
		base::destroy
		D::destroy
		base::destroy
		D::destroy
		base::destroy*/
}
int main(int argc, char **argv)
{
	//testBaseD();
	testDestroy();
	return 0;
}
