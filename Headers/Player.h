/*
 * Player.h
 *
 *  Created on: Oct 22, 2018
 *      Author: edwardmunn
 */
#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Headers/Card.h"
#include "../Headers/QueensCard.h"

using namespace std;

class Player {
public:
	Player(int, bool, std::string, sf::Font&);
	bool moving;
	unsigned int playerNumber;


	//mutator methods
	void setDebt(int);
	void setConnections(int);
	void setHiddenDebt(int);
	void setPosition(sf::Vector2f);
	void setTileNumber(int);
	void setHouse(Card);
	void setDegree(Card);
	void addQCard(Card);

	//accessor methods
	int getDebt();
	Card getHouse();
	int getTile();
	int getConnections();
	int getHiddenDebt();
	sf::Vector2f getPosition();
	sf::RectangleShape getShape();
	sf::RectangleShape shape;
	sf::Text playerName;
	std::string name;

	sf::Text getText();

	Card house;
	Card degree;
	vector<Card> QCards;

private:
	int debt;
	unsigned int connections;
	unsigned int hiddenDebt;
	unsigned int currentTile;
	bool ai;

	//GUI
	unsigned int width = 75;
	unsigned int height = 75;

};