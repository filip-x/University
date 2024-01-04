#include "domain2.h"
#include <sstream>
#include<iostream>
#include<fstream>
#include <vector>
#include <string>

using namespace std;
Stars::Stars(string name,string constelation,int ra,int dec,int diameter)
{
    set_name(name);
    set_constelation(constelation);
    set_ra(ra);
    set_dec(dec);
    set_diameter(diameter);
}

Stars::Stars()
{
}

Stars::~Stars()
{
}

string Stars::get_name()
{
	return this->name;
}

string Stars::get_constelation()
{
	return this->constelation;
}

int Stars::get_ra()
{
	return this->ra;
}

int Stars::get_dec()
{
	return this->dec;
}
int Stars::get_diameter()
{
    return this->diameter;
}

void Stars::set_name(string name)
{
	this->name = name;
}

void Stars::set_constelation(string constelation)
{
	this->constelation= constelation;
}

void Stars::set_ra(int ra)
{
	this->ra = ra;
}

void Stars::set_dec(int dec)
{
	this->dec = dec;
}
void Stars::set_diameter(int diameter)
{
    this->diameter = diameter;
}

std::ostream& operator<<(std::ostream& output_stream, Stars& element)
{
    output_stream << element.get_name() << "," << element.get_constelation() << "," << element.get_ra() << "," << element.get_dec() <<element.get_diameter()<< "\n";
    return output_stream;
}

std::istream& operator>>(std::istream& input_stream, Stars& element)
{
    std::string line;
    std::string property;
    getline(input_stream, line);
    std::stringstream line_stream(line);
    std::vector<std::string> element_properties;
    while (getline(line_stream, property, ','))
        element_properties.push_back(property);
    if (element_properties.size() == 0)
        return input_stream;

    element.set_name(element_properties[0]);
    element.set_constelation(element_properties[1]);
    element.set_ra(std::stoi(element_properties[2]));
    element.set_dec(std::stoi(element_properties[3]));
    element.set_diameter(std::stoi(element_properties[4]));

    return input_stream;
}

bool Stars::operator==(const Stars& T) const
{
    return this->name == T.name && this->constelation == T.constelation &&
        this->ra == T.ra && this->dec == T.dec && this->diameter == T.diameter;
}