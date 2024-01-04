#pragma once
#include "new_repository.h"
#include<algorithm>
#include <fstream>

File_Repository::File_Repository(std::string path_to_file)
{
	this->file_path = path_to_file;
	repo_iterator = NULL;
}

File_Repository::~File_Repository()
{
	for (auto element : this->my_list)
		delete element;
}



void File_Repository::Create_Iterator()
{
	std::vector<Tape*> temporary_vector = file_into_vector();
	std::vector<Tape*> new_copy_list;
	if (repo_iterator != NULL)
	{
		delete repo_iterator;
	}
	repo_iterator = new Iterator(temporary_vector);

}

void File_Repository::repository_add(Tape* new_element_to_add)
{
	std::vector<Tape*> temporary_vector = file_into_vector();
	temporary_vector.push_back(new_element_to_add);//we point to the object of the repo_dynamic_array(directly) and use the overloaded+= operator
	vector_into_file(temporary_vector);
}

void File_Repository::repository_delete(string title_to_delete)
{
	std::vector<Tape*> temporary_vector = file_into_vector();
	std::remove_if(temporary_vector.begin(), temporary_vector.end(), [&title_to_delete](Tape* element)
		{
			if (element->get_title() == title_to_delete)
				return true;
			else
				return false;
		});
	temporary_vector.pop_back();
	vector_into_file(temporary_vector);
}
Tape* File_Repository::repository_search(string title_to_search)
{
	std::vector<Tape*> temporary_vector = file_into_vector();
	std::vector<Tape*>::iterator it = std::find_if(temporary_vector.begin(), temporary_vector.end(), [&title_to_search](Tape* element)// find_if return an iterator to element we get him in it
		{
			if (element->get_title() == title_to_search)
				return 1;
			else
				return 0;
		});
	if (it ==temporary_vector.end())
		return NULL;
	else
		return new Tape(*it);// *it( it's like it.get_current()
}

void File_Repository::repository_update(string title_to_update, string update_section, Date update_date_of_creation, int update_access_count, string update_footage_preview)
{
	std::vector<Tape*> temporary_vector = file_into_vector();
	Tape* new_tape = new Tape(title_to_update, update_section, update_date_of_creation, update_access_count, update_footage_preview);
	std::replace_if(temporary_vector.begin(), temporary_vector.end(), [&title_to_update](Tape* element)
		{
			if (element->get_title() == title_to_update)
			{
				delete element;
				return 1;
			}
			else
				return 0;
		}, new_tape);
	vector_into_file(temporary_vector);
}
std::vector<Tape*> File_Repository::get_array_for_listing()
{
	return file_into_vector();
}

void File_Repository::next_tape()
{
	repo_iterator->next();
}

Tape* File_Repository::current_tape()
{
	return repo_iterator->current_element();
}

void File_Repository::repository_add_mylist(Tape* new_element_to_add_into_my_list)
{

	this->my_list.push_back(new_element_to_add_into_my_list);

}

std::vector<Tape*> File_Repository::get_my_list_for_listing()
{
	std::vector<Tape*> new_print_array;
	std::for_each(this->my_list.begin(), this->my_list.end(), [&new_print_array](Tape* element)
		{
			Tape* copy_of_element = new Tape(element);
			new_print_array.push_back(copy_of_element);
		});
	return new_print_array;
}

std::vector<Tape*>File_Repository::list_section_access_count(string section, int access_count)
{
	std::vector<Tape*> new_print_array;
	std::vector<Tape*> temporary_vector = file_into_vector();
	std::for_each(temporary_vector.begin(), temporary_vector.end(), [&new_print_array, &section, &access_count](Tape* element)
		{
			if (element->get_section() == section && element->get_access_count() < access_count)
			{
				Tape* copy_of_element = new Tape(element);
				new_print_array.push_back(copy_of_element);
			}
		});
	return new_print_array;

}

void File_Repository::vector_into_file(std::vector<Tape*> &vector_to_insert_into_file)
{
	ofstream file(file_path);
	std::for_each(vector_to_insert_into_file.begin(), vector_to_insert_into_file.end(), [&file](Tape* element)
		{
			file << element;

		});
	file.close();
}

std::vector<Tape*> File_Repository::file_into_vector()
{
	ifstream file(file_path);
	std::vector<Tape*> file_into_vector;
	Tape* element;
	while (file>>element)
	{
		file_into_vector.push_back(element);
	}
	file.close();
	return file_into_vector;
}
