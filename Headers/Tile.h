/*
 * Tile.h
 *
 *  Created on: Oct 22, 2018
 *      Author: edwardmunn
 */

#ifndef TILE_H_
#define TILE_H_

#include<string>
//wtf do these do together to allow me to use strings
using namespace std;

class Tile {
public:
	Tile();
	Tile(string, int, int);

	//accessor methods
	string getType();
	int getXPosition();
	int getYPosition();




private:
	string type, message;
	//guiReference;
	int tileNumber, xPosition, yPosition, value;
};

#endif /* TILE_H_ */

