#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Commands.h"
#include "Tracking.h"



class GUI {
private:
	sf::RenderWindow window{ sf::VideoMode(1400, 1000), "How to get a cat 2" };
	sf::Texture texture;
	sf::Texture textureL;
	sf::Texture textureCBefore;
	sf::Texture textureCBack;
	sf::Texture textureCLeft;
	sf::Texture textureCRight;
	sf::Texture textureWater;


	sf::Sprite background;
	sf::Sprite backgroundL;
	sf::Sprite catBefore;
	sf::Sprite catBack;
	sf::Sprite catLeft;
	sf::Sprite catRight;
	sf::Sprite cat;
	sf::Sprite waterS;

	float x = 315.f;
	float y = 320.f;	
	Tracking* tracking;


public:
	GUI(Tracking * tracking);
	Commands startWin();
	Commands selectLevelWin();
	Commands afterLevelWin( int num_level, int max_level);
	Commands endWin();
	Commands gameOverWin();
	

	void level();
	void cat_Before();
	void cat_Back();
	void cat_Left();
	void cat_Right();
	Commands levelGame(Move move = Default);
	void moveCat(Move move);
	void water();
	sf::Sprite heart();
	sf::Sprite fish();

	
	
	

};