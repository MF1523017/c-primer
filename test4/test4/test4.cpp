#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main(int argc,char **argv)
{
#if 0
	//**********++i and i++
	int i=0;
	//cout << i<<" "<<++i<<endl;//不建议这样的写法，会产生未定义的结果
	int j=1,k=2;
	if(i<j<k)//i<j 为真，即1<k=2,则为真
		cout<<k<<endl;
	j=i++;//j=0
	k=++i;//k=2
	cout<<j<<" "<<k<<endl;
#endif
#if 0
	//******************* 迭代器会序列改变内容
	string s = "hello world!";
	auto pbeg = s.begin();
	while (pbeg != s.end())
		cout << *pbeg++ << endl;//等价于 *pbeg;
									//++pbeg;
	pbeg = s.begin();
	while (pbeg != s.end()) {
		*pbeg = toupper(*pbeg);
		++pbeg;
	}
	cout << s << endl;//HELLO WORLD
#endif
#if 0
	//********条件运算符********
	int grade;
	cin >> grade;
	string finalgrade = (grade < 60) ? "fail" : "pass";
	cout << finalgrade << endl;
	finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
	cout << finalgrade << endl;
#endif

#if 0
	//**************位操作
	unsigned int bit = 1;
	cout << (bit^(bit << 5)) << endl;//^异或操作

#endif
#if 0
	//******sizeof 运算符*******
	//所有的指针都是4
	//类型引用和该类型一样
	cout << "int length is:"<<sizeof(int) << endl;//4
	cout << "int* length is:" << sizeof(int*) << endl;//4;
	cout << "int& length is:" << sizeof(int&) << endl;//4
	cout << "char length is:" << sizeof(char) << endl;//1
	cout << "char* length is:" << sizeof(char*) << endl;//4
	cout << "char& length is:" << sizeof(char&) << endl;//1
	cout << "short length is:" << sizeof(short) << endl;//2
	cout << "short* length is:" << sizeof(short*) << endl;//4
	cout << "short& length is:" << sizeof(short&) << endl;//2
	cout << "float length is:" << sizeof(float) << endl;//4
	cout << "double length is:" << sizeof(double) << endl;//8
	cout << "double* length is:" << sizeof(double*) << endl;//4
	cout << "double& length is:" << sizeof(double&) << endl;//8
	cout << "long long length is:" << sizeof(long long) << endl;//8
	cout << "long length is:" << sizeof(long) << endl;//4
	cout << "long double length is:" << sizeof(long double) << endl;//8
	
#endif
#if 1
	int s;
	while (cin >> s)//如果输入的是int 类型，cin>>s 返回bool值　true,否则返回false
		cout << s << endl;
#endif
	return 0;
}