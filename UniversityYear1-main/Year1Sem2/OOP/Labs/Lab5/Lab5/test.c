#include "test.h"
#include "supply.h"
#include "service.h"
#include "repo.h"
#include "assert.h"
#include "string.h"

void CreateSupply_ValidInput_PositiveResponse()
{
	supply* new_supply = create_supply(1, "comsa", "filip", 2);
	assert(new_supply->location_code == 1 && strcmp(new_supply->store_type, "comsa") == 0 && strcmp(new_supply->supply_type, "filip") == 0 && new_supply->store_lock_complexity == 2);
}

void CreateRepository_ValidInput_PositiveResponse()
{
	repository_of_supplies* supplies = create_element();
	assert(supplies->storage->count == 0);
}

void AddingSupply_ValidInput_PositiveResponse()
{
	controller* service = create_service();
	adding_supplies(service, 0, "comsa", "filip", 1);
	assert(search_of_the_list(service->list, 0) != NULL);
}

void AddingSupply_ValidInput_PositiveResponse2()
{
	controller* service = create_service();
	adding_supplies(service, 0, "comsa", "filip", 1);
	supply* new_supply = search_of_the_list(service->list, 0);
	assert(service->list->storage->count == 1 && strcmp(new_supply->store_type, "comsa") == 0 && strcmp(new_supply->supply_type, "filip") == 0 && new_supply->store_lock_complexity == 1);
}

void UpdateSupply_ValidInput_PositiveResponse()
{
	controller* service = create_service();
	adding_supplies(service, 0, "comsa", "filip", 1);
	update_supply(service, 0, "lala", "d", 2);
	supply* new_supply = search_of_the_list(service->list, 0);// saving the supply
	assert(service->list->storage->count == 1 && strcmp(new_supply->store_type, "lala") == 0 && strcmp(new_supply->supply_type, "d") == 0 && new_supply->store_lock_complexity == 2);
}

void DeleteSupply_ValidInput_PositiveResponse()
{
	controller* service = create_service();
	adding_supplies(service, 0, "comsa", "filip", 1);
	adding_supplies(service, 1, "lala", "d", 2);
	delete_supply(service, 0);
	assert(service->list->storage->count == 1 && search_of_the_list(service->list, 0) == NULL && search_of_the_list(service->list, 1) != NULL);
}

void Filter_ValidInput_PositiveResponse()
{
	controller* service = create_service();
	adding_supplies(service, 0, "comsa", "filip", 1);
	adding_supplies(service, 1, "lala", "d", 2);
	adding_supplies(service, 2, "e", "mere", 3);
	int list_filtered_count;
	supply** list_filtered = list_of_filter(service, &list_filtered_count, NULL, NULL);
	assert(list_filtered_count == 3);
}

void Undo_ValidInput_PositiveResponse()
{
	controller* service = create_service();
	adding_supplies(service, 0, "comsa", "filip", 1);
	adding_supplies(service, 1, "lala", "d", 2);
	undo(service);
	assert(service->list->storage->count == 1);
}

void Redo_ValidInput_PositiveResponse()
{
	controller* service = create_service();
	adding_supplies(service, 0, "comsa", "filip", 1);
	adding_supplies(service, 1, "lala", "d", 2);
	undo(service);
	redo(service);
	assert(service->list->storage->count == 2);
}

void run_all_tests()
{
	CreateSupply_ValidInput_PositiveResponse();
	CreateRepository_ValidInput_PositiveResponse();
	AddingSupply_ValidInput_PositiveResponse();
	AddingSupply_ValidInput_PositiveResponse2();
	UpdateSupply_ValidInput_PositiveResponse();
	DeleteSupply_ValidInput_PositiveResponse();
	Filter_ValidInput_PositiveResponse();
	Undo_ValidInput_PositiveResponse();
	Redo_ValidInput_PositiveResponse();
}