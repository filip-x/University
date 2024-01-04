#pragma once
#include "repository.h"

using namespace std;

class Service
{
public:
	Service();
	~Service();
	void append_function(string title,string section,string date_of_creation,int access_count,string footage_preview);
	void delete_function(string title);
	void update_function(string title, string section, string date_of_creation, int access_count, string footage_preview);
	Dynamic_array* list_function();


private:
	Repository* recordings;
};

