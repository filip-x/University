#pragma once
#include "aircraft.h"
using namespace std;
class Plane : public Aircraft
{
public:
	Plane(int id, std::string model, vector<string> activity, std::string max_altitude,int it_is_private);
	int get_is_private();
	string get_main_wings();
private:
	int is_private;
	string wings;
};




