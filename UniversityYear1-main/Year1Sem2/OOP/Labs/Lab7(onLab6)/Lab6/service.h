#pragma once
#include "repository.h"
#include<ctime>
typedef tm Date;
using namespace std;

class Service
{
public:
	Service();
	~Service();
	void creating_the_iterator();
	void append_function(string title,string section, Date date_of_creation,int access_count,string footage_preview);
	void delete_function(string title);
	void update_function(string title, string section, Date date_of_creation, int access_count, string footage_preview);
	Dynamic_array<Tape>* list_function();
	Tape* next_tape();
	void save_tape_by_title(string title);
	Dynamic_array<Tape>* list_my_list();
	Dynamic_array<Tape>* list_by_section_access(string section,int access_count);

private:
	Repository* recordings;
};

