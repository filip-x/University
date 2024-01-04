#pragma once 
#include "my_list_repo.h"
#include "tape.h"
#include <vector>
class My_list_html :public Repo_my_list
{
public:
	My_list_html(string path_to_file);
	void saving_my_list(Tape* new_element_to_add) override;
	vector<Tape*> display_my_list() override;
	string path_to_file;
	void open() override;

private:
	vector<Tape*> read_from_file();
	void write_into_file(vector<Tape*>);


};

