#pragma once
#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "ArrayStack.h"


class Deck {
private:
	ArrayStack<Card> deck;
public:
	Deck() : deck() {};

	// populate deck with all 52 playing cards
	void makeDeck();

	// some of these methods are just going to call the arraystack methods
	void addCard(Card c) { deck.push(c); }
	bool isEmpty() {return deck.isEmpty(); }
	Card peek()  { return deck.peek(); }
	void printDeck() { deck.print(); }

	// parameter will be a player or dealer hand
	void dealCard(ArrayStack<Card>& hand);
	// shuffling the deck will call the ArrayStack's shuffle method 4 times, to ensure super shuffling
	void shuffleDeck();

};

#endif