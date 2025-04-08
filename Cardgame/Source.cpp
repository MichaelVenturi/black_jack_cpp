#include <iostream>

#include "Deck.h"

using namespace std;

const bool onOneLine = true;

void playBlackJack();
bool hasAce(ArrayStack<Card> hand);
bool isAce(Card c);
int handTotal(int curTotal, bool hasAce);
bool hasBlackJack(int total);
bool bust(int);

int main() {

	char choice;
	
	do {
		playBlackJack();
		cout << "Play again? Y/N\n";
		cin >> choice;

	} while(choice == 'Y' || choice == 'y');

	cout << "Thank you for playing with us!\n"; 
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
			playerHasAce = isAce(d.peek()) ? true : playerHasAce;
			playerSum += d.peek();
			d.dealCard(playerHand);
			
		}else{ // deal dealer
			if (dealerHand.isEmpty()) dealerHidden = d.peek(); 
			dealerHasAce = isAce(d.peek()) ? true : playerHasAce;
			dealerSum += d.peek();
			d.dealCard(dealerHand); 
		}
	} 

	dealerShownSum = handTotal(dealerSum, dealerHasAce);
	// check if dealer has blackjack
	if (hasBlackJack(dealerShownSum)) {
		cout << "OOPS!  DEALER HAS BLACKJACK!\n";
		dealerHand.print();
		return;
	}// check if player has blackjack
	if (hasBlackJack(handTotal(playerSum, playerHasAce)) ) {
		cout << "HOORAY!  YOU HAVE BLACKJACK!\n";
		playerHand.print();
		return;
	}// check if both players get blackjack
	if (hasBlackJack(dealerShownSum) && hasBlackJack(handTotal(playerSum, playerHasAce))) {
		cout << "PUSH!  YOU BOTH HAVE BLACKJACK!\n";
		return;
	}

	// subtract the hidden card's rank directly if dealer has no aces, or if he has an ace face up (one ace and a normal card, or two aces)
	if (!dealerHasAce || isAce(dealerHand.peek())) dealerShownSum -= toValue(dealerHidden.rank);
	// subtract 11 if dealer has 1 ace and its the hidden card
	else dealerShownSum -= 11;

	// display starting hands
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
	while(choice != 'S' && choice !='D' && playerSum < 21){
		cout << "Hit (H) Stand (S) or Double down (D): ";
		cin >> choice;

		// use a switch since there will be more options in the future (double, split)
		switch (choice) {
		case 'D':
		case 'd':
			cout << "DOUBLE DOWN! ";
		case 'H':
		case 'h':
			cout << "HIT ME!  player showing: ";
			playerSum += d.peek();
			d.dealCard(playerHand);
			cout << handTotal(playerSum, playerHasAce) << endl;
			playerHand.print(onOneLine);
			break;
		case 'S':
		case 's':
			cout << "Player stands on " << handTotal(playerSum, playerHasAce) << endl;
			break;
		default:
			cout << "Error: invalid choice\n";
			continue;
		}

		if (bust(handTotal(playerSum, playerHasAce))) {
			cout << "OOPS!  YOU BUSTED OUT AT " << handTotal(playerSum, playerHasAce) << ", SORRY!\n";
			goto loss;
		}
	}

	// dealer turn
	// dealer hits on soft 17, so we only care about his ace for if he opens with blackjack
	while (dealerSum < 17) {
		dealerSum += d.peek();
		d.dealCard(dealerHand);
	}
	
		cout << "Dealer has: " << dealerSum << endl;
		dealerHand.print(onOneLine);

		if (dealerSum > 21){
			cout << "The Dealer busted out!  You win!\n";
			return;
		} else if(handTotal(playerSum, playerHasAce) > dealerSum){
			cout << "you win\n";
			return;
		} else if(handTotal(playerSum, playerHasAce) == dealerSum){
			cout << "tie\n";
			return;
		}
	loss:
		cout << "Better luck next time\n";
		return;
}

// check if the player has an ace, necessary since the score will fluctuate if they do
// honestly I probably didnt need to do all this extra shit with the passing a lambda to a function, but it's cool as hell so I'm keeping it
bool hasAce(ArrayStack<Card> hand) {
	Card ace;
	return hand.has(ace, [](Card c1, Card c2)-> bool {return c1.rank == c2.rank; });
}

bool isAce(Card c) {
	return c.rank == Rank::ace;
}

// calculate your hand total (take aces into account)
int handTotal(int total, bool hasAce) {
	// we only need to check if there is one ace, if they have two aces, only one of them can ever count as 11 (both would make 22)
	// add the full value of the ace (+10) if current total is 11 or less.  otherwise, ace is treated as 1
	if (total <= 11 && hasAce) total += 10;

	return total;
}

bool hasBlackJack(int total) {
	return total == 21;
}
bool bust(int total) {
	return total > 21;
}