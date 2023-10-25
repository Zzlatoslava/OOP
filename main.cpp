#include <iostream>
#include "PlayerMovement.h"
#include "GameField.h"



int main() {
	
	try {
		std::cout << "Start game!\n";
		
	}
	catch (const char* error_message) {
		std::cout << error_message << std::endl;
	}

	
	return 0;
}