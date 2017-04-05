// constructor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class A
{
public:
	A() { cout << "create A" << endl; }
	~A() { cout << "destroy A" << endl; }
};
class B :public A
{
public:
	B(A &a):_a(a) {};
	B() { cout << "create B" << endl; }
	~B() { cout << "destroy B" << endl; }
private:
	A _a;
};
int main()
{
	A a;
	B b(a);
    return 0;
}

