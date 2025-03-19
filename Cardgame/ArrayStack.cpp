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

// copy constructor
template <class ItemType>
ArrayStack<ItemType>::ArrayStack(const ArrayStack& other) : top(other.top), size(other.size) {
	items= new ItemType[other.size];
	std::copy(other.items, other.items + (other.top + 1), items);
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

// add element to top of stack
template <class ItemType>
bool ArrayStack<ItemType>::push(ItemType newItem)  {
	if (!isFull()) {
		top++;
		items[top] = newItem;
		return true;
	}
	return false;
}
// remove top element from stack
template <class ItemType>
bool ArrayStack<ItemType>::pop()  {
	if (!isEmpty()) {
		top--;
		return true;
	}
	return false;
}

// view top of stack
template <class ItemType>
ItemType ArrayStack<ItemType>::peek() const {
	if (!isEmpty()) {
		return items[top];
	}
	exit(1);
}

// this function will check if I have a specific card/itemtype, but I also want to check just if it has the cards rank or maybe even suit.  I need a different function for that to pass as a param
template <class ItemType>
bool ArrayStack<ItemType>::has(ItemType item, std::function<bool(ItemType, ItemType)> compareFunc) {
	if (compareFunc) {
		for (int i = 0; i < top + 1; i++) 
			if (compareFunc(item, items[i])) return true;
			
		return false;
	}
	else {
		for (int i = 0; i < top + 1; i++) 
			if (item == items[i]) return true;		

		return false;
	}
}

// shuffle with fisher-yates algorithm
template <class ItemType>
void ArrayStack<ItemType>::shuffle() {
	srand(time(NULL));
	for (int i = top; i > 0; i--) {
		int j = rand() % (i + 1);
		ItemType temp = items[i];
		items[i] = items[j];
		items[j] = temp;
	}
}

// get item at index
template <class ItemType>
ItemType ArrayStack<ItemType>::itemAt(int i) {
	if (!isEmpty() && i <= top && i >= 0) {
		return items[i];
	}
	exit(1);
}

template <class ItemType>
void ArrayStack<ItemType>::print() {
	for (int i = 0; i < top+1; i++) {
		std::cout << items[i] << std::endl;
	}
}

// overload assignment operator
template <class ItemType>
ArrayStack<ItemType> ArrayStack<ItemType>::operator=(const ArrayStack& other){
	this->top = other.top;
	this->size = other.size;
	this->items = new ItemType[size];
	std::copy(other.items, other.items + (top + 1), this->items);
	return *this;
}

// explicit instantiations
template class ArrayStack<Card>;
template class ArrayStack<int>;