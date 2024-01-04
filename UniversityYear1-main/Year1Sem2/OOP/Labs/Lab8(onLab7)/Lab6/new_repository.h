#pragma once


#include "iterator.h"
#include<ctime>
#include <vector>
#include "tape.h"
#include "repository_inherit.h"
typedef tm Date;
class File_Repository :public Repository_Inherit
{
public:
	File_Repository(std::string path_to_file);
	~File_Repository();
	void Create_Iterator() override;
	void repository_add(Tape* new_element_to_add)override;
	void repository_delete(string title)override;
	Tape* repository_search(string title)override;
	void repository_update(string title, string update_section, Date update_date_of_creation, int update_access_count, string update_footage_preview)override;
	std::vector<Tape*>  get_array_for_listing()override;
	void next_tape()override;
	Tape* current_tape()override;
	void repository_add_mylist(Tape* new_element_to_add_into_my_list)override;
	std::vector<Tape*>  get_my_list_for_listing()override;
	std::vector<Tape*>  list_section_access_count(string section, int access_count)override;
	void vector_into_file(std::vector<Tape*> &vector_to_insert_into_file);
	std::vector<Tape*> file_into_vector();
private:
	//Dynamic_array<Tape>* repo_dynamic_array;// we point  to the dynamic array  AS6
	std::string file_path;
	Iterator* repo_iterator;
	std::vector<Tape*> my_list;



};
