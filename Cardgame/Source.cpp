#include <iostream>

#include "Deck.h"

using namespace std;

void playBlackJack();
bool hasAce(ArrayStack<Card> hand);
int handTotal(ArrayStack<Card> hand, int curTotal = -1);
int main() {

	bool acesHigh = false;
	Suit s = Suit::hearts;
	Suit s2 = Suit::hearts;

	Card card1(Rank::ace, Suit::hearts);
	Card card2(Rank::king, Suit::spades);

	ArrayStack<Card> playerHand;

	playerHand.push(card2);

	cout << hasAce(playerHand);

	playerHand.push(card1);

	
	
	playBlackJack();

	return 0;
}

void playBlackJack(){
	cout << "OK ... OPEN THE GAME\n\n";
	// todo: increase max size of ArrayStack, blackjack is usually played with multiple 52 card decks shuffled together
	Deck d;
	d.makeDeck();
	d.shuffleDeck();
	ArrayStack<Card> playerHand;
	ArrayStack<Card> dealerHand;
	int playerSum = 0;
	int dealerSum = 0;
	int dealerShownSum = 0;
	Card dealerHidden; // the card the player cannot see
	// deal 4 cards: 2 to dealer and 2 to player (player first)

	for(int i = 1; i <= 4; i++){
		if(i % 2 == 1){	// deal player
			d.dealCard(playerHand);
		}else{ // deal dealer
			if (dealerHand.isEmpty()) dealerHidden = d.peek(); 
			d.dealCard(dealerHand); 
		}
	} 
	playerSum = handTotal(playerHand);
	dealerSum = handTotal(dealerHand);
	// check if dealer has blackjack
	if (dealerSum == 21) {
		cout << "OOPS!  DEALER HAS BLACKJACK!\n";
		dealerHand.print();
		return;
	}
	// if the hidden card is an ace, handTotal will calculate it as 11.  So the shown some would need to be 11 less than it is
	dealerShownSum = dealerHidden.rank == Rank::ace ? dealerSum - 11 : dealerSum - toValue(dealerHidden.rank);
	cout << "PLAYER SHOWING: \n";
	playerHand.print();
	cout << "TOTAL: " << playerSum << endl;
	cout << "\nDEALER SHOWING: \n" << dealerHand.peek() << "\n?????\n";
	cout << "TOTAL: " << dealerShownSum << endl;
	
	// todo: dealer's first card be concealed.  
	// maybe output the peek card, then once the dealer starts hitting, print each card he deals.
	// player does not know the dealer's hidden card until he is done hitting, typically.  

	/* Player turn: hit or stand
	loop until player decides to stand.  every hit, deal a new card.  
	If player's cards add up to 21 or more, loop ends.
	*/

	char choice = 'H'; // H for hit, S for stand
	while(choice != 'S' && playerSum < 21){
		cout << "Hit or Stand? (H / S): ";
		cin >> choice;
		if(choice != 'S' && choice != 'H'){
			cout << "Error: invalid choice\n";
			continue;
		}

	}
}

// check if the player has an ace, necessary since the score will fluctuate if they do
bool hasAce(ArrayStack<Card> hand) {
	Card ace;
	return hand.has(ace, [](Card c1, Card c2)-> bool {return c1.rank == c2.rank; });
}

// calculate your hand total (take aces into account)
int handTotal(ArrayStack<Card> hand, int curTotal) {
	int aceVal = 0;
	int total = max(curTotal, 0);
	if (hasAce(hand)) aceVal = 10;
	// if no curTotal value is passed, then add all cards in hand currently.  This is to prevent looping and adding cards that were already counted
	// we will add card values to the function as they are drawing otherwise.  This function will mainly be for checking if we need to make the Ace high
	if(curTotal < 0)
		for (int i = 0; i < hand.getSize(); i++)
		{
			total += hand.itemAt(i);
		}
	// add the full value of the ace (+10) if current total is 11 or less.  otherwise, ace is treated as 1
	if (total <= 11) total += aceVal;

	return total;
}