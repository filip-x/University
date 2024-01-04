#pragma once
#include "repo.h"
#include "aircraft.h"
#include "plane.h"
#include "helicopter.h"
#include "hot_air_balloon.h"
class Service
{
public:
	void append_function(string type, int id, std::string model, vector<string> activity, std::string max_altitude, int extra);
	vector<Aircraft>* list_function();

private:
	Repo list_aircrafts;
};
