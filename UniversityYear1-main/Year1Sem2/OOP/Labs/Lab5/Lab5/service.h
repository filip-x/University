#pragma once
#include"repo.h"
#include "dynamic_array_undo_redo.h"
typedef struct {

	repository_of_supplies* list;
	dynamic_stack* copy_undo;
	dynamic_stack* copy_redo;
}controller;

controller* create_service();
void adding_supplies(controller* service, int location_code_to_be_added, char *store_type_to_be_added, char *supply_type_to_be_added, int complexity_to_be_added);
void update_supply(controller* service, int location_code_to_update, char *store_type_update, char *supply_type_update, int complexity_update);
void delete_supply(controller* service, int location_code_to_delete);
supply* list_of_supplies(controller* service, int *counter);
int verification_existence_of_supply(controller* service, int location_code_to_search);
void delete_service(controller* service);
supply** list_of_filter(controller* service, int* count, int (*filter_function)(void*, void*), void* passing_param);
void sorting_function(supply** list_to_sort, int count, int (*compare_function)(supply*, supply*));
int undo(controller* service);
int redo(controller* service);
int second_implementation_undo(controller* service);
int second_implementation_redo(controller* service);
void count_command(controller* service);



