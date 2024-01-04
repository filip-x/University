#include "service.h"
#include <string>
#include <sstream>
#include <iostream>
#include "exceptions.h"
#include "Tests.h"
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
typedef tm Date;
class Ui
{
public:
	Ui();
	~Ui();
	void start();	
	int validation_int(string word_of_command);
	int validation_date(Date input_date);
	int convert_into_int(string string_to_convert);
	string date_to_string(Date date_to_display);
	void delete_the_coma(string& title_command, string& section_command, string& date_of_creation_command, string& access_count_command, string& footage_preview_command);
private:
	Service* service;
};

Ui::Ui()
{
	service = NULL;
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
			if (words_from_command == "mode" && service != NULL)
			{
				reader >> words_from_command;
				if (words_from_command == "A")
				{
					current_mode = "mode A";
				}
				else if (words_from_command == "B")
				{
					current_mode = "mode B";
					service->creating_the_iterator();
				}
			}
			else if ( words_from_command == "fileLocation")
			{
				reader.get();
				std::string path;
				getline(reader, path);
				File_Repository* repository_saver = new File_Repository(path);
				service = new Service(repository_saver);
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
					int day, year, month;
					int placeholder = sscanf(date_of_creation_command.c_str(), "%d-%d-%d", &month, &day, &year);
					Date date_of_creation;
					date_of_creation.tm_mon = month;
					date_of_creation.tm_mday = day;
					date_of_creation.tm_year = year;
					if (validation_date(date_of_creation) == 0)
						throw Exceptions("Date expired");
					number_access_count = convert_into_int(access_count_command);
					service->append_function(title_command, section_command, date_of_creation, number_access_count, footage_preview_command);
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
					int day, year, month;
					int placeholder = sscanf(date_of_creation_command.c_str(), "%d-%d-%d", &month, &day, &year);
					Date date_of_creation;
					date_of_creation.tm_mon = month;
					date_of_creation.tm_mday = day;
					date_of_creation.tm_year = year;
					if (validation_date(date_of_creation) == 0)
						throw Exceptions("Date expired");
					service->update_function(title_command, section_command, date_of_creation, number_access_count, footage_preview_command);
				}
			}
			else if (words_from_command == "delete" && (current_mode == "mode A"))// DELETE
			{
				string title_command;
				string access_count_command;
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
			else if (words_from_command == "list")
			{
				if(current_mode == "mode A")
				{

					std::vector<Tape*> print_list = service->list_function();

					std::for_each(print_list.begin(), print_list.end(), [&](Tape* element) 
						{
							cout << "Title: " << element->get_title() << " Section: " << element->get_section() << " Date of creation: " << date_to_string(element->get_date_of_creation())<< " Access count: " << element->get_access_count() << " Footage preview: " << element->get_footage_preview() << "\n";
						});
					for (auto element : print_list)
					{
						delete element;
					}
				}
				else if(current_mode == "mode B")// TO DO
				{

					string section_command;
					string access_count_command;
					reader >> section_command;
					reader >> access_count_command;
					int number_access_count;

					if (section_command == "" || access_count_command == "")
					{
						throw Exceptions("Empty command");
					}
					else
					{
						if (validation_int(access_count_command) == 0)
							throw Exceptions("Access count is not a number!!!");
						number_access_count = convert_into_int(access_count_command);
						if (section_command.back() == ',')
						{
							section_command.pop_back();//deletes the last letter
						}
						std::vector<Tape*> print_list = service->list_by_section_access(section_command,number_access_count);

						std::for_each(print_list.begin(), print_list.end(), [&](Tape* element)
							{
								cout << "Title: " << element->get_title() << " Section: " << element->get_section() << " Date of creation: " << date_to_string(element->get_date_of_creation()) << " Access count: " << element->get_access_count() << " Footage preview: " << element->get_footage_preview() << "\n";
							});
						for (auto element : print_list)
						{
							delete element;
						}
					}
					
				}
			}
			else if (words_from_command == "next" && (current_mode == "mode B"))
			{
				Tape* display_element = this->service->next_tape();
				cout << "Title: " << display_element->get_title() << " Section: " << display_element->get_section() << " Date of creation: " << date_to_string(display_element->get_date_of_creation()) << " Access count: " << display_element->get_access_count() << " Footage preview: " << display_element->get_footage_preview() << "\n";

			}
			else if (words_from_command == "save" && (current_mode == "mode B"))//TO DO
			{
				string title_command;
				reader >> title_command;
				if (title_command == "")
				{
					throw Exceptions("No title");

				}
				else
				{
					this->service->save_tape_by_title(title_command);
				}

			}
			else if (words_from_command == "mylist" && (current_mode == "mode B"))// to do 
			{

				std::vector<Tape*> print_list = service->list_my_list();

				std::for_each(print_list.begin(), print_list.end(), [&](Tape* element)
					{
						cout << "Title: " << element->get_title() << " Section: " << element->get_section() << " Date of creation: " << date_to_string(element->get_date_of_creation()) << " Access count: " << element->get_access_count() << " Footage preview: " << element->get_footage_preview() << "\n";
					});
				for (auto element : print_list)
				{
					delete element;
				}
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

int Ui::validation_date(Date input_date)
{
	if (input_date.tm_mon <= 0 || input_date.tm_mon > 12)
		return 0;
	int max_days[] = { 0, 31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31 };
	if (input_date.tm_year % 4 == 0)// an bisect
		max_days[2]++;
	if (input_date.tm_mday <= 0 || input_date.tm_mday > max_days[input_date.tm_mon])
		return 0;
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

string Ui::date_to_string(Date date_to_display)
{
	char string_date[100];
	sprintf(string_date, "%d-%d-%d", date_to_display.tm_mon, date_to_display.tm_mday, date_to_display.tm_year);
	return string(string_date);
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

	//user_interface->start();

	delete user_interface;

	return 0;
}