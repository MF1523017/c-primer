#include"shape.h"
#include<iostream>
int main(int argc, char **argv)
{
	//Shape *p = new Shape;//error Shape is abstract
	Shape *r = new Rectangle;//r�Ǿ�̬���ͣ�rָ����Ƕ�̬����
	Shape *e = new Ellipse;
	r->draw();//����shape�е�draw������Ȼ����ø��Ե�doDraw����
	e->draw(Shape::BLUE);
	std::cout<<e->objectID();
	std::cout <<r->objectID();
	return 0;
}