#include"foo.h"

int main(int argc, char **argv)
{
	Foo f(0);
	std::cout << f++ << std::endl;
	std::cout<<++f<<std::endl;

	++f;
	return 0;
}