#include <iostream>
#include "Game.h"



int main() {
	
	try {
		std::cout << "Start game!\n";
        
		Player player1;
		GameField map(30,20);
		PlayerMovement nav(&player1, &map);
		CreateField GMap(&map, &nav);
		Game game(&nav, &GMap);
		game.startGame();



	}
	catch (const char* error_message) {
		std::cout << error_message << std::endl;
	}

	
	//return 0;
}