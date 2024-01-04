#include "service.h"
#include <fstream>
using namespace std;

#define FILE_DELIMITER " | "

service::service(repo_car& repository) : repository(repository)
{
	// nothing yet
}

service::~service()
{
	// nothing yet
}

void service::add(std::string manufacture, std::string model, int year, std::string color)
{
	car vehicle(manufacture, model, year, color);
	repository.repo_add(vehicle);
}

void service::remove(std::string manufacture)
{
	car vehicle = repository.repo_search(manufacture);
	repository.repo_remove(vehicle);
}

void service::update(std::string manufacture, std::string new_model, int new_year, std::string new_color)
{
	car old_vehicle = repository.repo_search(manufacture);
	car new_vehicle = car(manufacture, new_model,new_year, new_color);
	repository.repo_update(old_vehicle, new_vehicle);
}

vector<car> service::list()
{
	return repository.repo_list();
}

void service::ReadFile(string PathToFile)
{
	ifstream File(PathToFile);
	string Line;
	while (getline(File, Line))
	{
		auto SplitList = service::SplitString(Line, FILE_DELIMITER);
		const int manufacture_index = 0, model_index = 1, year_index = 2, color_index = 3;
		std::string manufacture = SplitList[manufacture_index];
		std::string model = SplitList[model_index];
		int year = stoi(SplitList[year_index]);
		std::string color = SplitList[color_index];
		this->add(manufacture, model, year, color);
	}
}

int service::nr_of_cars(std::string manufacture)
{
	// Number of cars function
	// we iterate through the list of cars
	// and count all the cars that have the same 
	int count = 0;
	auto Data = list();
	for (auto vehicle : Data)
	{
		if (vehicle.getter_manufacture() == manufacture)
			count++;
	}
	return count;
}

vector<string> service::SplitString(string SomeString, string Delimiter)
{
	size_t StartPosition = 0, StopPosition;
	vector<string> Pieces;
	while ((StopPosition = SomeString.find(Delimiter, StartPosition + 1)) != string::npos)
	{
		Pieces.push_back(SomeString.substr(StartPosition, StopPosition - StartPosition));
		StartPosition = StopPosition + Delimiter.size();
	}
	if (StartPosition < SomeString.size())
		Pieces.push_back(SomeString.substr(StartPosition));
	return Pieces;
}
