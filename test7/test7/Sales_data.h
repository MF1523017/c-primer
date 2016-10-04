#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>
using std::string;
using std::istream;
using std::ostream;
class Sales_data
{
public:
	string bookNo;
	unsigned units_sold;
	double revenue;
	Sales_data()=default;
	//~Sales_data();
	string isbn()const;
	Sales_data &combine(const Sales_data &rhs);
	double avg_price()const;
	
	
//private:

};
Sales_data & combine(const Sales_data &rhl);
istream &read(istream &is,Sales_data &item);
ostream &print(ostream &os,Sales_data &item);
/*
Sales_data::Sales_data()
{
	;
}

Sales_data::~Sales_data()
{
	;
}


*/
#endif