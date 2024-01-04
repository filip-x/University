#include "Domain.h"

car::car(std::string manufacture, std::string model, int year, std::string color):
	manufacture(manufacture), model(model), year(year), color(color)
{
	// still nothing
}

car::~car()
{
	// nothing for now
}

std::string car::getter_manufacture() const
{
	return manufacture;
}

std::string car::getter_model() const
{
	return model;
}

int car::getter_year() const
{
	return year;
}
std::string car::getter_color() const
{
	return color;
}

bool car::operator==(car AnotherElement) const
{
	if (this->getter_manufacture() == AnotherElement.getter_model() &&
		this->getter_model() == AnotherElement.getter_model() &&
		this->getter_year() == AnotherElement.getter_year() &&
		this->getter_color() == AnotherElement.getter_color())
		return true;
	return false;
}

void car::setter_manufacture(std::string new_manufacture)
{
	manufacture = new_manufacture;
}

void car::setter_model(std::string new_model)
{
	manufacture = new_model;
}

void car::setter_year(int new_year)
{
	manufacture = new_year;
}

void car::setter_color(std::string new_color)
{
	manufacture = new_color;
}
