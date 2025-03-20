#include <iostream>

#include "Deck.h"

using namespace std;

const bool onOneLine = true;

void playBlackJack();
bool hasAce(ArrayStack<Card> hand);
int handTotal(int curTotal, bool hasAce);
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
	bool playerHasAce = false;
	bool dealerHasAce = false;
	Card dealerHidden; // the card the player cannot see
	// deal 4 cards: 2 to dealer and 2 to player (player first)

	for(int i = 1; i <= 4; i++){
		if(i % 2 == 1){	// deal player
			playerHasAce = d.peek().rank == Rank::ace ? true : playerHasAce;
			playerSum += d.peek();
			d.dealCard(playerHand);
			
		}else{ // deal dealer
			if (dealerHand.isEmpty()) dealerHidden = d.peek(); 
			dealerHasAce = d.peek().rank == Rank::ace ? true : dealerHasAce;
			dealerSum += d.peek();
			d.dealCard(dealerHand); 
		}
	} 



	dealerShownSum = handTotal(dealerSum, dealerHasAce);
	// check if dealer has blackjack
	if (dealerShownSum == 21) {
		cout << "OOPS!  DEALER HAS BLACKJACK!\n";
		dealerHand.print();
		return;
	}// check if player has blackjack
	if (handTotal(playerSum, playerHasAce) == 21) {
		cout << "HOORAY!  YOU HAVE BLACKJACK!\n";
		playerHand.print();
		return;
	}// check if both players get blackjack
	if (handTotal(playerSum, playerHasAce) + dealerShownSum == 42) {
		cout << "PUSH!  YOU BOTH HAVE BLACKJACK!\n";
		return;
	}

	// subtract the hidden card's rank directly if dealer has no aces, or if he has an ace face up (one ace and a normal card, or two aces)
	if (!dealerHasAce || dealerHand.peek().rank == Rank::ace) dealerShownSum -= toValue(dealerHidden.rank);
	// subtract 11 if dealer has 1 ace and its the hidden card
	else dealerShownSum -= 11;

	cout << "PLAYER SHOWING: \n";
	playerHand.print();
	cout << "TOTAL: " << handTotal(playerSum, playerHasAce) << endl;
	cout << "\nDEALER SHOWING: \n" << dealerHand.peek() << "\n?????\n";
	cout << "TOTAL: " << dealerShownSum << endl;

	/* Player turn: hit or stand
	loop until player decides to stand.  every hit, deal a new card.  
	If player's cards add up to 21 or more, loop ends.
	*/

	char choice = 'H'; // H for hit, S for stand
	while(choice != 'S' && playerSum < 21){
		cout << "Hit or Stand? (H / S): ";
		cin >> choice;

		// use a switch since there will be more options in the future (double, split)
		switch (choice) {
		case 'H':
			cout << "HIT ME!  player showing:\n";
			d.dealCard(playerHand);
			playerHand.print(onOneLine);

			break;
		case 'S':

		default:
			cout << "Error: invalid choice\n";
			continue;
		}



	}
}

// check if the player has an ace, necessary since the score will fluctuate if they do
// honestly I probably didnt need to do all this extra shit with the passing a lambda to a function, but it's cool as hell so I'm keeping it
bool hasAce(ArrayStack<Card> hand) {
	Card ace;
	return hand.has(ace, [](Card c1, Card c2)-> bool {return c1.rank == c2.rank; });
}

// calculate your hand total (take aces into account)
int handTotal(int total, bool hasAce) {

	// we only need to check if there is one ace, if they have two aces, only one of them can ever count as 11 (both would make 22)
	// add the full value of the ace (+10) if current total is 11 or less.  otherwise, ace is treated as 1
	if (total <= 11 && hasAce) total += 10;

	return total;
}