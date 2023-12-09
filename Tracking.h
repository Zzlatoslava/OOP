#pragma once
#include "Move.h"
#include "CreateField.h"
#include "InputReader.h"

enum Event {
	Reduced = 1,
	Adding = 2,
	Collect = 3,
	Teleport = 4,
	None = 0
};

class Tracking
{
private:
	Player* p;
	GameField* map;
	PlayerMovement* nav;
	int level;
	
	int totalScore = 0;

public:
	Tracking(Player* p, GameField* map, PlayerMovement* nav, int mLevel = 1);

	bool winGame();
	bool movePlayer();
	Direction moveSelection(Move action);
	void printIndicators();
	bool dead();
	int getHealth();
	int getScore();
	int getTotalScore();

	int getLevel();
	void setLevel(int mLevel);

	Event getEvent(int x, int y);
	void update();



};
