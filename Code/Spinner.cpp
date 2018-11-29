#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include "../Headers/Spinner.h"

unsigned seed(std::chrono::steady_clock::now().time_since_epoch().count());
std::default_random_engine e(seed);

float spinner::getSizeX(){
	return sizeX;
}

float spinner::getSizeY(){
	return sizeY;
}

spinner::spinner(){
	init();
}

spinner::spinner(int x, int y){
	init();
	setPosition(x, y);
	pointer.setPosition(sf::Vector2f(x+pointer.getSize().x/2, y-150));
}

sf::RectangleShape spinner::getShape() {
	return spinnerShape;
}

sf::RectangleShape spinner::getPointer() {
	return pointer;
}

void spinner::setPosition(float x, float y){
	spinnerShape.setPosition(sf::Vector2f(x, y));
}

void spinner::setRotation(float r) {
	spinnerShape.setRotation(r);
}

float spinner::getRotation() {
	return spinnerShape.getRotation();
}

void spinner::hover(bool yes) {
	if (yes)
		spinnerShape.setTexture(&hoverTexture);
	else
		spinnerShape.setTexture(&spinnerTexture);
}

void spinner::spinAnimation() {
	if (spinAngle > 0) {
		setRotation(getRotation() + spinAngle);
		spinAngle -= 0.5;
		return;
	}
	spinning = false;
}

int spinner::spin() {
	std::uniform_int_distribution<int> gen(1, 10);
	int randomNumber = round(gen(e));
	setRotation((10-randomNumber)*36-5);
	spinAngle = 50;	
	spinning = true;
	return randomNumber;
}

void spinner::init() {
	pointer.setSize(sf::Vector2f(100.0f, 100.0f));
	pointer.setRotation(180);
	spinning = false;
	pointer.setPosition(sf::Vector2f(300, 100));
	pointerTexture.loadFromFile(textureArrow);
	pointer.setTexture(&pointerTexture);
	spinnerShape.setSize(sf::Vector2f(getSizeX(), getSizeY()));
	spinnerTexture.loadFromFile(texture);
	hoverTexture.loadFromFile(textureHover);
	spinnerShape.setTexture(&spinnerTexture);
	spinnerShape.setOrigin(getSizeX() / 2, getSizeY() / 2);
}

