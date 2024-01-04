#pragma once
#include "department.h"
#include <string>
class Neonatal:public Department
{
public:
	Neonatal(std::string hospital_name, int nr_of_doctors, int nr_of_mothers,int nr_of_newborns,double average_grade);
	 bool is_eficient() override ;
	 std::string to_string()override;


private:
	int nr_of_mother;
	int nr_of_newborn;
	double average_grade;
};


