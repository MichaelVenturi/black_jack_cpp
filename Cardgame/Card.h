#pragma once

#ifndef CARD_H
#define CARD_H

#include "CardTypes.h"


struct Card {

	Rank rank;
	Suit suit;


	int compareTo(Card c);
	std::ostream& operator<<(std::ostream& out);
	bool operator==(Card c);
	
};

#endif