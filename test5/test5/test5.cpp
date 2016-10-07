#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(int argc,char **argv)
{
#if 1
	//************嵌套if else语句
	const vector<string> score{ "F","D","C","B","A","A++" };
	string finalScore;
	int grade;
	while (cin >> grade)
	{
		if (grade < 60)
			finalScore = score[0];
		else
		{
			finalScore = score[(grade - 60) / 10 + 1];
			if (grade != 100) {
				if (grade % 10>7)
					finalScore += "+";
				else if (grade % 10 < 3)
					finalScore += "-";
			}
		}
		cout << finalScore << endl;
	}
#endif
#if 0
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
	
#endif
#if 0
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
	
#endif
	
	
	return 0;
}