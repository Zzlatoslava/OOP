#include "Game.h"
bool titlesOn = true;
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
	
	
	file.InputSettingsReader("keys.txt");
	while (work) {

		switch (command) {
		case START:
			command = graphics.startWin();
			
			break;
		case SELECT_LEVEL:
			command = graphics.selectLevelWin();
			if (command == LEVEL_1) {
				if (titlesOn) {
					tracking.setLevel(1);
					command = TITLES;
				}
				else {
					tracking.setLevel(1);
					command = LEVEL;
				}
			}
			else if (command == LEVEL_2) {
				tracking.setLevel(2);
				command = LEVEL;
			}
			break;
		case TITLES:
			command = graphics.titlesGUI();
			break;

		case LEVEL:
			
			GMap.setLevel(tracking.getLevel());
			GMap.createLevel();
			
			
			Move move;
			move = Default;
			
			
			while (command != END && command != START  && command != EXIT) {
				command = graphics.levelGame(nav.getXCoordinate(), nav.getYCoordinate(), GMap.getCoordM(), GMap.getCoordR(), move);
				//move = reader.read(file.getKeyList());
				if (command == W)move = move_up;
				else if (command == A) move = move_left;
				else if (command == S) move = move_down;
				else if (command == D) move = move_right;
				else move = Default;


				nav.move(tracking.moveSelection(move));
				if (tracking.movePlayer()) {
					GMap.moveEnemyM();
					GMap.moveEnemyR();
					tracking.printIndicators();
					//command = graphics.levelGame(nav.getXCoordinate(), nav.getYCoordinate(), GMap.getCoordM(), GMap.getCoordR(), move);
					if (tracking.dead()) {
						command = GAME_OVER;

						tracking.update();
						break;
					}
					if (tracking.winGame()) {
						command = LEVEL_WIN;

						break;
					}
				}
				


			} ;
			if (command == START) {
				tracking.update();
				break;
			}
					
			break;
				
			
		case LEVEL_WIN:
			command = graphics.afterLevelWin(tracking.getLevel(), MAX_LEVEL);
			tracking.update();
			if (command == LEVEL) {
				titlesOn = false;
				command = TITLES;
			}
			
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







