#include "SetIterator.h"
#include "Set.h"
#include<exception>


SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	index = 0;
	
}


void SetIterator::first() {
	//TODO - Implementation
	index = 0;
}


void SetIterator::next() {
	//TODO - Implementation
	if (index >= set.size())
		throw std::exception("Out of bounds!");
	index++;
	
}


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	if (valid() == false)
		throw std::exception("It's not valid!");
	return set.vector[index];
}
/*ADT Set

Change the iterator to be able to go k steps forward. Add the following operation in the SetIterator class:

//moves the current element from the iterator k steps forward, or makes the iterator invalid if there are less than k elements left in the Set.
//throws an exception if the iterator is invalid or if k is negative or zero
void jumpForward(int k);*/
void SetIterator::jumpForward(int k)
{

	if (set.size() <= index+k)
	{
		throw std::exception("Out of bounds!");
	}
		index=index+k;
	
}
bool SetIterator::valid() const {
	//TODO - Implementation
	if (index >= set.size())
		return false;
	else
		return true;
}





