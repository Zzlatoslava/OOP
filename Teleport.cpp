#include "Teleport.h"


Teleport::Teleport(PlayerMovement* pmovement) {
	if (pmovement == nullptr) {
		throw "Error in creating a Teleport class object\n";
	}
	this->movement = pmovement;
}

void Teleport::someEvent() {
	movement->setCoordinates(28, 9); 
	movement->setPassabilityGF(24, 10);
	movement->setPassabilityGF(24, 11);
}

int Teleport::getID()
{
	return this->id;
}
