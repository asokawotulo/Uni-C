#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
#include <vector>
#include "Card.cpp"
using namespace std;

class Blackjack {
	protected:
		bool dealerDone;
		bool playerDone;
		vector<Card> player_deck;
		vector<Card> dealer_deck;
		vector<Card> full_deck;

	public:
		void resetCards();
		void addCard(vector<Card> *deck);
		void viewHands();
		int countValue(vector<Card> deck);
		int playGame();
		Blackjack();
};

#endif