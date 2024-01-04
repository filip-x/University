#pragma once
#include "supply.h"
#include "dynamicarray.h"
typedef struct {
	dynamic_array* storage;
}repository_of_supplies;

repository_of_supplies* create_element();
supply* search_of_the_list(repository_of_supplies* repo_supplies,int locatio_code_search);
void append_function(repository_of_supplies* repo_supplies, supply* appending_element);
void remove_function(repository_of_supplies* repo_supplies, int location_code_remove);
void update_of_the_list(repository_of_supplies* repo_supplies, int location_code_search, supply* information_update);
int getter_count_of_supplies(repository_of_supplies* repo_supplies);
supply* getter_list_of_supplies(repository_of_supplies* repo_supplies);
supply* copy_supply(supply* existing_supply);
void delete_repo(repository_of_supplies* repository);


