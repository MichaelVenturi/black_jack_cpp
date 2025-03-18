#include <iostream>

#include "Deck.h"

using namespace std;

int main() {

	bool acesHigh = false;
	Suit s = Suit::hearts;
	Suit s2 = Suit::hearts;

	Card card1(Rank::ace, Suit::hearts);
	Card card2(Rank::king, Suit::spades);
	
	Deck d;
	d.makeDeck();
	d.printDeck();

	ArrayStack<Card> playerHand;
	ArrayStack<Card> dealerHand;

	return 0;
}

void playBlackJack(){
	// todo: increase max size of ArrayStack, blackjack is usually played with multiple 52 card decks shuffled together
	Deck d;
	d.makeDeck();
	ArrayStack<Card> playerHand;
	ArrayStack<Card> dealerHand;
	int playerSum = 0;
	int dealerSum = 0;
	// deal 4 cards: 2 to dealer and 2 to player (player first)
	for(int i = 1; i <= 4; i++){
		if(i % 2 == 1){	// deal player
			playerSum += d.peek();
			d.dealCard(playerHand);
		}else{ // deal dealer
			dealerSum += d.peek();
			d.dealCard(dealerHand); 
		}
	}
	playerHand.print();
	dealerHand.print(); // todo: dealer's first card be concealed.  
	// maybe output the peek card, then once the dealer starts hitting, print each card he deals.
	// player does not know the dealer's hidden card until he is done hitting, typically.  

	// todo: check if dealer has blackjack (this means 21 but with a face card)

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