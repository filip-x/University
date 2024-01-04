#pragma once
#include "Definitions.h"
#include <string>
class car
{
private:
	std::string manufacture;
	std::string model;
	int year;
	std::string color;
public:
	car(std::string, std::string, int, std::string);
	~car();
	// Getters
	std::string getter_manufacture() const;
	std::string getter_model() const;
	int getter_year() const;
	std::string getter_color() const;
	bool operator==(car) const;
	// Setters
	void setter_manufacture(std::string);
	void setter_model(std::string);
	void setter_year(int);
	void setter_color(std::string);
};