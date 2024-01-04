#include "hot_air_balloon.h"

Hot_air_balloon::Hot_air_balloon(int id, std::string model, vector<string> activity, std::string max_altitude,int weight_limit)
{
	this->id = id;
	this->model = model;
	this->activity = activity;
	this->max_altitude = max_altitude;
	this->weight_limit = weight_limit;
}

int Hot_air_balloon::get_weight_limit()
{
	return this->weight_limit;
}
