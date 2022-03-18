#pragma once


#ifndef CARD_TYPES_H
#define CARD_TYPES_H

#include <iostream>
#include <string>

// create type for Suit
enum class Suit {
	hearts,
	diamonds,
	clubs,
	spades
};
// return suit as a string
std::string to_string(Suit s);
// Suit oss
std::ostream& operator<<(std::ostream& out, const Suit& s);
// compare suit
bool operator==(Suit s1, Suit s2);
bool operator!=(Suit s1, Suit s2);


// create type for rank
// includes aces high and aces low (determined by card game)
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
	king = 13,
};
// return Rank as a string (tedious :/ )
std::string to_string(Rank r);
// return the Rank as an integer value
int to_value(Rank r);
// rank oss
std::ostream& operator<<(std::ostream& out, const Rank& r);
// compare rank
// these operators will likely only be used in a game where jacks, queens, and kings are ranked differently
bool operator==(Rank r1, Rank r2);
bool operator!=(Rank r1, Rank r2);
bool operator<(Rank r1, Rank r2);
bool operator>(Rank r1, Rank r2);
bool operator<=(Rank r1, Rank r2);
bool operator>=(Rank r1, Rank r2);



#endif