#include "CardTypes.h"


// return suit as a string
std::string to_string(Suit s) {
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

// Suit oss
std::ostream& operator<<(std::ostream& out, const Suit& s) {
	out << to_string(s);
	return out;
}

// suit comparators 
bool operator==(Suit s1, Suit s2) {
	return (to_string(s1).compare(to_string(s2)) == 0);
}
bool operator!=(Suit s1, Suit s2) {
	return !(operator==(s1, s2));
}

// return Rank as a string (tedious :/ )
std::string to_string(Rank r) {
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
int to_value(Rank r) {
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
	out << to_string(r);
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
	return (operator<(r2, r1));
}

bool operator<=(Rank r1, Rank r2)
{
	return !(operator>(r1, r2));
}

bool operator>=(Rank r1, Rank r2)
{
	return !(operator<(r1, r2));
}
