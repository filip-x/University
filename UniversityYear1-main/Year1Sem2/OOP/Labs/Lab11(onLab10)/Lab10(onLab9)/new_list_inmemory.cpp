#include "my_list_inmemory.h"
#include<iostream>
#include<fstream>
#include<algorithm>
#include <Windows.h>


My_list_InMemory::My_list_InMemory()
{
	
}

void My_list_InMemory::saving_my_list(Tape* new_element_to_add)
{
	storage.push_back(new Tape(new_element_to_add));
}

vector<Tape*> My_list_InMemory::display_my_list()
{
	return storage;
}
