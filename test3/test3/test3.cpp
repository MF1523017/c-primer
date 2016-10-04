#include<iostream>
#include<string>
#include<vector>
#include<iterator>
using std::begin;
using std::end;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(int argc,char ** argv)
{
	/////////////////////string learning************************************************************
	//int n=10;
	//string a(n,'a');
	string s1;
	cout<<s1[0]<<endl;//nothing but can compile
	string s2;
//	cin>>s1;//>>s2;//如果s1输入的时候“   hello   ”输出是“hello”
	/************************************************
	while(cin>>s1)//一直input 但不会保留空白符，遇到空白符会进入下一次循环 当输入Q\n时 将退出循环
	{
		//cout<<s1<<endl;
		s2+=s1+' ';
		cout<<s1.size()<<endl;
		cout<<s2<<endl;
	}
	*/



	//************************************************************************************************



	/* some operation toupper tolower ispunct isspace and so on
	string word;
	while(getline(cin,s2))//能够保留空白符，输入Q时退出
	{
		decltype(s2.size()) punct_cnt=0;//decltype(v) a，编译器会分析v（v可以是函数语句）的类型从而判断a的类型
		for(auto &s :s2)
		{
			if (ispunct(s))
				punct_cnt++;
			s=toupper(s);
			s=tolower(s);
		//	cout<<s<<"punct_number is"<<punct_cnt<<endl;//output every char and the punct count
		}
		for (decltype(s2.size()) index=0;index<s2.size()&& !isspace(s2[index]);index++)//toupper the first word by space!
		{
			s2[index]=toupper(s2[index]);
		}
		cout<<s2<<endl;
		cout<<s2.size()<<endl;
	}

	//*/
	
	
	//*****************************************************************



	/*some test about the index
	const string hex_s="0123456789ABCDEF";
	string result;
	int n;
	while(cin>>n)
	
		if(n<hex_s.size())
			result=result+hex_s[n];

	cout<<result<<endl;
	*/

	//cout<<s1<<s2<<endl;
	
	/************************************************
	s1="hello";
	s2="world";
	string s3=s1+','+s2+'\n';
	cout<<s3<<endl;
	*/


	//////////////////////////////////////////vector learning****************************************************************
	/*
	vector<string>v1(10,"hi");
	for(auto v :v1)
		cout<<v<<endl;//output every string in v1
	//input 0-99 save in v2
	vector<int> v2;
	for(int i=0;i<100;i++)
		v2.push_back(i);
	for (int i=0;i<100;i++)
		cout<<v2[i];

	vector<int>v3;
	
	
	int v_n;
	while(cin>>v_n)
	{
		v3.push_back(v_n);
	}
	for (auto v:v3)
		cout<<v<<endl;
	
	vector<int>::const_iterator iter,iter1;
	iter=v3.cbegin();
	iter1=v3.cend();
	cout<<iter1-iter<<endl;//iter1-iter is the size of the v3 and is the difference_type which is the int type
	*/
	
	
	
	
	//******************************************pointer and numbers************************8
/*
	int a1[5]={1,2,3,4,5};

	auto a1_n=end(a1)-begin(a1);
	cout<<a1_n<<endl;
	auto a2(a1);//等价于 auto a2(&a1[0]),所以是int *
	//*a2=43;//auto a2(a1)推断出来a2是一个int *类型，所以无法直接用a2=43来赋值，但可以对*a2=a[0]=43;
	
	a2=a2+5;

	for(int *b=a1;b!=a2;b++)
	cout<<*b<<endl;
	//等价于上面的代码
	int *b=begin(a1);
	int *e=end(a1);//指向a1尾元素的下一个位置的指针
	for(;b!=e;b++)
		cout<<*b<<endl;
		*/


	//*********************************************多维数组****************************

	int ai[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int (&row)[4]=ai[1];//row为一个4个元素的引用，初始化成为ai的第二行
	cout<<row[0]<<endl;


	return 0;
}