#include "CollectAPoint.h"


CollectAPoint::CollectAPoint(PlayerMovement* pmovement) {
	if (pmovement == nullptr) {
		throw "Error in creating a CollectAPoint class object\n";
	}
	this->movement = pmovement;
}

void CollectAPoint::someEvent() {
	movement->increaseScore(1);
} 