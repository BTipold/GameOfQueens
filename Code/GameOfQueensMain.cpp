#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../Headers/GameBoard.h"
#include "../Headers/Player.h"
#include "../Headers/Spinner.h"
#include "../Headers/Card.h"
#include "../Headers/QueensCard.h"
#include "../Headers/Tile.h"

//GLOBAL VARIABLES
int destination[] = { 0,0,0,0 };
bool canSpin = true;
bool stillOnStartingSpace = true;
bool finished = false;
sf::Font font;

//FUNCTIONS
bool clicked(sf::RectangleShape, sf::RenderWindow&, sf::View);
void playerAnimation(Player&, GameBoard);

int main() {
	//%%%%%%%%%%%%%%%%%%%%%%%
	//%%% INITIALIZATION %%%%
	//%%%%%%%%%%%%%%%%%%%%%%%



	//WINDOW
	sf::RenderWindow window(sf::VideoMode(width, height), "The Game Of Queens", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		//%%%%%%%%%%%%%%%%%%%%%%
		//%%% MAIN MENU LOOP %%%
		//%%%%%%%%%%%%%%%%%%%%%%				

		//INITIALIZE ARROWS
		sf::Cursor hover;
		hover.loadFromSystem(sf::Cursor::Hand);
		sf::Cursor arrow;
		arrow.loadFromSystem(sf::Cursor::Arrow);
		sf::Cursor waiting;
		waiting.loadFromSystem(sf::Cursor::Wait);

		//INITIALIZE FONTS
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) { //basic fonts were used, no time to search for the perfect one
			std::cout << "Font failed to load" << std::endl;
		}

		//MAIN MENU BACKGROUND
		sf::RectangleShape backgroundMM(sf::Vector2f(1920, 1080));
		backgroundMM.setPosition(sf::Vector2f(0, 0));
		sf::Texture background;
		background.loadFromFile("..\\..\\Resources\\Board\\Blurry_board.jpg");
		backgroundMM.setTexture(&background);

		//CREATING MAIN MENU SCREEN BUTTONS
		sf::RectangleShape startGame(sf::Vector2f(332, 92));
		startGame.setPosition(sf::Vector2f(800, 600));

		sf::RectangleShape instructions(sf::Vector2f(332, 92));
		instructions.setPosition(sf::Vector2f(800, 750));

		sf::RectangleShape logo(sf::Vector2f(1161, 429));
		logo.setPosition(sf::Vector2f(350, 0));

		sf::Texture leftButton1;
		leftButton1.loadFromFile("..\\..\\Resources\\buttonleft.png");
		sf::Texture rightButton1;
		rightButton1.loadFromFile("..\\..\\Resources\\buttonright.png");

		sf::RectangleShape player0Left(sf::Vector2f(50, 300));
		player0Left.setPosition(300, 405);
		player0Left.setTexture(&leftButton1);
		sf::RectangleShape hover1L(sf::Vector2f(50, 300));
		hover1L.setFillColor(sf::Color::Color(255, 255, 255, 180));
		hover1L.setPosition(300, 405);
		sf::RectangleShape player0Right(sf::Vector2f(player0Left.getSize().x, player0Left.getSize().y));
		player0Right.setPosition(sf::Vector2f(player0Left.getPosition().x + player0Left.getSize().x + player0Left.getSize().y, player0Left.getPosition().y));
		player0Right.setTexture(&rightButton1);
		sf::RectangleShape hover1R(sf::Vector2f(50, 300));
		hover1R.setFillColor(sf::Color::Color(255, 255, 255, 180));
		hover1R.setPosition(sf::Vector2f(player0Left.getPosition().x + player0Left.getSize().x + player0Left.getSize().y, player0Left.getPosition().y));
		sf::RectangleShape player0(sf::Vector2f(player0Left.getSize().y, player0Left.getSize().y));
		player0.setPosition(sf::Vector2f(player0Left.getPosition().x + player0Left.getSize().x, player0Left.getPosition().y));

		sf::RectangleShape player1Left(sf::Vector2f(50, 300));
		player1Left.setPosition(1220, 405);
		player1Left.setTexture(&leftButton1);
		sf::RectangleShape hover2L(sf::Vector2f(50, 300));
		hover2L.setPosition(1220, 405);
		hover2L.setFillColor(sf::Color::Color(255, 255, 255, 180));
		sf::RectangleShape player1Right(sf::Vector2f(50, 300));
		player1Right.setPosition(sf::Vector2f(player1Left.getPosition().x + player1Left.getSize().x + player1Left.getSize().y, player1Left.getPosition().y));
		player1Right.setTexture(&rightButton1);
		sf::RectangleShape hover2R(sf::Vector2f(player1Left.getSize().x, player1Left.getSize().y));
		hover2R.setFillColor(sf::Color::Color(255, 255, 255, 180));
		hover2R.setPosition(sf::Vector2f(player1Left.getPosition().x + player1Left.getSize().x + player1Left.getSize().y, player1Left.getPosition().y));
		sf::RectangleShape player1(sf::Vector2f(player1Left.getSize().y, player1Left.getSize().y));
		player1.setPosition(sf::Vector2f(player1Left.getPosition().x + player1Left.getSize().x, player1Left.getPosition().y));

		sf::RectangleShape player2Left(sf::Vector2f(50, 300));
		player2Left.setTexture(&leftButton1);
		player2Left.setPosition(300, 755);
		sf::RectangleShape hover3L(sf::Vector2f(50, 300));
		hover3L.setPosition(300, 755);
		hover3L.setFillColor(sf::Color::Color(255, 255, 255, 180));
		sf::RectangleShape player2Right(sf::Vector2f(50, 300));
		player2Right.setPosition(sf::Vector2f(player2Left.getPosition().x + player2Left.getSize().x + player2Left.getSize().y, player2Left.getPosition().y));
		player2Right.setTexture(&rightButton1);
		sf::RectangleShape hover3R(sf::Vector2f(50, 300));
		hover3R.setFillColor(sf::Color::Color(255, 255, 255, 180));
		hover3R.setPosition(sf::Vector2f(player2Left.getPosition().x + player2Left.getSize().x + player2Left.getSize().y, player2Left.getPosition().y));
		sf::RectangleShape player2(sf::Vector2f(player2Left.getSize().y, player2Left.getSize().y));
		player2.setPosition(sf::Vector2f(player2Left.getPosition().x + player2Left.getSize().x, player2Left.getPosition().y));

		sf::RectangleShape player3Left(sf::Vector2f(50, 300));
		player3Left.setPosition(1220, 755);
		player3Left.setTexture(&leftButton1);
		sf::RectangleShape hover4L(sf::Vector2f(50, 300));
		hover4L.setPosition(1220, 755);
		hover4L.setFillColor(sf::Color::Color(255, 255, 255, 180));
		sf::RectangleShape player3Right(sf::Vector2f(player3Left.getSize().x, player3Left.getSize().y));
		player3Right.setPosition(sf::Vector2f(player3Left.getPosition().x + player3Left.getSize().x + player3Left.getSize().y, player3Left.getPosition().y));
		player3Right.setTexture(&rightButton1);
		sf::RectangleShape hover4R(sf::Vector2f(player3Left.getSize().x, player3Left.getSize().y));
		hover4R.setPosition(sf::Vector2f(player3Left.getPosition().x + player3Left.getSize().x + player3Left.getSize().y, player3Left.getPosition().y));
		hover4R.setFillColor(sf::Color::Color(255, 255, 255, 180));
		sf::RectangleShape player3(sf::Vector2f(player3Left.getSize().y, player3Left.getSize().y));
		player3.setPosition(sf::Vector2f(player3Left.getPosition().x + player3Left.getSize().x, player3Left.getPosition().y));


		//INSTRUCTIONS POP-UP
		sf::RectangleShape intPopUp(sf::Vector2f(1200, 800));
		intPopUp.setPosition(360, 140);

		sf::Texture intPopUpTexture;
		intPopUpTexture.loadFromFile("..\\..\\Resources\\intpop.png");
		intPopUp.setTexture(&intPopUpTexture);
		

		//PLAYER TEXTURES
		sf::Texture startTexture;
		startTexture.loadFromFile("..\\..\\Resources\\start.png");
		startGame.setTexture(&startTexture);

		sf::Texture instructionsTexture;
		instructionsTexture.loadFromFile("..\\..\\Resources\\instructions3.png");
		instructions.setTexture(&instructionsTexture);

		sf::Texture logoTexture;
		logoTexture.loadFromFile("..\\..\\Resources\\logo.png");
		logo.setTexture(&logoTexture);

		sf::Texture AlanTexture;
		AlanTexture.loadFromFile("..\\..\\Resources\\Player1.png");
		sf::Texture ManjiTexture;
		ManjiTexture.loadFromFile("..\\..\\Resources\\Player2.png");
		sf::Texture WoolfTexture;
		WoolfTexture.loadFromFile("..\\..\\Resources\\Player3.png");
		sf::Texture DStrong;
		DStrong.loadFromFile("..\\..\\Resources\\Player4.png");
		sf::Texture AlanRVTexture;
		AlanRVTexture.loadFromFile("..\\..\\Resources\\Player5.png");


		std::string playerNames[] = { "Alan", "Manji", "Woolf with a hat", "Black and Decker", "Alan in an RV" };
		sf::Texture playerTextures[] = { AlanTexture, ManjiTexture, WoolfTexture, DStrong, AlanRVTexture};
		int pct[] = { 0,0,0,0 };

		player0.setTexture(&playerTextures[pct[0]]);
		player1.setTexture(&playerTextures[pct[1]]);
		player2.setTexture(&playerTextures[pct[2]]);
		player3.setTexture(&playerTextures[pct[3]]);

		//VARIABLES	
		sf::View view;																							//create new camera
		view.reset(sf::FloatRect(0, 0, width, height));															//initialize camera
		view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
		unsigned int gameSize = 3;
		unsigned int numOfPlayers = 2;
		int spriteNum = 4;
		vector<Player> players;

		//AI OR REAL PLAYER?
		int ai[] = { 0,0,0,0 };

		while (true) {  //MAIN MENU LOOP
			//CREATE OBJECTS
			sf::Event newEvent;
			bool exit = false;
			while (window.pollEvent(newEvent)) {
				if (newEvent.type == newEvent.Closed) {
					window.close();
				}
				if (newEvent.type == sf::Event::MouseButtonPressed) {
					if (clicked(startGame, window, view)) {
						exit = true;
					}
				}
			}
			if (exit)
				break;

			window.clear();
			window.draw(backgroundMM);
			window.draw(startGame);
			window.draw(instructions);
			window.draw(logo);
			if (clicked(startGame, window, view)) {
				window.setMouseCursor(hover);
			}
			else if (clicked(instructions, window, view)) {
				window.setMouseCursor(hover);
			}
			else
				window.setMouseCursor(arrow);
			window.display();
		}

		while (true) {  //MAIN MENU LOOP
			//CREATE OBJECTS
			sf::Event newEvent;
			bool exit = false;
			while (window.pollEvent(newEvent)) {
				if (newEvent.type == newEvent.Closed) {
					window.close();
				}
				if (newEvent.type == sf::Event::MouseButtonPressed) {
					if (clicked(startGame, window, view)) {
						exit = true;
					}
					if (clicked(player0Right, window, view)) {
						pct[0] = (pct[0] + 1) % (spriteNum + 1);
						player0.setTexture(&playerTextures[pct[0]]);
					}
					if (clicked(player0Left, window, view)) {
						pct[0] = pct[0] - 1;
						if (pct[0] == -1) { pct[0] = spriteNum; }
						player0.setTexture(&playerTextures[pct[0]]);
					}
					if (clicked(player1Right, window, view)) {
						pct[1] = (pct[1] + 1) % (spriteNum + 1);
						player1.setTexture(&playerTextures[pct[1]]);
					}
					if (clicked(player1Left, window, view)) {
						pct[1] = pct[1] - 1;
						if (pct[1] == -1) { pct[1] = spriteNum; }
						player1.setTexture(&playerTextures[pct[1]]);
					}
					if (clicked(player2Right, window, view)) {
						pct[2] = (pct[2] + 1) % (spriteNum + 1);
						player2.setTexture(&playerTextures[pct[2]]);
					}
					if (clicked(player2Left, window, view)) {
						pct[2] = pct[2] - 1;
						if (pct[2] == -1) { pct[2] = spriteNum; }
						player2.setTexture(&playerTextures[pct[2]]);
					}
					if (clicked(player3Right, window, view)) {
						pct[3] = (pct[3] + 1) % (spriteNum + 1);
						player3.setTexture(&playerTextures[pct[3]]);
					}
					if (clicked(player3Left, window, view)) {
						pct[3] = pct[3] - 1;
						if (pct[3] == -1) { pct[3] = spriteNum; }
						player3.setTexture(&playerTextures[pct[3]]);
					}
				}
				if (newEvent.type == sf::Event::TextEntered) {
					std::cout << (char)newEvent.text.unicode;
				}
			}
			if (exit)
				break;

			window.clear();
			window.draw(backgroundMM);
			window.draw(startGame);
			window.draw(logo);
			window.draw(player0Right);
			window.draw(player0Left);
			window.draw(player0);
			window.draw(player1Right);
			window.draw(player1Left);
			window.draw(player1);
			window.draw(player2Right);
			window.draw(player2Left);
			window.draw(player2);
			window.draw(player3Right);
			window.draw(player3Left);
			window.draw(player3);
			if (clicked(startGame, window, view)) {
				window.setMouseCursor(hover);
			}
			else if (clicked(player0Right, window, view)) {
				window.draw(hover1R);
				window.setMouseCursor(hover);
			}
			else if (clicked(player0Left, window, view)) {
				window.draw(hover1L);
				window.setMouseCursor(hover);
			}
			else if (clicked(player1Right, window, view)) {
				window.draw(hover2R);
				window.setMouseCursor(hover);
			}
			else if (clicked(player1Left, window, view)) {
				window.draw(hover2L);
				window.setMouseCursor(hover);
			}
			else if (clicked(player2Right, window, view)) {
				window.draw(hover3R);
				window.setMouseCursor(hover);
			}
			else if (clicked(player2Left, window, view)) {
				window.draw(hover3L);
				window.setMouseCursor(hover);
			}
			else if (clicked(player3Right, window, view)) {
				window.draw(hover4R);
				window.setMouseCursor(hover);
			}
			else if (clicked(player3Left, window, view)) {
				window.draw(hover4L);
				window.setMouseCursor(hover);
			}
			else
				window.setMouseCursor(arrow);
			window.display();
		}
		window.clear();
		sf::Text loading;
		loading.setFont(font);
		loading.setString("Loading, please wait...");
		loading.setCharacterSize(60);
		loading.setFillColor(sf::Color::White);
		loading.setOrigin(sf::Vector2f(loading.getGlobalBounds().width / 2, loading.getGlobalBounds().height));
		loading.setPosition(sf::Vector2f(width/2, height/2));
		window.draw(loading);
		window.display();
		window.setMouseCursor(waiting);

		for (unsigned int i = 0; i < numOfPlayers; i++) {
			Player temp(i, false,playerNames[pct[i]], font);
			players.push_back(temp);
		}

		// this can be done in  a for loop i think -- do it later
		players[0].shape.setTexture(&playerTextures[pct[0]]);
		players[1].shape.setTexture(&playerTextures[pct[1]]);
		//players[2].shape.setTexture(&playerTextures[pct[2]]);
		//players[3].shape.setTexture(&playerTextures[pct[3]]);

		//%%%%%%%%%%%%%%%%%%%%%%
		//%%% MAIN GAME LOOP %%%
		//%%%%%%%%%%%%%%%%%%%%%%

		//VARIABLES
		unsigned int zoomLevel = 0;							//current zoom level
		const unsigned int maxZoom = 10;					//max zoom level
		const unsigned int minZoom = 0;						//min zoom level
		float zoomFactor = 20.0f / 21.0f;					//How much you zoom out
		double lastMouseX = 0;								//last mouse x position
		double lastMouseY = 0;								//last mouse y position
		float mouseDeltaX = 0;								//change in mouse x position
		float mouseDeltaY = 0;								//change in mouse y position
		double viewLeftCoord = 0;							//left border of the camera
		double viewRightCoord = 1920;						//right border of the camera
		double viewTopCoord = 0;							//top border of the camera
		double viewBottomCoord = 1080;						//bottom border of the camera
		int turn = 0;
		bool canSpin = true;
		bool reSpin = false;
		vector<sf::Drawable*> toRender;
		spinner spinspin(1200, 650);



		//%%%%%%%%%%%%%%%%%%%%%
		//%%% LOAD TEXTURES %%%
		//%%%%%%%%%%%%%%%%%%%%%
		sf::Texture NullTexture;
		NullTexture.loadFromFile("..\\..\\Resources\\NullTexture.png");

		//DEGREES
		vector<sf::Texture> DegreeCards;
		DegreeCards.push_back(NullTexture);
		sf::Texture arts;
		arts.loadFromFile("..\\..\\Resources\\Degrees\\Arts.png");
		DegreeCards.push_back(arts);
		sf::Texture commerce;
		commerce.loadFromFile("..\\..\\Resources\\Degrees\\Commerce.png");
		DegreeCards.push_back(commerce);
		sf::Texture comp_sci;
		comp_sci.loadFromFile("..\\..\\Resources\\Degrees\\Computer Science.png");
		DegreeCards.push_back(comp_sci);
		sf::Texture con_ed;
		con_ed.loadFromFile("..\\..\\Resources\\Degrees\\Con Ed.png");
		DegreeCards.push_back(con_ed);
		sf::Texture engineering;
		engineering.loadFromFile("..\\..\\Resources\\Degrees\\Engineering.png");
		DegreeCards.push_back(engineering);
		sf::Texture general_science;
		general_science.loadFromFile("..\\..\\Resources\\Degrees\\General Sciences.png");
		DegreeCards.push_back(general_science);
		sf::Texture life_sci;
		life_sci.loadFromFile("..\\..\\Resources\\Degrees\\Life Science.png");
		DegreeCards.push_back(life_sci);
		sf::Texture nursing;
		nursing.loadFromFile("..\\..\\Resources\\Degrees\\Nursing.png");
		DegreeCards.push_back(nursing);
		sf::Texture phe_kin;
		phe_kin.loadFromFile("..\\..\\Resources\\Degrees\\PheKin.png");
		DegreeCards.push_back(phe_kin);

		vector<sf::Texture> HouseCards;
		//RESIDENCES
		HouseCards.push_back(NullTexture);
		sf::Texture brandt;
		brandt.loadFromFile("..\\..\\Resources\\Residences\\Brandt.png");
		HouseCards.push_back(brandt);
		sf::Texture ghettho1;
		ghettho1.loadFromFile("..\\..\\Resources\\Residences\\Ghettho house (complete trash hole).png");
		HouseCards.push_back(ghettho1);
		sf::Texture ghettho2;
		ghettho2.loadFromFile("..\\..\\Resources\\Residences\\Ghetto House (actually nice tho...).png");
		HouseCards.push_back(ghettho2);
		sf::Texture parents;
		parents.loadFromFile("..\\..\\Resources\\Residences\\Live with parents.png");
		HouseCards.push_back(parents);
		sf::Texture north;
		north.loadFromFile("..\\..\\Resources\\Residences\\North of Princess.png");
		HouseCards.push_back(north);
		sf::Texture don;
		don.loadFromFile("..\\..\\Resources\\Residences\\Residence Don.png");
		HouseCards.push_back(don);
		sf::Texture stauffer;
		stauffer.loadFromFile("..\\..\\Resources\\Residences\\Stauffer Library.png");
		HouseCards.push_back(stauffer);
		sf::Texture vic;
		vic.loadFromFile("..\\..\\Resources\\Residences\\Victoria Hall.png");
		HouseCards.push_back(vic);
		sf::Texture west;
		west.loadFromFile("..\\..\\Resources\\Residences\\West Campus.png");
		HouseCards.push_back(west);

		vector<sf::Texture> QueensCards;
		//QUEENSCARDS
		QueensCards.push_back(NullTexture);
		sf::Texture ban_righ;
		ban_righ.loadFromFile("..\\..\\Resources\\Queens cards\\Ban Righ has tater tots for breaky.png");
		HouseCards.push_back(ban_righ);
		sf::Texture whiteCard;
		whiteCard.loadFromFile("..\\..\\Resources\\Residences\\White Card.png");
		sf::Texture beers;
		beers.loadFromFile("..\\..\\Resources\\Queens cards\\Crushed 40 beers in 24 hours.png");
		HouseCards.push_back(beers);
		sf::Texture concussion;
		concussion.loadFromFile("..\\..\\Resources\\Queens cards\\Didn't get a concussion hitting a beer can off your head.png");
		HouseCards.push_back(concussion);
		sf::Texture academic_probation;
		academic_probation.loadFromFile("..\\..\\Queens cards\\Queens cards\\Get off academic probation.png");
		HouseCards.push_back(academic_probation);
		sf::Texture midterm;
		midterm.loadFromFile("..\\..\\Resources\\Queens cards\\Got 51% on your midterm.png");
		HouseCards.push_back(midterm);
		sf::Texture CPL;
		CPL.loadFromFile("..\\..\\Resources\\Queens cards\\Made it onto Canadian Party Life.png");
		HouseCards.push_back(CPL);
		sf::Texture ticket_on_hoco;
		ticket_on_hoco.loadFromFile("..\\..\\Resources\\Queens cards\\No ticket on HOCO.png");
		HouseCards.push_back(ticket_on_hoco);
		sf::Texture osap;
		osap.loadFromFile("..\\..\\Resources\\Queens cards\\OSAP comes in.png");
		HouseCards.push_back(osap);
		sf::Texture costco;
		costco.loadFromFile("..\\..\\Resources\\Queens cards\\Parents come and take you on a yuuuuge Costco run.png");
		HouseCards.push_back(costco);
		sf::Texture cancel830;
		cancel830.loadFromFile("..\\..\\Resources\\Queens cards\\Prof. McLeod cancels an 830.png");
		HouseCards.push_back(cancel830);
		sf::Texture extension;
		extension.loadFromFile("..\\..\\Resources\\Queens cards\\Prof. McLeod extended the due date for the assignment.png");
		HouseCards.push_back(extension);
		sf::Texture paddysboat;
		paddysboat.loadFromFile("..\\..\\Resources\\Queens cards\\Rode the St. Paddy's boat down Aberdeen.png");
		HouseCards.push_back(paddysboat);
		sf::Texture free_meal;
		free_meal.loadFromFile("..\\..\\Resources\\Queens cards\\Sneak into Ban Righ and get a free meal.png");
		HouseCards.push_back(free_meal);
		sf::Texture bike;
		bike.loadFromFile("..\\..\\Resources\\Queens cards\\Someone found your bike a townie stole.png");
		HouseCards.push_back(bike);
		sf::Texture stages;
		stages.loadFromFile("..\\..\\Resources\\Queens cards\\Still have your keys and wallet after a blackout night at stages.png");
		HouseCards.push_back(stages);
		sf::Texture TA;
		TA.loadFromFile("..\\..\\Resources\\Queens cards\\The TAs bless you with 100% for your assignment.png");
		HouseCards.push_back(TA);
		sf::Texture free_pizza;
		free_pizza.loadFromFile("..\\..\\Resources\\Queens cards\\There's free pizza on campus.png");
		HouseCards.push_back(free_pizza);
		sf::Texture weed;
		weed.loadFromFile("..\\..\\Resources\\Queens cards\\Trudeau legalizes marijuana.png");
		HouseCards.push_back(weed);
		sf::Texture dog;
		dog.loadFromFile("..\\..\\Resources\\Queens cards\\You get to pet a dog.png");
		HouseCards.push_back(dog);
		sf::Texture dinner;
		dinner.loadFromFile("..\\..\\Resources\\Queens cards\\You made something that wasn't KD for dinner.png");
		HouseCards.push_back(dinner);
		sf::Texture clean;
		clean.loadFromFile("..\\..\\Resources\\Queens cards\\Your housemates actually cleaned up after themselves.png");
		HouseCards.push_back(clean);
		sf::Texture tam;
		tam.loadFromFile("..\\..\\Resources\\Queens cards\\Your year got the tam.png");
		HouseCards.push_back(tam);


		//%%%%%%%%%%%%%%%%%%%%%
		//%%% LOAD TEXTURES %%%
		//%%%%%%%%%%%%%%%%%%%%%

		sf::RectangleShape houseCardRect(sf::Vector2f(201 * 2, 312 * 2));
		houseCardRect.setPosition(sf::Vector2f(15, 132));
		sf::RectangleShape degreeCardRect(sf::Vector2f(201 * 2, 312 * 2));
		degreeCardRect.setPosition(sf::Vector2f(176, 132));

		sf::Texture houseCardSetter = HouseCards[0];
		houseCardRect.setTexture(&houseCardSetter);
		sf::Texture degreeCardSetter = DegreeCards[0];
		degreeCardRect.setTexture(&degreeCardSetter);

		GameBoard board(numOfPlayers, gameSize);

		sf::RectangleShape popUpRect(sf::Vector2f(201 * 2, 312 * 2));
		popUpRect.setOrigin(sf::Vector2f(popUpRect.getSize().x / 2, popUpRect.getSize().y / 2));
		popUpRect.setPosition(sf::Vector2f(width / 2, height / 2));
		popUpRect.setFillColor(sf::Color::Color(0, 0, 0, 180));

		sf::RectangleShape popUpRect2(sf::Vector2f(800, 300));
		popUpRect2.setOrigin(sf::Vector2f(popUpRect2.getSize().x / 2, popUpRect2.getSize().y / 2));
		popUpRect2.setPosition(sf::Vector2f(width / 2, height / 2));
		popUpRect2.setFillColor(sf::Color::Color(0, 0, 0, 180));

		sf::RectangleShape hoverCard(sf::Vector2f(201 * 2, 312 * 2));
		hoverCard.setOrigin(sf::Vector2f(popUpRect.getSize().x / 2, popUpRect.getSize().y / 2));
		hoverCard.setPosition(sf::Vector2f(width / 2, height / 2));
		hoverCard.setFillColor(sf::Color::Color(255, 255, 255, 150));
		hoverCard.setTexture(&whiteCard);

		sf::RectangleShape leftButton(sf::Vector2f(350, 100));
		leftButton.setPosition(sf::Vector2f(popUpRect2.getPosition().x - popUpRect2.getSize().x / 2 + 25, popUpRect2.getPosition().y + 25));
		leftButton.setFillColor(sf::Color::Color(50, 50, 50, 255));

		sf::RectangleShape rightButton(sf::Vector2f(350, 100));
		rightButton.setPosition(sf::Vector2f(popUpRect2.getPosition().x + popUpRect2.getSize().x / 2 - rightButton.getSize().x - 25, popUpRect2.getPosition().y + 25));
		rightButton.setFillColor(sf::Color::Color(50, 50, 50, 255));

		//toRender.push_back(background);
		sf::Text PopUpText;
		PopUpText.setFont(font);
		PopUpText.setPosition(sf::Vector2f(popUpRect2.getPosition().x, popUpRect2.getPosition().y + 25));

		sf::Text PopUpTextVal;
		PopUpTextVal.setFont(font);
		PopUpTextVal.setCharacterSize(69); //	;)
		PopUpTextVal.setPosition(sf::Vector2f(popUpRect2.getPosition().x, popUpRect2.getPosition().y + 70));

		sf::Text statsText;
		statsText.setFont(font);
		statsText.setPosition(sf::Vector2f(15, 25));
		statsText.setFillColor(sf::Color::Black);
		statsText.setString("Turn: " + players[turn].playerName.getString() + "\nCash: $" + std::to_string(players[turn].getDebt()) + "\nHouse:\t\tDegree:\n\n\n\n\nQueen's Cards:");

		//VIEW
		window.setMouseCursor(arrow);													//set camera view
		while (true) {
			//EVENT INTERACTION
			sf::Event newEvent;
			while (window.pollEvent(newEvent)) {
				if (newEvent.type == newEvent.Closed) {
					window.close();
				}
				if (newEvent.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {								//if scroll wheel
					float mouseWheelDelta = newEvent.mouseWheelScroll.delta;									//log scroll info
					if (mouseWheelDelta == 1 && zoomLevel < maxZoom) {											//if scroll up
						view.zoom(zoomFactor);
						zoomLevel++;
					}
					else if (mouseWheelDelta == -1 && zoomLevel > minZoom) {									//if scroll down
						view.zoom(1.05f);
						zoomLevel--;
					}
				}
				//IF CLICK
				if (newEvent.type == sf::Event::MouseButtonPressed) {
					std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << "\n";
					if (clicked(spinspin.getShape(), window, view) && canSpin) {			//If clicked on spinner
						if (destination[turn] == 0) {
							window.setMouseCursor(arrow);
							spinspin.hover(false);

							sf::Text leftButtonText;
							leftButtonText.setFont(font);
							leftButtonText.setCharacterSize(25);
							leftButtonText.setPosition(sf::Vector2f(leftButton.getPosition().x + leftButton.getSize().x / 2, leftButton.getPosition().y + leftButton.getSize().y / 2));
							leftButtonText.setString("Left");
							leftButtonText.setOrigin(sf::Vector2f(leftButtonText.getGlobalBounds().width, leftButtonText.getGlobalBounds().height));

							sf::Text rightButtonText;
							rightButtonText.setFont(font);
							rightButtonText.setCharacterSize(25);
							rightButtonText.setPosition(sf::Vector2f(rightButton.getPosition().x + rightButton.getSize().x / 2, rightButton.getPosition().y + rightButton.getSize().y / 2));
							rightButtonText.setString("Right");
							rightButtonText.setOrigin(sf::Vector2f(rightButtonText.getGlobalBounds().width, rightButtonText.getGlobalBounds().height));

							PopUpText.setString("Which path will you take?");
							PopUpText.setOrigin(sf::Vector2f(popUpRect2.getSize().x / 2, popUpRect2.getSize().y / 2));
							PopUpText.setPosition(sf::Vector2f(popUpRect2.getPosition().x + 15, popUpRect2.getPosition().y + 15));
							while (true) {
								bool exit = false;
								sf::Event newEvent;
								while (window.pollEvent(newEvent)) {
									if (newEvent.type == sf::Event::MouseButtonPressed) {
										if (clicked(leftButton, window, window.getDefaultView())) {
											players[turn].setTileNumber(10);
											exit = true;
										}
										else if (clicked(rightButton, window, window.getDefaultView())) {
											exit = true;
										}
									}
								}
								if (clicked(leftButton, window, window.getDefaultView())) {
									leftButton.setFillColor(sf::Color::Color(80, 80, 80, 255));
									window.setMouseCursor(hover);
								}
								else if (clicked(rightButton, window, window.getDefaultView())) {
									rightButton.setFillColor(sf::Color::Color(80, 80, 80, 255));
									window.setMouseCursor(hover);
								}
								else {
									window.setMouseCursor(arrow);
									leftButton.setFillColor(sf::Color::Color(50, 50, 50, 255));
									rightButton.setFillColor(sf::Color::Color(50, 50, 50, 255));
								}
								window.clear();
								window.setView(view);
								window.draw(board.getShape());
								window.draw(spinspin.getShape());
								window.draw(spinspin.getPointer());
								for (int i = 0; i < numOfPlayers; i++) {
									playerAnimation(players[i], board);
									window.draw(players[i].playerName);
									window.draw(players[i].getShape());
								}
								window.setView(window.getDefaultView());
								window.draw(popUpRect2);
								window.draw(PopUpText);
								window.draw(statsText);
								window.draw(leftButton);
								window.draw(rightButton);
								window.draw(leftButtonText);
								window.draw(rightButtonText);
								window.draw(houseCardRect);
								window.draw(degreeCardRect);
								window.display();
								if (exit)
									break;
							}
						}
						window.setMouseCursor(arrow);
						int spinNumber = spinspin.spin();
						std::cout << spinNumber << std::endl;
						if (players[turn].getTile() < 10 && spinNumber + players[turn].getTile() >= 10) {
							destination[turn] = players[turn].getTile() + spinNumber + 21;
						}
						else
							destination[turn] = players[turn].getTile() + spinNumber;
						canSpin = false;
					}
				}
			}

			//EXECUTE TURN!
			if (destination[turn] != players[turn].getTile() || !finished && !stillOnStartingSpace) {		//IF PLAYER n IS NOT AT HIS DESTINATION OR HES NOT FINISHED AND NOT ON STARTING SPACE
				if (!players[turn].moving && !spinspin.spinning) {											//IF PLAYER n IS NOT MOVING AND NOT SPINNING
					int type = 0;
					Card card;
					//CHECK IF PLAYER GETS A CARD
					if (!stillOnStartingSpace) {																//IF PLAYER n IS NOT ON STARTING SPACE
						if (board.getTile(players[turn].getTile()).getType() == "queens" && players[turn].getTile() == destination[turn]) {		//IF QUEENS CARD
							card = board.getQueensCard();														//POP A CARD
							type = 1;
							players[turn].addQCard(card);
							players[turn].setDebt(players[turn].getDebt()+card.getValue());						//SET HIDDEN VALUE
						}
						if (board.getTile(players[turn].getTile()).getType() == "spin" && players[turn].getTile() == destination[turn]) {		//IF RESPIN
							reSpin = true;
							std::cout << "RESPIN\n";
						}
						if (board.getTile(players[turn].getTile()).getType() == "housing") {				//IF QUEENS CARD
							card = board.getHousingCard();													//POP A CARD
							type = 2;
							players[turn].setHouse(card);													//SET HIDDEN VALUE
							houseCardSetter = HouseCards[players[turn].house.id];
							houseCardRect.setTexture(&houseCardSetter);
							std::cout << card.getMessage() << std::endl;
						}
						if (board.getTile(players[turn].getTile()).getType() == "osap" && players[turn].getTile() == destination[turn]) {					//IF QUEENS CARD
							players[turn].setDebt(500);														//SET HIDDEN VALUE
							type = 3;
						}
						if (board.getTile(players[turn].getTile()).getType() == "rent") {
							type = 4;
							players[turn].setDebt(players[turn].getDebt() - players[turn].house.getValue());//SET HIDDEN VALUE
						}
						if (board.getTile(players[turn].getTile()).getType() == "tuition") {
							type = 6;
							players[turn].setDebt(players[turn].getDebt() - players[turn].degree.getValue());//SET HIDDEN VALUE
						}
						if (board.getTile(players[turn].getTile()).getType() == "degree1") {
							card = board.getDegreeCard();										//POP A CARD
							degreeCardSetter = DegreeCards[card.getId()];
							type = 5;
							players[turn].degree = card;									//SET HIDDEN VALUE
							degreeCardSetter = DegreeCards[players[turn].degree.id];
							degreeCardRect.setTexture(&degreeCardSetter);
							std::cout << card.getMessage() << std::endl;
						}
						if (board.getTile(players[turn].getTile()).getType() == "degree3") {
							card = board.getBestDegreeCard();										//POP A CARD
							degreeCardSetter = DegreeCards[card.getId()];
							type = 5;
							players[turn].degree = card;									//SET HIDDEN VALUE
						}
					}
					statsText.setString("Turn: " + players[turn].name + "\nCash: $" + std::to_string(players[turn].getDebt()) + "\nHouse:\t\tDegree:");
					// POP UP MESSAGE!
					if (type!=0) {
						while (true) {
							bool exit = false;
							sf::Event newEvent;
							while (window.pollEvent(newEvent)) {
								if (newEvent.type == sf::Event::MouseButtonPressed) {
									if (clicked(popUpRect, window, window.getDefaultView())) {
										exit = true;
									}
								}
							}
							window.clear();
							window.setView(view);
							window.draw(board.getShape());
							window.draw(spinspin.getShape());
							window.draw(spinspin.getPointer());
							for (int i = 0; i < numOfPlayers; i++) { //Loop through playersss
								playerAnimation(players[i], board);
								window.draw(players[i].getShape());
								window.draw(players[i].playerName);
							}
							window.setView(window.getDefaultView());
							if (type == 1 || type == 3 || type == 4 || type == 6) {
								window.draw(popUpRect2);
								if (type == 1) {
									PopUpTextVal.setString("+" + std::to_string(card.getValue()) + "!");
									PopUpTextVal.setOrigin(sf::Vector2f(PopUpTextVal.getLocalBounds().width / 2, PopUpTextVal.getLocalBounds().height / 2));
									PopUpText.setString(card.getMessage());
								}
								if (type == 3) {
									PopUpTextVal.setString("+500!");
									PopUpTextVal.setOrigin(sf::Vector2f(PopUpTextVal.getLocalBounds().width / 2, PopUpTextVal.getLocalBounds().height / 2));
									PopUpText.setString("You got OSAP!");
								}
								if (type == 4) {
									PopUpTextVal.setString("-" + std::to_string(players[turn].house.getValue()));
									PopUpTextVal.setOrigin(sf::Vector2f(PopUpTextVal.getLocalBounds().width / 2, PopUpTextVal.getLocalBounds().height / 2));
									PopUpText.setString("You paid your rent.");
								}
								if (type == 6) {
									PopUpTextVal.setString("-" + std::to_string(players[turn].degree.getValue()));
									PopUpTextVal.setOrigin(sf::Vector2f(PopUpTextVal.getLocalBounds().width / 2, PopUpTextVal.getLocalBounds().height / 2));
									PopUpText.setString("You paid your tuition.");
								}
								window.draw(PopUpTextVal);
								window.draw(PopUpText);
								if (clicked(popUpRect2, window, window.getDefaultView())) {
									popUpRect2.setFillColor(sf::Color::Color(55, 55, 55, 180));
									window.setMouseCursor(hover);
								}
								else {
									popUpRect2.setFillColor(sf::Color::Color(0, 0, 0, 180));
									window.setMouseCursor(arrow);
								}
							}
							if (type == 2 || type == 5) {
								if (type == 2) {
									popUpRect.setTexture(&houseCardSetter);
									popUpRect.setFillColor(sf::Color::Color(255, 255, 255, 255));
								}
								else if (type == 5) {
									popUpRect.setTexture(&degreeCardSetter);
									popUpRect.setFillColor(sf::Color::Color(255, 255, 255, 255));
								}
								if (clicked(popUpRect, window, window.getDefaultView())) {
									window.draw(popUpRect);
									window.setMouseCursor(hover);
									window.draw(hoverCard);
								}
								else {
									window.draw(popUpRect);
									window.setMouseCursor(arrow);
								}
							}
							window.draw(houseCardRect);
							window.draw(degreeCardRect);
							window.draw(statsText);
							window.display();
							if (exit)
								break;
						}
						window.setMouseCursor(arrow);
					}
					if (players[turn].getTile() == destination[turn] && !players[turn].moving && !stillOnStartingSpace) {	//IF PLAYER n IS AT DESTINATION AND NOT MOVING
						finished = true;																					//TURN IS FINISHED
					}
					else {
						players[turn].moving = true;
						if (players[turn].getTile() == 9)
							players[turn].setTileNumber(31);
						else
							players[turn].setTileNumber(players[turn].getTile() + 1);										//INCREASE HIS PLAYER TILE
					}
				}
			}
			//FINISH TURN
			if (destination[turn] == players[turn].getTile() && finished) {						//Reached destination
				canSpin = true;																//LET NEXT PLAYER SPIN
				stillOnStartingSpace = true;												//NEXT PLAYER IS ON STARTING SPACE
				if (!reSpin)
					turn = (turn + 1) % numOfPlayers;										//CYCLICAL ADDITION
				reSpin = false;
				finished = false;															//NEXT PLAYER IS NOT FINISHED
				houseCardSetter = HouseCards[players[turn].house.id];
				houseCardRect.setTexture(&houseCardSetter);
				degreeCardSetter = DegreeCards[players[turn].degree.id];
				degreeCardRect.setTexture(&degreeCardSetter);
			}

			//UPDATE STATS
			statsText.setString("Turn: " + players[turn].name + "\nCash: $" + std::to_string(players[turn].getDebt()) + "\nHouse:\t\tDegree:");
			players[turn].playerName.setPosition(sf::Vector2f(players[turn].getShape().getPosition().x, players[turn].getShape().getPosition().y-50));

			//UPDATE VIEW COORDINATES
			viewLeftCoord = view.getCenter().x - (width / 2)*pow(zoomFactor, zoomLevel);						//update left camera boarder
			viewTopCoord = view.getCenter().y - (height / 2)*pow(zoomFactor, zoomLevel);						//update top camera boarder
			viewRightCoord = view.getCenter().x + (width / 2)*pow(zoomFactor, zoomLevel);						//update right camera boarder
			viewBottomCoord = view.getCenter().y + (height / 2)*pow(zoomFactor, zoomLevel);						//update bottom camera boarder

			//PAN AROUND
			sf::Vector2i mPos = sf::Mouse::getPosition(window);													//get mouse pos
			mouseDeltaX = mPos.x - lastMouseX;																	//change in mouse x
			mouseDeltaY = mPos.y - lastMouseY;																	//change in mouse y
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !clicked(spinspin.getShape(), window, view)) {		//if left click
				view.move(mouseDeltaX*0.5f, mouseDeltaY*0.5f);													//move around
			}

			//RE-CENTRE
			if (view.getCenter().x - (width / 2)*pow(zoomFactor, zoomLevel) < 0)								//if too far left
				view.move(-(view.getCenter().x - (width / 2)*pow(zoomFactor, zoomLevel)), 0);
			else if (view.getCenter().x + (width / 2)*pow(zoomFactor, zoomLevel) > width)						//if too far right
				view.move(width - (view.getCenter().x + (width / 2)*pow(zoomFactor, zoomLevel)), 0);
			if (view.getCenter().y - (height / 2)*pow(zoomFactor, zoomLevel) < 0)								//if too far up
				view.move(0, -(view.getCenter().y - (height / 2)*pow(zoomFactor, zoomLevel)));
			else if (view.getCenter().y + (height / 2)*pow(zoomFactor, zoomLevel) > height)						//if too far down
				view.move(0, height - (view.getCenter().y + (height / 2)*pow(zoomFactor, zoomLevel)));
			lastMouseX = mPos.x;																				//update last mouse movement x
			lastMouseY = mPos.y;																				//update last mouse movement y

			//UPDATE STATS



			//BUTTON HOVER
			if (clicked(spinspin.getShape(), window, view) && canSpin) {
				spinspin.hover(true);
				window.setMouseCursor(hover);
			}
			else {
				window.setMouseCursor(arrow);
				spinspin.hover(false);
			}

			//UPDATE FRAME
			window.clear();
			spinspin.spinAnimation();
			window.setView(view);
			window.draw(board.getShape());
			window.draw(spinspin.getShape());
			window.draw(spinspin.getPointer());
			for (int i = 0; i < numOfPlayers; i++) {
				playerAnimation(players[i], board);
				window.draw(players[i].getShape());
				window.draw(players[i].getText());
			}
			window.setView(window.getDefaultView());
			window.draw(statsText);
			window.draw(houseCardRect);
			window.draw(degreeCardRect);
			window.display();																					//continually update the display
		}
	}

	return 0;
}

