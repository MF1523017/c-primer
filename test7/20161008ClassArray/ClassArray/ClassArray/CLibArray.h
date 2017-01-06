#ifndef CLIBARRAY_H
#define CLIBARRAY_H
#include<vector>
#include<iostream>
//using elementType = int;
//using elementPrt =elementType *;
typedef int elementType;
typedef int* elementPtr;
class CArray
{
	friend std::ostream &operator<<(std::ostream &os, const CArray &rhs);
	friend CArray operator+(const CArray &lhs, const CArray &rhs);//+
private:
	int _arraySize;
	int _arrayCapacity;
	elementPtr _buff;
	CArray &_recap(int cap);
	CArray &_checkCap(int s);
public:
	CArray(std::vector<elementType>rhs);
	CArray(int s, int c, elementPtr b) :_arraySize(s), _arrayCapacity(c) {
		_buff = new elementType(_arrayCapacity);
		for (int i = 0; i < _arraySize; ++i)
			_buff[i] = b[i];
	};
	CArray():_arraySize(0),_arrayCapacity(0),_buff(nullptr) {};//初始化列表
	CArray(const CArray &rhs);
	CArray & operator=(const CArray &rhs);
	~CArray();
	CArray &append(elementType e);
	int size()const { return _arraySize; };
	int capacity()const { return _arrayCapacity; };
	elementType & at(int index)const;
	CArray& copy(CArray &rst);
	bool compare(CArray &rst);
	CArray &insert(int index, elementType e);
};
std::ostream &operator<<(std::ostream &os, const CArray &rhs);
CArray operator+(const CArray &lhs, const CArray &rhs);//+
#endif // !

