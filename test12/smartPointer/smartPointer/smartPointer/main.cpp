#include"smartPointer.h"
#include<iostream>
#include<memory>
struct owner
{
	std::weak_ptr<owner> other;
};
//循环引用,可用使用weak_ptr来解决循环引用问题
void  circular_references()
{
	std::shared_ptr<owner>p1(new owner());
	{
		//p1->other(1)->p2->other(2)->p1//构成了一个环，循环引用的问题，退出该作用域的时候，发现p1依然有两个引用，没有被释放
		std::shared_ptr<owner>p2(new owner());
		p1->other = p2;
		p2->other = p1;//other是weak_ptr指针，并不会增加共享对象的引用计数，所以避免了循环引用带来的问题
			//退出该作用域的时候发现p1只有一个引用
		//std::weak_ptr<owner>p3(p2);//这里虽然p2,p3都指向了new owner但是由于p3是weak_ptr并不会改变p2的引用计数
	}
	int i = 0;
}
void unique_ptrTest()
{
	std::unique_ptr<double> p1(new double(3));
	//std::unique_ptr<double> p2(p1);//error，unique_ptr不支持拷贝
	//std::unique_ptr<double> p3 = p1;//error，unique_ptr 不支持赋值
	p1.reset(new double(4));
}
void share_ptrTest()
{
	std::shared_ptr<int> pt(new int(3));
	int i = 0;
	{
		std::shared_ptr<int> ptCopy = pt;
		int j = 1;
		//ptCopy 和pt都指向了int(3),引用计数为2
	}
	//pt = new int(4);//error 不能将一个指针赋予shared_ptr
	pt.reset(new int(4));//pt指向了一个新对象
}
void smartPointerTest()
{
	smartPointer sp(new Point(2, 3));//*_use=1
	{
		smartPointer sp2 (sp);//*_use=2
		smartPointer sp3 = sp2;//*_use=3
		sp2 = new Point(4, 3);//*sp2._use=1，（在拷贝复制的时候，
							//--*_use,改变了指向Point(2,3)的指针个数）
						//*sp._use=*sp3._use=2
		sp2 = new Point(5, 3);//*sp2._use=1,(sp2原对象被释放)
						//因为没有其他的指针指向Point(4,3),所以被释放
						//*sp._use=*sp3._use=2
	}
}
int main(int argc, char **argv) 
{
	circular_references();
	unique_ptrTest();
	share_ptrTest();
	smartPointerTest();
	return 0;
}