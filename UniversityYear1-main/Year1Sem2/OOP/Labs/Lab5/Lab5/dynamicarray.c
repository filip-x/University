#include"dynamicarray.h"

#include <stdlib.h>

dynamic_array* create_array()
{
	//the initial allocation
	dynamic_array* dynamical_list_of_supplies = malloc(sizeof(dynamic_array));
	dynamical_list_of_supplies->maximum_elements = 100;
	dynamical_list_of_supplies->list_of_elements = malloc(sizeof(void*)* dynamical_list_of_supplies->maximum_elements);
	dynamical_list_of_supplies->count = 0;
	return dynamical_list_of_supplies;
}

void resize(dynamic_array* dynamical_list_of_supplies)// if it's maximim = count not here 
{
	// we reallocate
	int i;
	void** copy_of_list = malloc(sizeof(void*) * dynamical_list_of_supplies->maximum_elements*2);
	for (i = 0; i < dynamical_list_of_supplies->count; i++)
	{
		copy_of_list[i] = dynamical_list_of_supplies->list_of_elements[i];

	}
	free(dynamical_list_of_supplies->list_of_elements);
	dynamical_list_of_supplies->list_of_elements = copy_of_list;
	dynamical_list_of_supplies->maximum_elements = dynamical_list_of_supplies->maximum_elements * 2;
}

void delete_an_array(dynamic_array* dynamical_list_of_supplies,void (*element_destructor)(void*))// at the end of the program we need to delete all the memory that se used
{// deallocate
	int i;
	for (i = 0; i < dynamical_list_of_supplies->count; i++)// every element free
		element_destructor(dynamical_list_of_supplies->list_of_elements[i]);
	free(dynamical_list_of_supplies->list_of_elements);// list array free
	free(dynamical_list_of_supplies);
}

dynamic_array* copy(dynamic_array* list_of_elements, void* (*copy_element)(void*))
{// undo-redo(copy of an array)
	int i;
	dynamic_array* copy_list= create_array();
	while (copy_list->maximum_elements != list_of_elements->maximum_elements)
	{
		resize(copy_list);
	}
	for (i = 0; i < list_of_elements->count; i++)
		copy_list->list_of_elements[i] = copy_element(list_of_elements->list_of_elements[i]);
	copy_list->count = list_of_elements->count;
	return copy_list;
}
