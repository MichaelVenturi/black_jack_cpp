#include "Deck.h"


// deal the top most card to the target hand
void Deck::dealCard(ArrayStack<Card> hand){
	if(isEmpty()){
		std::cout << "Deck is empty";
		return;
	}
	Card c = peek();
	deck.pop();
	hand.push(c);
}

void Deck::makeDeck() {
	for (int i = 0; i < SUIT_MAX; i++) {
		for (int j = 0; j < RANK_MAX; j++) {
			Card c(generateRank(j), generateSuit(i));
			deck.push(c);
		}
	}
}