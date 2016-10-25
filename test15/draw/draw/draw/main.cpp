#include"shape.h"
#include<iostream>
int main(int argc, char **argv)
{
	//Shape *p = new Shape;//error Shape is abstract
	Shape *r = new Rectangle;
	Shape *e = new Ellipse;
	r->draw();
	e->draw();
	std::string err("error");
	r->error(err);//使用自己的error
	r->Shape::error(err);//指定使用Shape的error
	e->error(err);
	e->error("ellipse error");
	std::cout<<r->objectID()<<std::endl;
	std::cout <<e->objectID() << std::endl;//这里虽然定了Ellipse的objectID()但，并不会进入其中，只能进入Shape的objectID()函数内
	Ellipse *e2 = new Ellipse;
	std::cout << e2->objectID() << std::endl;//这里会进入到Ellipse的objectID()
	return 0;
}