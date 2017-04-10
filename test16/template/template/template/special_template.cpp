#include"special_template.h"
#include<unordered_set>
bool operator == (const Base &lhs, const Base &rhs)
{
	return lhs.getData() == rhs.getData();
}
void testSpecialTemplate()
{
	std::unordered_set<Base> sb;
	sb.insert(1);
	sb.insert(Base());
	for (auto b : sb)
		std::cout << b.getData() << std::endl;
}