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

// shuffle with fisher-yates algorithm
template <class ItemType>
void ArrayStack<ItemType>::shuffle() {
	srand(time(NULL));
	for (int i = size - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		ItemType temp = items[i];
		items[i] = items[j];
		items[j] = temp;
	}
}

template <class ItemType>
ItemType ArrayStack<ItemType>::itemAt(int i) {
	if (!isEmpty() && i <= top && i >= 0) {
		return items[i];
	}
	exit(1);
}

template <class ItemType>
void ArrayStack<ItemType>::print() {
	for (int i = 0; i < size; i++) {
		std::cout << items[i] << std::endl;
	}
}



// explicit instantiations
template class ArrayStack<Card>;
template class ArrayStack<int>;