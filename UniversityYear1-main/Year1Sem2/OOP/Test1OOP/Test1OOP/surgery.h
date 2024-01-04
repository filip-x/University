#pragma once
#include "department.h"

class Surgery:public Department
{
public:
	Surgery(std::string hospital_name, int nr_of_doctors,int nr_of_patients);
	bool is_eficient() override;
	std::string to_string() override;

private:
	int number_of_patients;
};


