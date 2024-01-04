#pragma once
#include "SortedBag.h"
#include <stack>
class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);

	//TODO - Representation
	std::stack<BSTNode*> TraversalStack;
	BSTNode* CurrentNode;
public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

