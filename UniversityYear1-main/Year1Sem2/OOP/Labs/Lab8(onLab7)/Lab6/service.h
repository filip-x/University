#pragma once
#include "repository.h"
#include<ctime>
#include <vector>
#include "exceptions.h"
#include "repository_inherit.h"
#include "new_repository.h"
typedef tm Date;
using namespace std;

class Service
{
public:
	Service(Repository_Inherit* recordings=new File_Repository("test.txt"));
	~Service();
	void creating_the_iterator();
	void append_function(string title,string section, Date date_of_creation,int access_count,string footage_preview);
	void delete_function(string title);
	void update_function(string title, string section, Date date_of_creation, int access_count, string footage_preview);
	std::vector<Tape*> list_function();
	Tape* next_tape();
	void save_tape_by_title(string title);
	std::vector<Tape*> list_my_list();
	std::vector<Tape*> list_by_section_access(string section,int access_count);

private:
	Repository_Inherit* recordings;
};

