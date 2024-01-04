#include "repository.h"
#include <algorithm>
#include "AppException.h"
using namespace std;
void repo_car::repo_add(car vehicle)
{
	if ( ! (repo_search(vehicle.getter_manufacture()) == NULL_car))
		throw AppException("There already exists an element with that manufacture");
	cars.push_back(vehicle);
}

void repo_car::repo_remove(car vehicle)
{	
	auto NewEnd = remove(cars.begin(), cars.end(), vehicle);
	if (NewEnd == cars.end())
		throw AppException("The element doesn't exist!");
	cars.erase(NewEnd, cars.end());
}

void repo_car::repo_update(car old_vehicle, car new_vehicle)
{
	if (repo_search(old_vehicle.getter_manufacture()) == NULL_car)
		throw AppException("The element doesn't exist!");
	replace(cars.begin(), cars.end(), old_vehicle, new_vehicle);
}

vector<car> repo_car::repo_list()
{
	return cars;
}

car repo_car::repo_search(std::string manufacture)
{
	for (auto vehicle : cars)
		if (vehicle.getter_manufacture() == manufacture)
			return vehicle;
	return NULL_car;
}
