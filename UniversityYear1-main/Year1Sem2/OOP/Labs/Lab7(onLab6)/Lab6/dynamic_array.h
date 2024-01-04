#pragma once
#include"tape.h"
#include "exceptions.h"
#include<ctime>
using namespace std;

// constructor destructor and resize-first
// access data ,delete data, insert second 
template <class element_type>
class Dynamic_array
{
public:
	Dynamic_array();//constructor
	~Dynamic_array();// destructor
	element_type*& operator[](int position_in_array);// to access the array
	void operator+=(element_type* new_tape);// to insert(add) in the array on the last position
	void operator-=(int position_in_array);// to delete from the array
	int get_count();


private:
	element_type** array_of_tapes;// or storage of tapes() ( first* is for pointer second is for list)
	int count_array;
	int maxim_array;
	void resize_array();// resize
};
// this was the CPP
template<typename element_type>
Dynamic_array<element_type>::Dynamic_array()
{
	this->maxim_array = 2;
	this->count_array = 0;
	this->array_of_tapes = new element_type * [this->maxim_array];//with new it puts a * from "oficiu"

}
template<typename element_type>
Dynamic_array<element_type>::~Dynamic_array()
{
	for (int i = 0; i < this->count_array; i++)
	{
		delete this->array_of_tapes[i];
	}
	delete this->array_of_tapes;
}
// I overloaded the opertor to: gives acces , add's an element and delete's an element
template<typename element_type>
element_type*& Dynamic_array<element_type>::operator[](int position_in_array)// function for get objectt( tape) // this function is to get and set (2 in 1)
{
	// TODO: insert return statement here
	if (position_in_array < 0 || position_in_array >= this->count_array)
	{
		throw Exceptions("Ney");
	}
	return this->array_of_tapes[position_in_array];
}
template<typename element_type>
void Dynamic_array<element_type>::operator+=(element_type* new_tape)
{
	this->count_array++;
	resize_array();
	this->array_of_tapes[this->count_array - 1] = new_tape;
}
template<typename element_type>
void Dynamic_array<element_type>::operator-=(int position_in_array)
{

	if (position_in_array < 0 || position_in_array >= this->count_array)
	{
		throw Exceptions("Ney");
	}
	for (int i = position_in_array; i < this->count_array - 1; i++)
	{
		this->array_of_tapes[i] = this->array_of_tapes[i + 1];
	}
	this->count_array--;
	resize_array();

}
template<typename element_type>
int Dynamic_array<element_type>::get_count()
{
	return this->count_array;
}
template<typename element_type>
void Dynamic_array<element_type>::resize_array()// bigger or smaller
{
	element_type** temporarly_dynamic_array;
	if (this->count_array == this->maxim_array)
	{
		temporarly_dynamic_array = new element_type * [this->maxim_array * 2];
	}
	else if (this->count_array < this->maxim_array / 2)
	{
		temporarly_dynamic_array = new element_type * [this->maxim_array / 2];
	}
	else
	{
		return;
	}

	for (int i = 0; i < this->count_array; i++)
	{
		temporarly_dynamic_array[i] = this->array_of_tapes[i];
	}
	delete array_of_tapes;// we delete the array
	this->array_of_tapes = temporarly_dynamic_array;// the final touch to the array

}





