#include"test6.h"
#include<iostream>
using std::cout;
using std::endl;
int count_call_static()
{
	static int c_cnt=0;//只进行一次初始化，
	return ++c_cnt;
}
int count_call_reference(int &c_cnt)
{
	return ++c_cnt;
}
bool is_sentance(const string &s)
{
	string::size_type ctr = 0;
	return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}
string::size_type find_char(const string &s,char c,string::size_type &cnt)
{
	int index=s.size();
	for (int i=0;i<s.size();++i)
	{
		if (s[i]==c)
		{
			if (index==s.size())
				index=i;
			cnt++;
		}
		
	}
	return index;
}

void print(const int *beg,const int *end)
{
	while(beg!=end)
	{
		cout<<*beg++<<endl;
	}

}

char &get_val(string &s,string::size_type ix)
{
	return s[ix];
}

int add(int fs,int sd)
{
	return fs+sd;
}

int add_3(int tr,int pf(int,int))
{
	return tr+pf(1,2);
}

/*
inline const string & shortStr(const string &s1,const string &s2)
{
	return s1.size()<=s2.size()?s1:s2;
}

*/
/*int add(char fs=15,char sd=25)
{
	return fs+sd;
}
*/
int func(int *p)
{
	return p[0];
}
int  testReturn()
{
	int p[2];
	*p = 1;
	*(p+1) = 2;
	return func(p);
}