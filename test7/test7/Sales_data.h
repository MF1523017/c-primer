#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>
using std::string;
using std::istream;
using std::ostream;
class Sales_data
{
	friend istream &read(istream &is, Sales_data &item);
	friend ostream &print(ostream &os, Sales_data &item);
public:
	
	//Sales_data()=default;
	//~Sales_data();
	string isbn()const;
	Sales_data &combine(const Sales_data &rhs);
	double avg_price()const;
	
	
private:
	string _bookNo;
	static unsigned _units_sold;
	double _revenue;

};

istream &read(istream &is,Sales_data &item);
ostream &print(ostream &os,Sales_data &item);

#endif