#pragma once
#ifndef BLOB_H
#define BLOB_H
#include<vector>
#include<memory>
#include<string>
template<typename T>class Blob
{
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob()=default;
	Blob(initializer_list<T> i1);
	size_type size()const { return data->size(); }
	bool empty()const { return data->empty(); }
	void push_back(const T&&t) { data->push_back(std::move(t)); }
	void pop_back();
	T &back();
	T& operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>>data;
	void check(size_type i, const std::string &msg)const;
};
#endif // !BLOB_H
