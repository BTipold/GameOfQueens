#pragma once
#include <iostream>
#include "string.h"
#include <SFML/Graphics.hpp>

class spinner {
private:
	const float sizeX = 400;
	const float sizeY = 400;
	std::string texture = "..\\..\\Resources\\Spinner\\SpinSpin.png";
	std::string textureHover = "..\\..\\Resources\\Spinner\\SpinSpin_Hover.png";
	std::string textureArrow = "..\\..\\Resources\\Spinner\\Arrow spinner.png";
	sf::Texture pointerTexture;
	sf::Texture spinnerTexture;
	sf::Texture hoverTexture;
	sf::RectangleShape spinnerShape;
	sf::RectangleShape pointer;

public:
	bool spinning;
	float spinAngle = 0;
	void init();
	float getSizeX();
	float getSizeY();
	spinner();
	spinner(int, int);
	sf::RectangleShape getShape();
	sf::RectangleShape getPointer();
	void setPosition(float, float);
	void setRotation(float);
	float getRotation();
	void hover(bool);
	void spinAnimation();
	int spin();
};

