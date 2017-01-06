#include"CLibArray.h"
std::ostream &operator<<(std::ostream &os, const CArray &rhs)
{
	for (int i = 0; i < rhs.size(); ++i)
		os << rhs._buff[i] << " ";
	return os;
}
CArray::CArray(std::vector<elementType>rhs):_arraySize(rhs.size()),_arrayCapacity(2*rhs.size())
{
	_buff = new elementType[_arrayCapacity];
	for (int i = 0; i < rhs.size(); ++i)
		_buff[i] = rhs[i];
}
CArray::CArray(const CArray &rhs)
{
	*this = rhs;
}
CArray &CArray::operator=(const CArray &rhs)
{
	if (this == &rhs)
		return *this;
	elementPtr buff = new elementType[rhs._arrayCapacity];
	for (int i = 0; i < rhs.size(); ++i)
		buff[i] =rhs._buff[i];
	if(!_buff)
		delete []_buff;
	_buff = buff;
	_arraySize = rhs._arraySize;
	_arrayCapacity = rhs._arrayCapacity;
	return *this;
}
CArray::~CArray()
{ 
	delete[]_buff; 
	_arrayCapacity = 0; 
	_arraySize = 0; 
	_buff = nullptr; 
}

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
	elementPtr tmpbuff = new elementType[cap];
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

CArray operator+(const CArray &lhs, const CArray &rhs)
{
	CArray tmp = lhs;
	for (int i = 0; i < rhs.size(); ++i)
		tmp.append(rhs._buff[i]);
	return CArray(tmp);
}