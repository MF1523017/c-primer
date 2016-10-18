#include"CLibArray.h"
CArray &CArray::_checkCap(int s)
{
	if (s >= _arrayCapacity)
	{
		_arrayCapacity = 2 * s;
		_recap(_arrayCapacity);
	}
	return *this;
}
CArray &CArray::_recap(int cap)
{
		elementPrt tmpbuff = new elementType[cap];
		_arrayCapacity = cap;
		_arraySize = _arraySize < _arrayCapacity ? _arraySize : _arrayCapacity;
		for (int i = 0; i < _arraySize; ++i)
			tmpbuff[i] = _buff[i];
		delete[]_buff;
		_buff = tmpbuff;
	return *this;
}
CArray& CArray::append(elementType e)
{
	_checkCap(_arraySize + 1);
	_buff[_arraySize] = e;
	_arraySize += 1;
	return *this;
}
elementType &CArray::at(int index)const
{
	return _buff[index];
}
CArray &CArray::insert(int index, elementType e)
{
	_checkCap(_arraySize + 1);
	for (int i = _arraySize; i > index; --i)
		_buff[i] = _buff[i - 1];
	_buff[index] = e;
	return *this;
}
CArray& CArray::copy(CArray &rst)
{
	_checkCap(rst.capacity());
	for (int i = 0; i < rst.size(); ++i)
		_buff[i] = rst._buff[i];
	_arraySize = rst.size();
	_arrayCapacity = rst.capacity();
	return *this;
}
bool CArray::compare(CArray &rst)
{
	if (_arraySize != rst.size() || _arrayCapacity != rst.capacity())
		return false;
	for (int i = 0; i < _arraySize; ++i)
	{
		if (_buff[i] != rst._buff[i])
			return false;
	}
	return true;
}