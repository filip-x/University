#include "Tests.h"
#include "service.h"
#include "exceptions.h"
#include "assert.h"

// Add
void AddCommand_DuplicateInput_ThrowException()
{
	Service* service = new Service;
	bool assertion_result;
	try {
		service->append_function("1", "1", "1", 2, "2");
		service->append_function("1", "1", "1", 2, "2");
		assertion_result = false;
	}
	catch (Exceptions)
	{
		assertion_result = true;
	}
	catch (...)
	{
		assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

void AddCommand_ValidInput_CorrectAddition()
{
	Service* service = new Service;
	bool assertion_result;
	try {
		service->append_function("1", "1", "1", 2, "2");
		Dynamic_array* List = service->list_function();
		assertion_result = (*List)[0]->get_title() == "1";
	}
	catch (...)
	{
		assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

// Delete
void DeleteCommand_BadInput_ThrowException()
{
	Service* service = new Service;
	bool assertion_result;
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
		assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

void DeleteCommand_ValidInput_CorrectRemoval()
{
	Service* service = new Service;
	bool assertion_result;
	try {
		service->append_function("1", "1", "1", 2, "2");
		service->delete_function("1");
		Dynamic_array* List = service->list_function();
		assertion_result = List->get_count() == 0;
		delete List;
	}
	catch (...)
	{
		assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}


// Update
void UpdateCommand_BadInput_ThrowException()
{
	Service* service = new Service;
	bool assertion_result;
	try {
		service->update_function("11", "2", "2", 1, "2");
		assertion_result = false;
	}
	catch (Exceptions)
	{
		assertion_result = true;
	}
	catch (...)
	{
		assertion_result = false;
	}
	delete service;
	assert(assertion_result);
}

void UpdateCommand_ValidInput_CorrectUpdate()
{
	Service* service = new Service;
	bool assertion_result;
	try {
		service->append_function("1", "1", "1", 2, "1");
		service->update_function("1", "1", "1", 2, "3");
		Dynamic_array* List = service->list_function();
		Tape* stored = (*List)[0];
		assertion_result = stored->get_section() == "1" && stored->get_date_of_creation() == "1" && stored->get_access_count() == 2 && stored->get_footage_preview() == "3";
		delete List;
	}
	catch (...)
	{
		assertion_result = false;
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
}