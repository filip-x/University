#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>


// Overall complexity: O(n)
BSTNode* SortedBag::IterativeSearch(BSTNode* Node, TComp& Value) const// -search
{
	while (Node != 0 && Node->Info != Value)
	{
		if (ComparisonRelation(Value, Node->Info))
			Node = Node->Left;
		else Node = Node->Right;
	}
	return Node;
}

// Overall complexity: O(n)
int SortedBag::IterativeNrOccurances(BSTNode* Node, TComp& Value) const // -occur
{
	int Count = 0;
	Node = IterativeSearch(Node, Value);
	BSTNode* Aux;
	while (Node)
	{
		Count++;
		Aux = IterativeSearch(Node->Left, Value);
		if (Aux == 0)
			Aux = IterativeSearch(Node->Right, Value);
		Node = Aux;
	}
	return Count;
}

// Overall complexity: O(n)
// Exactly like search, but doesn't return a node 
// it returns a reference to the variabile holding the node
// which could be either a left node, a right node or the root itself
BSTNode** SortedBag::IterativeReferenceSearch(BSTNode** NodeP, TComp& Value)// -search but as refrence 
{
	BSTNode* Node = *NodeP;
	while (Node != 0 && Node->Info != Value)
	{
		if (ComparisonRelation(Value, Node->Info))
			NodeP = &Node->Left;
		else NodeP = &Node->Right;
		Node = *NodeP;
	}
	return NodeP;
}

// Overall Complexity: O(n) (together with the search part from the main remove function)
bool SortedBag::IterativeRemoveNode(BSTNode** NodeToBeRemovedP) // -remove
{
	BSTNode* NodeToBeRemoved = *NodeToBeRemovedP;
	while (true)
	{
		if (NodeToBeRemoved == 0)
			return false;
		// Case 1: no descendants
		if (NodeToBeRemoved->Left == 0 && NodeToBeRemoved->Right == 0)
		{
			delete NodeToBeRemoved;
			*NodeToBeRemovedP = 0;
			return true;
		}

		// Case 2: one descendant
		if (NodeToBeRemoved->Left == 0 && NodeToBeRemoved->Right)
		{
			*NodeToBeRemovedP = NodeToBeRemoved->Right;
			delete NodeToBeRemoved;
			return true;
		}
		if (NodeToBeRemoved->Left && NodeToBeRemoved->Right == 0)
		{
			*NodeToBeRemovedP = NodeToBeRemoved->Left;
			delete NodeToBeRemoved;
			return true;
		}

		// Case 3: both descendants exist
		BSTNode** ReplacementNode = &NodeToBeRemoved->Left;
		while ((*ReplacementNode)->Right)
			ReplacementNode = &(*ReplacementNode)->Right;
		NodeToBeRemoved->Info = (*ReplacementNode)->Info;
		NodeToBeRemovedP = ReplacementNode;
		NodeToBeRemoved = *NodeToBeRemovedP;
	}
}
//Complexity: O(nr*n)// bcs add has o(n) and we make it times nr 
void SortedBag::addOccurrences(int nr, TComp elem)// -add 
{	
	int i = 0;
	if (nr < 0)
	{
		throw std::exception();
	}
	else
	{	
		for (i = 0; i < nr; i++)
		{
			add(elem);
		}
	}
}
//Theta(1)
SortedBag::SortedBag(Relation r) {
	Count = 0;
	Root = 0;
	ComparisonRelation = r;
}
//UP
void SortedBag::add(TComp e) {
	BSTNode** CurrentNodeP = &Root;
	while (true)
	{
		BSTNode* Node = *CurrentNodeP;
		if (!Node)
		{
			*CurrentNodeP = new BSTNode{ e };
			Count++;
			return;
		}
		if (ComparisonRelation(e, Node->Info))
			CurrentNodeP = &Node->Left;
		else CurrentNodeP = &Node->Right;
	}
}

//UP
bool SortedBag::remove(TComp e) {
	BSTNode** Node = IterativeReferenceSearch(&Root, e);
	bool RemovedStatus = IterativeRemoveNode(Node);
	if (RemovedStatus)
		Count--;
	return RemovedStatus;
}

//UP
bool SortedBag::search(TComp elem) const {
	return IterativeSearch(Root, elem) != 0;
}

//UP
int SortedBag::nrOccurrences(TComp elem) const {
	return IterativeNrOccurances(IterativeSearch(Root, elem), elem);
}


//Theta(1)
int SortedBag::size() const {
	return Count;
}

//Theta(1)
bool SortedBag::isEmpty() const {
	return size() == 0;
}

//Theta(1)
SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}

//O(n)
SortedBag::~SortedBag() {
	if (Root != 0)
	{
		BSTNode** Queue = new BSTNode * [size()];
		BSTNode* CurrentNode;
		int n = 0;
		Queue[n++] = Root;
		for (int i = 0; i < n; i++)
		{
			CurrentNode = Queue[i];
			if (CurrentNode->Left != 0)
				Queue[n++] = CurrentNode->Left;
			if (CurrentNode->Right != 0)
				Queue[n++] = CurrentNode->Right;
			delete CurrentNode;
		}
		delete Queue;
	}
}
