#include<iostream>

class Counter
{
	int _own;
	static int _shared;
public:
	Counter() :_own(0) {};
	void f1() { _own = 0; _shared = 1; }
	static void f2() { //_own = 2; //static funcֻ�ܷ��ʾ�̬��Ա
		_shared = 3; }
	void f3()const { //_own = 4; //const���εĳ�Ա���������ܸı�Ǿ�̬��Ա����
		_shared = 5; }
};
int Counter::_shared = 0;
int main(int argc, char **argv)
{
	Counter c;
	const Counter d = c;
	//d.f1();//d��const Counter�����ܵ��÷�const��Ա����
	d.f2();
	d.f3();
	return 0;
}