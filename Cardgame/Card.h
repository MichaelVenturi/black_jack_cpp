#pragma once

#ifndef CARD_H
#define CARD_H

#include <iostream>

// create type for Suit
enum class Suit {
	hearts,
	diamonds, 
	clubs, 
	spades
};

// create type for rank
enum class Rank {
	ace = 1,
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ten = 10,
	jack = 11,
	queen = 12,
	king = 13
};

// return suit as a string
std::string to_string(Suit s);
// Suit oss
std::ostream& operator<<(std::ostream& out, const Suit& s);
// return Rank as a string (tedious :/ )
std::string to_string(Rank r);
// return the Rank as an integer value
int to_value(Rank r);
// rank oss
std::ostream& operator<<(std::ostream& out, const Rank& r);








#endif