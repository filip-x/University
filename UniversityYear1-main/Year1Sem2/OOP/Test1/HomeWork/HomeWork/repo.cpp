#pragma once
#include <vector>
#include "repo.h"


Repo::Repo()
{
	this->storage = new vector<Aircraft>;
}

Repo::~Repo()
{
	delete this->storage;
}

void Repo::add_aircraft(Aircraft to_add_element)
{
	this->storage->push_back(to_add_element);
}

vector<Aircraft>* Repo::list_of_aircrafts()
{
	return this->storage;
}
