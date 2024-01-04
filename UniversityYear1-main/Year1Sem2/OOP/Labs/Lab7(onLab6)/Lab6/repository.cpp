#include "repository.h"

Repository::Repository()
{
	this->repo_dynamic_array = new Dynamic_array<Tape>; // here we create the dynamic array 
	this->my_list = new Dynamic_array<Tape>;
	repo_iterator = NULL;
}

Repository::~Repository()
{
	int count = this->my_list->get_count();
	delete this->repo_dynamic_array;
	for (int i = 0; i <count; i++)
		*this->my_list -= 0;
	delete this->my_list;

}

void Repository::Create_Iterator()
{
	if (repo_iterator != NULL)
	{
		delete repo_iterator;
	}
	repo_iterator = new Iterator<Tape>(repo_dynamic_array);

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

void Repository::repository_update(string title_to_update, string update_section, Date update_date_of_creation, int update_access_count, string update_footage_preview)
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
Dynamic_array<Tape>* Repository::get_array_for_listing()
{
	Dynamic_array<Tape>* new_print_array = new Dynamic_array<Tape>;
	for (int i = 0; i < this->repo_dynamic_array->get_count(); i++)
	{
		*new_print_array += new Tape((*this->repo_dynamic_array)[i]);// the second constructor
	}
	return new_print_array;
}

void Repository::next_tape()
{
	repo_iterator->next();
}

Tape* Repository::current_tape()
{
	return repo_iterator->current_element();
}

void Repository::repository_add_mylist(Tape* new_element_to_add_into_my_list)
{
	
	*this->my_list += new_element_to_add_into_my_list;
	
}

Dynamic_array<Tape>* Repository::get_my_list_for_listing()
{
	Dynamic_array<Tape>* new_print_array = new Dynamic_array<Tape>;
	for (int i = 0; i < this->my_list->get_count(); i++)
	{
		*new_print_array += new Tape((*this->my_list)[i]);// the second constructor
	}
	return new_print_array;
}

Dynamic_array<Tape>* Repository::list_section_access_count(string section,int access_count)
{
	Dynamic_array<Tape>* new_print_array = new Dynamic_array<Tape>;
	for (int i = 0; i < this->repo_dynamic_array->get_count(); i++)
	{
		if((*this->repo_dynamic_array)[i]->get_section()== section && (*this->repo_dynamic_array)[i]->get_access_count() < access_count)
			*new_print_array += new Tape((*this->repo_dynamic_array)[i]);// the second constructor
	}
	return new_print_array;
}




