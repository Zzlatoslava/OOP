#pragma once
#include "AddingHelath.h"
#include "CollectAPoint.h"
#include "ReducedHealth.h"
#include "Teleport.h"
#include <iostream>
#define MAX_LEVEL 2




class CreateField {
private:
	int level;
	GameField* field;
	PlayerMovement* movement;
public:

	CreateField(GameField* gamefield,PlayerMovement* pmovement, int level = 1);
	void createLevel();
	void setEventCF( EventInterface* event, int quantity);
	int getLevel();
	void setLevel(int num_level);
};