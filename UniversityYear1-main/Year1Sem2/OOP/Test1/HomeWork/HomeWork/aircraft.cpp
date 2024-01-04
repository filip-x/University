#include "aircraft.h"

int Aircraft::get_id()
{
    return this->id;
}

std::string Aircraft::get_model()
{
    return this->model;
}

vector<std::string> Aircraft::get_activity()
{
     return this->activity;
}

std::string Aircraft::get_max_altitude()
{
    return this->max_altitude;
}