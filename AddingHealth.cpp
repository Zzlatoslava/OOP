#include "AddingHelath.h"


AddingHealth::AddingHealth(PlayerMovement* pmovement) {
	if (pmovement == nullptr) {
		throw "Error in creating a CollectAPoint class object\n";
	}
	this->movement = pmovement;
}

void AddingHealth::someEvent() {
	movement->increaseHealth(1);
}