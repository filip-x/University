#pragma once
#include"dynamic_array_undo_redo.h"
#include "dynamicarray.h"
#include <stdlib.h>

dynamic_stack* create_stack()
{
	// a stack = a list of dynamic arrays that only do push and pop
	dynamic_stack* dynamical_list_of_supplies = malloc(sizeof(dynamic_stack));
	dynamical_list_of_supplies->maximum_elements = 100;
	dynamical_list_of_supplies->list_of_elements = malloc(sizeof(void*) * dynamical_list_of_supplies->maximum_elements);
	dynamical_list_of_supplies->count = 0;
	return dynamical_list_of_supplies;
}

void resize_stack(dynamic_stack* dynamical_list_of_supplies)// if it's maximim = count not here 
{
	int i;
	void** copy_of_list = malloc(sizeof(void*) * dynamical_list_of_supplies->maximum_elements * 2);
	for (i = 0; i < dynamical_list_of_supplies->count; i++)
	{
		copy_of_list[i] = dynamical_list_of_supplies->list_of_elements[i];

	}
	free(dynamical_list_of_supplies->list_of_elements);
	dynamical_list_of_supplies->list_of_elements = copy_of_list;
	dynamical_list_of_supplies->maximum_elements = dynamical_list_of_supplies->maximum_elements * 2;
}

void delete_an_stack(dynamic_stack* dynamical_list_of_supplies)// at the end of the program we need to delete all the memory that se used
{
	int i;
	clear(dynamical_list_of_supplies);//array delete
	free(dynamical_list_of_supplies->list_of_elements);// list array free
	free(dynamical_list_of_supplies);
}
void add_in_the_stack(dynamic_stack* stack ,void* command_remember)//or push 
{
	stack->list_of_elements[stack->count++] = command_remember;
	if (stack->count == stack->maximum_elements)
		resize_stack(stack);
}
void* pop_out_of_the_stack(dynamic_stack* stack)
{
	return stack->list_of_elements[--stack->count];
	
}
int is_empty(dynamic_stack* stack)
{
	if (stack->count == 0)
		return 1;
	else
		return 0;
}
void clear(dynamic_stack* stack)
{
	int i;
	for (i = 0; i < stack->count; i++)
	{
		delete_an_array(stack->list_of_elements[i], delete_supply_space);
	}
	stack->count = 0;

}
