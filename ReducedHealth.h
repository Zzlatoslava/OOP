#pragma once
#include "EventInterface.h"
#include "PlayerMovement.h"

class ReducedHealth : public EventInterface {

private:
	PlayerMovement* movement;
	int id = 1;
public:
	explicit ReducedHealth(PlayerMovement* pmovement);
	void someEvent()override;
	int getID() override;
};