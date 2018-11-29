#include <iostream>
#include <string>
#include "../Headers/QueensCard.h"
#include "../Headers/Card.h"

// QueensCard constructor
QueensCard::QueensCard(std::string str, int val, int id, int clr) : Card("You got a Queen's Card", val, id) {
	hiddenMessage = str; //must store away from what a player can see
	colour = clr;
}

std::string QueensCard::getHiddenMessage() {
	return hiddenMessage;
}

int QueensCard::getValue() {
	return value;
}
