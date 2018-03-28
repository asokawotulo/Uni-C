#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

Card::Card(string c, string s){
	this->card = c;
	this->suit = s;
}

string Card::getCard(){
	string output;
	output = this->suit;
	output += " ";
	output += this->card;
	return output;
}