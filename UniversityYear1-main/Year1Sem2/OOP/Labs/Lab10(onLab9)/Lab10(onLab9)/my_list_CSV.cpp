#include "my_list_CSV.h"
#include<iostream>
#include<fstream>
#include<algorithm>
#include <Windows.h>


My_list_CSV::My_list_CSV(string path_to_file)
{
	this->path_to_file = path_to_file;
}

void My_list_CSV::saving_my_list(Tape* new_element_to_add)
{
	std::vector<Tape*> temporary_vector = read_from_file();
	temporary_vector.push_back(new_element_to_add);//we point to the object of the repo_dynamic_array(directly) and use the overloaded+= operator
	write_into_file(temporary_vector);
}

vector<Tape*> My_list_CSV::display_my_list()
{
	return read_from_file();
}

void My_list_CSV::open()
{
	string cmd = "start excel \"" + path_to_file + "\"";
	system(cmd.c_str());
}

vector<Tape*> My_list_CSV::read_from_file()
{
	ifstream file(path_to_file);
	std::vector<Tape*> file_into_vector;
	Tape* element;
	while (file >> element)
	{
		file_into_vector.push_back(element);
	}
	file.close();
	return file_into_vector;
		
}

void My_list_CSV::write_into_file(vector<Tape*> vector_to_insert_into_file)
{
	ofstream file(path_to_file);
	std::for_each(vector_to_insert_into_file.begin(), vector_to_insert_into_file.end(), [&file](Tape* element)
		{
			file << element;

		});
	file.close();
}
