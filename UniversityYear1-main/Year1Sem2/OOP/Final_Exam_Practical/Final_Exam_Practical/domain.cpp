#include "domain.h"
#include <sstream>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
Astronomer::Astronomer(string name ,string constelation)
{
    set_name(name);
    set_constelation(constelation);
    
}

Astronomer::Astronomer()
{
}

Astronomer::~Astronomer()
{
}

string Astronomer::get_name()
{
	return this->name;
}

string Astronomer::get_constelation()
{
	return this->constelation;
}



void Astronomer::set_name(string name)
{
	this->name= name;
}

void Astronomer::set_constelation(string constelation)
{
	this->constelation = constelation;
}

bool Astronomer::operator==(const Astronomer& T) const
{
    return this->name == T.name && this->constelation == T.constelation;
}

std::ostream& operator<<(std::ostream& output_stream, Astronomer& element)
{
    output_stream << element.get_name() << "," << element.get_constelation() << "\n";
    return output_stream;
}

std::istream& operator>>(std::istream& input_stream, Astronomer& element)
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
   

    return input_stream;
}
