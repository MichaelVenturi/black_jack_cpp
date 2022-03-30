#include <iostream>

#include "Card.h"

using namespace std;

int main() {
	// github push
	bool acesHigh = false;
	Suit s = Suit::hearts;
	Suit s2 = Suit::hearts;

	Card card1(Rank::ace, Suit::hearts);
	Card card2(Rank::king, Suit::spades);

	//int x = 12 + static_cast<int>(r);
	cout << (card1 == card2) << endl;
	

	return 0;
}