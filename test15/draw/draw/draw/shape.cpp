#include"shape.h"
#include<iostream>
#if 1
void Rectangle::draw()const
{
	std::cout << "draw Rectangle" << std::endl;
}
#endif
void Ellipse::draw()const
{
	std::cout << "draw Ellipse" << std::endl;
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
	return 110;
}
int Ellipse::objectID()const//并没有什么卵用
{
	return 120;
}