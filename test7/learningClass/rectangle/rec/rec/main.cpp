#include"rectangle.h"

int main(int argc, char **argv)
{
	Rectangle r(0, 0, 1, 2);
	int h = r.height();
	int w = r.width();
	int a = r.area();
	r.MoveTo(3, 3);
	return 0;
}