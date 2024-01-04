#include "tape.h"

Tape::Tape(string new_title, string new_section, string new_date_of_creation,int new_access_count, string new_footage_preview)
{
	this->title = new_title;
	this->section = new_section;
	this->date_of_creation = new_date_of_creation;
	this->access_count = new_access_count;
	this->footage_preview = new_footage_preview;
}

Tape::Tape(Tape* element_to_copy)// clone constructor
{
	this->title = element_to_copy->get_title();
	this->section = element_to_copy->get_section();
	this->date_of_creation = element_to_copy->get_date_of_creation();
	this->access_count = element_to_copy->get_access_count();
	this->footage_preview = element_to_copy->get_footage_preview();
}

string Tape::get_title()
{
	return this->title;
}

string Tape::get_section()
{
	return this->section;
}

string Tape::get_date_of_creation()
{
	return this->date_of_creation;
}

int Tape::get_access_count()
{
	return this->access_count;
}

string Tape::get_footage_preview()
{
	return this->footage_preview;
}

void Tape::set_section(string new_section)
{
	this->section = new_section;
}

void Tape::set_date_of_creation(string new_date_of_creation)
{
	this->section = new_date_of_creation;
}

void Tape::set_access_count(int new_access_count)
{
	this->section = new_access_count;
}

void Tape::set_footage_preview(string new_footage_preview)
{
	this->footage_preview = new_footage_preview;
}
