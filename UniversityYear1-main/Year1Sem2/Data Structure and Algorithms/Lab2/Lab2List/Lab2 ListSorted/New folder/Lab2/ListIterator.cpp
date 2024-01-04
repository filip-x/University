#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
	//TODO - Implementation
	this->current_node = list.head;
}
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
void ListIterator::first(){
	//TODO - Implementation
	this->current_node = list.head;
}
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
void ListIterator::next(){
	//TODO - Implementation
	if(valid()==true)
		this->current_node = this->current_node->next;
	else
	{
		throw exception("Invalid ");
	}
}
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
bool ListIterator::valid() const{
	//TODO - Implementation
	if(this->current_node != NULL)
		return true;
	return false;
}
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
TComp ListIterator::getCurrent() const{
	//TODO - Implementation
	if (valid() == true)
		return this->current_node->info;
	else
	{
		return NULL_TCOMP;
	}
}
//Complexity: Best Case : First Position = > Complexity Theta(1)
//Worst Case : Last Position = > Complexity Theta(n)
//Average Case : Any other position = > Complexity Theta(n)
//Overall complexity : O(n)
void ListIterator::previous()
{
	if (valid() == false)
		throw exception("Invalid");
	if (current_node == list.head)
	{
		current_node = NULL;
		return;
	}
	node* temporary_node = list.head;
	while (temporary_node->next != current_node)
	{
		temporary_node = temporary_node->next;
	}
	current_node = temporary_node;
}
//ADT SortedList
//Make the iterator bidirectional.Add the following operation in the SortedListIterator class.
//changes the current element from the iterator to the previous element, or, if the current element was the first, makes the iterator invalid
//throws an exception if the iterator is not valid



