#include "Game.h"

Game::Game() {

	Player player;
	GameField map;
	PlayerMovement nav(&player, &map);
	Tracking tracking(&player, &map, &nav);
	CreateField GMap(&map, &nav);
	GUI graphics(&tracking);
	Commands command = START;
	bool work = true;
	FileReader file;
	InputReader reader;
	file.InputSettingsReader("keys.txt");
	while (work) {

		switch (command) {
		case START:
			command = graphics.startWin();
			break;
		case SELECT_LEVEL:
			command = graphics.selectLevelWin();
			if (command == LEVEL_1) {
				tracking.setLevel(1);
				command = LEVEL;
			}
			else if (command == LEVEL_2) {
				tracking.setLevel(2);
				command = LEVEL;
			}
			break;
		case LEVEL:
			
			GMap.setLevel(tracking.getLevel());
			GMap.createLevel();

			graphics.levelGame(nav.getXCoordinate(), nav.getYCoordinate() );
			Move move;
			
			while (true) {
				move = reader.read(file.getKeyList());
				nav.move(tracking.moveSelection(move));
				
				if (tracking.movePlayer()) {
					tracking.printIndicators();
					command = graphics.levelGame(nav.getXCoordinate(), nav.getYCoordinate(), move);

				}
				if (move == escape) {
					command = START;

					break;
				}
				if (tracking.dead()) {
					command = GAME_OVER;
					break;
				}
				if (tracking.winGame()) {
					command = LEVEL_WIN;
					break;
				}


			} ;
			tracking.update();
						
			break;
				
			
		case LEVEL_WIN:
			command = graphics.afterLevelWin(tracking.getLevel(), MAX_LEVEL);
			tracking.update();
			
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







