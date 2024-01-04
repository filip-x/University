#pragma once
#include <vector>
#include "domain2.h"
#include <string>
class Repository2
{
public:
	Repository2();
	~Repository2();
	void adding_function(Stars);
	void update_function(Stars, Stars);
	void delete_function(Stars);
	std::vector<Stars> list_function();
	Stars search_function(Stars);
	void read_from_file(std::string);
	void read_into_file(std::string);

private:

	std::vector<Stars> storage2;
};

