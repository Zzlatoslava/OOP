#pragma once
#include <SFML/Graphics.hpp>
#include "CreateField.h"

class Game {
private:
	PlayerMovement* movement;
	CreateField* map;
	sf::RenderWindow window{ sf::VideoMode(1400, 1000), "How to get a cat 2" };
public:
	Game(PlayerMovement* pmovement , CreateField* newMap );
	void startGame();
	void selectLevel();
	void movePlayer(Direction);
	void afterLevel();
	void endGame();
};