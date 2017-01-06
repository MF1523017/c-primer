#include<iostream>
#include<cstring>

class String
{
public:
	String() :_buff(nullptr) {}
	~String() {
		delete[]_buff;
		_buff = nullptr;
	}
	String(const String &rhs)
	{
		*this = rhs;
	}
	String& operator=(const String &rhs)
	{
		if (this == &rhs)
			return *this;
		char *buff = new char[strlen(rhs._buff) + 1];
		strcpy(buff, rhs._buff);
		delete _buff;
		_buff = buff;
		return *this;
	}

	String(const char *str)
	{
		_buff = new char[strlen(str) + 1];
		strcpy(_buff, str);
	}
	void update(const char *str)
	{
		_buff = new char[strlen(str) + 1];
		strcpy(_buff, str);
	}
private:
	char *_buff;
};
void handle(String &x)
{
	x.update("1234");
}
int main(int argc, char **argv)
{
	String s1("123"), s2;
	handle(s1);
	s2 = s1;
	return 0;
}