#pragma once
#include<iostream>
class Point
{
public:
	Point() :_x(0), _y(0) {}
	Point(int x, int y) :_x(x), _y(y) {}
	int &x() { return _x; }
	int &y() { return _y; }
private:
	int _x;
	int _y;
};
class smartPointer
{
public:
	smartPointer(Point p) :_use(new int(1)), _p(new Point(p)) {}
	smartPointer(Point *p) :_use(new int(1)), _p(p) {}
	smartPointer(const smartPointer &rhs):_use(rhs._use),_p(rhs._p)
	{
		++*_use;//_use��rhs._use ָ��ͬһ����ַ
		//ǳ����������һ���ı���һ��Ҳ�ı�
	}
	smartPointer& operator=(const smartPointer &rhs)
	{
		++*rhs._use;
		if (--*_use == 0)//���û������ָ��ָ��ԭ���󣬾��ͷŵ�
		{
			std::cout << "delete the old object\n";
			delete _use;
			delete _p;
		}
		_use = rhs._use;
		_p = rhs._p;
		return *this;
	}
	~smartPointer()
	{
		if (--*_use == 0)
		{
			std::cout << "destroy the smartPointer!\n";
			delete _use;
			delete _p;
		}
	}
private:
	int *_use;
	Point *_p;
};