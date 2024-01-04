#include "repository.h"

Repository::Repository()
{
	this->repo_dynamic_array = new Dynamic_array; // here we create the dynamic array 
}

Repository::~Repository()
{
	delete this->repo_dynamic_array;
}

void Repository::repository_add(Tape* new_element_to_add)
{
	*this->repo_dynamic_array += new_element_to_add;//we point to the object of the repo_dynamic_array(directly) and use the overloaded+= operator

}

void Repository::repository_delete(string title_to_delete)
{
	for (int i = 0; i < this->repo_dynamic_array->get_count(); i++)
	{
		if ((*this->repo_dynamic_array)[i]->get_title() == title_to_delete)// this is the overloader[]= get the object 
		{
			delete (*this->repo_dynamic_array)[i];//delete from memory
			*this->repo_dynamic_array -= i;// remake the positioning
		}
	}
}
Tape* Repository::repository_search(string title_to_search)
{
	for (int i = 0; i < this->repo_dynamic_array->get_count(); i++)
	{
		if ((*this->repo_dynamic_array)[i]->get_title() == title_to_search)
		{
			return (*this->repo_dynamic_array)[i];
		}
	}
	return NULL;
}

void Repository::repository_update(string title_to_update, string update_section, string update_date_of_creation, int update_access_count, string update_footage_preview)
{
	for (int i = 0; i < this->repo_dynamic_array->get_count(); i++)
	{
		if ((*this->repo_dynamic_array)[i]->get_title() == title_to_update)
		{
			Tape* new_tape = new Tape(title_to_update,update_section,update_date_of_creation,update_access_count,update_footage_preview);
			delete (*this->repo_dynamic_array)[i];
			(*this->repo_dynamic_array)[i] = new_tape;
			break;
		}
		
	}

}

Dynamic_array* Repository::get_array_for_listing()
{
	Dynamic_array* new_print_array = new Dynamic_array;
	for (int i = 0; i < this->repo_dynamic_array->get_count(); i++)
	{
		*new_print_array += new Tape((*this->repo_dynamic_array)[i]);// the second constructor
	}
	return new_print_array;
}





