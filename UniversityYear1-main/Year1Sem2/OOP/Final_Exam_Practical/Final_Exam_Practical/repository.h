#pragma once
#include <vector>
#include "domain.h"
#include <string>
class Repository1
{
public:
	Repository1();
	~Repository1();
	void adding_function(Astronomer);
	void update_function(Astronomer,Astronomer);
	void delete_function(Astronomer);
	std::vector<Astronomer> list_function();
	Astronomer search_function(Astronomer);
	void read_from_file(std::string);
	void read_into_file(std::string);

private:

	std::vector<Astronomer> storage1;
};

