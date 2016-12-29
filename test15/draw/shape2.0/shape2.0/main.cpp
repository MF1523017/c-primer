#include"shape.h"
#include<iostream>
int main(int argc, char **argv)
{
	//Shape *p = new Shape;//error Shape is abstract
	Shape *r = new Rectangle;//r是静态类型，r指向的是动态类型
	Shape *e = new Ellipse;
	r->draw();//调用shape中的draw函数，然后调用各自的doDraw函数
	e->draw(Shape::BLUE);
	std::cout<<e->objectID();
	std::cout <<r->objectID();
	return 0;
}