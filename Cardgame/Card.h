#pragma once
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <functional>


extern const int SUIT_MAX;
extern const int RANK_MAX;

// create type for Suit
enum class Suit {
	hearts,
	diamonds,
	clubs,
	spades
};
std::string toString(Suit s);
// let's add a to value func so we can compare suits, for games where some suits are better than others
int toValue(Suit s);
std::ostream& operator<<(std::ostream& out, const Suit& s);
bool operator==(Suit s1, Suit s2);
bool operator!=(Suit s1, Suit s2);
// generate a suit based on an integer value (for populating deck)
Suit generateSuit(int i);

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
	king = 13,
};
std::string toString(Rank r);
int toValue(Rank r);
std::ostream& operator<<(std::ostream& out, const Rank& r);
// these operators will likely only be used in a game where jacks, queens, and kings are ranked differently
bool operator==(Rank r1, Rank r2);
bool operator!=(Rank r1, Rank r2);
bool operator<(Rank r1, Rank r2);
bool operator>(Rank r1, Rank r2);
bool operator<=(Rank r1, Rank r2);
bool operator>=(Rank r1, Rank r2);
// generate a rank based on an integer value (for populating deck)
Rank generateRank(int i);

struct Card {

	Rank rank;
	Suit suit;

	Card() : rank(Rank::ace), suit(Suit::diamonds){};
	Card(Rank r, Suit s) : rank(r), suit(s) {};

	bool operator==(Card c);
	bool operator!=(Card c);
	int operator+(Card c);
};
std::string toString(Card c);
std::ostream& operator<<(std::ostream& out, const Card& c);
int operator+(int i, Card c);
int operator+=(int& i, Card c);

#endif