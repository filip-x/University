#include "service.h"

Service::Service()
{
	this->recordings = new Repository;
}


Service::~Service()
{
	delete this->recordings;
}

void Service::append_function(string title, string section, string date_of_creation, int access_count, string footage_preview)
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

void Service::update_function(string title, string section, string date_of_creation, int access_count, string footage_preview)
{
	if (this->recordings->repository_search(title) == NULL)
	{
		throw Exceptions("It dose not exist mate!");
	}
	this->recordings->repository_update(title, section, date_of_creation, access_count, footage_preview);
}

Dynamic_array* Service::list_function()
{
	return this->recordings->get_array_for_listing();
}
