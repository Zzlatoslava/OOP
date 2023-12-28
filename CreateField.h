#pragma once
#include "AddingHelath.h"
#include "CollectAPoint.h"
#include "ReducedHealth.h"
#include "Teleport.h"
#include "DoubleScore.h"
#include "DamageInteractionScheme.h"
#include "PushInteractionScheme.h"
#include "RandomMoveScheme.h"
#include "SeekAndMoveScheme.h"

#include <iostream>
#define MAX_LEVEL 2

struct Coord {
	int x = 0 ;
	int y = 0;
};



class CreateField {

public:

	CreateField(GameField* gamefield,PlayerMovement* pmovement, int level = 1);
	void createLevel();
	void setEventCF( EventInterface* event, int quantity);
	int getLevel();
	void setLevel(int num_level);
	void moveEnemyM();
	Coord getCoordM();
	void moveEnemyR();
	Coord getCoordR();
	

private:
	int level;
	GameField* field;
	PlayerMovement* movement;
	Enemy <SeekAndMoveScheme, PushInteractionScheme> Miroslava;
	Enemy <RandomMoveScheme, DamageInteractionScheme> Radmila;
};