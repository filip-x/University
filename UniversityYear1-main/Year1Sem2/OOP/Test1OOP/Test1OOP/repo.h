#pragma once
#include <vector>
#include "department.h"
class Repository
{
public:
	~Repository();
	void add(Department*);
	const std::vector<Department*> get();
	void write_file(std::string);
	
private:
	std::vector<Department*> storage;
};


