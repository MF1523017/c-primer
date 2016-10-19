#include"textQuery.h"
#include<sstream>
TextQuery::TextQuery(std::istream & infile)
{
	std::string lineText;
	int lineNum = 0;
	while (std::getline(infile, lineText))
	{
		_text.push_back(lineText);
		std::istringstream tmpLine(lineText);
		std::string tmpWord;
		while (tmpLine >> tmpWord)
		{
			_words[tmpWord].insert(lineNum);
		}
		lineNum++;
	}
}
void TextQuery::query(std::string &s)
{
	try
	{
		auto result = _words.at(s);
		std::cout << s << " occurs about " << result.size() << std::endl;
		for (auto b : result)
		{
			std::cout << "(line " << b << ") " 
						<< _text[b] << std::endl;
		}

	}
	catch (std::out_of_range err)
	{
		std::cout << err.what() << std::endl
			<< s << " not in the file"<<std::endl;
	}
}