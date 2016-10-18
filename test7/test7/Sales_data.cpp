#include"Sales_data.h"
unsigned int Sales_data::_units_sold = 1;
string Sales_data::isbn()const
{
	return _bookNo;
}
double Sales_data::avg_price()const
{
	if(_units_sold)
		return _revenue/_units_sold;
	else
		return 0;
}
Sales_data & Sales_data::combine(const Sales_data& rhs)
{
	_units_sold+=rhs._units_sold;
	_revenue+=rhs._revenue;
	return *this;
}
Sales_data add(const Sales_data& lhs,const Sales_data rhs)
{
	Sales_data sum=lhs;
	sum.combine(rhs);
	return sum;
}
istream &read(istream &is,Sales_data &item)
{
	double price=0;
	is>>item._bookNo>>item._units_sold>>price;
	item._revenue=price*item._units_sold;
	return is;
}
ostream &print(ostream &os,	Sales_data &item)
{
	os<<item._bookNo<<" "<<item._units_sold<<" "<<item.avg_price()<<" "<<item._revenue;
	return os;
}