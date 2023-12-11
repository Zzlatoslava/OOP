#include "Game.h"

Game::Game() {

	Player player;
	GameField map;
	PlayerMovement nav(&player, &map);
	FileReader file;
	InputReader reader;
	Tracking tracking(&player, &map, &nav, &reader);
	CreateField GMap(&map, &nav);
	GUI graphics(&tracking);
	Commands command = START;
	bool work = true;
	
	Message message(&tracking,MessageTracker::OutputMode::Console, "game_log.txt");
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
			message.newGame();
			graphics.levelGame(nav.getXCoordinate(), nav.getYCoordinate() );
			Move move;
			
			while (true) {
				move = reader.read(file.getKeyList());
				nav.move(tracking.moveSelection(move));
				if (tracking.movePlayer()) {
					message.commandExecuted(tracking.moveToString(move));
					tracking.printIndicators();
					command = graphics.levelGame(nav.getXCoordinate(), nav.getYCoordinate(), move);

				}
				else if (move == escape) {
					command = START;
					break;
				}
				else {
					message.commandNotExecuted();
				}
				
				if (tracking.dead()) {
					command = GAME_OVER;
					message.playerLoses();
					break;
				}
				if (tracking.winGame()) {
					command = LEVEL_WIN;
					message.playerWins();
					break;
				}


			} ;
			
						
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







