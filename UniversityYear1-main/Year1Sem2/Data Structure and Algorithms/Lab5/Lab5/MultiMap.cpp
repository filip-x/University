#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

// Complexity of all the rest function besides resize are Theta(1)
int MultiMap::hash_table(TKey key,int index)const// index is position of a permutation of a hash table
{
	if (key < 0)
		key *= -1;
	return (int)(((key % capacity) * 2 + index + index * index)*1.0 / 2) % capacity;
	
}

// Complexity is O(n)
void MultiMap::resize()
{
	int index_for_hashtable;
	int final_position_in_storage;
	capacity *= 2;
	TElem* new_temporary_storage = new TElem[capacity]{};
	for (int i = 0; i < capacity; i++)
	{
		new_temporary_storage[i] = NULL_TELEM;
	}
	for (int i = 0; i < capacity / 2; i++)
	{
		if (storage[i] != NULL_TELEM && storage[i] != DELETED_TELEM)// if the element we want to move exist, we will find him the new position in the temporary storage.(bcs the hashtable will be different) 
		{
			index_for_hashtable = 0;
			final_position_in_storage = hash_table(storage[i].first,index_for_hashtable);
			while(new_temporary_storage[final_position_in_storage] != NULL_TELEM) // if something is allready in the position we search for the next empty position.
			{
				index_for_hashtable++;
				final_position_in_storage = hash_table(storage[i].first, index_for_hashtable);
			}
			new_temporary_storage[final_position_in_storage] = storage[i];
		}
	}
	// the usual switch
	delete storage;
	storage = new_temporary_storage;
}



MultiMap::MultiMap() {
	//TODO - Implementation
	capacity = 8;// with 2 it takes like 4 min +- 
	count = 0;
	storage = new TElem[capacity]{};
	for (int i = 0; i < capacity; i++)
	{
		storage[i] = NULL_TELEM;
	}
}
// Complexity is O(n)bcs with the iterator it will go on every element and the remove function is Theta(1)
void MultiMap::filter(Condition cond)
{// for loop  if 
	MultiMapIterator im = iterator();
	while (im.valid()) 
	{

		TElem element = im.getCurrent();
		if (cond(element.second) == false)
		{
			remove(element.first,element.second);
		}
		im.next();
	}
}


void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
	if (count * 1.0 / capacity >= 0.75)// 
	{
		resize();
	}
	count++;
	int index_for_hashtable = 0;
	int final_position_in_storage = hash_table(c, index_for_hashtable);
	while (storage[final_position_in_storage] != NULL_TELEM && storage[final_position_in_storage] != DELETED_TELEM) // if something is allready in the position we search for the next empty position.// if s TElem then we do the while
	{
		index_for_hashtable++;
		final_position_in_storage = hash_table(c, index_for_hashtable);
	}
	storage[final_position_in_storage] = { c,v };// we add the key and the value 
}


bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	int index_for_hashtable = 0;
	int final_position_in_storage = hash_table(c, index_for_hashtable);
	TElem element_to_remove = { c,v };
	
	while (index_for_hashtable != capacity && storage[final_position_in_storage] != element_to_remove) // if something is allready in the position we search for the next empty position.// if s TElem then we do the while
	{// this is the search of the element we want to remove
		
		index_for_hashtable++;
		final_position_in_storage = hash_table(c, index_for_hashtable);

		
	}
	if(index_for_hashtable == capacity)
		return  false;
	else
	{
		count--;
		storage[final_position_in_storage] = DELETED_TELEM;// the deletion 
		return true;
	}
}


vector<TValue> MultiMap::search(TKey c) const {
	//TODO - Implementation
	vector<TValue> container_values_of_the_key;
	int index_for_hashtable = 0;
	int final_position_in_storage = hash_table(c, index_for_hashtable);
	while (storage[final_position_in_storage] != NULL_TELEM) // if something is allready in the position we search for the next empty position.// if s TElem then we do the while
	{
		if (storage[final_position_in_storage].first == c)
		{
			container_values_of_the_key.push_back(storage[final_position_in_storage].second);// we only want the value as the problem sugessted
		}
		index_for_hashtable++;
		final_position_in_storage = hash_table(c, index_for_hashtable);
	}
	return container_values_of_the_key;
}


int MultiMap::size() const {
	//TODO - Implementation
	return count;
}


bool MultiMap::isEmpty() const {
	//TODO - Implementation
	return size()==0;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
	//TODO - Implementation
	delete storage;
}

