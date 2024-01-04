#include "service.h"

Service::Service(Repository_Inherit* recordings)
{
	this->recordings = recordings;
}

Service::~Service()
{
	delete this->recordings;
}

void Service::creating_the_iterator()
{
	this->recordings->Create_Iterator();
}

void Service::append_function(string title, string section, Date date_of_creation, int access_count, string footage_preview)
{
	if (this->recordings->repository_search(title) != NULL)
	{
		throw Exceptions("It exists mate!");
	}
	Tape* adding_tape = new Tape(title, section, date_of_creation, access_count, footage_preview);
	this->recordings->repository_add(adding_tape);
}

void Service::delete_function(string title)
{
	if (this->recordings->repository_search(title) == NULL)
	{
		throw Exceptions("It dose not exist mate!");
	}
	this->recordings->repository_delete(title);
}

void Service::update_function(string title, string section, Date date_of_creation, int access_count, string footage_preview)
{
	if (this->recordings->repository_search(title) == NULL)
	{
		throw Exceptions("It dose not exist mate!");
	}
	this->recordings->repository_update(title, section, date_of_creation, access_count, footage_preview);
}
std::vector<Tape*> Service::list_function()
{
	return this->recordings->get_array_for_listing();
}

Tape* Service::next_tape()
{
	Tape* current_element_display;
	current_element_display = recordings->current_tape();
	recordings->next_tape();
	return current_element_display;
}

void Service::save_tape_by_title(string title)
{
	Tape* saver;
	if (this->recordings->repository_search(title) == NULL)
	{
		throw Exceptions("It dose not exist mate!");
	}
	saver = recordings->repository_search(title);
	recordings->repository_add_mylist(saver);

}

std::vector<Tape*> Service::list_my_list()
{
	return this->recordings->get_my_list_for_listing();
}

std::vector<Tape*> Service::list_by_section_access(string section,int access_count)
{
	return this->recordings->list_section_access_count(section,access_count);
}







