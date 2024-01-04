#include"plane.h"

Plane::Plane(int id, std::string model, vector<string> activity, std::string max_altitude,int it_is_private)
{
	this->id = id;
	this->model = model;
	this->activity = activity;
	this->max_altitude = max_altitude;
	this->is_private = it_is_private;
}

int Plane::get_is_private()
{
	return this->is_private;
}

string Plane::get_main_wings()
{
	return this->wings;
}
