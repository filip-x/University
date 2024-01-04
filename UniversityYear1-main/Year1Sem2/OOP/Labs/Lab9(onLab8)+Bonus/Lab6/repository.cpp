#include "repository.h"
#include<algorithm>
Repository::Repository()
{
	
	repo_iterator = NULL;
}

Repository::~Repository()
{
	
	for (auto element : this->repo_dynamic_array)
	{
		delete element;
	}
	for (auto element : this->my_list)
	{
		delete element;
	}

}

void Repository::Create_Iterator()
{
	std::vector<Tape*> new_copy_list;
	if (repo_iterator != NULL)
	{
		delete repo_iterator;
	}
	std::for_each(this->repo_dynamic_array.begin(), this->repo_dynamic_array.end(),[&new_copy_list](Tape* element)
		{
			Tape* copy_element = new  Tape(element);
			new_copy_list.push_back(copy_element);
			
		});
	repo_iterator = new Iterator(new_copy_list);

}

void Repository::repository_add(Tape* new_element_to_add)
{
	this->repo_dynamic_array.push_back(new_element_to_add);//we point to the object of the repo_dynamic_array(directly) and use the overloaded+= operator

}

void Repository::repository_delete(string title_to_delete)
{
	std::remove_if(this->repo_dynamic_array.begin(), this->repo_dynamic_array.end(), [&title_to_delete](Tape* element)
		{
			if (element->get_title() == title_to_delete)
			{
				return true;
			}
			else
			{
				return false;
			}
		});
	delete this->repo_dynamic_array.back();
	this->repo_dynamic_array.pop_back();
}
Tape* Repository::repository_search(string title_to_search)
{
	std::vector<Tape*>::iterator it = std::find_if(this->repo_dynamic_array.begin(), this->repo_dynamic_array.end(), [&title_to_search](Tape* element)// find_if return an iterator to element we get him in it
		{
			if (element->get_title() == title_to_search)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		});
	if (it == this->repo_dynamic_array.end())
		return NULL;
	else
		return new Tape(*it);// *it( it's like it.get_current()
}

void Repository::repository_update(string title_to_update, string update_section, Date update_date_of_creation, int update_access_count, string update_footage_preview)
{

	Tape* new_tape = new Tape(title_to_update, update_section, update_date_of_creation, update_access_count, update_footage_preview);
	std::replace_if(this->repo_dynamic_array.begin(), this->repo_dynamic_array.end(), [&title_to_update](Tape* element)
		{
			if (element->get_title() == title_to_update)
			{
				delete element;
				return 1;
			}
			else
				return 0;
		},new_tape);
}
std::vector<Tape*> Repository::get_array_for_listing()
{
	std::vector<Tape*> new_print_array;
	std::for_each(this->repo_dynamic_array.begin(), this->repo_dynamic_array.end(), [&new_print_array](Tape* element) 
		{
			Tape* copy_of_element = new Tape(element);
			new_print_array.push_back(copy_of_element);
		});
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
	
	this->my_list.push_back(new_element_to_add_into_my_list);
	
}

std::vector<Tape*> Repository::get_my_list_for_listing()
{
	std::vector<Tape*> new_print_array;
	std::for_each(this->my_list.begin(), this->my_list.end(), [&new_print_array](Tape* element)
		{
			Tape* copy_of_element = new Tape(element);
			new_print_array.push_back(copy_of_element);
		});
	return new_print_array;
}

std::vector<Tape*>Repository::list_section_access_count(string section,int access_count)
{
	std::vector<Tape*> new_print_array;
	std::for_each(this->repo_dynamic_array.begin(), this->repo_dynamic_array.end(), [&new_print_array,&section,&access_count](Tape* element)
		{
			if (element->get_section() == section && element->get_access_count() < access_count)
			{
				Tape* copy_of_element = new Tape(element);
				new_print_array.push_back(copy_of_element);
			}
		});
	return new_print_array;
	
}
