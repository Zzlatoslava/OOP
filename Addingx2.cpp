#include "Addingx2.h"

Addingx2::Addingx2(PlayerMovement* pmovement)
{
	if (pmovement == nullptr) {
		throw "Error in creating a CollectAPoint class object\n";
	}
	this->movement = pmovement;
}

void Addingx2::someEvent()
{
	movement->increaseScore(2);
}

int Addingx2::getID()
{
	return this->id;
}

