#pragma once
#include "aircraft.h"
class Repo
{
public:
	Repo();
	~Repo();
	void add_aircraft(Aircraft to_add_element);
	vector<Aircraft>* list_of_aircrafts();
private:
	vector<Aircraft>* storage;
};