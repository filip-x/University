#pragma once
#include "aircraft.h"
#include <vector>
using namespace std;
class Helicopter :public Aircraft
{
public:
	Helicopter(int id, std::string model, vector<string> activity, std::string max_altitude, int it_is_private);
	int get_is_private();
private:
	int is_private;
};

