#pragma once
#include "RenderingInterface.h"
#include <SFML/Graphics.hpp>


class RenderGUI :public RenderingInterface{
private:
	sf::Texture texture;
	sf::Texture textureL;
	sf::Texture textureCBefore;
	sf::Texture textureCBack;
	sf::Texture textureCLeft;
	sf::Texture textureCRight;
	sf::Texture textureWater;
	sf::Texture textureFish;
	sf::Texture textureHeart;
	sf::Texture textureTeleport;
	sf::Texture textureFishRed;
	sf::Texture textureEnemy;
	

	sf::Sprite background;
	sf::Sprite backgroundL;
	sf::Sprite catBefore;
	sf::Sprite catBack;
	sf::Sprite catLeft;
	sf::Sprite catRight;
	sf::Sprite waterS;
	sf::Sprite fishS;
	sf::Sprite heartS;
	sf::Sprite teleportS;
	sf::Sprite fishRedS;
	sf::Sprite enemyRS;
	sf::Sprite enemyMS;
	


public:
	RenderGUI();
	void setBackground(std::string);
	void level();
	void cat_Before();
	void cat_Back();
	void cat_Left();
	void cat_Right();
	void water();
	void heart();
	void fish();
	void fishRed();
	void teleport();
	void enemy();
	sf::Sprite getBackground();
	sf::Sprite getLevel();
	sf::Sprite getCatBefore();
	sf::Sprite getCatBack();
	sf::Sprite getCatLeft();
	sf::Sprite getCatRight();
	sf::Sprite getWater();
	sf::Sprite getHeart();
	sf::Sprite getFish();
	sf::Sprite getFishRed();
	sf::Sprite getTeleport();
	sf::Sprite getEnemyR();
	sf::Sprite getEnemyM();
};