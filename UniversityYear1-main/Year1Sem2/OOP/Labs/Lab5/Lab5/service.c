#include "supply.h"
#include "repo.h"
#include"service.h"
#include <string.h>
#include <stdlib.h>



controller* create_service()
{
	controller* service = malloc(sizeof(controller));
	service->list = create_element();
	service->copy_redo = create_stack();
	service->copy_undo = create_stack();
	return service;
}
void adding_supplies(controller *service,int location_code_to_be_added,char *store_type_to_be_added,char *supply_type_to_be_added,int complexity_to_be_added)
{
	int i;
	supply* item_to_be_added = create_supply(location_code_to_be_added, store_type_to_be_added, supply_type_to_be_added, complexity_to_be_added);
	count_command(service);
	append_function(service->list, item_to_be_added);
}
void update_supply(controller* service, int location_code_to_update,char *store_type_update,char *supply_type_update,int complexity_update)
{
	supply* update_item = create_supply(location_code_to_update, store_type_update, supply_type_update, complexity_update);
	count_command(service);
	update_of_the_list(service->list, location_code_to_update, update_item);

}
void delete_supply(controller* service, int location_code_to_delete)
{
	count_command(service);
	remove_function(service->list,location_code_to_delete);
}

supply* list_of_supplies(controller* service, int* counter)
{
	*counter = getter_count_of_supplies(service->list);
	supply* list = getter_list_of_supplies(service->list);
	return list;
}

int verification_existence_of_supply(controller* service, int location_code_to_search)
{
	if(search_of_the_list(service->list, location_code_to_search)== NULL)
		return 0;
	else
		return 1;
}

void sorting_function(supply** list_to_sort, int count, int (*compare_function)(supply*, supply*))
{
	supply* auxiliary;
	int i, j;
	for (i = 0; i < count - 1; i++)
		for(j = i; j < count; j++)
			if (compare_function(list_to_sort[i], list_to_sort[j]) == 0)
			{
				auxiliary = list_to_sort[i];
				list_to_sort[i] = list_to_sort[j];
				list_to_sort[j] = auxiliary;
			}
}

supply** list_of_filter(controller* service, int* count, int (*filter_function)(void*, void*), void* passing_param)// we return a list of supplys given by user input
{
	int i;
	int j = 0;
	supply** list_for_filtering=malloc(sizeof(supply*)* service->list->storage->maximum_elements);
	for (i = 0; i < service->list->storage->count; i++)
	{
		if (filter_function == NULL || filter_function(service->list->storage->list_of_elements[i],passing_param) == 1)
		{
			list_for_filtering[j++] = service->list->storage->list_of_elements[i];
		}
	}
	*count = j;// valoare de la adresa din count
	return list_for_filtering;
}

// Undo - Redo List of Lists
void count_command(controller *service)//save the current state
{
	dynamic_array* copy_list=copy(service->list->storage, copy_supply);//list=repo,storage=dyamic array
	add_in_the_stack(service->copy_undo, copy_list);
	clear(service->copy_redo);
}
int undo(controller* service)
{
	if (is_empty(service->copy_undo) == 1)
		return 0;
	dynamic_array* last=pop_out_of_the_stack(service->copy_undo); // previous action
	dynamic_array* copy_service= copy(service->list->storage, copy_supply); // actual action
	dynamic_array* copy_last = copy(last, copy_supply); // previous action copy
	add_in_the_stack(service->copy_redo, copy_service); // we add the actual action to the redo stack
	// Performing the undo itself...
	delete_an_array(service->list->storage, delete_supply_space);
	service->list->storage = copy_last;
	delete_an_array(last, delete_supply_space);
	return 1;
}

int redo(controller* service)
{
	if (is_empty(service->copy_redo) == 1)
		return 0;
	dynamic_array* last = pop_out_of_the_stack(service->copy_redo); // previous undoed action
	dynamic_array* copy_service = copy(service->list->storage, copy_supply); // actual action
	dynamic_array* copy_last = copy(last, copy_supply); // previous undoed action copy
	add_in_the_stack(service->copy_undo, copy_service); // we add the actual action to the undo stack
	// Performing the undo itself...
	delete_an_array(service->list->storage, delete_supply_space);
	service->list->storage = copy_last;
	delete_an_array(last, delete_supply_space);
	return 1;
}


typedef struct {
	char* command_type;
	supply* first_supply;
	supply* second_supply;
} operation;
// Undo - Redo  - List of operations
void second_implementation_count_command(controller* service, char* command_type, supply* some_supply, supply* another_supply)//save the current state
{
	operation* new_operation = malloc(sizeof(operation));
	strcpy(new_operation->command_type, command_type);
	new_operation->first_supply = some_supply;
	new_operation->second_supply = another_supply;
	add_in_the_stack(service->copy_undo, copy_list);
	clear(service->copy_redo);
}

int second_implementation_undo(controller* service)
{

}
int second_implementation_redo(controller* service)
{

}




void delete_service(controller* service)
{
	delete_repo(service->list);
	delete_an_stack(service->copy_redo);
	delete_an_stack(service->copy_undo);
	free(service);
}