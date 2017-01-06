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
	//d ����Base &bʱ���иֻ��d�е�Base���֣�Ҳ����ֻ��һ����ָ�뱻����b�������ܹ���̬�󶨣����ʵ�D�е�method1���޷�����D�е�method2��
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
//	result:����~Base()�����麯��������delete b[i]ɾ������Base�Ķ���ֻ�����Base����������
//	base::destroy
//	base::destroy
//	base::destroy
	//�����������������Ϊvirtual ~Base()
	//result:���������������ڽ��������������
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
