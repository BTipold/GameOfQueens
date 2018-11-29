/*
 * Tile.cpp
 *
 *  Created on: Oct 22, 2018
 *      Author: edwardmunn
 */

#include "../Headers/Player.h"
#include "../Headers/Tile.h"

Tile::Tile() {
	message = "";
	type = "";
	tileNumber = 0;

}

 Tile::Tile(string typeIn, int xPositionIn, int yPositionIn) {
	 type = typeIn;
	 xPosition = xPositionIn;
	 yPosition = yPositionIn;
}

string Tile::getType() {
    return type;
}

int Tile::getXPosition() {
    return xPosition;
}

int Tile::getYPosition() {
    return yPosition;
}
