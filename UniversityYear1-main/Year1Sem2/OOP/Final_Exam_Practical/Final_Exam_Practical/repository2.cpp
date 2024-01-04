#include "repository2.h"
#include <string>
#include <fstream>

using namespace std;
Repository2::Repository2()
{

}

Repository2::~Repository2()
{

}

void Repository2::adding_function(Stars element)
{
	this->storage2.push_back(element);

}

void Repository2::update_function(Stars old_element, Stars new_element)
{
	for (int i = 0; i < this->storage2.size(); i++)
	{
		if (storage2[i].get_name() == old_element.get_name())
		{
			storage2[i] = new_element;
			break;
		}
	}
}

void Repository2::delete_function(Stars delete_element)
{
	for (int i = 0; i < this->storage2.size(); i++)
	{
		if (this->storage2[i].get_name() == delete_element.get_name())
		{
			storage2.erase(storage2.begin() + i);
			break;
		}
	}
}

std::vector<Stars> Repository2::list_function()
{
	return this->storage2;
}

Stars Repository2::search_function(Stars search_element)
{

	for (int i = 0; i < this->storage2.size(); i++)
	{
		if (this->storage2[i].get_name() == search_element.get_name())
		{
			return this->storage2[i];
			break;
		}
	}
}


void Repository2::read_from_file(string path2)
{
	ifstream file2(path2);
	Stars element;
	while (file2 >> element)
	{
		this->adding_function(element);
	}
}

void Repository2::read_into_file(string path2)
{
	ofstream file2(path2);
	for (auto element : storage2)
	{
		file2 << element;
	}
}

