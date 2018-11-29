#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "../Headers/Spinner.h"
#include "../Headers/Player.h"
#include "../Headers/QueensCard.h"
#include "../Headers/Card.h"
#include "../Headers/Tile.h"

extern unsigned int width;							//window width
extern unsigned int height;							//window height

class GameBoard {
private:
	sf::RectangleShape Board;
	sf::Texture texture;
	std::vector<Card> queens_card_vec;
	std::vector<Card> degree_card_vec;
	std::vector<Card> housing_card_vec;
	std::vector<Player> players;
	std::vector<Tile> tiles;
	int num_players;
	int game_size;
	int player_turn;
	std::string textureFile = "..\\..\\Resources\\Board\\board_more_tiles.png";


public:
	GameBoard();
	GameBoard(int, int);
	//Pop's a Queen's card off the stack and returns it.
	Card getQueensCard(); 
	Card getHousingCard();
	Card getDegreeCard();
	Card getBestDegreeCard();
	sf::RectangleShape getShape();
	Tile getTile(int);
};  
