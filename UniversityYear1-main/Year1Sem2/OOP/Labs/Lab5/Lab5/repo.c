#include "repo.h"
#include<string.h>
#include<stdlib.h>




 repository_of_supplies* create_element()
 {
	

	repository_of_supplies* supplies= malloc(sizeof(repository_of_supplies));// we create only one 
	supplies->storage = create_array();
	return supplies;
 }

 supply* search_of_the_list(repository_of_supplies* repo_supplies,int location_code_search)// we have a function supply because we return a element of the list that is of type supplies
 {
	 int i;
	 // initialisation in the declaration ( if the list has not the location_code that we desire)
	 for(i=0;i<repo_supplies->storage->count;i++)
	 { 
		 if (((supply*)(repo_supplies->storage->list_of_elements[i]))->location_code == location_code_search)
			 return repo_supplies->storage->list_of_elements[i];
	 }
	 return NULL;
 }

 void append_function(repository_of_supplies* repo_supplies, supply* appending_element)
 {
	 int first_empty_position =repo_supplies->storage->count;//este ultimul element deja
	 repo_supplies->storage->list_of_elements[first_empty_position] = appending_element;
	 repo_supplies->storage->count ++;
	 

 }


 void remove_function(repository_of_supplies* repo_supplies, int location_code_remove)
 {
	 int i;
	 int j;
	 for (i = 0; i < repo_supplies->storage->count; i++)
	 {
		 if (((supply*)(repo_supplies->storage->list_of_elements[i]))->location_code == location_code_remove)
		 {
			 for (j = i + 1; j < repo_supplies->storage->count; j++)
				 repo_supplies->storage->list_of_elements[j - 1] = repo_supplies->storage->list_of_elements[j];
			 break;
		 }
	 }
	 repo_supplies->storage->count--;

 }


 void update_of_the_list(repository_of_supplies* repo_supplies, int location_code_search, supply* information_update)// we have a function supply because we return a element of the list that is of type supplies
 {
	 int i;
	 for (i = 0; i < repo_supplies->storage->count; i++)
	 {
		 if (((supply*)(repo_supplies->storage->list_of_elements[i]))->location_code == location_code_search)
		 {
			 ((supply*)(repo_supplies->storage->list_of_elements[i]))->store_lock_complexity = information_update->store_lock_complexity;
			 strcpy(((supply*)(repo_supplies->storage->list_of_elements[i]))->store_type, information_update->store_type);
			 strcpy(((supply*)(repo_supplies->storage->list_of_elements[i]))->supply_type, information_update->supply_type);
		 }
	 }
 }
 // when I print I will need to know the count of the supplies  
 int getter_count_of_supplies(repository_of_supplies* repo_supplies)
 {
	 return repo_supplies->storage->count;
 }
 // when I print I will need to know the list of the supplies 
 supply* getter_list_of_supplies(repository_of_supplies* repo_supplies)
 {
	 return repo_supplies->storage->list_of_elements;
 }

 void delete_repo(repository_of_supplies* repository)
 {
	 delete_an_array(repository->storage, delete_supply_space);
	 free(repository);

 }