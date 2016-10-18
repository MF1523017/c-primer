#pragma once
#include<iostream>
#include<string>
class Sales_item
{
	friend std::istream & operator >>(std::istream & in, Sales_item & rhs);
public:
	std::string isbn()const { return _isbn; };
private:
	std::string _isbn;

};
std::istream & operator >>(std::istream & in, Sales_item & rhs);