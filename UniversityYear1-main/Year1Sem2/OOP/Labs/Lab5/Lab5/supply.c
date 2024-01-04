#include "supply.h"
#include<stdlib.h>
#include<string.h>


// p->location_code <=> (*p).location_code;
// accessing the location_code property of the p structure variable
// Here we have the getters and the setters
supply* create_supply(int new_location_code, char* new_store_type, char *new_supply_type, int new_store_lock_complexity)
{
	
	
	supply* new_supply_created = malloc(sizeof(supply));
	new_supply_created->location_code = new_location_code;
	strcpy(new_supply_created->store_type, new_store_type);
	strcpy(new_supply_created->supply_type, new_supply_type);
	new_supply_created->store_lock_complexity = new_store_lock_complexity;

	return new_supply_created;
}

void setter_location(supply* existing_supply, int new_location_code)
{
	existing_supply->location_code = new_location_code;

}

void setter_store_type(supply* existing_supply, char* new_store_type)
{
	strcpy(existing_supply->store_type, new_store_type);
}

void setter_supply_type(supply* existing_supply, char *new_supply_type)
{
	strcpy(existing_supply->supply_type, new_supply_type);
}

void setter_store_lock_complexity(supply* existing_supply, int new_store_lock_complexity)
{
	existing_supply->store_lock_complexity = new_store_lock_complexity;
}
// Setters 
int  getter_location(supply* existing_supply)
{
	return existing_supply->location_code;
}

void getter_store_type(supply* existing_supply,char *return_value)
{
	strcpy(return_value, existing_supply->store_type);

}

void getter_supply_type(supply* existing_supply, char *return_value)
{
	strcpy(return_value, existing_supply->supply_type);
}

int getter_store_lock_complexity(supply* existing_supply)
{
	return existing_supply->store_lock_complexity;
}
// Getters

supply* copy_supply(supply* existing_supply)
{
	return create_supply(existing_supply->location_code, existing_supply->store_type, existing_supply->supply_type, existing_supply->store_lock_complexity);
}
void delete_supply_space(supply* existing_supply)
{
	free(existing_supply);
}


