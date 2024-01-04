#include "html_file.h"
#include<iostream>
#include<fstream>
#include<algorithm>
#include <sstream>
#include<ctime>
typedef tm Date;
My_list_html::My_list_html(string path_to_file)
{
	this->path_to_file = path_to_file;
}

void My_list_html::saving_my_list(Tape* new_element_to_add)
{
	std::vector<Tape*> temporary_vector = read_from_file();
	temporary_vector.push_back(new_element_to_add);//we point to the object of the repo_dynamic_array(directly) and use the overloaded+= operator
	write_into_file(temporary_vector);
}

vector<Tape*> My_list_html::display_my_list()
{
	return read_from_file();
}

void My_list_html::open()
{
	string cmd = "start \"C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe\" \"" + path_to_file + "\"";
	system(cmd.c_str());
}

vector<Tape*> My_list_html::read_from_file()
{
	char string_line[1000];
	string property;
	stringstream object_generator;
	ifstream file(path_to_file);
	std::vector<Tape*> file_into_vector;
	Tape* element;
	file.getline(string_line, 1000);
	while (string(string_line) != "<tr>")
	{
		if(!file.getline(string_line,1000))
			break;
	}
	for (int i = 0; i <= 5; i++)
	{
		file.getline(string_line, 1000);
	}
	file.getline(string_line, 1000);
	while (string(string_line) == "<tr>")
	{
		for (int i = 1; i <= 5; i++)
		{
			file.getline(string_line, 1000);
			property = string(string_line).substr(4, strlen(string_line) - 9);
			object_generator << property << ",";
		}
		object_generator << "\n";
		file.getline(string_line, 1000);
		object_generator >> element;
		file_into_vector.push_back(element);
		file.getline(string_line, 1000); // reading the next <tr>
	}
	return file_into_vector;
}

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
void My_list_html::write_into_file(vector<Tape*> vector_to_insert_into_file)
{
	ofstream file(path_to_file);
	stringstream string_stream;
	string_stream << "<!DOCTYPE html>\n<html>\n<head>\n<title>Tapes</title>\n</head>\n<body>\n<table border =\"1\">\n";
	string_stream << "<tr>\n<td>Title</td>\n<td>Section</td>\n<td>Date</td>\n<td>Access Count</td>\n<td>Footage Preview</td>\n</tr>\n";
	for (Tape* current_element : vector_to_insert_into_file)
	{
		string_stream << "<tr>\n<td>" << current_element->get_title() << "</td>\n<td>"<<current_element->get_section()<<"</td>\n<td>"<<date_to_string(current_element->get_date_of_creation())<<"</td>\n<td>"<<current_element->get_access_count()<<"</td>\n<td>"<<current_element->get_footage_preview()<<"</td>\n</tr>\n";

	}
	string_stream << "</table>\n</body>\n</html>";
	file << string_stream.str();
	file.close();
}


