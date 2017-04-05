#pragma once
#include<iostream>
#include<vector>
#include<memory>
/*
应该记住类模板的名字不是一个类型名，类模板是用来实例化类型，
*/


template<typename T=int>//默认实参int 类型
class Blob
{
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	//constructor
	Blob() :data(std::make_shared<std::vector<T>>()) {};
	Blob(std::initializer_list<T> il) :data(std::make_shared<std::vector<T>>(il)) {};
	//
	template<typename It>
	Blob(It b, It e):data(std::make_shared<std::vector<T>>(b,e)){}
	
	//mem_function
	size_type size()const { return data->size(); };
	bool empty()const { return data->empty(); }
	void push_back(const T &rhs) { data->push_back(rhs); }
	void push_back(T &&rhs) { data->push_back(std::move(rhs)); }
	void pop_back() { 
		check(0, "pop_back on empty Blob");
		data->pop_back(); }
	T &back() { 
		check(0, "back on empty Blob");
		return data->back(); }
	T &front() { 
		check(0, "front on empty Blob");
		return data->front(); }
	T &operator[](size_type i)const;
private:
	//mem_num
	std::shared_ptr<std::vector<T>>data;
	void check(size_type i, const std::string &msg)const;
	
};

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg)const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template<typename T>
T & Blob<T>::operator[](size_type i)const
{
	check(i, "subscript out of range");
	return (*data)[i];
}
void testClass();
