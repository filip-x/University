#pragma once
#include "Definitions.h"
#include "Domain.h"
#include <vector>

#define NULL_car car("","",0,"")

class repo_car
{
private:
	std::vector<car> cars;
public:
	void repo_add(car);
	void repo_remove(car);
	void repo_update(car, car);
	car repo_search(std::string);
	std::vector<car> repo_list();
};