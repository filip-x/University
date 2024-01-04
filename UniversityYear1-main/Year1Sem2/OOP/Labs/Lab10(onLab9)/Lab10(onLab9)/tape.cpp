#include "tape.h"
#include <iostream>
#include <sstream>
#include <vector>

Tape::Tape(string new_title, string new_section, Date new_date_of_creation,int new_access_count, string new_footage_preview)
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

Date Tape::get_date_of_creation()
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
/*
void Tape::set_section(string new_section)
{
	this->section = new_section;
}

void Tape::set_date_of_creation(Date new_date_of_creation)
{
	this->date_of_creation = new_date_of_creation;
}

void Tape::set_access_count(int new_access_count)
{
	this->access_count = new_access_count;
}

void Tape::set_footage_preview(string new_footage_preview)
{
	this->footage_preview = new_footage_preview;
}*/

inline string date_to_string(Date date_to_display)
{
	char string_date[100];
	sprintf(string_date, "%d-%d-%d", date_to_display.tm_mon, date_to_display.tm_mday, date_to_display.tm_year);
	return string(string_date);
}

inline Date string_to_date(string date)
{
	int day, year, month;
	int placeholder = sscanf(date.c_str(), "%d-%d-%d", &month, &day, &year);
	Date date_of_creation;
	date_of_creation.tm_mon = month;
	date_of_creation.tm_mday = day;
	date_of_creation.tm_year = year;
	return date_of_creation;
}

istream& operator>>(istream& input_stream, Tape*& element)
{
	std::string line;
	std::string property;
	getline(input_stream, line);
	std::stringstream line_stream(line);
	std::vector<std::string> properties;
	while (getline(line_stream, property, ','))
		properties.push_back(property);
	if (properties.size() == 0)
		return input_stream;
	std::string title = properties[0];
	std::string section = properties[1];
	std::string date = properties[2];
	std::string access_count = properties[3];
	std::string footage_preview = properties[4];
	element = new Tape(title, section, string_to_date(date), std::stoi(access_count), footage_preview);
	return input_stream;
}

ostream& operator<<(ostream& output_stream, Tape* element)
{
	output_stream << element->get_title() << "," << element->get_section() << "," << date_to_string(element->get_date_of_creation()) << "," << std::to_string(element->get_access_count()) << "," << element->get_footage_preview() << "\n";
	return output_stream;
}
