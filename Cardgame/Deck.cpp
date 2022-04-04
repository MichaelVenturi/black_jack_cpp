#include "Deck.h"

void Deck::makeDeck() {
	for (int i = 0; i < SUIT_MAX; i++) {
		for (int j = 0; j < RANK_MAX; j++) {
			Card c(generateRank(j), generateSuit(i));
			deck.push(c);
		}
	}
}