#pragma once
#include<string>
class Shape
{
public:
	static int ID;
	//原则上derived classes 必须定义自己的draw
	virtual void draw()const = 0;//pure virtual 目的是为了让
								//derived class 只继承函数接口,
								//每一个derived class 都必须定义自己的draw
	//derived classes可以不定义自己的error用shape的
	virtual void error(const std::string &msg="ghost,no error")const;//非pure virtual 目的是为了
								//让derived class 继承该函数的接口和缺省实现，
								//这里只有shape 定义了自己的error 
								//derived class 调用shape的error ，即所谓的缺省实现
	//原则上 derived classes不可以定义自己的objectID，只能用Shape
	int objectID()const;//non-virtual 目的是为了
						//令 derived classes 继承函数的接口和一份强制性实现
						//任何derived classes 都不应该改变其行为
						//non-virtual 代表的意义是不变性，凌驾特异性
private:
	virtual int getID()const = 0;
};
class Rectangle :public Shape
{
public:
	//Rectangle() = default;
	Rectangle(int l, int w) :_length(l), _width(w),_id(++Shape::ID) {};
	virtual void draw()const;//pure virtual 必须声明
	virtual void error(const std::string &msg)const;//若要重载必须声明
	virtual int getID()const { return _id; };
private:
	int _length;
	int _width;
	int _id;

};
class Circle :public Shape
{
public:
	//Circle ()= default;
	Circle(int r) :_radius(r), _id(++Shape::ID){  };
	virtual void draw()const;//pure virtual 必须声明
	virtual int getID()const { return _id; };
private:
	int _radius;
	int _id;
};