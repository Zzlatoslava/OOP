#include "DoubleScore.h"


DoubleScore::DoubleScore(PlayerMovement* pmovement) {
	if (pmovement == nullptr) {
		throw "Error in creating a CollectAPoint class object\n";
	}
	this->movement = pmovement;
}

void DoubleScore::someEvent() {
	movement->increaseDoubleScore(2);
}

int DoubleScore::getID()
{
	return this->id;
}