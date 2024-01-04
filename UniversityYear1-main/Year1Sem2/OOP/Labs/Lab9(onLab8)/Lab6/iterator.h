#pragma once 

#include"exceptions.h"
#include<vector>
#include"tape.h"

class Iterator 
{
public:
	Iterator(std::vector<Tape*> array_of_tapes);
	void next();
	Tape* current_element();

private:
	std::vector<Tape*> array_to_be_iterated;
	int current_element_position;

};

inline Iterator::Iterator(std::vector<Tape*> array_of_tapes)
{
	array_to_be_iterated = array_of_tapes;
	current_element_position = 0;
}

inline void Iterator::next()
{
	if (array_to_be_iterated.size()-1 == current_element_position)
		current_element_position = 0;
	else
	{
		current_element_position += 1;
	}
}


inline Tape* Iterator::current_element()
{
	if (array_to_be_iterated.size() == 0)
	{
		throw Exceptions("List has no elements");
	}
	return array_to_be_iterated[current_element_position];
}
