#include<iostream>
#include"service.h"
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int validation_int(string word_from_command)
{
	int length = word_from_command.length();
	for (int i = 0; i < length; i++)
	{
		if (word_from_command.c_str()[i] < '0' || word_from_command.c_str()[i]>'9')
		{
			return 0;
		}
	}
	return 1;
}
class UI
{
public:
	UI();
	~UI();
	void commands();
	void start();
private: 
	Service* service;
};

UI::UI()
{
	this->service = new Service();
}

UI::~UI()
{
	delete service;
}


void UI::commands()
{
	char string_stream[1000];
	string words_from_command;
	while (true)
	{
		cout << "Write a command:";
		cin.getline(string_stream, 1000);
		stringstream reader;
		reader << string_stream;
		reader >> words_from_command;
		if (words_from_command == "add")
		{
			int id_int;
			string type;
			string private_aircraft;
			string  id_command;
			string model_command;
			vector<string> activity_command_vector;
			string activity;
			string max_altitude_command;
			reader >>type>>id_command >> model_command >> activity >> max_altitude_command;
			activity_command_vector.push_back(activity);
			id_int = stoi(id_command);
			if (type == "Helicopter")
			{
				reader >> private_aircraft;
				int int_private = stoi(private_aircraft);
				service->append_function(type, id_int, model_command, activity_command_vector, max_altitude_command,int_private);
			}
			else if(type == "Plane")
			{
				reader >> private_aircraft;
				int int_private = stoi(private_aircraft);
				service->append_function(type, id_int, model_command, activity_command_vector, max_altitude_command, int_private);
			}
			else if(type == "Balloon")
			{
				reader >> private_aircraft;
				int int_private = stoi(private_aircraft);
				service->append_function(type, id_int, model_command, activity_command_vector, max_altitude_command, int_private);
			}
			
		}
		else if (words_from_command == "list")
		{

			vector<string> activity_command_vector;
			string activity;
			reader >> activity;
			activity_command_vector.push_back(activity);
			if (validation_int(activity) == 0)
			{

				std::vector<Aircraft>* print_list = service->list_function();
				for (Aircraft i : *print_list)
				{
					if (i.get_activity()[0] == activity)
						cout << "id: " << i.get_id() << " Model: " << i.get_model() << " Activity: " << i.get_activity()[0] << " Max_att: " << i.get_max_altitude()<<"\n";
				}
				
			}
			else if(validation_int(activity)==1)
			{
				std::vector<Aircraft>* print_list = service->list_function();
				for (Aircraft i : *print_list)
				{
					if (i.get_max_altitude() >= activity)
						cout << "id: " << i.get_id() << " Model: " << i.get_model() << " Activity: " << i.get_activity()[0] << " Max_att: " << i.get_max_altitude()<<"\n";
				}
				
			}


		}
	}

}


void UI::start()
{
	commands();
}

int main()
{
	//tests();
	UI user_interface;
	user_interface.start();
}