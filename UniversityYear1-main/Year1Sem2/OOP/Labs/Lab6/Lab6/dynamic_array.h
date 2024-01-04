#pragma once
#include"tape.h"
#include "exceptions.h"
using namespace std;

// constructor destructor and resize-first
// access data ,delete data, insert second 
class Dynamic_array
{
public:
	Dynamic_array();//constructor
	~Dynamic_array();// destructor
	Tape*& operator[](int position_in_array);// to access the array
	void operator+=(Tape* new_tape);// to insert(add) in the array on the last position
	void operator-=(int position_in_array);// to delete from the array
	int get_count();


private:
	Tape** array_of_tapes;// or storage of tapes() ( first* is for pointer second is for list)
	int count_array;
	int maxim_array;
	void resize_array();// resize
};


