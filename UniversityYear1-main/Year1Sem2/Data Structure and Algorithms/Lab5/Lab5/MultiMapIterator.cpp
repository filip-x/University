#include "MultiMapIterator.h"
#include "MultiMap.h"

//all the Complexitys are Theta(1)// it iterates only a few times so it is Theta(1), when searching for the next non empty position
MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	//TODO - Implementation
	current_position = 0;
	while (current_position <c.capacity && (c.storage[current_position]== NULL_TELEM || c.storage[current_position]==DELETED_TELEM))
	{
		current_position++;
	}
}

TElem MultiMapIterator::getCurrent() const{
	//TODO - Implementation
	if (valid() == false)
		throw exception();
	return col.storage[current_position];
}

bool MultiMapIterator::valid() const {
	//TODO - Implementation

	return col.capacity!=current_position;// it will return true or false 
}

void MultiMapIterator::next() {
	//TODO - Implementation
	if (valid() == false)
		throw exception();
	current_position++;// to not be on the same position
	while (current_position < col.capacity && (col.storage[current_position] == NULL_TELEM || col.storage[current_position] == DELETED_TELEM))
	{
		current_position++;
	}
}

void MultiMapIterator::first() {
	//TODO - Implementation
	current_position = 0;
	while (current_position < col.capacity && (col.storage[current_position] == NULL_TELEM || col.storage[current_position] == DELETED_TELEM))
	{
		current_position++;
	}
}

