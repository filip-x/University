#pragma once
#include "repository.h"
#include "Domain.h"
#include "Definitions.h"
#include "AppException.h"
#include <vector>
#include <string>

class service
{
private:
	repo_car& repository;
	static std::vector<std::string> SplitString(std::string, std::string);
public:
	service(repo_car & = repo_car());
	~service();
	void add(std::string, std::string, int, std::string);
	void remove(std::string);
	void update(std::string, std::string, int, std::string);
	std::vector<car> list();
	void ReadFile(std::string);
	int nr_of_cars(std::string);
};