#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main(int argc,char **argv)
{
	int i=0;
	//cout<<i<<" "<<i++<<endl;//������������д���������δ����Ľ��
	int j=1,k=2;
	if(i<j<k)//i<j Ϊ�棬��1<k=2,��Ϊ��
		cout<<k<<endl;
	j=i++;//j=0
	k=++i;//k=2
	cout<<j<<" "<<k<<endl;
	return 0;
}