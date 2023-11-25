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
	while (work) {

		switch (command) {
		case START:
			command = graphics.startWin();
			break;
		case SELECT_LEVEL:
			command = graphics.selectLevelWin();
			break;
		case LEVEL_1:
			tracking.setLevel(1);
			GMap.setLevel(tracking.getLevel());
			GMap.createLevel();
			graphics.levelGame();
			Move move;
			do {

				//move = reader.read(list.getKeyList());
				//move = reader.read(file.getKeyList());
				
				if (tracking.movePlayer(&move)) {
					tracking.printIndicators();
					graphics.levelGame(move);
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

					//graphics.levelGame(&level, &cat);

					
					
			


			} while (true);
			
			//graphics.setCoord();
			player.setHealth(HEALTH);
			player.setScore(0);
			//command = LEVEL_WIN;
			break;


			/*GMap.setLevel(1);
			GMap.createLevel();
			
			Move move;
			
			 do {
				
				 //move = reader.read(list.getKeyList());
				move = reader.read(file.getKeyList());
				if (map.isEvent(nav.getXCoordinate(), nav.getYCoordinate())) {

					std::cout << typeid(map.getEvent(nav.getXCoordinate(), nav.getYCoordinate())).name() << "\n";
				} 
				if (nav.move(moveSelection(move))) {
					std::cout << "X: " << nav.getXCoordinate()<<"\n";
					std::cout << "Y: " << nav.getYCoordinate()<<"\n";
					std::cout << "Score: " << player1.getScore()<<"\n";
					std::cout << "Health: " << player1.getHealth() << "\n";
					
					

					//graphics.levelGame(&level, &cat);
					
					if (graphics.levelGame() == EXIT) {
						command = EXIT;
						break;
					}
					if (dead(&player1)) {
						command = GAME_OVER;
						break;
					}
				}
				
				
			 } while (!winGame(&nav, &map));
			 if (dead(&player1)) {
				 command = GAME_OVER;
				 break;
			 }
			 graphics.setCoord();
			 player1.setHealth(HEALTH);
			 player1.setScore(0);
			command = LEVEL_WIN;
			break;*/
			break;
		case LEVEL_2:
			
			// отработка передвижения
			command = LEVEL_WIN;
			break;
		case LEVEL_WIN:
			command = graphics.afterLevelWin(tracking.getLevel(), MAX_LEVEL);
			
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





