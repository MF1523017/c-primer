/*
date:2016/10/19
author:LiPei
Ҫ��
1���������ȡ�ļ�ʱ�������סÿһ���������ڵ�������
	��˱������ж�ȡ�ļ�������ÿ�зֽ�Ϊ�����ĵ��ʡ�
2�����������ʱ��
	�����ܻ��ÿ���������ڵ��к�
	�кű��밴������������ظ�
	�����ܹ���ӡ��ָ���к��е��ı�
��ƣ�
	ʹ��vector<string>�����ı���ÿһ��
	ʹ��set����ÿ���������ڵ�����
	ʹ��map��ÿ�����ʺͱ���õ��ʵ�set��������������
	ʹ��istringstream�ֽⵥ������
*/

#include"textQuery.h"
#include<iostream>
#include<fstream>
#include<string>
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
int main(int argc, char **argv)
{
	ifstream infile("testText.txt");
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for,or q to quit: ";
		string s;

		if (!(cin >> s)||s == "q")
			break;
		 tq.query(s);
	}

}