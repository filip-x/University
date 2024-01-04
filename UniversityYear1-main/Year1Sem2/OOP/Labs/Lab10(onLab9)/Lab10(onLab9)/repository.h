#pragma once

#include "iterator.h"
#include<ctime>
#include <vector>
#include "tape.h"
#include "repository_inherit.h"
typedef tm Date;
class Repository :public Repository_Inherit
{
public:
	Repository();
	~Repository();
	void Create_Iterator() override;
	void repository_add(Tape* new_element_to_add)override;
	void repository_delete(string title)override;
	Tape* repository_search(string title)override;
	void repository_update(string title,string update_section,Date update_date_of_creation,int update_access_count,string update_footage_preview)override;
	std::vector<Tape*>  get_array_for_listing()override;
	void next_tape()override;
	Tape* current_tape()override;
	void repository_add_mylist(Tape* new_element_to_add_into_my_list);
		std::vector<Tape*>  get_my_list_for_listing();
	std::vector<Tape*>  list_section_access_count(string section,int access_count)override;


private:
	//Dynamic_array<Tape>* repo_dynamic_array;// we point  to the dynamic array  AS6
	std::vector<Tape*>repo_dynamic_array;
	Iterator* repo_iterator;
	std::vector<Tape*> my_list;

	
	
};
