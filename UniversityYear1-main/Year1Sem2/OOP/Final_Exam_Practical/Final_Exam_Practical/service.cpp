#include "service.h"
#include <assert.h>
using namespace std;

Service::Service()
{

}

Service::~Service()
{

}

void Service::add(std::string attr1, std::string attr2)
{
	 Astronomer element_to_add(attr1, attr2);
	 this->service_repo1.adding_function(element_to_add);

	
}
// we make an object of the information that the user inputs from the keyboard and we add it with the help of the  repository of the stars in which we add the star
void Service::add2(std::string name, std::string constelation, int ra, int dec,int diameter)
{
	Stars element_to_add(name, constelation, ra, dec,diameter);
	this->service_repo2.adding_function(element_to_add);
}

void Service::update(std::string attr1 , std::string attr2)
{
	Astronomer new_element(attr1, attr2);
	Astronomer old_element = this->service_repo1.search_function(new_element);
	this->service_repo1.update_function(old_element, new_element);

}

void Service::update2(std::string name, std::string constelation,int ra ,int dec ,int diameter )
{
	Stars new_element(name, constelation, ra, dec, diameter);
	Stars old_element = this->service_repo2.search_function(new_element);
	this->service_repo2.update_function(old_element, new_element);
}

void Service::remove(string attr1)
{
	Astronomer element_to_delete = service_repo1.search_function(Astronomer(attr1, ""));
	this->service_repo1.delete_function(element_to_delete);
}

void Service::remove2(std::string attr5)
{
	Stars element_to_delete = service_repo2.search_function(Stars(attr5, "",0,0,0));
	this->service_repo2.delete_function(element_to_delete);
}

vector<Astronomer> Service::list()
{
	return this->service_repo1.list_function();
}

vector<Stars> Service::list2()
{
	return this->service_repo2.list_function();
}

void Service::read_file(string path)
{
	this->service_repo1.read_from_file(path);
}

void Service::read_file2(std::string path)
{
	this->service_repo2.read_from_file(path);
}

void Service::write_file(string path)
{
	this->service_repo1.read_into_file(path);
}

void Service::write_file2(std::string path)
{
	this->service_repo2.read_into_file(path);
}

std::vector<Stars> Service::search_stars(string name_to_find)
{
	auto list_stars = list2();
	vector<Stars> same_element;
	int count = 0;
	for (auto element : list_stars)
		if (element.get_name().find(name_to_find) != string::npos)// invalid poassition
			same_element.push_back(element);
	return same_element;
}


