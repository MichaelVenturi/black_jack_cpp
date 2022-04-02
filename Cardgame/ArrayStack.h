#pragma once
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "Card.h"
#include <time.h>

const int MAX_STACK = 52; // size of a deck

// should I bother with template classes?  will I use this for more than just Cards?
template<class ItemType>
class ArrayStack {
private:
	ItemType* items;
	int top; // equal to top most occupied index
	int size; // top most index is size - 1
public:
	// constructors
	ArrayStack();
	ArrayStack(int s);
	// destructor
	~ArrayStack();

	int getSize() { return size; };
	bool isEmpty() const;
	bool isFull() const;
	bool push(ItemType newItem);
	bool pop();
	ItemType peek() const;

	void shuffle();
	ItemType itemAt(int i);
	void print();
};






#endif