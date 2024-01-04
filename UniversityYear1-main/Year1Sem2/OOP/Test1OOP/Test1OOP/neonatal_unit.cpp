#include "neonatal_unit.h"

Neonatal::Neonatal(std::string hospital_name, int nr_of_doctors, int nr_of_mothers, int nr_of_newborns, double average_grade)
{
	this->hospital_name = hospital_name;
	this->nr_of_doctors = nr_of_doctors;
	this->nr_of_mother = nr_of_mothers;
	this->nr_of_newborn = nr_of_newborns;
	this->average_grade = average_grade;
	type = "Neonatal Unit";
}

bool Neonatal::is_eficient()
{
	if (this->average_grade > 8.5 && this->nr_of_newborn >= this->nr_of_mother)
		return true;
	return false;
}

std::string Neonatal::to_string()
{
	std::string str = "";
	str += "Hospital Name: " + this->hospital_name + " | Nr of doctors:" + std::to_string(this->nr_of_doctors) + " Nr of mothers: " + std::to_string(this->nr_of_mother) + " Nr of Newborn: " + std::to_string(this->nr_of_newborn) + " Average Grade: " + std::to_string(this->average_grade);
	return str;
}
