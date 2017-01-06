#pragma once
#include<string>
class Figure
{
public:
	Figure() :_id(0) {};
	Figure(int id) :_id(id) {}
	Figure(const Figure &rhs) :_id(rhs._id) {};
	Figure &operator =(const Figure &rhs) {
		if (this == &rhs)
			return *this;
		_id = rhs._id;
		return *this;
	}
	~Figure() { ; }
	 virtual void draw() =0;
private:
	int _id;
};
class Circle :public Figure
{
public:
	Circle(int id, int x, int y, int r) :Figure(id), _x(x), _y(y), _r(r) {};
	Circle(const Circle &rhs){
		*this = rhs;
	};
	Circle &operator=(const Circle &rhs)
	{
		if (this == &rhs)
			return *this;
		(Figure&)(*this) = rhs;
		_x = rhs._x;
		_y = rhs._y;
		_r = rhs._r;
		return *this;
	}
private:
	int _x;
	int _y;
	int _r;
};
	/*1>  class Circle	size(16) :
	1>  	+-- -
	1>   0 | +-- - (base class Figure)
	1>   0 | | _id
	1> | +-- -
	1>   4 | _x
	1>   8 | _y
	1>  12 | _r
	1>  	+-- -*/
//1>  class Circle	size(20) :
//	1>  	+-- -
//	1>   0 | +-- - (base class Figure)
//	1>   0 | | {vfptr}
//1>   4 | | _id
//1> | +-- -
//1>   8 | _x
//1>  12 | _y
//1>  16 | _r
//1>  	+-- -
class Shape
{
public:
	static int ID;
	enum ShapeColor{RED,GREEN,BLUE};
	//原则上derived classes 必须定义自己的draw
	void draw(ShapeColor color = RED)const//NVI(non-virtual interface)手法
	{
		doDraw(color);
	}
	virtual void doDraw(ShapeColor color)const = 0;//pure virtual 目的是为了让
								//derived class 只继承函数接口,
								//每一个derived class 都必须定义自己的draw
	//derived classes可以不定义自己的error用shape的
	virtual void error(const std::string &msg)const;//非pure virtual 目的是为了
								//让derived class 继承该函数的接口和缺省实现，
								//这里只有shape 定义了自己的error 
								//derived class 调用shape的error ，即所谓的缺省实现
	//原则上 derived classes不可以定义自己的objectID，只能用Shape
	int objectID()const;//non-virtual 目的是为了
						//令 derived classes 继承函数的接口和一份强制性实现
						//任何derived classes 都不应该改变其行为
						//non-virtual 代表的意义是不变性，凌驾特异性
	
};
class Rectangle :public Shape
{
public:
	virtual void doDraw(ShapeColor color)const;//pure virtual 必须声明
	virtual void error(const std::string &msg)const;//若要重载必须声明
private:
	int length;

};
class Ellipse :public Shape
{
public:
	virtual void doDraw(ShapeColor color)const;//pure virtual 必须声明
	int objectID()const;//并不能重载Shape中的objectID()

};