#pragma once
#include<string>
class Shape
{
public:
	static int ID;
	//ԭ����derived classes ���붨���Լ���draw
	virtual void draw()const = 0;//pure virtual Ŀ����Ϊ����
								//derived class ֻ�̳к����ӿ�,
								//ÿһ��derived class �����붨���Լ���draw
	//derived classes���Բ������Լ���error��shape��
	virtual void error(const std::string &msg="ghost,no error")const;//��pure virtual Ŀ����Ϊ��
								//��derived class �̳иú����Ľӿں�ȱʡʵ�֣�
								//����ֻ��shape �������Լ���error 
								//derived class ����shape��error ������ν��ȱʡʵ��
	//ԭ���� derived classes�����Զ����Լ���objectID��ֻ����Shape
	int objectID()const;//non-virtual Ŀ����Ϊ��
						//�� derived classes �̳к����Ľӿں�һ��ǿ����ʵ��
						//�κ�derived classes ����Ӧ�øı�����Ϊ
						//non-virtual ����������ǲ����ԣ����������
private:
	virtual int getID()const = 0;
};
class Rectangle :public Shape
{
public:
	//Rectangle() = default;
	Rectangle(int l, int w) :_length(l), _width(w),_id(++Shape::ID) {};
	virtual void draw()const;//pure virtual ��������
	virtual void error(const std::string &msg)const;//��Ҫ���ر�������
	virtual int getID()const { return _id; };
private:
	int _length;
	int _width;
	int _id;

};
class Circle :public Shape
{
public:
	//Circle ()= default;
	Circle(int r) :_radius(r), _id(++Shape::ID){  };
	virtual void draw()const;//pure virtual ��������
	virtual int getID()const { return _id; };
private:
	int _radius;
	int _id;
};