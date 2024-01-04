#include "Set.h"
#include "SetITerator.h"
// I didn't consider the full explained thing to  do and the complexity is not right ( it can't be O(1) it can only be Theta(1) and to add we  should consider that we have the search function in  it 
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
Set::Set() {
	//TODO - Implementation -Done 
	this->capacity = 5;
	this->vector = new TElem[this->capacity];
	this->count = 0;
}

//Complexity:n = count
//Best Case = Average Case: Whenever the array isn't full: O(1)
//Worst Case:When the array is full: T(n) = n+12 => O(n) 
bool Set::add(TElem elem) {
	//TODO - Implementation -Done
	if (search(elem) == true)
	{
		return false;
	}
	if (this->capacity == this->count)
	{
		this->capacity = this->capacity * 2;
		TElem* tempo_vector = new TElem[this->capacity];
		for (int i = 0; i < this->count; i++)
		{
			tempo_vector[i] = this->vector[i];
		}
		delete this->vector;
		this->vector = tempo_vector;
	}
	this->vector[count] = elem;// can't sort because we don't know how to compare TElem
	this->count++;
	return true;
	
}

//Complexity:n= count
//Best Case = Worst Case = Average Case:
//There are 2 steps in this algorithm:- reaching the element( i-steps)
//									  - the actual removel of the element n-i steps
//=> Complexity of O(n)

bool Set::remove(TElem elem) {
	//TODO - Implementation -Done
	int sem = 1;
	for(int i =0;i<this->count;i++)
		if (this->vector[i] == elem)
		{
			for (int j = i + 1; j < this->count; j++)
				this->vector[j - 1] = this->vector[j];
			this->count--;
			sem = 0;
			break;
		}
	if (sem==1)
		return false;
	else
	{
		return true;
	}
}
//Complexity:n= count
//Best Case: if the element is on the first position   Complexity: O(1)
//Worst Case: if the element is on the last position	Complexity O(n)
//Average Case: T(n) =( sum of all cases)/ (count cases)
// T(n) = (Sum from 1 to n)/ n = {[n(n+1)]/2}/n => (n+1)/2 => O(n)
bool Set::search(TElem elem) const {
	//TODO - Implementation
	for( int i=0;i<this->count;i++)
		if (vector[i] == elem)
		{
			return true;
		}
	return false;
}


//Complexity Best Case = Worst Case = Average Case : Theta(1) 
int Set::size() const {
	//TODO - Implementation -Done

	return this->count;
}


//Complexity Best Case = Worst Case = Average Case : Theta(1) 
bool Set::isEmpty() const {
	//TODO - Implementation -Done
	if (this->count == 0)
		return true;
	return false;

}


//Complexity Best Case = Worst Case = Average Case : Theta(1) 
Set::~Set() {
	//TODO - Implementation -Done
	delete this->vector;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


