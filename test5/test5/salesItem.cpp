#include"salesItem.h"
std::istream & operator >>(std::istream & in, Sales_item & rhs)
{
	in >> rhs._isbn;
	return in;
}