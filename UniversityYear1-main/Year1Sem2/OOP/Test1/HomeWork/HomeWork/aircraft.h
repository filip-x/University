#pragma once
#include <string>
#include<vector>
using namespace std;
class Aircraft
{
public:
	
	virtual int get_id();
	virtual std::string get_model();
	virtual vector<string> get_activity();
	virtual std::string get_max_altitude();

protected:
	int id;
	std::string model;
	vector<string> activity;
	std::string max_altitude;

};

