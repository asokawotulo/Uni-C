#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
	protected:
		string card, suit;

	public:
		Card(string c, string s);
		string getCard();
};

#endif