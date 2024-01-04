#include"surgery.h"

Surgery::Surgery(std::string hospital_name, int nr_of_doctors, int nr_of_patients)
{
	this->hospital_name = hospital_name;
	this->nr_of_doctors = nr_of_doctors;
	this->number_of_patients = nr_of_patients;
	type = "Surgery";
	
}

bool Surgery::is_eficient()
{
	if((double) this->number_of_patients / this->nr_of_doctors >= 2)
		return true;
	return false;
}



std::string Surgery::to_string()
{
	std::string str = "";
	str += "Hospital Name: " + this->hospital_name + " | Nr of doctors:" + std::to_string(this->nr_of_doctors) + " | Nr of patients: " + std::to_string(this->number_of_patients);
	return str;
}