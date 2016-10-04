#ifndef TEST6_H
#define TEST6_H
#include<string>
//在头文件中进行函数声明！在源文件中进行定义
using std::string;
//typedef int arrT[10];

int count_call();
int count_call1(int &c_cnt);
string::size_type find_char(const string &s,char c,string::size_type &cnt);
void print(const int *beg,const int *end);
char &get_val(string &s,string::size_type ix);
int add(int fs=10,int sd=20);
//int add(char fs=15,char sd=25);
inline const string & shortStr(const string &s1,const string &s2)
{
	return s1.size()<=s2.size()?s1:s2;
}

int add_3(int tr,int pf(int ,int));

//using F=int(int *,int);


#endif