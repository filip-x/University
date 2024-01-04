#pragma once
#include<string>
using namespace std;
class Tape
{
public:

	Tape(string title, string section, string date_of_creation,int access_count,string footage_preview);
	Tape(Tape* element_to_copy);
	string get_title();
	string get_section();
	string get_date_of_creation();
	int get_access_count();
	string get_footage_preview();
	void set_section(string section);
	void set_date_of_creation(string date_of_creation);
	void set_access_count(int access_count);
	void set_footage_preview(string footage_preview);


	

private:
	string title;
	string section;
	string date_of_creation;
	int access_count;
	string footage_preview;
};
