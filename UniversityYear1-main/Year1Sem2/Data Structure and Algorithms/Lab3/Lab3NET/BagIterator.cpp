#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

//All  of the functions have the complexity = Theta(1)
BagIterator::BagIterator(const Bag& c): bag(c)
{
	//TODO - Implementation
	this->position = bag.head;
	this->frequence = 1;

}

void BagIterator::first() {
	//TODO - Implementation
	this->position = bag.head;
	this->frequence = 1;

}


void BagIterator::next() {
	//TODO - Implementation
	if (valid() == false)
		throw exception("Wrong");
	else
	{
		this->frequence++;
		if (this->frequence > bag.bag[this->position].frequency)
		{
			this->position = bag.next[this->position];
			this->frequence = 1;
		}
	}
}


bool BagIterator::valid() const {
	//TODO - Implementation
	if (position == -1)
		return false;
	return true;
}



TElem BagIterator::getCurrent() const
{
	//TODO - Implementation
	if (valid() == false)
		throw exception("Wrong");
	else
	{
		return bag.bag[position].element;
	}
}
