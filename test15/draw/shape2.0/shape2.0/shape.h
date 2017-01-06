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
	//ԭ����derived classes ���붨���Լ���draw
	void draw(ShapeColor color = RED)const//NVI(non-virtual interface)�ַ�
	{
		doDraw(color);
	}
	virtual void doDraw(ShapeColor color)const = 0;//pure virtual Ŀ����Ϊ����
								//derived class ֻ�̳к����ӿ�,
								//ÿһ��derived class �����붨���Լ���draw
	//derived classes���Բ������Լ���error��shape��
	virtual void error(const std::string &msg)const;//��pure virtual Ŀ����Ϊ��
								//��derived class �̳иú����Ľӿں�ȱʡʵ�֣�
								//����ֻ��shape �������Լ���error 
								//derived class ����shape��error ������ν��ȱʡʵ��
	//ԭ���� derived classes�����Զ����Լ���objectID��ֻ����Shape
	int objectID()const;//non-virtual Ŀ����Ϊ��
						//�� derived classes �̳к����Ľӿں�һ��ǿ����ʵ��
						//�κ�derived classes ����Ӧ�øı�����Ϊ
						//non-virtual ����������ǲ����ԣ����������
	
};
class Rectangle :public Shape
{
public:
	virtual void doDraw(ShapeColor color)const;//pure virtual ��������
	virtual void error(const std::string &msg)const;//��Ҫ���ر�������
private:
	int length;

};
class Ellipse :public Shape
{
public:
	virtual void doDraw(ShapeColor color)const;//pure virtual ��������
	int objectID()const;//����������Shape�е�objectID()

};