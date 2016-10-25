#pragma once
#include<string>
#include<iostream>
class AirPlane
{
public:
	AirPlane(int p) :_passengers(p) {};
	virtual void fly(const std::string &des)const=0;//pure virtual func的目的是为了让derived class 只继承函数接口
													//这里指定默认目的地
private:
	int _passengers;
};
class AirPlaneA :public AirPlane 
{
public:
	AirPlaneA(int p) :AirPlane::AirPlane(p) {};
	virtual void fly(const std::string &dst)const
	{
		AirPlane::fly(dst);
	}

};
class AirPlaneB :public AirPlane
{
public:
	AirPlaneB(int p) :AirPlane::AirPlane(p) {};
	virtual void fly(const std::string &dst)const
	{
		AirPlane::fly(dst);
	}

};
class AirPlaneC :public AirPlane
{
public:
	AirPlaneC(int p) :AirPlane::AirPlane(p) {};
	virtual void fly(const std::string &dst)const
	{
		std::cout << dst << std::endl;//C与BA 不同，可以指定目的地
	}

};