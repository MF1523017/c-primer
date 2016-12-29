#include"smartPointer.h"
#include<iostream>
#include<memory>
struct owner
{
	std::weak_ptr<owner> other;
};
//ѭ������,����ʹ��weak_ptr�����ѭ����������
void  circular_references()
{
	std::shared_ptr<owner>p1(new owner());
	{
		//p1->other(1)->p2->other(2)->p1//������һ������ѭ�����õ����⣬�˳����������ʱ�򣬷���p1��Ȼ���������ã�û�б��ͷ�
		std::shared_ptr<owner>p2(new owner());
		p1->other = p2;
		p2->other = p1;//other��weak_ptrָ�룬���������ӹ����������ü��������Ա�����ѭ�����ô���������
			//�˳����������ʱ����p1ֻ��һ������
		//std::weak_ptr<owner>p3(p2);//������Ȼp2,p3��ָ����new owner��������p3��weak_ptr������ı�p2�����ü���
	}
	int i = 0;
}
void unique_ptrTest()
{
	std::unique_ptr<double> p1(new double(3));
	//std::unique_ptr<double> p2(p1);//error��unique_ptr��֧�ֿ���
	//std::unique_ptr<double> p3 = p1;//error��unique_ptr ��֧�ָ�ֵ
	p1.reset(new double(4));
}
void share_ptrTest()
{
	std::shared_ptr<int> pt(new int(3));
	int i = 0;
	{
		std::shared_ptr<int> ptCopy = pt;
		int j = 1;
		//ptCopy ��pt��ָ����int(3),���ü���Ϊ2
	}
	//pt = new int(4);//error ���ܽ�һ��ָ�븳��shared_ptr
	pt.reset(new int(4));//ptָ����һ���¶���
}
void smartPointerTest()
{
	smartPointer sp(new Point(2, 3));//*_use=1
	{
		smartPointer sp2 (sp);//*_use=2
		smartPointer sp3 = sp2;//*_use=3
		sp2 = new Point(4, 3);//*sp2._use=1�����ڿ������Ƶ�ʱ��
							//--*_use,�ı���ָ��Point(2,3)��ָ�������
						//*sp._use=*sp3._use=2
		sp2 = new Point(5, 3);//*sp2._use=1,(sp2ԭ�����ͷ�)
						//��Ϊû��������ָ��ָ��Point(4,3),���Ա��ͷ�
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