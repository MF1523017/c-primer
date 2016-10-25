#include"airplane.h"
void AirPlane::fly(const std::string &dst)const
{
	std::cout << "dst is " << dst << std::endl
		<< "passengers are " << _passengers << std::endl;
	
}