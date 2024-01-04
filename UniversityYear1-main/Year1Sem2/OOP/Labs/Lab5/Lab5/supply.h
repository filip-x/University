#pragma once


typedef struct {


	int location_code;
	char store_type[50];
	char supply_type[50];
	int store_lock_complexity;

}supply;

supply* create_supply(int new_location_code, char *new_store_type, char *new_supply_type, int new_store_lock_complexity);

void setter_location(supply* existing_supply, int new_location_code);
void setter_store_type(supply* existing_supply, char *new_store_type);
void setter_supply_type(supply* existing_supply,char *new_supply_type);
void setter_store_lock_complexity(supply* existing_supply, int new_store_lock_complexity);
int  getter_location(supply* existing_supply);
void getter_store_type(supply* existing_supply,char *return_value);
void getter_supply_type(supply* existing_supply,char *return_value);
int  getter_store_lock_complexity(supply* existing_supply);
void delete_supply_space(supply* existing_supply);
supply* copy_supply(supply* existing_supply);









