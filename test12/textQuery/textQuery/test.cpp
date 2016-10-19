/*
date:2016/10/19
author:LiPei
要求：
1，当程序读取文件时，必须记住每一个单词所在的行数，
	因此必须逐行读取文件，并且每行分解为独立的单词。
2，当程序输出时，
	必须能获得每个单词所在的行号
	行号必须按升序出现且无重复
	必须能够打印出指定行号中的文本
设计：
	使用vector<string>保存文本的每一行
	使用set保存每个单词所在的行数
	使用map将每个单词和保存该单词的set的行数关联起来
	使用istringstream分解单个单词
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