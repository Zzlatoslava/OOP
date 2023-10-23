#include "ReducedHealth.h"


ReducedHealth::ReducedHealth(PlayerMovement* pmovement) {
	if (pmovement == nullptr) {
		throw "Error in creating a ReducedHealth class object\n";
	}
	this->movement = pmovement;
}

void ReducedHealth::someEvent() {
	movement->decreaseHealth(1);
}