bool clicked(sf::RectangleShape rect, sf::RenderWindow &window, sf::View view) {
	sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);

	sf::Vector2f tempPos = rect.getPosition();
	rect.setPosition(rect.getPosition().x - rect.getOrigin().x, rect.getPosition().y - rect.getOrigin().y);
	if (mouse.x > rect.getPosition().x && mouse.x < rect.getPosition().x + rect.getSize().x && mouse.y > rect.getPosition().y && mouse.y < rect.getPosition().y + rect.getSize().y)
		return true;
	else
		return false;
	rect.setPosition(tempPos);
}

void playerAnimation(Player &player, GameBoard board) {
	sf::Vector2f playerPos = player.getPosition();
	sf::Vector2f tilePos = sf::Vector2f(board.getTile(player.getTile()).getXPosition(), board.getTile(player.getTile()).getYPosition());
	if (playerPos == tilePos && !stillOnStartingSpace) {
		player.moving = false;
		return;
	}
	float deltaX = tilePos.x - playerPos.x;
	float deltaY = tilePos.y - playerPos.y;
	if (deltaX != 0 || deltaY != 0) {
		stillOnStartingSpace = false;
		if (deltaX > 0)
			player.setPosition(sf::Vector2f(playerPos.x += 2, playerPos.y));
		else if (deltaX < 0)
			player.setPosition(sf::Vector2f(playerPos.x -= 2, playerPos.y));
		if (deltaY > 0)
			player.setPosition(sf::Vector2f(playerPos.x, playerPos.y += 2));
		else if (deltaY < 0)
			player.setPosition(sf::Vector2f(playerPos.x, playerPos.y -= 2));
		if (deltaX < 2 && deltaX > -2)
			player.setPosition(sf::Vector2f(tilePos.x, playerPos.y));
		if (deltaY < 2 && deltaY > -2)
			player.setPosition(sf::Vector2f(playerPos.x, tilePos.y));
		if (deltaY < 2 && deltaX < 2 && deltaY > -2 && deltaX > -2)
			player.setPosition(tilePos);
	}
}

