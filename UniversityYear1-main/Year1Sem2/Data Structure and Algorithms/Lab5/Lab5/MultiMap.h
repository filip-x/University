#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
typedef bool (*Condition)(TValue);
#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)
#define DELETED_TELEM pair<int,int>(-1111111, -1111111)// an extra 1 
class MultiMapIterator;

class MultiMap
{
	friend class MultiMapIterator;


private:
	//TODO - Representation
	TElem* storage;
	int capacity; // it says the size of the storage
	int count; // how many things I have in the storage so far
	int hash_table(TKey,int index)const;
	void resize();
	
public:
	//constructor
	MultiMap();
	void filter(Condition cond);
	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//descturctor
	~MultiMap();


};

