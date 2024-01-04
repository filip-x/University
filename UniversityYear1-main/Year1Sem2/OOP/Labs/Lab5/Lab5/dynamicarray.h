#pragma once

typedef struct {

	int count;
	void** list_of_elements;
	int maximum_elements;

}dynamic_array;

dynamic_array* create_array();
void resize(dynamic_array* dynamical_list_of_supplies);
void delete_an_array(dynamic_array* dynamical_list_of_supplies, void (*element_destructor)(void*));
dynamic_array* copy(dynamic_array* list_of_elements, void* (*copy_element)(void*));
