#pragma once
#include "EventInterface.h"
#include "PlayerMovement.h"

class Teleport: public EventInterface {
private:
	PlayerMovement* movement;
	int id = 4;
public:
	explicit Teleport(PlayerMovement* pmovement);
	void someEvent()override;
	int getID() override;
};