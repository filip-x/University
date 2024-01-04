#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;
//Complexity O(n)
SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	BSTNode* SomeNode = bag.Root;
	while (SomeNode)
	{
		TraversalStack.push(SomeNode);
		SomeNode = SomeNode->Left;
	}
	if (TraversalStack.empty() == false)
		CurrentNode = TraversalStack.top();
	else CurrentNode = 0;
}
//Complexity Theta(1)
TComp SortedBagIterator::getCurrent() {
	if (valid() == false)
		throw exception();
	return CurrentNode->Info;
}
//Complexity Theta(1)
bool SortedBagIterator::valid() {
	return CurrentNode != 0;
}
//Complexity o(n)
void SortedBagIterator::next() {
	if (valid() == false)
		throw exception();
	BSTNode* SomeNode = TraversalStack.top();
	TraversalStack.pop();
	if (SomeNode->Right)
	{
		SomeNode = SomeNode->Right;
		while (SomeNode)
		{
			TraversalStack.push(SomeNode);
			SomeNode = SomeNode->Left;
		}
	}
	if (TraversalStack.empty() == false)
		CurrentNode = TraversalStack.top();
	else CurrentNode = 0;
}
// Complexity O(n)
void SortedBagIterator::first() {
	while (TraversalStack.empty() == false)
		TraversalStack.pop();
	BSTNode* SomeNode = bag.Root;
	while (SomeNode)
	{
		TraversalStack.push(SomeNode);
		SomeNode = SomeNode->Left;
	}
	if (TraversalStack.empty() == false)
		CurrentNode = TraversalStack.top();
	else CurrentNode = 0;
}

