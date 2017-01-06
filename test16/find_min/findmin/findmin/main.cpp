#include<iostream>
#include<vector>
using std::vector;
template<typename T>//,class Tv>
T find_min(T b, T e)
{
	T minIter = b;
	for (T i = b; i != e; ++i)
	{
		if (*i < *minIter)
		{
			minIter = i;
		}
	}
	return minIter;
}
int main(int argc, char **argv)
{
	vector<int>v1({ 2,1,4,5,6 });
	std::cout << *(find_min(v1.begin(), v1.end()));
	return 0;
}