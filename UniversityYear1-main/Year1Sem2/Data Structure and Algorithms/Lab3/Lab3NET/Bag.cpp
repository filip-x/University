#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;
// Complexity: O(cap) where cap is the capacity of the resized bag ( *2 bigger then before )
void Bag::resize()
{
	this->cap = this->cap * 2;
	bag_pair* new_pair = new bag_pair[this->cap];
	int* new_next = new int[this->cap];
	for (int i = 0; i < this->cap / 2; i++)
	{
		new_pair[i] = this->bag[i];
		new_next[i] = this->next[i];
	}
	for (int i = this->cap / 2; i < this->cap - 1; i++)// we make the space for when we doubled the size of the cap 
		new_next[i] = i + 1;
	new_next[this->cap - 1] = -1;
	delete bag;// we  delete the initial bag and reassign the the bag from the new bag that has double the size 
	delete next;
	this->bag = new_pair;
	this->next = new_next;
	this->first_empty = this->cap/2;
}

// Complexity: Theta(n) where n is the initial capacity
Bag::Bag() {
	//TODO - Implementation
	this->cap = 2;
	this->bag = new bag_pair[this->cap];
	this->next = new int[this->cap];
	this->head = -1;
	for (int i = 0; i < this->cap - 1; i++)
		this->next[i] = i + 1;
	this->next[this->cap-1] = -1;// the last element we will make -1 so it is invalid
	this->first_empty = 0;
	count = 0;
}
//Complexity: Theta(n)
int Bag::distinctCount() const
{
	int ct = 0;
	int current = this->head;
	while (current != -1 )
	{
		current = this->next[current];
		ct++;
	}
	return ct;
}

//Complexity: O(n)-from search
void Bag::add(TElem elem) {
	//TODO - Implementation
	count++;
	if (search(elem) == true)
	{
		int current = this->head;
		while (current != -1 && this->bag[current].element != elem)
		{
			current = this->next[current];
		}
		this->bag[current].frequency++;
	}
	else
	{
		if (first_empty == -1)// if it is full
			resize();
		if (this->head == -1)// is empty 
		{
			bag_pair new_element;
			new_element.element = elem;
			new_element.frequency = 1;
			int new_position = this->first_empty;
			this->bag[new_position] = new_element;
			this->first_empty = this->next[this->first_empty];
			this->head = new_position;//previous position-for me 
			this->next[this->head] = -1;
		}
		else
		{
			int i = this->head;
			while (next[i] != -1)
			{
				i = next[i];
			}
			bag_pair new_element;
			new_element.element = elem;
			new_element.frequency = 1;
			int new_position = this->first_empty;
			this->bag[new_position] = new_element;
			this->first_empty = this->next[this->first_empty];
			next[i] = new_position;
			next[new_position] = -1;

		}
	}
}
//Complexity:O(n)
bool Bag::remove(TElem elem) {
	//TODO - Implementation
	int current=this->head;
	int prev=-1;
	while (current != -1 && this->bag[current].element != elem) //here it searches
	{
		prev = current;
		current = next[current];
	}
	//current = this->next[current];
	if (current != -1)
	{
		count--;
		if (this->bag[current].frequency == 1)
		{
			if (current == this->head)
				this->head = this->next[this->head];
			else
				this->next[prev] = this->next[current];
			this->next[current] = this->first_empty;
			this->first_empty = current;
			return true;
		}
		else
		{
			this->bag[current].frequency--;
			return true;
		}
	}
	else
	{
		return false;
	}
	 
}

// Complexity O(n)
bool Bag::search(TElem elem) const {
	//TODO - Implementation
	int current = this->head;
	while (current != -1 && this->bag[current].element !=elem)
	{
		current = this->next[current];
	}
	if (current != -1)
		return true;
	else
	{
		return false;
	}
	
}
// Complexity: O(n)
int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
	
	int current = this->head;
	while (current != -1 && this->bag[current].element != elem)
	{
		current = this->next[current];
	}
	if (current != -1)
		return this->bag[current].frequency;
	else
	{
		return 0;
	}
	
}

// Complexity: Theta(1)
int Bag::size() const {
	//TODO - Implementation
	return count;
}

// Complexity: Theta(1)
bool Bag::isEmpty() const {
	//TODO - Implementation

	return count == 0;
}
// Complexity: Theta(1)
BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

// Complexity: Theta(1)
Bag::~Bag() {
	//TODO - Implementation
	delete bag;
	delete next;
}

