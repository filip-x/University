#pragma once
#include "supply.h"
typedef struct {

	int count;
	void** list_of_elements;
	int maximum_elements;

}dynamic_stack;

dynamic_stack* create_stack();
void resize_stack(dynamic_stack* dynamical_list_of_supplies);
void delete_an_stack(dynamic_stack* dynamical_list_of_supplies);
void add_in_the_stack(dynamic_stack* stack, void* command_remember);
void* pop_out_of_the_stack(dynamic_stack* stack);
int is_empty(dynamic_stack* stack);
void clear(dynamic_stack* stack);