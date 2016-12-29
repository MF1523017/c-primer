#include"shape.h"
#include<iostream>
int Shape::ID = 0;
#if 1
void Shape::doDraw(ShapeColor color = RED)const
{
	std::cout << color << std::endl;
}
#endif
#if 1
void Rectangle::doDraw(ShapeColor color)const
{
	std::cout <<"Rectangle color is "<< color << std::endl;
}
#endif
void Ellipse::doDraw(ShapeColor color)const
{
	std::cout <<"Ellipse color is "<< color << std::endl;
}
void Shape::error(const std::string &msg)const
{
	std::cout << msg << std::endl;
}
void Rectangle::error(const std::string &msg)const
{
	std::cout << "Rectangle " << msg << std::endl;
}
int Shape::objectID()const
{
	return ++Shape::ID;
}
int Ellipse::objectID()const//并没有什么卵用
{
	return 120;
}