#pragma once
#include "aircraft.h"
using namespace std;
class Hot_air_balloon : public Aircraft
{
public:
	Hot_air_balloon(int id, std::string model, vector<string> activity, std::string max_altitude,int weight_limit);
	int get_weight_limit();
	
private:
	int weight_limit;
};




