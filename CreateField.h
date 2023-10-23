#pragma once
#include "AddingHelath.h"
#include "CollectAPoint.h"
#include "ReducedHealth.h"
#include "Teleport.h"





class CreateField {
private:
	int level;
	GameField* field;
	PlayerMovement* movement;
public:

	CreateField(GameField* gamefield,PlayerMovement* pmovement, int level = 1);
	void createLevel(int level =1);
};