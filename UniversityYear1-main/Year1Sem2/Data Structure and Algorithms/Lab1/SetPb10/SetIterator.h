#pragma once
#include "Set.h"

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	SetIterator(const Set& s);
	int index;// the number where we are

	//TODO - Representation

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
	 void jumpForward(int k);
};


