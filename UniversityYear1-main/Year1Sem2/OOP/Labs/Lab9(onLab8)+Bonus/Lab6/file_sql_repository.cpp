#pragma once
#include "file_sql_repository.h"
#include<algorithm>
#include <fstream>
#include "exceptions.h"
#include "sqlite3.h"
#include <sstream>

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
inline string date_to_string(Date date_to_display)
{
	char string_date[100];
	sprintf(string_date, "%d-%d-%d", date_to_display.tm_mon, date_to_display.tm_mday, date_to_display.tm_year);
	return string(string_date);
}
Sql_Repository::Sql_Repository(std::string path_to_file)
{
	repo_iterator = NULL;
	sqlite3* Database;
	this->file_path = path_to_file;
	int operation_succes;
	operation_succes = sqlite3_open(path_to_file.c_str(), &Database);// open the Database
	if (operation_succes != 0)
		throw Exceptions("Could not open database");
	std::string sql_to_create_table = "CREATE TABLE IF NOT EXISTS Tapes(Title text,Section text, Date text, Access_Count int, Footage_Preview text)";
	char* sql_error_message;
	operation_succes = sqlite3_exec(Database, sql_to_create_table.c_str(), NULL, 0, &sql_error_message);//running querry
	if (operation_succes != SQLITE_OK)
	{
		sqlite3_free(sql_error_message);
		sqlite3_close(Database);
		throw Exceptions("Error creating table!");
	}
	sqlite3_close(Database);// close the Database
}

Sql_Repository::~Sql_Repository()
{
	for (auto element : this->my_list)
		delete element;
}



void Sql_Repository::Create_Iterator()
{
	std::vector<Tape*> temporary_vector = file_into_vector();
	std::vector<Tape*> new_copy_list;
	if (repo_iterator != NULL)
	{
		delete repo_iterator;
	}
	repo_iterator = new Iterator(temporary_vector);

}

void Sql_Repository::repository_add(Tape* new_element_to_add)
{
	sqlite3* Database;
	int operation_succes;
	operation_succes = sqlite3_open(file_path.c_str(), &Database);
	if (operation_succes != 0)
	{
		delete new_element_to_add;
		throw Exceptions("Could not open database!");
	}
	std::stringstream sql_to_add_element_stream;
	sql_to_add_element_stream << "INSERT INTO Tapes(Title, Section, Date, Access_Count, Footage_Preview) VALUES('";
	sql_to_add_element_stream << new_element_to_add->get_title() << "', '" << new_element_to_add->get_section() << "', '" << date_to_string(new_element_to_add->get_date_of_creation());
	sql_to_add_element_stream << "', " << new_element_to_add->get_access_count() << ", '" << new_element_to_add->get_footage_preview() << "');";
	std::string sql_to_add_element = sql_to_add_element_stream.str();
	char* sql_error_message;
	operation_succes = sqlite3_exec(Database, sql_to_add_element.c_str(), NULL, 0, &sql_error_message);
	sqlite3_close(Database);
	delete new_element_to_add;
	if (operation_succes != SQLITE_OK)
		throw Exceptions((std::string("Could not add to database! ") + std::string(sql_error_message)).c_str());
}

