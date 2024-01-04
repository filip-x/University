#pragma once
#include<string>

class Department
{
public:
	virtual bool is_eficient()=0;
	virtual std::string to_string()=0;
	std::string type;
protected:
	std::string hospital_name;
	int nr_of_doctors;
	
};

