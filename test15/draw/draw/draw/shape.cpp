#include"shape.h"
#include<iostream>
int Shape::ID = 0;
#if 1
void Shape::draw()const
{
	std::cout << "ghost ,no shape can't draw" << std::endl;
}
void Rectangle::draw()const
{
	std::cout << "draw Rectangle" << std::endl;
}
#endif
void Circle::draw()const
{
	std::cout << "draw Circle" << std::endl;
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
	return getID();
}
