#include<iostream>
#include"test6.h"
using std::cout;
using std::cin;
using std::endl;

int odd[]={1,3,5,7,9};
int even[]={0,2,4,6,8};
decltype(odd) *arrPtr(int i)
{
	return (i%2)? &odd:&even;
}

int main(int argc,char **argv)
{
#if 0
	//**************************************learning static and reference **************************/

	int c_cnt=0;
	for(int i=0;i<10;i++)
	{
		cout<< count_call_reference(c_cnt)<<endl;//可以用引用改变数值
		cout<< count_call_static()<<endl;//static 静态对象可以保留局部对象
	}
	cout<<endl<<endl;
#endif
#if 0
	//***********************learning  the difference between func(const int  )and func(int)*******

	string s="lipei";
	string::size_type cnt=0;
	cout<<"find char:"<<find_char(s,'i',cnt)<<endl;//这里find_char输入的s可被看作const string ，
									//能够编译通过但如果find_char 没有使用常量引用，则会链接出错
	cout<<cnt<<endl;
	cnt=0;
	cout<< "find char:"<<find_char("lilipeipei",'i',cnt)<<endl;//"lilipeipei" 是const string 类型,
											//如果函数声明为find_char(string &s,char c,int cnt);则不能编译通过
	cout << "is sentance:"<<is_sentance(s) << endl;
	cout<<cnt<<endl;
	cout<<endl<<endl;
#endif
#if 0
	//********************函数形参是数组
	int aa[10]={1,2,3,4,5,6,7,8,9,0};
	print(std::begin(aa),std::end(aa));

	//***************引用返回左值

	string s_r("a value");
	get_val(s_r,0)='A';
	cout<<"get_value:"<<s_r<<endl;
	cout<<endl<<endl;
	
#endif
	//**********************返回数组指针，因为数组不能被拷贝，所以函数不能返回数组************
	auto pt = arrPtr(4);
	
	//************************默认实参%*****************
	cout << "override:\n";
	cout<<add()<<endl;//函数声明的时候将默认实参确定，定义的时候不要默认实参，否则会重复声明
	cout<<add(15)<<endl;
	cout<<add(25,35)<<endl;

	cout<<endl<<endl;
	//**********************inline 内联函数**********************

	const string in_s1="li";
	const string in_s2="pei";
	const string in_s3=shortStr(in_s1,in_s2);//内联函数比较短小，大多放到头文件里面，不用讲声明和定义分开
	cout<<"shorter string:"<<in_s3<<endl;
	cout<<endl<<endl;
	//************************************函数指针****************

	int (*pf)(int fs,int sd);//声明
	pf=add;//初始化
	cout<<"func pointer:"<<(*pf)(1,2)<<endl;
	cout<<add_3(3,pf)<<endl<<endl<<endl;//函数指针做形参

	
	return 0;
}