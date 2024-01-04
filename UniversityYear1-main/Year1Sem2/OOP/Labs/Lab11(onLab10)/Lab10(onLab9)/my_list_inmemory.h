#pragma once 
#include "my_list_repo.h"
#include "tape.h"
#include <vector>
class My_list_InMemory :public Repo_my_list
{
public:
	My_list_InMemory();
	void saving_my_list(Tape* new_element_to_add) override;
	vector<Tape*> display_my_list() override;
	void open() override {};


private:
	vector<Tape*> storage;
};

