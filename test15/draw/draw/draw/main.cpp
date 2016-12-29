#include"shape.h"
#include<iostream>
void testDraw()
{
	Shape *r = new Rectangle(1, 2);
	Shape *c = new Circle(3);
	r->draw();
	c->draw();
}
void testError()
{
	Shape *r = new Rectangle(1, 2);
	Shape *c = new Circle(3);
	
	r->error("error");//指定使用Shape的error
	c->error();
	//c->error("circle error");
}
void testObjectID()
{
	Shape *r = new Rectangle(1, 2);
	Shape *c = new Circle(3);
	std::cout << r->objectID() << std::endl;
	std::cout << c->objectID() << std::endl;
}
int main(int argc, char **argv)
{
	//Shape *p = new Shape;//error Shape is abstract
	//testDraw();
	//testError();
	testObjectID();
	
	return 0;
}