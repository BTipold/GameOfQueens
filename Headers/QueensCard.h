#pragma once
#include <string>
#include "../Headers/Card.h"
#include <iostream>

class QueensCard : public Card {
private:
	std::string hiddenMessage;
public:
	QueensCard(std::string, int, int, int);
	std::string getHiddenMessage();
	int getValue();
	int colour;
};