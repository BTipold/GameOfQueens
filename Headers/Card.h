#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Card {
protected:
	std::string message;
	int value;

public:
	int id;
	Card(std::string, int, int);
	Card();
	int getId();
	unsigned int getValue();
	std::string getMessage();
};