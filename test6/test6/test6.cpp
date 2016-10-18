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
		cout<< count_call_reference(c_cnt)<<endl;//���������øı���ֵ
		cout<< count_call_static()<<endl;//static ��̬������Ա����ֲ�����
	}
	cout<<endl<<endl;
#endif
#if 0
	//***********************learning  the difference between func(const int  )and func(int)*******

	string s="lipei";
	string::size_type cnt=0;
	cout<<"find char:"<<find_char(s,'i',cnt)<<endl;//����find_char�����s�ɱ�����const string ��
									//�ܹ�����ͨ�������find_char û��ʹ�ó������ã�������ӳ���
	cout<<cnt<<endl;
	cnt=0;
	cout<< "find char:"<<find_char("lilipeipei",'i',cnt)<<endl;//"lilipeipei" ��const string ����,
											//�����������Ϊfind_char(string &s,char c,int cnt);���ܱ���ͨ��
	cout << "is sentance:"<<is_sentance(s) << endl;
	cout<<cnt<<endl;
	cout<<endl<<endl;
#endif
#if 0
	//********************�����β�������
	int aa[10]={1,2,3,4,5,6,7,8,9,0};
	print(std::begin(aa),std::end(aa));

	//***************���÷�����ֵ

	string s_r("a value");
	get_val(s_r,0)='A';
	cout<<"get_value:"<<s_r<<endl;
	cout<<endl<<endl;
	
#endif
	//**********************��������ָ�룬��Ϊ���鲻�ܱ����������Ժ������ܷ�������************
	auto pt = arrPtr(4);
	
	//************************Ĭ��ʵ��%*****************
	cout << "override:\n";
	cout<<add()<<endl;//����������ʱ��Ĭ��ʵ��ȷ���������ʱ��ҪĬ��ʵ�Σ�������ظ�����
	cout<<add(15)<<endl;
	cout<<add(25,35)<<endl;

	cout<<endl<<endl;
	//**********************inline ��������**********************

	const string in_s1="li";
	const string in_s2="pei";
	const string in_s3=shortStr(in_s1,in_s2);//���������Ƚ϶�С�����ŵ�ͷ�ļ����棬���ý������Ͷ���ֿ�
	cout<<"shorter string:"<<in_s3<<endl;
	cout<<endl<<endl;
	//************************************����ָ��****************

	int (*pf)(int fs,int sd);//����
	pf=add;//��ʼ��
	cout<<"func pointer:"<<(*pf)(1,2)<<endl;
	cout<<add_3(3,pf)<<endl<<endl<<endl;//����ָ�����β�

	
	return 0;
}