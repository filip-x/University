#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
SortedIteratedList::SortedIteratedList(Relation r) {
	//TODO - Implementation
	head = NULL;
	count = 0;
	this->r = r;
}
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
int SortedIteratedList::size() const {
	//TODO - Implementation
	
	return count;
}
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
bool SortedIteratedList::isEmpty() const {
	//TODO - Implementation
	if (count == 0)
		return true;
	return false;
}
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
ListIterator SortedIteratedList::first() const {
	//TODO - Implementation
	return ListIterator(*this);// return an iterator  to the first position
}
//Complexity Best Case = Worst Case = Average Case : Theta(1) 
TComp SortedIteratedList::getElement(ListIterator poz) const {
	//TODO - Implementation
	if (poz.valid() == false)
		throw exception("Invalid");
	return poz.getCurrent();
}
//n - number of elements 
//Complexity:Best Case: The best case is when the element we want to remove is on the "head", 1st place in the represetation:n Theta(1)
//Complexity:Worst Case: The worst case is when the element we want to remove is on the last place of the representation Theta(n)
//Complexity: Average: The average case is the rest of the cases: O(n) => Theta(n) ( Total  is O(n)) ! Not average just Total)
TComp SortedIteratedList::remove(ListIterator& poz) {
	//TODO - Implementation
	if (poz.valid() == false)
	{
		throw exception("Invalid");
	}
	else
	{
		TComp removed_element;
		if (poz.current_node == head)
		{
			removed_element = head->info;
			poz.next();// to go on the next element
			delete head;
			head = poz.current_node;
			count--;
			return removed_element;
		}
		else
		{	
			removed_element = poz.getCurrent();
			node* index;
			index = head;
			while (index->next != poz.current_node)
			{
				index = index->next; 
			}
			poz.next();
			delete index->next;
			index->next = poz.current_node;
			count--;
	
			return removed_element;

		}
	}
}
//Complexity: Best Case = Average Case = Worst Case = > O(n)
// I could consider the relation !!!!
ListIterator SortedIteratedList::search(TComp e) const{
	//TODO - Implementation
	ListIterator index = first();
	while (index.valid()==true)
	{
		if (index.getCurrent() == e)
		{
			return index;
		}
		else
		{
			index.next();
		}
	}
	return index;
}
//n - number of elements 
//Complexity:Best Case: The best case is when orur list is empty and we add a new element on the first position(Head) Theta(1)
//Complexity:Worst Case: == Average Case: Inserting on any other position O(n)
void SortedIteratedList::add(TComp e) {
	//TODO - Implementation
	node* index = head;
	node* new_element = new node;//  the creation of  the node 
	new_element->info = e; // the creation of  the node 
	if (size() == 0)
	{
		head = new_element;
		head->next = NULL;
	}
	else
	{
		if (r(head->info, e) == false)
		{
			new_element->next = head;
			head = new_element;
		}
		else
		{
			while (index->next != NULL && r(index->next->info, e)== true)
			{
				index = index->next;
			}
			new_element->next = index->next;
			index->next = new_element;
		}
	}
	count++;
}


//Complexity: Best Case = Average Case = Worst Case => Theta(n)
SortedIteratedList::~SortedIteratedList() {
	//TODO - Implementation
	node* index = head;
	node* before_node;
	while (index!=NULL)
	{
		before_node = index;
		index = index->next;
		delete before_node; 
	}
	
}
