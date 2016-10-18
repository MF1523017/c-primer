#ifndef CLIBARRAY_H
#define CLIBARRAY_H

using elementType = int;
using elementPrt =elementType *;
class CArray
{

private:
	int _arraySize;
	int _arrayCapacity;
	elementPrt _buff;
	CArray &_recap(int cap);
	CArray &_checkCap(int s);
public:
	
	CArray():_arraySize(0),_arrayCapacity(0),_buff(nullptr) {};//初始化列表
	~CArray() { delete[]_buff; _arrayCapacity = 0; _arraySize = 0; _buff = nullptr; };
	CArray &append(elementType e);
	int size()const { return _arraySize; };
	int capacity()const { return _arrayCapacity; };
	elementType & at(int index)const;
	CArray& copy(CArray &rst);
	bool compare(CArray &rst);
	CArray &insert(int index, elementType e);
};
#endif // !

