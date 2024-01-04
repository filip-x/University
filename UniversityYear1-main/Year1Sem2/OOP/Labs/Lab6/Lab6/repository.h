#pragma once
#include "dynamic_array.h"

class Repository
{
public:
	Repository();
	~Repository();
	void repository_add(Tape* new_element_to_add);
	void repository_delete(string title);
	Tape* repository_search(string title);
	void repository_update(string title,string update_section,string update_date_of_creation,int update_access_count,string update_footage_preview);
	Dynamic_array* get_array_for_listing();

private:
	Dynamic_array* repo_dynamic_array;// we point  to the dynamic array 
	
};
