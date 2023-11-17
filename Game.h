#pragma once
#include "GUI.h"
#include "InputReader.h"
#include "CreateField.h"


class Game {

public:
	Game();
	bool winGame(PlayerMovement* pmove, GameField* map);
	bool dead(Player * player);
	Direction moveSelection(Move action);
};