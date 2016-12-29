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
		++*_use;//_use和rhs._use 指向同一个地址
		//浅拷贝，所以一个改变另一个也改变
	}
	smartPointer& operator=(const smartPointer &rhs)
	{
		++*rhs._use;
		if (--*_use == 0)//如果没有其他指针指向原对象，就释放掉
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