#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc,char **argv)
{
	///////**************************************************learning switch

	string ts="abcdefihopquuu";
	int a_cnt=0;
	int oth_cnt=0;
	for (auto c :ts)
	{
		switch (c)
		{
		case'a':
		case'e':
		case'i':
		case'o':
		case'u':
			a_cnt++;//只要是元音字母中的一个，都进行++操作
			break;
		default:
			oth_cnt++;
			break;
		}
	}
	cout<<a_cnt<<" "<<oth_cnt<<endl;
	
	///*************************************learning do while**********************************

	string ending;
	do
	{
		int v1,v2;
		cin>>v1>>v2;
		cout<<"v1+v2="<<(v1+v2)<<endl;
		cout<<"still ?"<<endl;
		cin>>ending;
	}while(ending[0]!='n');
	
	
	
	
	return 0;
}