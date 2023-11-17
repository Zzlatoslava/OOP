#include "Game.h"

Game::Game() {

	Player player1;
	GameField map;
	PlayerMovement nav(&player1, &map);
	CreateField GMap(&map, &nav);
	GUI graphics;
	FileReader file;
	file.InputSettingsReader("keys.txt");
	sf::Sprite level;
	sf::Sprite cat;
	InputReader reader;

	Commands command = START;
	bool work = true;
	while (work) {
		switch (command) {
		case START:
			command = graphics.startWin();
			break;
		case SELECT_LEVEL:
			command = graphics.selectLevelWin();
			break;
		case LEVEL_1:
			GMap.setLevel(1);
			GMap.createLevel();
			level = graphics.level();
			cat = graphics.cat();
			Move move;
			 do {
				move = reader.read(file.getKeyList());
				if (nav.move(moveSelection(move))) {
					std::cout << "X: " << nav.getXCoordinate()<<"\n";
					std::cout << "Y: " << nav.getYCoordinate()<<"\n";
					/*graphics.levelGame(&level, &cat, move);
					if (graphics.levelGame(&level, &cat, move) == EXIT) {
						command = EXIT;
						break;
					}*/
					if (dead(&player1)) {
						command = GAME_OVER;
						break;
					}
				}
				
				
			 } while (!winGame(&nav, &map));
			command = LEVEL_WIN;
			break;
		case LEVEL_2:
			GMap.setLevel(2);
			GMap.createLevel();
			// отработка передвижения
			command = LEVEL_WIN;
			break;
		case LEVEL_WIN:
			command = graphics.afterLevelWin(GMap.getLevel(), MAX_LEVEL);
			GMap.setLevel(GMap.getLevel() + 1);
			break;
		case END:
			command = graphics.endWin();
			break;
		case GAME_OVER:
			command = graphics.gameOverWin();
			break;
		case EXIT:
			work = false;
			break;
		default:
			throw "Game Error\n";


		}
	}
}

bool Game::winGame(PlayerMovement* pmove, GameField* map) {
	if (pmove->getXCoordinate() == map->getEndX() && pmove->getYCoordinate() == map->getEndY()) {
		return true;
	}
	return false;
}

bool Game::dead(Player * player ){
	if (player->getHealth() < 1) {
		return true;
	}
	return false;
}

Direction Game::moveSelection(Move action)
{
	switch (action) {
	case move_up:
		std::cout << "^\n";
		return UP;

	case move_left:
		std::cout << "<\n";
		return LEFT;

	case move_right:
		std::cout << ">\n";
		return RIGHT;

	case move_down:
		std::cout << "v\n";
		return DOWN;
	default:
		return NONE;
	}
}


