#pragma once
#include<vector>
#include"tape.h"
class Repo_my_list
{
public:
	virtual void saving_my_list(Tape*) = 0;
	virtual vector<Tape*> display_my_list() = 0;
	virtual void open()=0;
private:

};

