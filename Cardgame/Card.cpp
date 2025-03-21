#include "Card.h"


const int SUIT_MAX = 4;
const int RANK_MAX = 13;

// return suit as a string
std::string toString(Suit s) {
	switch (s) {
	case Suit::hearts:
		return "hearts";
	case Suit::diamonds:
		return "diamonds";
	case Suit::clubs:
		return "clubs";
	case Suit::spades:
		return "spades";
	default:
		break;
	}
}
//return suit as a number
int toValue(Suit s) {
	switch(s){
		case Suit::hearts:
			return 3;
		case Suit::diamonds:
			return 2;
		case Suit::clubs:
			return 1;
		case Suit::spades:
			return 4;
		default:
			break;
	}
}
// Suit oss
std::ostream& operator<<(std::ostream& out, const Suit& s) {
	out << toString(s);
	return out;
}
// suit comparators 
bool operator==(Suit s1, Suit s2) {
	return (toString(s1).compare(toString(s2)) == 0);
}
bool operator!=(Suit s1, Suit s2) {
	return !(operator==(s1, s2));
}
// generate suit
Suit generateSuit(int i) {
	switch (i) {
	case 0:return Suit::diamonds;
	case 1:return Suit::clubs;
	case 2:return Suit::hearts;
	case 3:return Suit::spades;
	default:
		// just gonna have it return an arbitrary suit, this should never happen
		std::cout << "index out of bounds\n"; return Suit::diamonds;
	}
}

// return Rank as a string (tedious :/ )
std::string toString(Rank r) {
	switch (r) {
	case Rank::ace:return "ace";
	case Rank::two:return "two";
	case Rank::three:return "three";
	case Rank::four:return "four";
	case Rank::five:return "five";
	case Rank::six:return "six";
	case Rank::seven:return "seven";
	case Rank::eight:return "eight";
	case Rank::nine:return "nine";
	case Rank::ten:return "ten";
	case Rank::jack:return "jack";
	case Rank::queen:return "queen";
	case Rank::king:return "king";
	}
}
// return the Rank as an integer value
int toValue(Rank r) {
	switch (r) {
	case Rank::jack:
	case Rank::queen:
	case Rank::king:
		return 10;
	default:
		return static_cast<int>(r);
	}
}
// rank oss
std::ostream& operator<<(std::ostream& out, const Rank& r) {
	out << toString(r);
	return out;
}
// rank comparisons (not for black jack)
// might need to be edited to account for aces
bool operator==(Rank r1, Rank r2)
{
	return static_cast<int>(r1) == static_cast<int>(r2);
}
bool operator!=(Rank r1, Rank r2)
{
	return !(operator==(r1, r2));
}
bool operator<(Rank r1, Rank r2)
{
	return static_cast<int>(r1) < static_cast<int>(r2);
}
bool operator>(Rank r1, Rank r2)
{
	return (operator<(r2,r1));
}
bool operator<=(Rank r1, Rank r2)
{
	return static_cast<int>(r1) <= static_cast<int>(r2);
}
bool operator>=(Rank r1, Rank r2)
{
	return (operator<=(r2, r1));
}
// generate rank
Rank generateRank(int i) {
	switch (i) {
	case 0:return Rank::ace;
	case 1:return Rank::two;
	case 2:return Rank::three;
	case 3:return Rank::four;
	case 4:return Rank::five;
	case 5:return Rank::six;
	case 6:return Rank::seven;
	case 7:return Rank::eight;
	case 8:return Rank::nine;
	case 9:return Rank::ten;
	case 10:return Rank::jack;
	case 11:return Rank::queen;
	case 12:return Rank::king;
	default: 
		std::cout << "index out of bounds\n"; return Rank::ace;
	}
}

// Card toString
std::string toString(Card c) {
	return (toString(c.rank) + " of " + toString(c.suit));
}
bool Card::operator==(Card c) {
	return this->rank == c.rank;
}
bool Card::operator!=(Card c) {
	return !(operator==(c));
}
// add two cards (for blackjack)
int Card::operator+(Card c){
	return toValue(this->rank) + toValue(c.rank);
}
std::ostream& operator<<(std::ostream& out, const Card& c){
	out << c.rank << " of " << c.suit;
	return out;
}
// add card to a number (for blackjack)
int operator+(int i, Card c){
	return i + toValue(c.rank);
}
int operator+=(int& i, Card c){
	i = i + c;
	return i;
}
