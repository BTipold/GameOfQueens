/*
 * Player.cpp
 *
 *  Created on: Oct 22, 2018
 *      Author: edwardmunn
 */

#include "../Headers/Player.h"
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

Player::Player(int playerNum, bool isAi, std::string name, sf::Font &font) {
	shape.setSize(sf::Vector2f(width, height));
	shape.setPosition(sf::Vector2f(235, 330));
	playerName.setFont(font);
	playerName.setString(name);
	playerName.setFillColor(sf::Color::Black);
	playerName.setOrigin(sf::Vector2f(playerName.getGlobalBounds().width / 2, 0));
	playerName.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y - 50));
	moving = false;
	debt = 0;
	connections = 0;
	hiddenDebt = 0;
	playerNumber = playerNum;
	currentTile = 0;
	ai = isAi;
	this->name = name;
	shape.setOrigin(sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2));
}

void Player::setDebt(int in) {
	debt = in;
}

void Player::setConnections(int in) {
	connections = in;
}

void Player::setHiddenDebt(int in) {
	hiddenDebt = in;
}

void Player::setPosition(sf::Vector2f in) {
	shape.setPosition(in);
}

void Player::setHouse(Card in) {
	house = in;
}

void Player::setDegree(Card in) {
	degree = in;
}

void Player::addQCard(Card in) {
	QCards.push_back(in);
}

void Player::setTileNumber(int in) {
	currentTile = in;
}

int Player::getDebt() {
	return debt;
}

Card Player::getHouse() {
	return house;
}

int Player::getTile() {
	return currentTile;
}

int Player::getConnections() {
	return connections;
}

int Player::getHiddenDebt() {
	return hiddenDebt;
}

sf::Vector2f Player::getPosition() {
	return shape.getPosition();
}

sf::RectangleShape Player::getShape() {

	return shape;
}

sf::Text Player::getText()
{
	return playerName;
}



