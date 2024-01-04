#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"test.h"
#include "supply.h"
#include "service.h"
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>

#include <crtdbg.h>
// this is the UI



// Print function
void print_on_screen(supply* element)
{
	char saving_the_store_type_to_display[256];
	char saving_the_supply_type_to_display[256];
	getter_supply_type(element, saving_the_supply_type_to_display);
	getter_store_type(element, saving_the_store_type_to_display);
	printf("Location Code: %d / Store Type: %s / Supply Type: %s / Complexity: %d \n", getter_location(element), saving_the_store_type_to_display, saving_the_supply_type_to_display, getter_store_lock_complexity(element));
}
// This was my first attempt(It is not good)
void print_of_the_menu()
{
	printf("List of commands you can use!!!");
	printf("\n1.Add\n");
	printf("2.Update\n");
	printf("3.Delete\n");
	printf("4.List\n");
	printf("5.List Supply type\n");
}

// Valdation of a string to be int 
int validation_if_string_is_int( char value[])
{
	int length_of_the_value = strlen(value)-1;
	int i;
	for (i = 0; i <= length_of_the_value; i++)
	{
		if (value[i] < '0' || value[i] > '9')
			return 0;
	
	}
	return 1;

}
// Validation of the command 
int syntactical_validation(char initial_command[100],char first_command_argument[100],char second_command_argument[100],char third_command_argument[100],char fourth_command_argument[100])
{
	if (strcmp(initial_command, "add") != 0 && strcmp(initial_command, "update") != 0 && strcmp(initial_command, "delete") != 0 && strcmp(initial_command,"list") && strcmp(initial_command, "undo") && strcmp(initial_command, "redo"))
		return 0;
	if (strcmp(initial_command, "list") == 0)
		return 1;
	if (strcmp(initial_command, "undo") == 0)
		return 1;
	if (strcmp(initial_command, "redo") == 0)
		return 1;
	if (strcmp(initial_command, "add") == 0)
	{
		char* location_code_string = first_command_argument;
		char* store_type_string = second_command_argument;
		char* supply_type_string = third_command_argument;
		char* complexity_code_string = fourth_command_argument;
		if (strlen(location_code_string) == 0 || strlen(store_type_string) == 0 || strlen(supply_type_string) == 0 || strlen(complexity_code_string) == 0)
			return 0;
		else
		{
			if (validation_if_string_is_int(location_code_string) == 1 && validation_if_string_is_int(complexity_code_string) == 1)
				return 1;
		}
				
	}
	if (strcmp(initial_command, "update") == 0)
	{
		char* location_code_string = first_command_argument;
		char* store_type_string = second_command_argument;
		char* supply_type_string = third_command_argument;
		char* complexity_code_string = fourth_command_argument;
		if (strlen(location_code_string) == 0 || strlen(store_type_string) == 0 || strlen(supply_type_string) == 0 || strlen(complexity_code_string) == 0)
			return 0;
		else
		{
			if (validation_if_string_is_int(location_code_string) == 1 && validation_if_string_is_int(complexity_code_string) == 1)
				return 1;
		}

	}
	if (strcmp(initial_command, "delete") == 0)
	{
		char* location_code_string = first_command_argument;
		if (strlen(location_code_string) == 0)
			return 0;
		else
		{
			if (validation_if_string_is_int(location_code_string) == 1)
				return 1;
		}
	}
}

// Command dissection 
void extracting_the_command_arguments(char saving_the_user_input[256],char initial_command[100],char first_command_argument[100],char second_command_argument[100],char third_command_argument[100],char fourth_command_argument[100])
{
	
	
	int counter_for_the_command = 0;
	char* command_word = strtok(saving_the_user_input, ", \n");
	while (command_word != NULL)
	{
		if (counter_for_the_command == 0)
			strcpy(initial_command, command_word);
		if (counter_for_the_command == 1)
			strcpy(first_command_argument, command_word);
		if (counter_for_the_command == 2)
			strcpy(second_command_argument, command_word);
		if (counter_for_the_command == 3)
			strcpy(third_command_argument, command_word);
		if (counter_for_the_command == 4)
			strcpy(fourth_command_argument, command_word);
		if (counter_for_the_command == 5)
			break;
			
		counter_for_the_command++;
		command_word = strtok(NULL, ", \n");
	}
	
}
// Change the string to int 
int string_into_int(char string[])
{
	int i;
	int int_number=0;
	int length = strlen(string);
	for (i = 0; i < length; i++)
	{
		int_number = 10 * int_number + string[i] - '0';
	}
	return int_number;
}

int maximum_store_lock_complexity_filter(supply* element_to_filter, int* maximum_store_lock_complexity)// ASSIGNMENT3 remake
{
	if (getter_store_lock_complexity(element_to_filter) <= *maximum_store_lock_complexity)
		return 1;
	else return 0;
}


int minimum_store_lock_complexity_filter(supply* element_to_filter, int* minimum_store_lock_complexity) // for the bonus
{
	if (getter_store_lock_complexity(element_to_filter) >= *minimum_store_lock_complexity)
		return 1;
	else return 0;
}

int supply_type_filter(supply* element_to_filter, char* supply_type)// ASSIGNMENT 3 remake
{
	char element_supply_type[20];
	getter_supply_type(element_to_filter, element_supply_type);
	if (strcmp(element_supply_type, supply_type) == 0)
		return 1;
	else return 0;
}

