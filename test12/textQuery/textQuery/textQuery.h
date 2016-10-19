#pragma once
#include<vector>
#include<string>
#include<set>
#include<map>
#include<iostream>
class TextQuery
{
public:
	TextQuery(std::istream &infile);
	void query(std::string &s);
private:
	std::vector<std::string> _text;
	std::map<std::string, std::set<int>> _words;

};