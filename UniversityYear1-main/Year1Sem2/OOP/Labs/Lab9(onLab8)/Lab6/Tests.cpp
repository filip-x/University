#include "Tests.h"
#include "service.h"
#include "exceptions.h"
#include "assert.h"
#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
// Add

void clear_test()
{
	std::ofstream file("test.txt");
	file << "";
	file.close();
}
typedef tm Date;
void AddCommand_DuplicateInput_ThrowException()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result = false;
	try {
		Date some_date = {0};
		service->append_function("1", "1", some_date, 2, "2");
		service->append_function("1", "1", some_date, 2, "2");
		//assertion_result = false;
	}
	catch (Exceptions)
	{
		assertion_result = true;
	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

void AddCommand_ValidInput_CorrectAddition()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result = false;
	try {
		Date some_date = {0};
		service->append_function("1", "1", some_date, 2, "2");
		std::vector<Tape*> List = service->list_function();
		assertion_result = List[0]->get_title() == "1";
	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

// Delete
void DeleteCommand_BadInput_ThrowException()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result = false;
	try {
		service->delete_function("1");
		assertion_result = false;
	}
	catch (Exceptions)
	{
		assertion_result = true;
	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

void DeleteCommand_ValidInput_CorrectRemoval()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result = false;
	try {
		Date some_date = {0};
		service->append_function("1", "1", some_date, 2, "2");
		service->append_function("2", "1", some_date, 2, "2");
		service->delete_function("1");
		std::vector<Tape*> List = service->list_function();
		assertion_result = List.size() == 1;
	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}


// Update
void UpdateCommand_BadInput_ThrowException()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result = false;
	try {
		Date some_date = {0};
		service->update_function("11", "2", some_date, 1, "2");
		assertion_result = false;
	}
	catch (Exceptions)
	{
		assertion_result = true;
	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

void UpdateCommand_ValidInput_CorrectUpdate()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result = false;
	try {
		Date some_date = {0};
		service->append_function("1", "1", some_date, 2, "1");
		service->append_function("2", "1", some_date, 2, "1");
		service->update_function("1", "1", some_date, 2, "3");
		std::vector<Tape*> List = service->list_function();
		Tape* stored = List[0];
		assertion_result = stored->get_section() == "1" && stored->get_access_count() == 2 && stored->get_footage_preview() == "3";
		
	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

// Save (Add)
void SaveCommand_ValidInput_CorrectSave()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result = false;
	try {
		Date some_date = {0};
		service->append_function("1", "1", some_date, 2, "1");
		service->append_function("2", "1", some_date, 2, "1");
		service->save_tape_by_title("1");
		assertion_result = service->list_my_list()[0]->get_title() == "1";
	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

void SaveCommand_BadInput_ThrowException()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result = false;
	try {
		service->save_tape_by_title("1");
		assertion_result = false;
	}
	catch (Exceptions)
	{
		assertion_result = true;
	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}
void Next_ValidInput_CorrectElement()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result=false;
	try {
		Date some_date = { 0 };
		service->append_function("1", "1", some_date, 2, "1");
		service->append_function("3", "3", some_date, 3, "3");
		service->creating_the_iterator();
		Tape* test_holder=service->next_tape();
		assertion_result = test_holder->get_title() == "1" ;
	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

void Next_ValidInputSecond_CorrectElement()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result=false;
	try {
		Date some_date = { 0 };
		service->creating_the_iterator();
		service->append_function("1", "1", some_date, 2, "1");
		service->append_function("3", "3", some_date, 3, "3");
		service->creating_the_iterator();
		Tape* test_holder = service->next_tape();
		test_holder = service->next_tape();
		assertion_result = test_holder->get_title() == "3";

	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

void ListBySectonAccessCount_ValidInput_CorrectCount()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result = false;
	try {
		Date some_date = { 0 };
		service->append_function("1", "2", some_date, 1, "1");
		service->append_function("2", "2", some_date, 2, "2");
		service->append_function("3", "2", some_date, 3, "3");
		auto list = service->list_by_section_access("2", 2);
		assertion_result = list.size() == 1;
	}
	catch (...)
	{
		//assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

void IteratorNext_EmptyList_ThrowException()
{
	clear_test();
	Service* service = new Service;
	bool assertion_result = false;
	try {
		service->creating_the_iterator();
		service->next_tape();
		assert(false);
	}
	catch (Exceptions)
	{
		assertion_result = true;
	}
	catch (...)
	{
		//assertion_result = false;

	}
	delete service;
	assert(assertion_result);
}


void run_tests()
{
	AddCommand_ValidInput_CorrectAddition();
	AddCommand_DuplicateInput_ThrowException();
	DeleteCommand_BadInput_ThrowException();
	DeleteCommand_ValidInput_CorrectRemoval();
	UpdateCommand_BadInput_ThrowException();
	UpdateCommand_ValidInput_CorrectUpdate();
	SaveCommand_ValidInput_CorrectSave();
	SaveCommand_BadInput_ThrowException();
	Next_ValidInput_CorrectElement();
	Next_ValidInputSecond_CorrectElement();
	ListBySectonAccessCount_ValidInput_CorrectCount();
	IteratorNext_EmptyList_ThrowException();
}