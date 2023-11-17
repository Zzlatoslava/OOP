#pragma once
#include <iostream>
#include "Move.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum Commands {
	START,
	SELECT_LEVEL,
	LEVEL_1,
	LEVEL_2,
	LEVEL_WIN,
	END,
	GAME_OVER,
	EXIT
};

class GUI {
private:
	sf::RenderWindow window{ sf::VideoMode(1400, 1000), "How to get a cat 2" };
	sf::Texture texture;
	sf::Texture textureCat;
	sf::Sprite background;
	sf::Sprite myCat;


public:
	GUI();
	Commands startWin();
	Commands selectLevelWin();
	sf::Sprite level();
	sf::Sprite cat();
	Commands levelGame(sf::Sprite* level, sf::Sprite* cat, Move move);
	Commands afterLevelWin( int num_level, int max_level);
	Commands endWin();
	Commands gameOverWin();

};