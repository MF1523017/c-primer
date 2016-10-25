#include "airplane.h"
#include<iostream>
using std::cout;
using std::endl;
int main(int argc, char **argv)
{
	std::string dst("nanjing");
	AirPlane *apA = new AirPlaneA(3);
	AirPlane *apB = new AirPlaneB(32);
	AirPlane *apC = new AirPlaneC(333);
	//std::string dst1("beijing");
	apA->fly(dst);
	apB->fly(dst);
	apC->fly(dst);
}