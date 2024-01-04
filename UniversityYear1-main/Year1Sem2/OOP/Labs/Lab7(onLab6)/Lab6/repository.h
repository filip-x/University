#pragma once
#include "dynamic_array.h"
#include "iterator.h"
#include<ctime>
typedef tm Date;
class Repository
{
public:
	Repository();
	~Repository();
	void Create_Iterator();
	void repository_add(Tape* new_element_to_add);
	void repository_delete(string title);
	Tape* repository_search(string title);
	void repository_update(string title,string update_section,Date update_date_of_creation,int update_access_count,string update_footage_preview);
	Dynamic_array<Tape>* get_array_for_listing();
	void next_tape();
	Tape* current_tape();
	void repository_add_mylist(Tape* new_element_to_add_into_my_list);
	Dynamic_array<Tape>* get_my_list_for_listing();
	Dynamic_array<Tape>* list_section_access_count(string section,int access_count);


private:
	Dynamic_array<Tape>* repo_dynamic_array;// we point  to the dynamic array 
	Iterator<Tape>* repo_iterator;
	Dynamic_array<Tape>* my_list;

};
