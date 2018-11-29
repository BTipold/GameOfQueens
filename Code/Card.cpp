#include <iostream>
#include <string>
#include "../Headers/Card.h"

Card::Card(std::string str, int val, int id) {
	message = str;
	value = val;
	this->id = id;
}

Card::Card() {
	message = "Null";
	value = 0;
	id = 0;
}

unsigned int Card::getValue() {
	return value;
}

std::string Card::getMessage() {
	return message;
}

int Card::getId() {
	return id;
}