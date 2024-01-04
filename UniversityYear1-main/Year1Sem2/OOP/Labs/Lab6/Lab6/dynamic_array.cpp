#include "dynamic_array.h"



Dynamic_array::Dynamic_array()
{
	this->maxim_array = 2;
	this->count_array = 0;
	this->array_of_tapes = new Tape*[this->maxim_array];//with new it puts a * from "oficiu"

}

Dynamic_array::~Dynamic_array()
{
	for (int i = 0; i < this->count_array; i++)
	{
		delete this->array_of_tapes[i];
	}
	delete this->array_of_tapes;
}
// I overloaded the opertor to: gives acces , add's an element and delete's an element
Tape*& Dynamic_array::operator[](int position_in_array)// function for get objectt( tape) // this function is to get and set (2 in 1)
{
	// TODO: insert return statement here
	if (position_in_array < 0 || position_in_array >= this->count_array)
	{
		throw Exceptions("Ney");
	}
	return this->array_of_tapes[position_in_array];
}

void Dynamic_array::operator+=(Tape* new_tape)
{
	this->count_array++;
	resize_array();
	this->array_of_tapes[this->count_array-1] = new_tape;
}

void Dynamic_array::operator-=(int position_in_array)
{

	if (position_in_array < 0 || position_in_array >= this->count_array)
	{
		throw Exceptions("Ney");
	}
	for (int i = position_in_array; i < this->count_array-1; i++)
	{
		this->array_of_tapes[i] = this->array_of_tapes[i + 1];
	}
	this->count_array--;
	resize_array();

}

int Dynamic_array::get_count()
{
	return this->count_array;
}

void Dynamic_array::resize_array()// bigger or smaller
{
	Tape** temporarly_dynamic_array;
	if (this->count_array == this->maxim_array)
	{
		temporarly_dynamic_array = new Tape * [this->maxim_array * 2];
	}
	else if(this->count_array < this->maxim_array/2)
	{
		temporarly_dynamic_array = new Tape * [this->maxim_array / 2];
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
