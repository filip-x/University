#include<iostream>
#include"service.h"
#include <sstream>
#include <vector>
#include <algorithm>
#include "repo.h"
#include "surgery.h"
#include "neonatal_unit.h"
using namespace std;


class Ui
{
public:
	Ui();
	~Ui();
	void command();
private:
	Repository* repo;
};

Ui::Ui()
{
	repo = new Repository();
}

Ui::~Ui()
{
	delete repo;
}

void Ui::command()
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
			string hospital_name;
			string department_type;
			string nr_of_doc;
			char dep[1000];
			reader >> hospital_name;
			reader.getline(dep, 100, ',');
			reader >> nr_of_doc;
			hospital_name.pop_back();
			//department_type.pop_back();
			nr_of_doc.pop_back();
			department_type = dep;

			if (department_type == " surgery")
			{
				string nr_of_patients;
				reader >> nr_of_patients;
				nr_of_patients.pop_back();
				repo->add(new Surgery(hospital_name, stoi(nr_of_doc), stoi(nr_of_patients)));
			}
			else
			{
				string nr_of_mothers;
				string nr_of_babies;
				string avg;
				reader >> nr_of_mothers >> nr_of_babies >> avg;
				nr_of_mothers.pop_back();
				nr_of_babies.pop_back();
				avg.pop_back();
				repo->add(new Neonatal(hospital_name, stoi(nr_of_doc), stoi(nr_of_mothers), stoi(nr_of_babies), stod(avg)));
			}

		}
		else if (words_from_command == "list")
		{
			if (reader.peek() == -1)
			{
				auto depinfo = repo->get();
				for (auto elem : depinfo)
					cout << elem->to_string() << "\n";
			}
			else
			{
				auto depinfo = repo->get();
				for (auto elem : depinfo)
					if (elem->is_eficient() == true)
						cout << elem->to_string() << "\n";
			}
		}
		else if (words_from_command == "fileLocation")
		{
			string file_name;
			reader.ignore();
			reader >> file_name;
			repo->write_file(file_name);
		}

	}

}

int main()
{
	auto UI = new Ui;
	UI->command();
	delete UI;
	return 0;
}