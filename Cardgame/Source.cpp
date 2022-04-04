#include <iostream>

#include "Deck.h"

using namespace std;

int main() {

	bool acesHigh = false;
	Suit s = Suit::hearts;
	Suit s2 = Suit::hearts;

	Card card1(Rank::ace, Suit::hearts);
	Card card2(Rank::king, Suit::spades);
	
	Deck d;
	d.makeDeck();
	d.printDeck();

	
	

	

	return 0;
}