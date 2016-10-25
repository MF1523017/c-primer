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
	r->error(err);//ʹ���Լ���error
	r->Shape::error(err);//ָ��ʹ��Shape��error
	e->error(err);
	e->error("ellipse error");
	std::cout<<r->objectID()<<std::endl;
	std::cout <<e->objectID() << std::endl;//������Ȼ����Ellipse��objectID()����������������У�ֻ�ܽ���Shape��objectID()������
	Ellipse *e2 = new Ellipse;
	std::cout << e2->objectID() << std::endl;//�������뵽Ellipse��objectID()
	return 0;
}