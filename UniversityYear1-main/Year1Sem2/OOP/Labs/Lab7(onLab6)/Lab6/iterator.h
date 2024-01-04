#pragma once 
#include "dynamic_array.h"
#include<ctime>
template< class element_type>
class Iterator 
{
public:
	Iterator(Dynamic_array<element_type>* array_of_tapes);
	void next();
	element_type* current_element();

private:
	Dynamic_array<element_type>* array_to_be_iterated;
	int current_element_position;

};
template<class element_type>
Iterator<element_type>::Iterator(Dynamic_array<element_type>* array_of_tapes)
{
	array_to_be_iterated = array_of_tapes;
	current_element_position = 0;
}

template<class element_type>
void Iterator<element_type>::next()
{
	if (array_to_be_iterated->get_count() == 0)
	{
		throw Exceptions("List has no elements");
	}
	if (array_to_be_iterated->get_count()-1 == current_element_position)
		current_element_position = 0;
	else
	{
		current_element_position += 1;
	}
}

template<class element_type>
element_type* Iterator<element_type>::current_element()
{
	if (array_to_be_iterated->get_count() == 0)
	{
		throw Exceptions("List has no elements");
	}
	return (*array_to_be_iterated)[current_element_position];
}
