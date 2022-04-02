#include <iostream>

#include "Card.h"
#include "ArrayStack.h"

using namespace std;

int main() {

	bool acesHigh = false;
	Suit s = Suit::hearts;
	Suit s2 = Suit::hearts;

	Card card1(Rank::ace, Suit::hearts);
	Card card2(Rank::king, Suit::spades);
	
	ArrayStack<int> a1(5);
	a1.push(1);
	a1.push(2);
	a1.push(3);
	a1.push(4);
	a1.push(5);
	a1.print();
	ArrayStack<Card> a2(3);
	a2.push(card1);
	a2.push(card2);
	a2.print();

	

	

	return 0;
}