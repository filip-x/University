#include "service.h"
#include <vector>
using namespace std;

void Service::append_function(string type, int id, std::string model, vector<string> activity, std::string max_altitude,int extra)
{
	if (type == "Plane")
	{
		Plane new_element(id, model, activity, max_altitude,extra);
		this->list_aircrafts.add_aircraft(new_element);
	}
	else if (type == "Helicopter")
	{
		Helicopter new_element(id, model, activity, max_altitude,extra);
		this->list_aircrafts.add_aircraft(new_element);
	}
	else if(type == "Balloon")
	{
		Hot_air_balloon new_element(id, model, activity, max_altitude,extra);
		this->list_aircrafts.add_aircraft(new_element);
	}

}

vector<Aircraft>* Service::list_function()
{
	return this->list_aircrafts.list_of_aircrafts();
}
