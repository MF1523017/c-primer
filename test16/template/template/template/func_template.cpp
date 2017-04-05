#include"func_template.h"
#include<iostream>
using std::cout;
using std::endl;
void test_func()
{
	cout << "compare(1, 0) :" << compare(1, 0) << endl;
	cout << "compare(0.1, 1.0) :" << compare(0.1, 1.0) << endl;
	cout << "compare('a', 'b') :" << compare('a', 'b') << endl;
	cout <<"compare('string1', 'string1') :" <<compare("string1", "string1") << endl;
	cout << "min(1,2): " << min(1, 2) << endl;
	cout << "min(1.3,0.2): " << min(1.3, 0.2) << endl;
}