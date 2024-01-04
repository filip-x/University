#pragma once

#include "iterator.h"
#include<ctime>
#include <vector>
#include "tape.h"
typedef tm Date;
class Repository_Inherit
{
public:
	virtual ~Repository_Inherit() = 0 {};
	virtual void Create_Iterator()=0;
	virtual void repository_add(Tape* new_element_to_add)=0;
	virtual void repository_delete(string title)=0;
	virtual Tape* repository_search(string title)=0;
	virtual void repository_update(string title, string update_section, Date update_date_of_creation, int update_access_count, string update_footage_preview)=0;
	virtual std::vector<Tape*>  get_array_for_listing()=0;
	virtual void next_tape()=0;
	virtual Tape* current_tape()=0;
	virtual void repository_add_mylist(Tape* new_element_to_add_into_my_list)=0;
	virtual std::vector<Tape*>  get_my_list_for_listing()=0;
	virtual std::vector<Tape*>  list_section_access_count(string section, int access_count)=0;
private:
};
