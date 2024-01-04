#include "repository.h"
#include <fstream>
#include <string>
using namespace std;
Repository1::Repository1()
{

}

Repository1::~Repository1()
{

}

void Repository1::adding_function(Astronomer element )
{
	this->storage1.push_back(element);

}

void Repository1::update_function(Astronomer old_element, Astronomer new_element)
{
	for (int i = 0; i < this->storage1.size(); i++)
	{
		if (storage1[i].get_name() == old_element.get_name())
		{
			storage1[i] = new_element;
			break;
		}
	}
}

void Repository1::delete_function(Astronomer delete_element)
{
	for (int i = 0; i < this->storage1.size(); i++)
	{
		if (this->storage1[i].get_name() == delete_element.get_name())
		{
			storage1.erase(storage1.begin()+i);
			break;
		}
	}
}

std::vector<Astronomer> Repository1::list_function()
{
	return this->storage1;
}

Astronomer Repository1::search_function(Astronomer search_element)
{

	for (int i = 0; i < this->storage1.size(); i++)
	{
		if (this->storage1[i].get_name() == search_element.get_name())
		{
			return this->storage1[i];
			break;
		}
		
	}
	return Astronomer();
}


void Repository1::read_from_file(string path)
{	
	ifstream file(path);
	Astronomer element;
	while (file>> element)
	{
		this->adding_function(element);
	}
}

void Repository1::read_into_file(string path)
{
	ofstream file(path);
	for (auto element : storage1)
	{
		file << element;
	}
}

