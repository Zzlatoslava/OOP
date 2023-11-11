#include <iostream>
#include "Game.h"




int main() {
	
	try {
		     
		Game game;
		InputReader reader;
		reader.setupKeys("keys.txt");

		
			reader.readInput();
		


	}
	catch (const char* error_message) {
		std::cout << error_message << std::endl;
	}

	return 0;
}