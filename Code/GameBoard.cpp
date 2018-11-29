#include "../Headers/Player.h"
#include "../Headers/GameBoard.h"
#include "../Headers/QueensCard.h"
#include "../Headers/Tile.h"
#include <algorithm>
#include <random>
#include <vector>
#include <fstream>
#include <chrono>


unsigned int width = 1920;							//window width
unsigned int height = 1080;							//window height
std::fstream config("..\\..\\Config.txt");

int findChar(string, char, int);

GameBoard::GameBoard() {
}

//Constructor for the GameBoard class.
GameBoard::GameBoard(int n_players, int g_size) {
	//INITIALIZE GUI
	Board.setSize(sf::Vector2f(width, height));
	texture.loadFromFile(textureFile);
	Board.setTexture(&texture);

	//INITIALIZE VARIABLES
	num_players = n_players;
	game_size = g_size;
	player_turn = 1;

	//INITIALIZE CARDS
	std::string lineIn;
	while (std::getline(config, lineIn) && lineIn.compare("#ENDQUEENSCARDS") != 0) {
		std::string messageTemp = lineIn.substr(0, lineIn.find("#"));
		int numTemp = stoi(lineIn.substr(lineIn.find("#") + 1, lineIn.size()));
		queens_card_vec.push_back(Card(messageTemp, numTemp, queens_card_vec.size() + 1));
	}
	while (std::getline(config, lineIn) && lineIn.compare("#ENDFACULTYCARDS") != 0) {
		std::string messageTemp = lineIn.substr(0, lineIn.find("#"));
		int numTemp = stoi(lineIn.substr(lineIn.find("#") + 1, lineIn.size()));
		degree_card_vec.push_back(Card(messageTemp, numTemp, degree_card_vec.size() + 1));
	}
	while (std::getline(config, lineIn) && lineIn.compare("#ENDHOUSINGCARDS") != 0) {
		std::string messageTemp = lineIn.substr(0, lineIn.find("#"));
		int numTemp = stoi(lineIn.substr(lineIn.find("#") + 1, lineIn.size()));
		housing_card_vec.push_back(Card(messageTemp, numTemp, housing_card_vec.size() + 1));
	}
	while (std::getline(config, lineIn)) {
		int tab1 = findChar(lineIn, '\t', 1);
		int tab2 = findChar(lineIn, '\t', 2);
		std::string type = lineIn.substr(0, tab1);
		int x = stoi(lineIn.substr(tab1 + 1, tab2 - tab1 - 1));
		int y = stoi(lineIn.substr(tab2 + 1, lineIn.size()));
		tiles.push_back(Tile(type, x, y));
	}
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	auto engine = default_random_engine{}; // or any other engine
	engine.seed(seed);

	//std::shuffle(std::begin(queens_card_vec), std::end(queens_card_vec), engine);
	std::shuffle(std::begin(degree_card_vec), std::end(degree_card_vec), engine);
	std::shuffle(std::begin(housing_card_vec), std::end(housing_card_vec), engine);
}

//Pop's a Queen's card off the stack and returns it.
Card GameBoard::getQueensCard() { //Pop's a Queen's card off the stack and returns it.
	Card card = queens_card_vec[queens_card_vec.size() - 1];
	queens_card_vec.pop_back();
	return card;
}

Card GameBoard::getHousingCard() {
	Card card = housing_card_vec[housing_card_vec.size() - 1];
	housing_card_vec.pop_back();
	return card;
}

Card GameBoard::getDegreeCard() {
	Card card = degree_card_vec[degree_card_vec.size() - 1];
	degree_card_vec.pop_back();
	return card;
}

sf::RectangleShape GameBoard::getShape() {
	return Board;
}

Tile GameBoard::getTile(int i) {
	return tiles[i];
}

int findChar(string s, char find, int n) {								//FUNCTION RETURNS THE INDEX OF THE N'th OCCURENCE OF CHAR 
	int count(0);														//COUNTER HOLDS NUM OF OCCURENCES OF CHAR
	for (int i(0); i < s.size(); i++) {									//LOOP THROUGH STRING
		if (s[i] == find) {												//IF I'TH ELEMENT OF STRING == CHAR
			if (count == n - 1)											//AND YOUR AT THE N'TH OCCURENCE
				return i;												//RETURN INDEX
			else
				count++;												//ELSE INCREASE COUNT OF OCCURENCES
		}
	}
	return -1;															//IF NOT FOUND RETURN -1
}

Card GameBoard::getBestDegreeCard() {
	Card card1 = degree_card_vec[degree_card_vec.size() - 1];
	degree_card_vec.pop_back();
	Card card2 = degree_card_vec[degree_card_vec.size() - 1];
	degree_card_vec.pop_back();
	Card card3 = degree_card_vec[degree_card_vec.size() - 1];
	degree_card_vec.pop_back();

	int a = card1.getValue();
	int b = card2.getValue();
	int c = card3.getValue();

	if (a < b && a < c) {
		degree_card_vec.push_back(card2);
		degree_card_vec.push_back(card3);
		return card1;
	}
	else if (b < a && b < c) {
		degree_card_vec.push_back(card3);
		degree_card_vec.push_back(card1);
		return card2;
	}
	else if (c < b && c < a) {
		degree_card_vec.push_back(card1);
		degree_card_vec.push_back(card2);
		return card3;
	}
}