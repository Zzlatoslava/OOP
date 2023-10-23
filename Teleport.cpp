#include "Teleport.h"


Teleport::Teleport(PlayerMovement* pmovement) {
	if (pmovement == nullptr) {
		throw "Error in creating a Teleport class object\n";
	}
	this->movement = pmovement;
}

void Teleport::someEvent() {
	movement->setCoordinates(1, 1); //поменять координаты 
}