int store_type_compare_descending(supply* first_element_to_compare, supply* second_element_to_compare)// 4 a 
{
	char first_element_store_type[20];
	char second_element_store_type[20];
	getter_store_type(first_element_to_compare, first_element_store_type);
	getter_store_type(second_element_to_compare, second_element_store_type);
	if (strcmp(first_element_store_type, second_element_store_type) > 0)
		return 1;
	else return 0;
}

int store_type_compare_ascending(supply* first_element_to_compare, supply* second_element_to_compare)//4 d
{
	char first_element_store_type[20];
	char second_element_store_type[20];
	getter_store_type(first_element_to_compare, first_element_store_type);
	getter_store_type(second_element_to_compare, second_element_store_type);
	if (strcmp(first_element_store_type, second_element_store_type) < 0)
		return 1;
	else return 0;
}


// Core of the app 
void starting()
{
	controller* service = create_service();
	char saving_the_user_input[256];
	char initial_command[100];
	char first_command_argument[100] ="";
	char second_command_argument[100]="";
	char third_command_argument[100]="";
	char fourth_command_argument[100]="";

	do
	{
		first_command_argument[0] = '\0';
		second_command_argument[0] = '\0';
		third_command_argument[0] = '\0';
		fourth_command_argument[0] = '\0';

		printf("Write a command:\n");
		fgets(saving_the_user_input, 256, stdin);
		extracting_the_command_arguments(saving_the_user_input,initial_command, first_command_argument, second_command_argument, third_command_argument, fourth_command_argument);
		if (strcmp(initial_command, "exit") == 0)
		{
			break;
		}
		if (syntactical_validation(initial_command, first_command_argument, second_command_argument, third_command_argument, fourth_command_argument) == 0)
		{
			printf("The command is not good!");
			continue;
		}
		if (strcmp(initial_command, "add") == 0)
		{
			int location_code_int = 0;
			int complexity_code_int = 0;
			char* location_code_string = first_command_argument;
			char* store_type_string = second_command_argument;
			char* supply_type_string = third_command_argument;
			char* complexity_code_string = fourth_command_argument;
			location_code_int = string_into_int(location_code_string);
			complexity_code_int = string_into_int(complexity_code_string);
			if (verification_existence_of_supply(service, location_code_int) == 1)
			{
				printf("No!");
				continue;
			}
			adding_supplies(service, location_code_int, store_type_string, supply_type_string, complexity_code_int);
		}
		if (strcmp(initial_command, "update") == 0)
		{
			int location_code_int = 0;
			int complexity_code_int = 0;
			char* location_code_string = first_command_argument;
			char* store_type_string = second_command_argument;
			char* supply_type_string = third_command_argument;
			char* complexity_code_string = fourth_command_argument;
			location_code_int = string_into_int(location_code_string);
			complexity_code_int = string_into_int(complexity_code_string);
			if (verification_existence_of_supply(service, location_code_int) == 0)
			{
				printf("No!");
				continue;
			}
			update_supply(service, location_code_int, store_type_string, supply_type_string, complexity_code_int);
		}
		if (strcmp(initial_command, "delete") == 0)
		{
			int location_code_int = 0;
			char* location_code_string = first_command_argument;
			location_code_int = string_into_int(location_code_string);
			if (verification_existence_of_supply(service, location_code_int) == 0)
			{
				printf("No!");
				continue;
			}
			delete_supply(service, location_code_int);
		}

		if (strcmp(initial_command, "list") == 0)
		{
			int is_number = 0;
			int complexity_lock;
			if (strlen(first_command_argument) > 0)
			{
				if (validation_if_string_is_int(first_command_argument) == 1)
				{
					is_number = 1;
					complexity_lock = string_into_int(first_command_argument);
				}

				if (is_number == 0)
				{// supply
					char* supply_type_string = first_command_argument;
					int i;
					int count;
					supply** list_filtered = list_of_filter(service, &count, supply_type_filter, supply_type_string);// supply_type_filter is the function that compares every element with the supply_type_string
					for (i = 0; i < count; i++)
						print_on_screen(list_filtered[i]);
					free(list_filtered);
				}
				if (is_number == 1)
				{// complexity
					if (strcmp(second_command_argument, "a") == 0 || strcmp(second_command_argument, "") == 0)
					{
						int i;
						int count;
						supply** list_filtered = list_of_filter(service, &count, maximum_store_lock_complexity_filter, &complexity_lock);
						sorting_function(list_filtered, count, store_type_compare_ascending);
						for (i = 0; i < count; i++)
							print_on_screen(list_filtered[i]);
						free(list_filtered);
					}
					else if (strcmp(second_command_argument, "d") == 0)
					{
						int i;
						int count;
						supply** list_filtered = list_of_filter(service, &count, minimum_store_lock_complexity_filter, &complexity_lock);
						sorting_function(list_filtered, count, store_type_compare_descending);
						for (i = 0; i < count; i++)
							print_on_screen(list_filtered[i]);
						free(list_filtered);
					}
				}
			}
			if (strlen(first_command_argument) == 0)
			{
				int i;
				int count;
				 supply** list_filtered= list_of_filter(service,&count,NULL, NULL);
				 for (i = 0; i < count; i++)
				 {
					 print_on_screen(list_filtered[i]);
				 }
				 free(list_filtered);
			}
		}
		if (strcmp(initial_command, "undo") == 0)
			undo(service);
		if (strcmp(initial_command, "redo") == 0)
			redo(service);
		
	} while (1);
	delete_service(service);
}

// The main
int main()
{
	run_all_tests();
	starting();
	_CrtDumpMemoryLeaks();
	return 0;
	
}



