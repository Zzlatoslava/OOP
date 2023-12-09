#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include "RenderGUI.h"
#include "Commands.h"
#include "Tracking.h"



class GUI {
private:
	sf::RenderWindow window{ sf::VideoMode(1400, 1000), "How to get a cat 2" };
	sf::Sprite cat;
	Tracking* tracking;
	RenderGUI graphics;


public:
	GUI(Tracking * tracking);
	Commands startWin();
	Commands selectLevelWin();
	Commands afterLevelWin( int num_level, int max_level);
	Commands endWin();
	Commands gameOverWin();
	

	Commands levelGame(int newX, int newY, Move move = Default);
	void moveCat(Move move);
	

	
	
	

};