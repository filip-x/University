#include "repo.h"
#include <fstream>


Repository::~Repository()
{
	for (auto element : storage)
		delete element;
}

void Repository::add(Department* new_dep)
{
	this->storage.push_back(new_dep);
}

const std::vector<Department*> Repository::get()
{
	return storage;
}

void Repository::write_file(std::string file_name)
{
	std::ofstream f(file_name);
	for (auto element : storage)
		f << element->type << " | " << element->to_string() << " | is_efficient: " << element->is_eficient() <<"\n";
	f.close();
}
