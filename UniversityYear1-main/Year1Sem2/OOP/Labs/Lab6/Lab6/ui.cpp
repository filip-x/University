#include "service.h"
#include <string>
#include <sstream>
#include <iostream>
#include "exceptions.h"
#include "Tests.h"
using namespace std;
class Ui
{
public:
	Ui();
	~Ui();
	void start();	
	int validation_int(string word_of_command);
	int convert_into_int(string string_to_convert);
	void delete_the_coma(string& title_command, string& section_command, string& date_of_creation_command, string& access_count_command, string& footage_preview_command);
private:
	Service* service;
};

Ui::Ui()
{
	service = new Service();
}
Ui::~Ui()
{
	delete service;
}
void Ui::start()
{
	char string_command[1000];
	string words_from_command;
	string current_mode="";
	while (true)
	{
		try
		{
			cout << "Write a command:";
			cin.getline(string_command, 1000);
			stringstream reader;
			reader << string_command;//from keyboard to reader
			//reader >> string_command;// the first word taken
			reader >> words_from_command;//first word into words_from_command
			if (words_from_command == "mode")
			{
				reader >> words_from_command;
				if (words_from_command == "A")
				{
					current_mode = "mode A";
				}
				else if (words_from_command == "B")
				{
					current_mode = "mode B";
				}
			}
			else if (words_from_command == "add" && (current_mode == "mode A"))// ADD
			{
				string title_command;
				string section_command;
				string date_of_creation_command;
				string access_count_command;//to convert into int 
				string footage_preview_command;
				int number_access_count = 0;

				reader >> title_command >> section_command >> date_of_creation_command >> access_count_command >> footage_preview_command;
				if (title_command == "" || section_command == "" || date_of_creation_command == "" || access_count_command == "" || footage_preview_command == "")
					throw Exceptions("Empty Command");
				else
				{
					delete_the_coma(title_command, section_command, date_of_creation_command, access_count_command, footage_preview_command);
					if (validation_int(access_count_command) == 0)
						throw Exceptions("Access count is not a number!!!");
					number_access_count = convert_into_int(access_count_command);
					service->append_function(title_command, section_command, date_of_creation_command, number_access_count, footage_preview_command);
				}
			}
			else if (words_from_command == "update" && (current_mode == "mode A"))//UPDATE
			{
				string title_command;
				string section_command;
				string date_of_creation_command;
				string access_count_command;//to convert into int 
				string footage_preview_command;
				int number_access_count;

				reader >> title_command >> section_command >> date_of_creation_command >> access_count_command >> footage_preview_command;
				if (title_command == "" || section_command == "" || date_of_creation_command == "" || access_count_command == "" || footage_preview_command == "")
					throw Exceptions("Empty Command");
				else
				{
					delete_the_coma(title_command, section_command, date_of_creation_command, access_count_command, footage_preview_command);
					if (validation_int(access_count_command) == 0)
						throw Exceptions("Access count is not a number!!!");
					number_access_count = convert_into_int(access_count_command);
					service->update_function(title_command, section_command, date_of_creation_command, number_access_count, footage_preview_command);
				}
			}
			else if (words_from_command == "delete" && (current_mode == "mode A"))// DELETE
			{
				string title_command;
				reader >> title_command;
				if (title_command == "")
					throw Exceptions("No title");
				else
				{
					if (title_command.back() == ',')
					{
						title_command.pop_back();//deletes the last letter
					}
					service->delete_function(title_command);
				}
			}
			else if (words_from_command == "exit")
			{
				break;
			}
			else if (words_from_command == "list" && (current_mode == "mode A"))
			{
				Dynamic_array* print_list = service->list_function();

				for (int i = 0; i < print_list->get_count(); i++)
				{
					cout << "Title: " << (*print_list)[i]->get_title() << " Section: " << (*print_list)[i]->get_section() << " Date of creation: " << (*print_list)[i]->get_date_of_creation() << " Access count: " << (*print_list)[i]->get_access_count() << " Footage preview: " << (*print_list)[i]->get_footage_preview() << "\n";
				}
				delete print_list;
			}
			else
			{
				throw Exceptions("You need to type a mode first.");
			}
		}
		catch (Exceptions ex) 
		{
			cout << ex.what();// it prints the message 
		}
		
	}
}

int Ui::validation_int(string word_from_command)
{
	int length = word_from_command.length();
	for (int i = 0; i < length; i++)
	{
		if (word_from_command[i]<'0' && word_from_command[i]>'9')
		{
			return 0;
		}
	}
	return 1;
}

int Ui::convert_into_int(string string_to_convert)
{
	int length = string_to_convert.length();
	int number = 0;
	for (int i = 0; i < length; i++)
	{
		number = number * 10 + string_to_convert[i] - '0';
	}

	return number;
}

void Ui::delete_the_coma(string& title_command, string& section_command, string& date_of_creation_command, string& access_count_command, string& footage_preview_command)
{
	
	if (title_command.back() == ',')
	{
		title_command.pop_back();//deletes the last letter
	}
	if (section_command.back() == ',')
	{
		section_command.pop_back();//deletes the last letter
	}
	if (date_of_creation_command.back() == ',')
	{
		date_of_creation_command.pop_back();//deletes the last letter
	}
	if (access_count_command.back() == ',')
	{
		access_count_command.pop_back();//deletes the last letter
	}
	if (footage_preview_command.back() == ',')
	{
		footage_preview_command.pop_back();//deletes the last letter
	}
}








int main()// the last 
{
	run_tests();
	Ui* user_interface = new Ui;

	user_interface->start();

	delete user_interface;

	return 0;
}