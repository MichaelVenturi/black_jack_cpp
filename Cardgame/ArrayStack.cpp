#include "ArrayStack.h"

// implementation

// constructors
template <class ItemType>
ArrayStack<ItemType>::ArrayStack(): top(-1), size(MAX_STACK) {
	items = new ItemType[size];
}
template <class ItemType>
ArrayStack<ItemType>::ArrayStack(int s) : top(-1) {
	size = s > MAX_STACK ? MAX_STACK : s; // if given size is larger than max size, set stack to max size
	items = new ItemType[size];
}

// destructor
template <class ItemType>
ArrayStack<ItemType>::~ArrayStack() {
	delete[] items;
}

template <class ItemType>
bool ArrayStack<ItemType>::isEmpty() const {
	return top < 0;
}
template <class ItemType>
bool ArrayStack<ItemType>::isFull() const {
	return top == size - 1;
}

template <class ItemType>
bool ArrayStack<ItemType>::push(ItemType newItem)  {
	if (!isFull()) {
		top++;
		items[top] = newItem;
		return true;
	}
	return false;
}
template <class ItemType>
bool ArrayStack<ItemType>::pop()  {
	if (!isEmpty()) {
		top--;
		return true;
	}
	return false;
}

template <class ItemType>
ItemType ArrayStack<ItemType>::peek() const {
	if (!isEmpty()) {
		return items[top];
	}
	exit(1);
}

// explicit instantiations
template class ArrayStack<Card>;