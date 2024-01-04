#pragma once
#include "repository.h"
#include "repository2.h"
#include <string>
#include <vector>
#include <string>

class Service
{
public:
	Service();
	~Service();
	void add(std::string,std::string);
	void add2(std::string, std::string,int ,int ,int);
	void update(std::string,std::string);
	void update2(std::string, std::string,int,int,int);
	void remove(std::string);
	void remove2(std::string);
	std::vector<Astronomer> list();
	std::vector<Stars> list2();
	void read_file(std::string path);
	void read_file2(std::string path);
	void write_file(std::string path);
	void write_file2(std::string path);
	std::vector<Stars> search_stars(std::string name_to_find);
	

private:
	Repository1 service_repo1;
	Repository2 service_repo2;
};