void Sql_Repository::repository_delete(string title_to_delete)
{
	sqlite3* Database;
	int operation_succes;
	operation_succes = sqlite3_open(file_path.c_str(), &Database);
	if (operation_succes != 0)
	{

		throw Exceptions("Could not open database!");
	}
	std::stringstream sql_to_remove_element_stream;
	sql_to_remove_element_stream << "DELETE FROM Tapes where Title = '" ;
	sql_to_remove_element_stream << title_to_delete<<"';";
	std::string sql_to_remove_element = sql_to_remove_element_stream.str();
	char* sql_error_message;
	operation_succes = sqlite3_exec(Database, sql_to_remove_element.c_str(), NULL, 0, &sql_error_message);
	sqlite3_close(Database);

	if (operation_succes != SQLITE_OK)
		throw Exceptions((std::string("Could not add to database! ") + std::string(sql_error_message)).c_str());
}
Tape* Sql_Repository::repository_search(string title_to_search)
{
	
	std::vector<Tape*> temporary_vector = file_into_vector();
	std::vector<Tape*>::iterator it = std::find_if(temporary_vector.begin(), temporary_vector.end(), [&title_to_search](Tape* element)// find_if return an iterator to element we get him in it
		{
			if (element->get_title() == title_to_search)
				return 1;
			else
				return 0;
		});
	if (it == temporary_vector.end())
		return NULL;
	else
		return new Tape(*it);// *it( it's like it.get_current()
	
}
void Sql_Repository::repository_update(string title_to_update, string update_section, Date update_date_of_creation, int update_access_count, string update_footage_preview)
{
	sqlite3* Database;
	int operation_succes;
	operation_succes = sqlite3_open(file_path.c_str(), &Database);
	if (operation_succes != 0)
	{
		
		throw Exceptions("Could not open database!");
	}
	std::stringstream sql_to_update_element_stream;
	sql_to_update_element_stream << "UPDATE Tapes SET Section = '"<< update_section<<"', Date='"<<date_to_string(update_date_of_creation)<<"', Access_Count="<<update_access_count<<", Footage_Preview='"<<update_footage_preview<<"' WHERE Title= '"<<title_to_update<<"';";
	std::string sql_to_add_element = sql_to_update_element_stream.str();
	char* sql_error_message;
	operation_succes = sqlite3_exec(Database, sql_to_add_element.c_str(), NULL, 0, &sql_error_message);
	sqlite3_close(Database);
	
	if (operation_succes != SQLITE_OK)
		throw Exceptions((std::string("Could not add to database! ") + std::string(sql_error_message)).c_str());

}
std::vector<Tape*> Sql_Repository::get_array_for_listing()
{
	return file_into_vector();
}

void Sql_Repository::next_tape()
{
	repo_iterator->next();
}

Tape* Sql_Repository::current_tape()
{
	return repo_iterator->current_element();
}

//void Sql_Repository::repository_add_mylist(Tape* new_element_to_add_into_my_list)
//{
//
//	this->my_list.push_back(new_element_to_add_into_my_list);
//
//}
//
//std::vector<Tape*> Sql_Repository::get_my_list_for_listing()
//{
//	std::vector<Tape*> new_print_array;
//	std::for_each(this->my_list.begin(), this->my_list.end(), [&new_print_array](Tape* element)
//		{
//			Tape* copy_of_element = new Tape(element);
//			new_print_array.push_back(copy_of_element);
//		});
//	return new_print_array;
//}

std::vector<Tape*>Sql_Repository::list_section_access_count(string section, int access_count)
{
	std::vector<Tape*> new_print_array;
	std::vector<Tape*> temporary_vector = file_into_vector();
	std::for_each(temporary_vector.begin(), temporary_vector.end(), [&new_print_array, &section, &access_count](Tape* element)
		{
			if (element->get_section() == section && element->get_access_count() < access_count)
			{
				Tape* copy_of_element = new Tape(element);
				new_print_array.push_back(copy_of_element);
			}
		});
	return new_print_array;

}

std::vector<Tape*> Sql_Repository::file_into_vector()
{
	sqlite3* Database;
	int operation_succes;
	std::vector<Tape*> temporary_storage;
	Tape* stored_element;
	//
	operation_succes = sqlite3_open(file_path.c_str(), &Database);
	if (operation_succes != 0)
		throw Exceptions("Could not open database!");
	//
	std::string sql_to_get_elements = "SELECT * FROM Tapes";
	char* sql_error_message;
	//
	auto function = [](void* void_temporary_storage, int column_nr, char** rows, char** columns) {
		const int title_index = 0, section_index = 1,  date_of_creation_index= 2, access_count_index = 3, footage_pewview_index = 4;
		std::vector<Tape*>* TemporaryStorage = (std::vector<Tape*>*) void_temporary_storage;//transformation from void* to vector( it is c not c++) FOR ME 
		Tape* StoredElement = new Tape(std::string(rows[title_index]), std::string(rows[section_index]), string_to_date(std::string(rows[date_of_creation_index])), std::stoi(std::string(rows[access_count_index])), std::string(rows[footage_pewview_index]));
		TemporaryStorage->push_back(StoredElement);
		return 0;
	};
	operation_succes = sqlite3_exec(Database, sql_to_get_elements.c_str(), function, &temporary_storage, &sql_error_message);// returning query
	//
	sqlite3_close(Database);
	if (operation_succes != SQLITE_OK)
		throw Exceptions((std::string("Could not retrieve data!") + std::string(sql_error_message)).c_str());
	//
	return temporary_storage;
}
