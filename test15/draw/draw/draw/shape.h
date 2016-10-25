#pragma once
#include<string>
class Shape
{
public:
	//ԭ����derived classes ���붨���Լ���draw
	virtual void draw()const = 0;//pure virtual Ŀ����Ϊ����
								//derived class ֻ�̳к����ӿ�,
								//ÿһ��derived class �����붨���Լ���draw
	//derived classes���Բ������Լ���error��shape��
	virtual void error(const std::string &msg)const;//��pure virtual Ŀ����Ϊ��
								//��derived class �̳иú����Ľӿں�ȱʡʵ�֣�
								//����ֻ��shape �������Լ���error 
								//derived class ����shape��error ������ν��ȱʡʵ��
	//ԭ���� derived classes�����Զ����Լ���objectID��ֻ����Shape
	int objectID()const;//non-virtual Ŀ����Ϊ��
						//�� derived classes �̳к����Ľӿں�һ��ǿ����ʵ��
						//�κ�derived classes ����Ӧ�øı�����Ϊ
						//non-virtual ����������ǲ����ԣ����������
	
};
class Rectangle :public Shape
{
public:
	virtual void draw()const;//pure virtual ��������
	virtual void error(const std::string &msg)const;//��Ҫ���ر�������
private:
	int length;

};
class Ellipse :public Shape
{
public:
	virtual void draw()const;//pure virtual ��������
	int objectID()const;//����������Shape�е�objectID()

};