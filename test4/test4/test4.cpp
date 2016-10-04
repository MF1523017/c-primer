#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main(int argc,char **argv)
{
	int i=0;
	//cout<<i<<" "<<i++<<endl;//不建议这样的写法，会产生未定义的结果
	int j=1,k=2;
	if(i<j<k)//i<j 为真，即1<k=2,则为真
		cout<<k<<endl;
	j=i++;//j=0
	k=++i;//k=2
	cout<<j<<" "<<k<<endl;
	return 0;
}