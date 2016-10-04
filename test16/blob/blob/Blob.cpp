#include"Blob.h"
template<typename T>
void Blob<T>::check(size_type i, const std::string &msg)const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}