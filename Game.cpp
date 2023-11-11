#include "Game.h"

Game::Game() {

	Player player1;
	GameField map(MAX_WIDTH, MAX_HEIGHT, 5, 5, 17, 0);
	PlayerMovement nav(&player1, &map, map.getStartX(), map.getStartY());
	CreateField GMap(&map, &nav);
	GUI graphics;

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
			// отработка передвижения
			command = graphics.level();
			break;
		case LEVEL_2:
			GMap.setLevel(1);
			GMap.createLevel();
			// отработка передвижения
			command = graphics.level();
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


