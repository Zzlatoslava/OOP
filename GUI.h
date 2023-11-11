#pragma once
#include <iostream>
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
	sf::Sprite sprite;


public:
	GUI();
	Commands startWin();
	Commands selectLevelWin();
	Commands level();
	Commands afterLevelWin( int num_level, int max_level);
	Commands endWin();
	Commands gameOverWin();
};